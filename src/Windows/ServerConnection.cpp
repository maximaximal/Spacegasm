#include "Windows/ServerConnection.h"
#include <CGame.h>
#include <CStringContainer.h>
#include <SFML/Network.hpp>
#include <CNetworkManager.h>
#include <CPacketHandler.h>

using namespace Window;

Window::ServerConnection::ServerConnection(sfg::Desktop *desktop, CGame *game) : Default(desktop)
{
    m_game = game;
    ui_t_main = sfg::Table::Create();
    ui_l_username = sfg::Label::Create(game->getNetworkManager()->getUsername());
    ui_l_serverIP = sfg::Label::Create(game->getNetworkManager()->getIP());
    ui_l_usernameLabel = sfg::Label::Create((*CStringContainer::Get())["MAINMENU_USERNAME"]);
    ui_l_serverIPLabel = sfg::Label::Create((*CStringContainer::Get())["MAINMENU_IP"]);
    ui_consoleWindow = sfg::ScrolledWindow::Create();
    ui_b_scrolledConsole = sfg::Box::Create( sfg::Box::VERTICAL );
    ui_e_console = sfg::Entry::Create();
    ui_btn_submit = sfg::Button::Create((*CStringContainer::Get())["SEND"]);
    ui_consoleWindow->AddWithViewport(ui_b_scrolledConsole);
    ui_consoleWindow->SetRequisition( sf::Vector2f( 500.f, 200.f ) );
    ui_l_consoleContent = sfg::Label::Create("");

    ui_t_main->Attach(ui_l_serverIPLabel, sf::Rect<unsigned int>(0, 0, 1, 1));
    ui_t_main->Attach(ui_l_serverIP, sf::Rect<unsigned int>(1, 0, 1, 1));
    ui_t_main->Attach(ui_l_usernameLabel, sf::Rect<unsigned int>(0, 1, 1, 1));
    ui_t_main->Attach(ui_l_username, sf::Rect<unsigned int>(1, 1, 1, 1));
    ui_t_main->Attach(ui_consoleWindow, sf::Rect<unsigned int>(0, 2, 1, 1));
    ui_t_main->Attach(ui_e_console, sf::Rect<unsigned int>(0, 3, 1, 1));
    ui_t_main->Attach(ui_btn_submit, sf::Rect<unsigned int>(1, 3, 1, 1));

    ui_consoleWindow->SetScrollbarPolicy( sfg::ScrolledWindow::HORIZONTAL_AUTOMATIC | sfg::ScrolledWindow::VERTICAL_ALWAYS );
    m_consoleOutputConnection = game->getPacketHandler()->getEvent(PTYPE_CONSOLE_OUTPUT).connect(sigc::mem_fun(this, &Window::ServerConnection::onConsoleOutput));
    ui_b_scrolledConsole->Pack(ui_l_consoleContent);
    ui_btn_submit->GetSignal(sfg::Button::OnLeftClick).Connect(&Window::ServerConnection::on_submitButtonPressed, this);
    ui_window->SetTitle((*CStringContainer::Get())["CONNECT_TO_SERVER"]);
    ui_box->Pack(ui_t_main, false, true);
}

Window::ServerConnection::~ServerConnection()
{
    m_consoleOutputConnection.disconnect();
}

void Window::ServerConnection::on_submitButtonPressed()
{
    std::string text = ui_e_console->GetText();
    sf::Packet packet;
    packet << PTYPE_MSG << text;
    ui_e_console->SetText("");
    m_game->getPacketHandler()->sendPacket(packet, "", 0, true);
}
void Window::ServerConnection::onConsoleOutput(sf::Packet packet, ENetPeer *peer)
{
    std::string output;
    packet >> output;
    ui_l_consoleContent->SetText(((std::string)ui_l_consoleContent->GetText()).append(output));
}
