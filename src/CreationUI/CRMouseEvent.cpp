#include "CreationUI/CRMouseEvent.h"

using namespace CRUI;

CRMouseEvent::CRMouseEvent(CRUI::MouseButton button, float x, float y)
{
     type = CRUI::MouseEvent;
     this->button = button;
     this->x = x;
     this->y = y;
}

CRMouseEvent::~CRMouseEvent()
{
    //dtor
}
