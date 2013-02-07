#include <CGame.h>
#include <thread>
#include <Windows/CLoginWindow.h>
#include <CTextureManager.h>

void CGame::onInit()
{
    this->window = new sf::RenderWindow(sf::VideoMode(800, 600), "SFML-Sidescroller V2");
    this->m_state = CGame::State::GUI;

    this->window->resetGLStates();

    m_createLobbyWindow = false;

    CTextureManager::Get()->setRenderWindow(window);

    m_FrameClock = new sf::Clock();
    m_FrameClock->restart();
    m_FrameTime = new sf::Time();

    m_packetHandler = new CPacketHandler();
    m_onConnectionEstablishedEventConnection = m_packetHandler->getEvent(PTYPE_FULLCONNECT).connect(sigc::mem_fun(this, &CGame::onConnectionEstablished));
    m_packetHandler->getEvent(PTYPE_CONSOLE_OUTPUT).connect(sigc::mem_fun(this, &CGame::onConsoleOutput));
    m_networkManager = NULL;

    m_guiManager = new CGUIManager(window->getSize().x, window->getSize().y);

    CLoginWindow *loginWindow = new CLoginWindow(window->getSize().x, window->getSize().y, m_guiManager->getCore());
    loginWindow->onLogin().connect(sigc::mem_fun(this, &CGame::connectToIp));
    m_loginWindowID = m_guiManager->addWindow(loginWindow);

    while(m_running)
    {
        this->onEvent();
        this->onUpdate();
        this->onRender();
    }
    this->onExit();
}
