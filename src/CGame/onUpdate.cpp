#include <CGame.h>
#include <sigc++/sigc++.h>
#include <IPConverter.h>
#include <Windows/CServerLobby.h>

void CGame::onUpdate()
{
    *m_FrameTime = m_FrameClock->getElapsedTime();
    m_FrameClock->restart();
    m_guiManager->onUpdate(m_FrameTime->asMilliseconds());
    if(m_createLobbyWindow)
    {
        CServerLobby *lobby = new CServerLobby(window->getSize().x, window->getSize().y, m_guiManager->getCore(), m_networkManager, m_packetHandler);
        m_guiManager->removeWindow(m_loginWindowID);
        m_serverLobbyID = m_guiManager->addWindow(lobby);
        m_createLobbyWindow = false;
    }
}
