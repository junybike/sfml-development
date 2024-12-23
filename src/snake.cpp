//
// Created by Jsn on 12/19/2024.
//

#include "../include/snake.h"

Snake::Snake(int blocksize)
{
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

void Snake::SetDirection(Direction l_dir) { m_dir = l_dir; }
Direction Snake::GetDirection() { return m_dir; }
int Snake::GetSpeed() { return m_speed; }

sf::Vector2i Snake::GetPosition()
{
    if (m_snakebody.empty()) return sf::Vector2i(1, 1);
    return m_snakebody.front().position;
}

int Snake::GetLives() { return m_lives; }
int Snake::GetScore() { return m_score; }

void Snake::IncreaseScore() {m_score += 10; }
bool Snake::HasLost() { return m_lost; }
void Snake::Lose() {m_lost = false; }
void Snake::ToggleLost() { m_lost = !m_lost; }

void Snake::Extend()
{
    if (m_snakebody.empty()) return;
    SnakeSegment& tail_head = m_snakebody[m_snakebody.size() - 1];

    if (m_snakebody.size() > 1)
    {
        SnakeSegment& tail_bone = m_snakebody[m_snakebody.size() - 1];

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