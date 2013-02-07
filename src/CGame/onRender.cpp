#include <CGame.h>
#include <iostream>
#include <CTextureManager.h>

using namespace std;

void CGame::onRender()
{
    m_drawMutex.lock();
    CTextureManager::Get()->setWindowActive();
    this->window->clear(sf::Color::Black);
    switch(m_state)
    {
        case CGame::State::GUI:
            window->draw(*m_guiManager);
            break;
        default:
            cout << "\e[0;41mUnknown Game State!\e[0m" << endl;
    }
    this->window->display();
    m_drawMutex.unlock();
}
