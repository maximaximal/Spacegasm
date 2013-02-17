#ifndef CWORLDLOOP_H
#define CWORLDLOOP_H

#include <thread>
#include <mutex>
#include <SFML/System.hpp>
#include <World.h>
#include <SystemManager.h>
#include <EntityManager.h>
#include <CPhysicsManagerServer.h>
#include <Systems/PhysicNetServer.h>
#include <CPacketHandler.h>

class CWorldLoop
{
    public:
        CWorldLoop(CPacketHandler *packetHandler);
        virtual ~CWorldLoop();

        void start();
        void stop();
    protected:
    private:
        std::thread *m_loopThread;
        std::mutex m_runningMutex;
        bool m_running;
        CPacketHandler *m_packetHandler;
        sf::Clock *m_loopClock;
        //Will be executed in the loop-thread
            void onInit();
            void onUpdate();
            void onExit();
        //Artemis
            artemis::World *m_world;
            artemis::EntityManager *m_entityManager;
            artemis::SystemManager *m_systemManager;
        //systems
            System::PhysicNetServer *m_physicNetServer;
        CPhysicsManagerServer *m_physicsManager;
};

#endif // CWORLDLOOP_H
