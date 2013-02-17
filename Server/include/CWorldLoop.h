#ifndef CWORLDLOOP_H
#define CWORLDLOOP_H

#include <thread>
#include <mutex>
#include <SFML/System.h>

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
};

#endif // CWORLDLOOP_H
