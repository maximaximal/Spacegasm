#include <CGame.h>
#include <CNetworkManager.h>

void CGame::onExit()
{
    if(m_networkManager != NULL)
        m_networkManager->stop();
    delete this->m_FrameClock;
    delete this->m_FrameTime;
    delete m_guiManager;
    delete this->window;
    delete m_networkManager;
    delete m_packetHandler;
    m_networkManager = NULL;
    m_networkThread = NULL;
}
