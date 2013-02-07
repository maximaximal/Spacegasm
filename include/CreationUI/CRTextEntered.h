#ifndef CRTEXTENTERED_H
#define CRTEXTENTERED_H

#include <CreationUI/CREvent.h>

namespace CRUI
{
    class CRTextEntered : public CREvent
    {
        public:
            CRTextEntered(std::string text);
            virtual ~CRTextEntered();
        protected:
        private:
    };
}


#endif // CRTEXTENTERED_H
