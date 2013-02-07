#include "CRWidget.h"

using namespace CRUI;

CRWidget::CRWidget()
{
    type = CRUI::Type::none;
}

CRWidget::~CRWidget()
{
    //dtor
}

sf::IntRect CRWidget::getRectangle()
{
    sf::IntRect rect;
    rect.left   = (int) this->getPosition().x;
    rect.top    = (int) this->getPosition().y;
    rect.width  = (int) this->getSize().x;
    rect.height = (int) this->getSize().y;
    return rect;
}
unsigned int CRWidget::getType()
{
    return m_type;
}
sigc::signal<void, CRMouseEvent>& CRWidget::onClicked()
{
    return m_onClicked();
}
sigc::signal<void, CRMouseEvent>& CRWidget::onHovered()
{
    return m_onHovered();
}
sigc::signal<void, CRMouseEvent>& CRWidget::onScrolled()
{
    return m_onScrolled();
}
sigc::signal<void, CRTextEntered>& CRWidget::onKeyPressed()
{
    return m_onKeyPressed();
}
sigc::signal<void, float, float>& CRWidget::onMoved()
{
    return m_onMoved();
}
