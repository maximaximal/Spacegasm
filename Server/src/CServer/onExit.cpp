#include <CServer.h>
#include <iostream>

using namespace std;

void CServer::onExit()
{
    delete m_address;
    delete this->chatManager;
    delete this->peerManager;
    delete this->playerManager;
    delete this->packetHandler;
    enet_host_destroy(m_server);
}
