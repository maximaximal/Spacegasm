#include "CWorldLoop.h"
#include <CServerConfig.h>
#include <iostream>

using namespace std;

CWorldLoop::CWorldLoop(CPacketHandler *packetHandler)
{
    m_loopThread = NULL;
    m_running = false;
    m_loopClock = NULL;
    m_packetHandler = packetHandler;
}

CWorldLoop::~CWorldLoop()
{
    this->stop();
    if(m_loopClock != NULL)
        delete m_loopClock;
    cout << "[SERVER] Game (World) Loop deleted succefully" << endl;
}

void CWorldLoop::start()
{
    if(m_loopThread == NULL)
    {
        cout << "[SERVER] Starting Game (World) Loop... (in external thread)" << endl;
        m_loopClock = new sf::Clock();
        m_loopClock->restart();
        m_running = true;
        m_loopThread = new thread(&CWorldLoop::onInit, this);
    }
    else
    {
        cout << "[SERVER] Game (World) Loop is already running!" << endl;
    }
}
void CWorldLoop::stop()
{
    m_runningMutex.lock();
    m_running = false;
    m_runningMutex.unlock();
    m_loopThread->join();
}
void CWorldLoop::onInit()
{
    m_physicsManager = new CPhysicsManagerServer();
    m_physicsManager->start();

    //Artemis
    m_world = new artemis::World();
    m_entityManager = m_world->getEntityManager();
    m_systemManager = m_world->getSystemManager();

    m_physicNetServer = (System::PhysicNetServer*) m_systemManager->setSystem(new System::PhysicNetServer(m_world, m_physicsManager, m_packetHandler));

    //Artemis System Initialization
    m_systemManager->initializeAll();
    bool running = true;
    cout << "[SERVER] Game (World) Loop is now running at a rate of " << CServerConfig::Get()->getGameLoopRate() << " ticks / second" << endl;
    while(running)
    {
        onUpdate();
        m_runningMutex.lock();
        running = m_running;
        m_runningMutex.unlock();
        //Wait
            sf::Time time = m_loopClock->getElapsedTime();
            m_loopClock->restart();
            sf::sleep(sf::seconds(1.0 / CServerConfig::Get()->getGameLoopRate() - time.asSeconds()));
    }
    onExit();
}
void CWorldLoop::onUpdate()
{
    m_world->loopStart();
    m_world->setDelta(m_loopClock->getElapsedTime().asMilliseconds());
    m_physicNetServer->process();
}
void CWorldLoop::onExit()
{
    delete m_world;
    delete m_physicsManager;
    cout << "[SERVER] Game (World) Loop shutdown succefully" << endl;
}
