#ifndef CREVENT_H
#define CREVENT_H

#include <string>

namespace CRUI
{
    enum Event {
        MouseEvent,
        TextEntered
    };
    enum MouseButton {
        left,
        right,
        middle
    };

    class CREvent
    {
        public:
            CREvent();
            virtual ~CREvent();
            unsigned int type;
            unsigned int button;
            float x, y;
            std:string text;
        protected:
        private:
    };
}

#endif // CREVENT_H
