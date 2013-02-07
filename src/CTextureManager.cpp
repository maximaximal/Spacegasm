#include "CTextureManager.h"

CTextureManager::CTextureManager()
{
    //ctor
}
CTextureManager::~CTextureManager()
{
    //dtor
}
void CTextureManager::setRenderWindow(sf::RenderWindow *window)
{
    m_window = window;
}
void CTextureManager::setWindowActive(bool active)
{
    m_window->setActive(active);
}
