#ifndef MAINMENU_H
#define MAINMENU_H

#include <SFGUI/SFGUI.hpp>
#include <Windows/Default.h>
#include <Windows/ConnectToServer.h>

class CGame;

namespace Window
{
    class MainMenu : public Default
    {
        public:
            MainMenu(sfg::Desktop *desktop, CGame *game);
            virtual ~MainMenu();
        protected:
            sfg::Table::Ptr ui_t_mainTable;
            sfg::Label::Ptr ui_l_welcomeText;
            sfg::Button::Ptr ui_btn_connectToServer;
            sfg::Button::Ptr ui_btn_quit;

            CGame *m_game;

            ConnectToServer *m_connectWindow;

            void on_connectToServerButtonPressed();
            void on_quitButtonPressed();
        private:
    };
}


#endif // MAINMENU_H
