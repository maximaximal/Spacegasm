#include <CGame.h>
#include <CNetworkManager.h>

void CGame::onExit()
{
    if(m_networkManager != NULL)
        m_networkManager->stop();
    delete this->m_FrameClock;
    delete this->m_FrameTime;
    if(w_mainWindow != NULL)
        delete w_mainWindow;
    if(w_serverConnection != NULL)
        delete w_serverConnection;
    delete m_world;
    delete m_desktop;
    delete m_sfgui;
    delete this->window;
    delete m_networkManager;
    delete m_packetHandler;
    m_networkManager = NULL;
    m_networkThread = NULL;
}
