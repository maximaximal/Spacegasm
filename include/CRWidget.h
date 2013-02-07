#ifndef CRWIDGET_H
#define CRWIDGET_H

#include <sigc++/sigc++.h>
#include <SFML/System.hpp>

#include <CreationUI/CRMouseEvent.h>

namespace CRUI
{
    class CRWidget
    {
        public:
            CRWidget();
            virtual ~CRWidget();

            virtual void update(float frametime);
            virtual void handleEvent(sf::Event &event) = 0;

            virtual void setPosition(sf::Vector2f pos) = 0;
            virtual void setSize(sf::Vector2f size) = 0;

            virtual sf::IntRect getRectangle();
            virtual sf::Vector2f getPosition() = 0;
            virtual sf::Vector2f getSize() = 0;

            sigc::signal<void, CRMouseEvent> onClicked();
            sigc::signal<void, CRMouseEvent> onHovered();
        protected:
            virtual void on_clicked() {};
            virtual void on_hover() {};

            sigc::signal<void, CRMouseEvent> m_onClicked;
            sigc::signal<void, CRMouseEvent> m_onHovered;
        private:
    };
}

#endif // CRWIDGET_H
