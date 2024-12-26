//
// Created by Jsn on 12/19/2024.
//

#include "../include/snake.h"

Snake::Snake(int blocksize, Textbox* l_log)
{
    m_log = l_log;
    m_size = blocksize;
    m_body.setSize(sf::Vector2f(m_size - 1, m_size - 1));
    Reset();
}

Snake::~Snake(){}

void Snake::Reset()
{
    m_snakebody.clear();

    m_snakebody.push_back(SnakeSegment(5, 7));
    m_snakebody.push_back(SnakeSegment(5, 6));
    m_snakebody.push_back(SnakeSegment(5, 5));

    SetDirection(Direction::None);
    m_speed = 15;
    m_lives = 3;
    m_score = 0;
    m_lost = false;
}

void Snake::SetDirection(Direction l_dir)
{
    m_dir = l_dir;
}

Direction Snake::GetDirection()
{
    return m_dir;
}

int Snake::GetSpeed()
{
    return m_speed;
}

sf::Vector2i Snake::GetPosition()
{
    if (m_snakebody.empty()) return sf::Vector2i(1, 1);
    return m_snakebody.front().position;
}

int Snake::GetLives()
{
    return m_lives;
}

int Snake::GetScore()
{
    return m_score;
}

void Snake::IncreaseScore()
{
    m_score += 10;
    m_log->Add("10+ ... Score: " + std::to_string((long long)m_score));
}

bool Snake::HasLost()
{
    return m_lost;
}

void Snake::Lose()
{
    m_lost = true;
}

void Snake::ToggleLost()
{
    m_lost = !m_lost;
}

void Snake::Extend()
{
    if (m_snakebody.empty()) return;
    SnakeSegment& tail_head = m_snakebody[m_snakebody.size() - 1];

    if (m_snakebody.size() > 1)
    {
        SnakeSegment& tail_bone = m_snakebody[m_snakebody.size() - 2];

        if (tail_head.position.x == tail_bone.position.x)
        {
            if (tail_head.position.y > tail_bone.position.y)
            {
                m_snakebody.push_back(SnakeSegment(tail_head.position.x, tail_head.position.y + 1));
            }
            else
            {
                m_snakebody.push_back(SnakeSegment(tail_head.position.x, tail_head.position.y - 1));
            }
        }
        else if (tail_head.position.y == tail_bone.position.y)
        {
            if (tail_head.position.x > tail_bone.position.x)
            {
                m_snakebody.push_back(SnakeSegment(tail_head.position.x + 1, tail_head.position.y));
            }
            else
            {
                m_snakebody.push_back(SnakeSegment(tail_head.position.x - 1, tail_head.position.y));
            }
        }
    }
    else
    {
        if (m_dir == Direction::Up)
        {
            m_snakebody.push_back(SnakeSegment(tail_head.position.x, tail_head.position.y + 1));
        }
        else if (m_dir == Direction::Down)
        {
            m_snakebody.push_back(SnakeSegment(tail_head.position.x, tail_head.position.y - 1));
        }
        else if (m_dir == Direction::Left)
        {
            m_snakebody.push_back(SnakeSegment(tail_head.position.x + 1, tail_head.position.y));
        }
        else
        {
            m_snakebody.push_back(SnakeSegment(tail_head.position.x - 1, tail_head.position.y));
        }
    }
}

void Snake::CheckCollision()
{
    if (m_snakebody.size() < 5) return;
    SnakeSegment& head = m_snakebody.front();

    for (auto itr = m_snakebody.begin() + 1; itr != m_snakebody.end(); itr++)
    {
        if (itr->position == head.position)
        {
            int segments = m_snakebody.end() - itr;
            Cut(segments);
            break;
        }
    }
}

void Snake::Cut(int l_segments)
{
    for (int i = 0; i < l_segments; i++)
    {
        m_snakebody.pop_back();
    }

    --m_lives;
    if (!m_lives) Lose();
    m_log->Add("Lives left" + std::to_string((long long)m_lives));
}

void Snake::Render(sf::RenderWindow& l_window)
{
    if (m_snakebody.empty()) return;

    auto head = m_snakebody.begin();
    m_body.setFillColor(sf::Color::Yellow);
    m_body.setPosition(head->position.x * m_size, head->position.y * m_size);
    l_window.draw(m_body);

    m_body.setFillColor(sf::Color::Green);
    for (auto itr = m_snakebody.begin() + 1; itr != m_snakebody.end(); itr++)
    {
        m_body.setPosition(itr->position.x * m_size, itr->position.y * m_size);
        l_window.draw(m_body);
    }
}

void Snake::Tick()
{
    if (m_snakebody.empty()) return;
    if (m_dir == Direction::None) return;
    Move();
    CheckCollision();
}

void Snake::Move()
{
    for (int i = m_snakebody.size() - 1; i > 0; --i)
    {
        m_snakebody[i].position = m_snakebody[i - 1].position;
    }

    if (m_dir == Direction::Left) --m_snakebody[0].position.x;
    else if (m_dir == Direction::Right) ++m_snakebody[0].position.x;
    else if (m_dir == Direction::Up) --m_snakebody[0].position.y;
    else if (m_dir == Direction::Down) ++m_snakebody[0].position.y;
}

Direction Snake::GetPhysicalDirection()
{
    if (m_snakebody.size() <= 1) return Direction::None;

    SnakeSegment& head = m_snakebody[0];
    SnakeSegment& neck = m_snakebody[1];

    if (head.position.x == neck.position.x) return (head.position.y > neck.position.y) ? Direction::Down : Direction::Up;
    else if (head.position.y == neck.position.y) return (head.position.x > neck.position.x) ? Direction::Right : Direction::Left;

    return Direction::None;
}