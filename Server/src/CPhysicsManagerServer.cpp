#include <CPhysicsManagerServer.h>
#include <CServerConfig.h>
#include <SFML/System.hpp>
#include <iostream>

using namespace std;

CPhysicsManagerServer::CPhysicsManagerServer() : CPhysicsManager()
{
    m_stepThread = NULL;
    m_contactListener = NULL;
    m_running = false;
}
CPhysicsManagerServer::~CPhysicsManagerServer()
{
    this->stop();
}
void CPhysicsManagerServer::start()
{
    m_running = true;
    m_stepThread = new std::thread(&CPhysicsManagerServer::stepThread, this); 
    cout << "[SERVER] Physics Loop is running now at " << CServerConfig::Get()->getPhysicsLoopRate() << " ticks / second." << endl;
}
void CPhysicsManagerServer::stop()
{
    cout << "[SERVER] Stopping Physics Loop..." << endl;
    m_runningMutex.lock();
    m_running = false;
    m_runningMutex.unlock();
}
sf::Time CPhysicsManagerServer::getStepTime()
{
    m_timeMutex.lock();
    sf::Time time = m_stepTime;
    m_timeMutex.unlock();
    return time;
}
void CPhysicsManagerServer::stepThread()
{
    bool running = true;
    m_contactListener = new CContactListener();
    m_world->SetContactListener(m_contactListener);
    sf::Clock clock;
    clock.restart();
    sf::Time time = sf::Time::Zero;
    while(running)
    {
        clock.restart();
        m_runningMutex.lock();
        running = m_running;
        m_runningMutex.unlock();

        this->lock();
        m_world->Step(1.0 / CServerConfig::Get()->getPhysicsLoopRate(), 6, 2);
        this->unlock();

        m_timeMutex.lock();
        m_stepTime = time;
        m_timeMutex.unlock();

        time = clock.getElapsedTime();

        sf::sleep(sf::seconds(1.0 / CServerConfig::Get()->getPhysicsLoopRate() - time.asSeconds()));
    }
    delete m_contactListener;
}
