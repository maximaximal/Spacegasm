#include "CWorldLoop.h"
#include <CServerConfig.h>

using namespace std;

CWorldLoop::CWorldLoop()
{
    m_loopThread = NULL;
    m_running = false;
    m_loopClock = NULL;
}

CWorldLoop::~CWorldLoop()
{
    this->stop();
    if(m_loopThread != NULL)
        delete m_loopThread;
    if(m_loopClock != NULL)
        delete m_loopClock;
}

void CWorldLoop::start()
{
    if(m_loopThread == NULL)
    {
        m_loopClock = new sf::Clock();
        m_loopClock.restart();
        m_running = true;
        m_loopThread = new thread(&CWorldLoop::onInit, this);
    }
}
void CWorldLoop::stop()
{
    m_runningMutex.lock();
    m_running = false;
    m_runningMutex.unlock();
    if(m_loopThread != NULL)
        m_loopThread.join();
}
void CWorldLoop::onInit()
{
    bool running = true;
    while(running)
    {
        onUpdate();
        m_runningMutex.lock();
        running = m_running;
        m_runningMutex.unlock();
        //Wait
            sf::Time time = m_loopClock->getElapsedTime();
            m_loopClock.restart();
            sf::sleep(1.0 / CServerConfig::Get()->getGameLoopRate - time.asSeconds());
    }
    onExit();
}
void CWorldLoop::onUpdate()
{

}
void CWorldLoop::onExit()
{

