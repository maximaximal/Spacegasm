#ifndef CONNECTTOSERVER_H
#define CONNECTTOSERVER_H

#include <Windows/Default.h>

class CGame;

namespace Window
{
    class ConnectToServer : public Default
    {
        public:
            ConnectToServer(sfg::Desktop *desktop, CGame *game);
            virtual ~ConnectToServer();
        protected:
            sfg::Table::Ptr ui_t_serverTable;
            sfg::Label::Ptr ui_l_serverIPLabel;
            sfg::Label::Ptr ui_l_serverUserLabel;
            sfg::Label::Ptr ui_l_serverPassLabel;
            sfg::Entry::Ptr ui_e_serverIP;
            sfg::Entry::Ptr ui_e_serverUsername;
            sfg::Entry::Ptr ui_e_serverPassword;
            sfg::Button::Ptr ui_btn_serverConnect;

            CGame *m_game;
            void on_connectButtonPressed();
        private:
    };
}


#endif // CONNECTTOSERVER_H
