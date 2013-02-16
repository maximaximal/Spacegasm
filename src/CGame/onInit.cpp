#include <CGame.h>
#include <thread>
#include <CTextureManager.h>
#include <CStringContainer.h>
#include <World.h>
#include <SystemManager.h>
#include <EntityManager.h>

void CGame::onInit()
{
    this->window = new sf::RenderWindow(sf::VideoMode(800, 600), "Spacegasm");
    this->m_state = CGame::State::GUI;

    this->window->resetGLStates();

    m_createLobbyWindow = false;

    m_world = new artemis::World();
    m_systemManager = m_world->getSystemManager();
    m_entityManager = m_world->getEntityManager();

    CTextureManager::Get()->setRenderWindow(window);

    m_FrameClock = new sf::Clock();
    m_FrameClock->restart();
    m_FrameTime = new sf::Time();

    m_packetHandler = new CPacketHandler();
    m_onConnectionEstablishedEventConnection = m_packetHandler->getEvent(PTYPE_FULLCONNECT).connect(sigc::mem_fun(this, &CGame::onConnectionEstablished));
    m_packetHandler->getEvent(PTYPE_CONSOLE_OUTPUT).connect(sigc::mem_fun(this, &CGame::onConsoleOutput));
    m_networkManager = NULL;

    CStringContainer::Get()->load("Data/Lang/en.xml");

    m_sfgui = new sfg::SFGUI();
    m_desktop = new sfg::Desktop();
    w_mainWindow = new Window::MainMenu(m_desktop, this);

    while(m_running)
    {
        this->onEvent();
        this->onUpdate();
        this->onRender();
    }
    this->onExit();
}
