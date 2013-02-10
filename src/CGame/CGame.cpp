#include "CGame.h"
#include <iostream>
#include <CNetworkManager.h>
#include <sigc++/sigc++.h>
#include <IPConverter.h>

using namespace std;

CGame::CGame()
{
    this->m_running = true;
    this->window = NULL;
    this->w_mainWindow = NULL;
    this->w_serverConnection = NULL;
}

CGame::~CGame()
{
    //dtor
}
void CGame::quit()
{
    m_running = false;
}
void CGame::connectToIp(unsigned int IP, std::string username, std::string password)
{
    if(m_networkManager != NULL)
    {
        m_networkManager->stop();
        m_networkThread->join();
        delete m_networkManager;
        delete m_networkThread;
        m_networkManager = NULL;
        m_networkThread = NULL;
    }
    m_networkManager = new CNetworkManager(IPConverter::toString(IP), NET_PORT, this, m_packetHandler, username, password);
    m_packetHandler->setSender(m_networkManager);
    cout << "[CLIENT] Connecting to IP: " << IPConverter::toString(IP) << "..." << endl;
    m_networkThread = new std::thread(&CNetworkManager::onInit, m_networkManager);
    m_networkThread->detach();
}
void CGame::onConnectionEstablished(sf::Packet packet, ENetPeer* peer)
{
    string connectMsg;
    int playerCount;
    packet >> connectMsg >> playerCount;
    cout << "[SERVER - HANDSHAKE] " << endl << "    " << connectMsg << endl;
    m_onConnectionEstablishedEventConnection.disconnect();
    m_createLobbyWindow = true;
}
void CGame::onConsoleOutput(sf::Packet packet, ENetPeer* peer)
{
    string output = "";
    packet >> output;
    cout << "\x1b[36m" << output << "\x1b[0m";
    m_outputMutex.lock();
    m_outputBuffer += output;
    m_outputMutex.unlock();
}
void CGame::lockDrawMutex()
{
    m_drawMutex.lock();
}
void CGame::unlockDrawMutex()
{
    m_drawMutex.unlock();
}
CNetworkManager* CGame::getNetworkManager()
{
    return m_networkManager;
}
