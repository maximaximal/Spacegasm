#ifndef CRCONTAINERWIDGET_H
#define CRCONTAINERWIDGET_H

#include <sigc++/sigc++.h>
#include <CreationUI/CRWidget.h>
#include <vector>

namespace CRUI
{
    class CRContainerWidget : public CRWidget
    {
        public:
            CRContainerWidget();
            virtual ~CRContainerWidget();

            virtual unsigned int addChild(CRWidget *child) = 0;
            virtual CRWidget getChild(unsigned int index) = 0;
            virtual void deleteChild(unsigned int index) = 0;
            virtual void clear() = 0;

            sigc::signal<void, CRWidget*>& onChildAdded();
            sigc::signal<void>& onChildRemoved();
            sigc::signal<void>& onCleared();
        protected:
            virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

            sigc::signal<void, CRWidget*> m_onChildAdded;
            sigc::signal<void> m_onChildRemoved;
            sigc::signal<void> m_onCleared;
        private:
    };
}


#endif // CRCONTAINERWIDGET_H
