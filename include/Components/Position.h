#ifndef POSITION_H
#define POSITION_H

#include <mutex>
#include <SFML/System.hpp>

namespace Component
{
    class Position : public artemis::Component
    {
        public:
            Position(float x, float y);
            Position(sf::Vector2f pos);
            virtual ~Position();

            void set(sf::Vector2f pos);
            sf::Vector2f get();
        protected:
            sf::Vector2f m_pos;
        private:
            std::mutex m_mutex;
    };
}


#endif // POSITION_H
