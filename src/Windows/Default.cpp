#include "Windows/Default.h"

using namespace Window;

Default::Default(sfg::Desktop *desktop)
{
    ui_window = sfg::Window::Create();
    ui_box = sfg::Box::Create();
    ui_window->Add(ui_box);

    ui_desktop = desktop;
    ui_desktop->Add(ui_window);
}

Default::~Default()
{
    ui_desktop->Remove(ui_window);
}
