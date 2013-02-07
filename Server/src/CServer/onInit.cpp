#include <CServer.h>
#include <iostream>
#include <exception>
#include <enet/enet.h>

using namespace std;

void CServer::onInit()
{
    cout << "[SERVER] Starting SFML-Sidescroller Server..." << endl;
    if(enet_initialize() != 0)
    {
        cout << "[SERVER] \e[0;41mCould not initialize enet!\e[0m" << endl;
        return;
    }
    atexit(enet_deinitialize);

    m_address = new ENetAddress();
    m_address->host = ENET_HOST_ANY;
    m_address->port = NET_PORT;

    m_server = enet_host_create(m_address, 32, 2, 0, 0);
    if(m_server == NULL)
    {
        cout << "[SERVER] \e[0;41mCould not create host! Port: " << NET_PORT << "\e[0m" << endl;
        return;
    }
    m_running = true;

    packetHandler = new CPacketHandler();
    packetHandler->setSender(this);
    playerManager = new CPlayerManager(packetHandler);
    chatManager = new CChatManager(this, packetHandler, playerManager);
    peerManager = new CPeerManager(m_server);

    cout << "[SERVER] Initializing complete! Now running..." << endl;
    while(m_running)
    {
        this->onUpdate();
    }
    cout << "[SERVER] Shutting down..." << endl;
    this->onExit();
}
