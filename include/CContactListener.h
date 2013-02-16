#ifndef CCONTACTLISTENER_H
#define CCONTACTLISTENER_H

#include <Box2D/Box2D.h>

class CContactListener : public b2ContactListener
{
    public:
        CContactListener();
        virtual ~CContactListener();

        void BeginContact(b2Contact *contact);
        void EndContact(b2Contact *contact);
    protected:
    private:
};

#endif // CCONTACTLISTENER_H
