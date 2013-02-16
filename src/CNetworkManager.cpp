#include "CNetworkManager.h"
#include <iostream>
#include <CGame.h>
#include <IPConverter.h>
#include <CPacketHandler.h>

using namespace std;

CNetworkManager::CNetworkManager(std::string IP, unsigned int port, CGame *game, CPacketHandler *handler, std::string username, std::string password)
{
    m_IP = IP;
    m_username = username;
    m_password = password;
    m_address = new ENetAddress();
    m_client = new ENetHost();
    m_address->host = 0;
    m_address->port = port;
    m_game = game;
    m_running = false;
    m_packetHandler = handler;
    dataMutex = new std::mutex;
}
void CNetworkManager::onInit()
{
    if(m_running == false)
    {
        cout << "[CLIENT] Starting Network-Manager..." << endl;
        if(enet_initialize() != 0)
        {
            cout << "[CLIENT] \e[0;41mCould not initialize enet!\e[0m" << endl;
            return;
        }
        atexit(enet_deinitialize);
        m_client = enet_host_create(NULL, 1, 2, 0, 0);
        if(m_client == NULL)
        {
            cout << "[CLIENT] \e[0;41mCould not create host! Port: " << m_address->port << "\e[0m" << endl;
            return;
        }
        enet_address_set_host(m_address, m_IP.c_str());

        m_peer = enet_host_connect(m_client, m_address, 2, 0);

        if(m_peer == NULL)
        {
            cout << "[CLIENT] \e[0;41mNo available peers!\e[0m" << endl;
            return;
        }

        m_running = true;
        bool running = true;
        cout << "[CLIENT] Initializing complete! Now running..." << endl;
        while(running)
        {
            dataMutex->lock();
            running = m_running;
            dataMutex->unlock();
            this->onUpdate();
        }
    }
    else
    {
        cout << "[CLIENT] \e[0;41mThe NetworkManager is already running!\e[0m" << endl;
    }
}
void CNetworkManager::onUpdate()
{
    ENetEvent event;
    sf::Packet packet;
    this->dataMutex->lock();
    while(enet_host_service(m_client, &event, 1000) > 0)
    {
        switch(event.type)
        {
            case ENET_EVENT_TYPE_CONNECT:
                cout << "[CLIENT] Connected! " << IPConverter::toString(event.peer->address.host) << endl;
                m_onConnectionSuccess(this);
                packet.clear();
                packet << PTYPE_FULLCONNECT << m_username;
                this->sendPacket(packet, "", 0, true);
                cout << "[CLIENT] Sent Connection-Packet (Username: " << m_username << ")" << endl;
                break;
            case ENET_EVENT_TYPE_DISCONNECT:
                break;
            case ENET_EVENT_TYPE_RECEIVE:
                packet.clear();
                packet.append(event.packet->data, event.packet->dataLength);
                m_packetHandler->handlePacket(packet, event.peer);
                enet_packet_destroy(event.packet);
                break;
        }
    }
    this->dataMutex->unlock();
}
void CNetworkManager::sendPacket(sf::Packet& packet, std::string username, unsigned int channel, bool relieable)
{
    ENetPacket *enetPacket;
    if(relieable)
        enetPacket = enet_packet_create(packet.getData(), packet.getDataSize() + 1, ENET_PACKET_FLAG_RELIABLE);
    else
        enetPacket = enet_packet_create(packet.getData(), packet.getDataSize() + 1, ENET_PACKET_FLAG_UNRELIABLE_FRAGMENT);
    enet_peer_send(m_peer, channel, enetPacket);
    enet_host_flush(m_client);
}
void CNetworkManager::sendPacket(sf::Packet& packet, std::vector<std::string> username, unsigned int channel, bool relieable)
{
    vector<string>::iterator it;
    for(it = username.begin(); it != username.end(); ++it)
    {
        this->sendPacket(packet, *it, channel, relieable);
    }
}

CNetworkManager::~CNetworkManager()
{
    enet_peer_disconnect(m_peer, 0);
    delete m_address;
    delete dataMutex;
    ENetEvent event;
    bool  success = false;
    while (enet_host_service(m_client, &event, 3000) > 0)
    {
        switch (event.type)
        {
            case ENET_EVENT_TYPE_RECEIVE:
                enet_packet_destroy (event.packet);
                break;
            case ENET_EVENT_TYPE_DISCONNECT:
                puts ("[CLIENT] Succefully disconnected! - Shutting down NetworkManager...");
                enet_host_destroy(m_client);
                success = true;
                break;
        }
    }
    if(!success)
    {
        enet_peer_reset(m_peer);
        enet_host_destroy(m_client);
        cout << "[CLIENT] NetworkManager forced disconnect & stopped" << endl;
    }
}
void CNetworkManager::stop()
{
    m_running = false;
}
unsigned int CNetworkManager::getPort()
{
    this->dataMutex->lock();
    unsigned int port = m_address->port;
    this->dataMutex->unlock();
    return port;
}
std::string CNetworkManager::getIP()
{
    std::string IP = m_IP;
    return IP;
}
std::string CNetworkManager::getUsername()
{
    return m_username;
}
