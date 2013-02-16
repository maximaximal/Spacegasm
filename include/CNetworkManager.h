#ifndef CNETWORKMANAGER_H
#define CNETWORKMANAGER_H

#include <string>
#include <enet/enet.h>
#include <SFML/Network.hpp>
#include <sigc++/sigc++.h>
#include <CPacketSender.h>
#include <thread>
#include <mutex>
#include <vector>

class CGame;
class CPacketHandler;

class CNetworkManager : public CPacketSender
{
    public:
        /**
            @brief Connects to the specified server.
            @param IP The IP in the format "127.0.0.1"
            @param port The port to connect to.
            @param game A pointer to the game-object that wants to start the Network-Manager.
        **/
        CNetworkManager(std::string IP, unsigned int port, CGame *game, CPacketHandler *handler, std::string username, std::string password);
        virtual ~CNetworkManager();
        void onUpdate();
        /**
            @brief Connects to the server specified in the constructor.
        **/
        void onInit();
        /**
            @brief The manager will be stopped & cleared after the next loop.
        **/
        void stop();
        unsigned int getPort();
        std::string getIP();
        std::string getUsername();
        virtual void sendPacket(sf::Packet& packet, std::string username, unsigned int channel, bool relieable);
        virtual void sendPacket(sf::Packet& packet, std::vector<std::string> username, unsigned int channel, bool relieable);
 
        //Events
            sigc::signal<void, CNetworkManager*>& onConnectionSuccess() {return m_onConnectionSuccess;}
    protected:
    private:
        std::string m_IP, m_username;
        std::string m_password;
        std::mutex *dataMutex;
        bool m_running;
        ENetAddress *m_address;
        ENetHost *m_client;
        ENetPeer *m_peer;
        CGame *m_game;
        CPacketHandler *m_packetHandler;
        sigc::signal<void, CNetworkManager*> m_onConnectionSuccess;
};

#endif // CNETWORKMANAGER_H
