#ifndef CRMOUSEEVENT_H
#define CRMOUSEEVENT_H

#include <CreationUI/CREvent.h>

namespace CRUI
{
    class CRMouseEvent : public CREvent
    {
        public:
            CRMouseEvent(CRUI::MouseButton button, float x, float y);
            virtual ~CRMouseEvent();
        protected:
        private:
    };
}


#endif // CRMOUSEEVENT_H
