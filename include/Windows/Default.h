#ifndef DEFAULT_H
#define DEFAULT_H

#include <SFGUI/SFGUI.hpp>

namespace Window
{
    class Default
    {
        public:
            Default(sfg::Desktop *desktop);
            virtual ~Default();
        protected:
            sfg::Window::Ptr ui_window;
            sfg::Desktop *ui_desktop;
            sfg::Box::Ptr ui_box;
        private:
    };
}


#endif // DEFAULT_H
