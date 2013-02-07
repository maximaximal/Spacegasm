#include "CRtextEntered.h"

using namespace CRUI;

CRTextEntered::CRTextEntered(std::string text)
{
    this->type = CRUI::TextEntered;
    this->text = text;
}

CRTextEntered::~CRTextEntered()
{
    //dtor
}
