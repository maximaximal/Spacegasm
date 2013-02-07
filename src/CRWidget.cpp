#include "CRWidget.h"

using namespace CRUI;

CRWidget::CRWidget()
{
    //ctor
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
