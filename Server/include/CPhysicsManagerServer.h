#include <Box2D/Box2D.h>
#include <thread>
#include <mutex>
#include <CPhysicsManager.h>
#include <SFML/System.hpp>
class CPhysicsManagerServer : public CPhysicsManager
{
    public:
        CPhysicsManagerServer();
        virtual ~CPhysicsManagerServer();

        void start();
        void stop();

        sf::Time getStepTime();
    private:
        void stepThread();
        std::thread *m_stepThread;
        std::mutex m_runningMutex;
        std::mutex m_timeMutex;
        sf::Time m_stepTime;
        bool m_running;
};
