#ifndef CRWIDGET_H
#define CRWIDGET_H

#include <sigc++/sigc++.h>
#include <SFML/System.hpp>

#include <CreationUI/CRMouseEvent.h>
#include <SFML/Graphics.hpp>
namespace CRUI
{
    enum class Type {
        None,
        Window,
        ContainerWidget
    };
    class CRWidget : public sf::Drawable
    {
        public:
            CRWidget();
            virtual ~CRWidget();

            virtual void update(float frametime);
            virtual void handleEvent(sf::Event &event) = 0;

            virtual void setPosition(sf::Vector2f pos) = 0;
            virtual void setSize(sf::Vector2f size) = 0;

            unsigned int getType();

            virtual sf::IntRect getRectangle();
            virtual sf::Vector2f getPosition() = 0;
            virtual sf::Vector2f getSize() = 0;

            sigc::signal<void, CRMouseEvent>& onClicked();
            sigc::signal<void, CRMouseEvent>& onHovered();
            sigc::signal<void, CRMouseEvent>& onScrolled();
            sigc::signal<void, CRTextEntered>& onKeyPressed();
            sigc::signal<void, float, float>& onMoved();
        protected:
            virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const = 0;

            virtual void on_click(CRMouseEvent) {};
            virtual void on_hover(CRMouseEvent) {};
            virtual void on_scroll(CRMouseEvent) {};
            virtual void on_keyPress(CRTextEntered) {};
            virtual void on_move(float x, float y) {};

            sigc::signal<void, CRMouseEvent> m_onClicked;
            sigc::signal<void, CRMouseEvent> m_onHovered;
            sigc::signal<void, CRMouseEvent> m_onScrolled;
            sigc::signal<void, CRTextEntered> m_onKeyPressed;
            sigc::signal<void, float, float> m_onMoved;

            float x, y, width, height;
            unsigned int m_type;
        private:
    };
}

#endif // CRWIDGET_H
