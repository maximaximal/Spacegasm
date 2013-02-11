#include "Components/Position.h"

using namespace Component;

Position::Position(float x, float y)
{
    m_pos = sf::Vector2f(x, y);
}
Position::Position(sf::Vector2f pos)
{
    m_pos = pos;
}

Position::~Position()
{
    //dtor
}

void Position::set(sf::Vector2f pos)
{
    m_mutex.lock();
    m_pos = pos;
    m_mutex.unlock();
}

sf::Vector2f Position::get()
{
    sf::Vector2f vec;
    m_mutex.lock();
    vec = m_pos;
    m_mutex.unlock();
}
