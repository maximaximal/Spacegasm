#ifndef CRWINDOW_H
#define CRWINDOW_H

#include <CreationUI/CRWidget.h>
#include <
class CRWindow : public CRWidgetC
{
    public:
        CRWindow();
        virtual ~CRWindow();
        virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const
    protected:
    private:
};

#endif // CRWINDOW_H
