#ifndef CCONTACTLISTENER_H
#define CCONTACTLISTENER_H

#include <Box2D/Box2D.h>
#include <CPacketSender.h>

class CContactListener : public b2ContactListener
{
    public:
        CContactListener(CPacketSender *sender);
        virtual ~CContactListener();

        void BeginContact(b2Contact *contact);
        void EndContact(b2Contact *contact);
    protected:
    private:
        CPacketSender *m_packetSender;
};

#endif // CCONTACTLISTENER_H
