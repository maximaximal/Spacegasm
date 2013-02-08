#ifndef SERVERCONNECTION_H
#define SERVERCONNECTION_H

#include <SFML/Network.hpp>
#include <enet/enet.h>
#include <sigc++/sigc++.h>

#include <Windows/Default.h>

class CGame;

namespace Window
{
    class ServerConnection : public Default
    {
        public:
            ServerConnection(sfg::Desktop *desktop, CGame *game);
            virtual ~ServerConnection();

            void onConsoleOutput(sf::Packet packet, ENetPeer *peer);
        protected:
            sfg::Table::Ptr ui_t_main;
            sfg::Label::Ptr ui_l_serverIPLabel;
            sfg::Label::Ptr ui_l_usernameLabel;
            sfg::Label::Ptr ui_l_username;
            sfg::Label::Ptr ui_l_serverIP;

            sfg::ScrolledWindow::Ptr ui_consoleWindow;
            sfg::Box::Ptr ui_b_scrolledConsole;
            sfg::Entry::Ptr ui_e_console;
            sfg::Button::Ptr ui_btn_submit;
            sfg::Label::Ptr ui_l_consoleContent;
            CGame *m_game;

            sigc::connection m_consoleOutputConnection;
            void on_submitButtonPressed();
        private:
    };
}

#endif // SERVERCONNECTION_H
