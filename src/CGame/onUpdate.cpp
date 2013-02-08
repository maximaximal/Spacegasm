#include <CGame.h>
#include <sigc++/sigc++.h>
#include <IPConverter.h>
#include <Windows/ServerConnection.h>

void CGame::onUpdate()
{
    *m_FrameTime = m_FrameClock->getElapsedTime();
    m_FrameClock->restart();
    m_desktop->Update(m_FrameTime->asSeconds());
    if(m_createLobbyWindow)
    {
        delete w_mainWindow;
        w_mainWindow = NULL;
        w_serverConnection = new Window::ServerConnection(m_desktop, this);
        m_createLobbyWindow = false;
    }
}
