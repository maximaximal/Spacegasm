#ifndef CSERVERCONFIG_H
#define CSERVERCONFIG_H

#include <string>
#include <CSingleton.h>

class CServerConfig : public TSingleton<CServerConfig>
{
    public:
        CServerConfig();
        /**
             @brief Loads the standard config file (serverConf.xml) or creates it if needed.
        **/
        void load();
        /**
            @brief Creates a new serverConf.xml and overwrites the old one if there is one.
        **/
        void create();
        virtual ~CServerConfig();

        std::string getServerMessage() {return m_serverMessage;}
        int getGameLoopRate() {return m_gameLoopRate;}
        int getPhysicsLoopRate() {return m_physicsLoopRate;}
        int getPhysicNetworkRate() {return m_physicNetworkRate;}
    protected:
        std::string m_serverMessage;
        int m_gameLoopRate;
        int m_physicsLoopRate;
        int m_physicNetworkRate;
    private:
};

#endif // CSERVERCONFIG_H
