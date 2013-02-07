#ifndef CPEERMANAGER_H
#define CPEERMANAGER_H

#include <map>
#include <string>
#include <enet/enet.h>

class CPeerManager
{
    public:
        CPeerManager(ENetHost *host);
        virtual ~CPeerManager();
        ENetPeer* get(unsigned int ID);
        unsigned int add(ENetPeer *peer);
        void remove(unsigned int ID);
    protected:
    private:
        std::map<unsigned int, ENetPeer*> m_peers;
        ENetHost *m_host;
        unsigned int m_peerIndex;
};

#endif // CPEERMANAGER_H
