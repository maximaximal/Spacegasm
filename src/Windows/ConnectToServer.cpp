#include "Windows/ConnectToServer.h"
#include <CStringContainer.h>
#include <IPConverter.h>
#include <CGame.h>

using namespace Window;

ConnectToServer::ConnectToServer(sfg::Desktop *desktop, CGame *game) : Default(desktop)
{
    m_game = game;

    ui_t_serverTable = sfg::Table::Create();
    ui_l_serverIPLabel = sfg::Label::Create((*CStringContainer::Get())["MAINMENU_IP"]);
    ui_l_serverUserLabel = sfg::Label::Create((*CStringContainer::Get())["MAINMENU_USERNAME"]);
    ui_l_serverPassLabel = sfg::Label::Create((*CStringContainer::Get())["MAINMENU_PASSWORD"]);
    ui_e_serverIP = sfg::Entry::Create("127.0.0.1");
    ui_e_serverUsername = sfg::Entry::Create("");
    ui_e_serverPassword = sfg::Entry::Create("");
    ui_btn_serverConnect = sfg::Button::Create((*CStringContainer::Get())["CONNECT"]);

    ui_t_serverTable->Attach(ui_l_serverIPLabel, sf::Rect<unsigned int>(0, 0, 1, 1));
    ui_t_serverTable->Attach(ui_l_serverUserLabel, sf::Rect<unsigned int>(0, 1, 1, 1));
    ui_t_serverTable->Attach(ui_l_serverPassLabel, sf::Rect<unsigned int>(0, 2, 1, 1));
    ui_t_serverTable->Attach(ui_e_serverIP, sf::Rect<unsigned int>(1, 0, 1, 1));
    ui_t_serverTable->Attach(ui_e_serverUsername, sf::Rect<unsigned int>(1, 1, 1, 1));
    ui_t_serverTable->Attach(ui_e_serverPassword, sf::Rect<unsigned int>(1, 2, 1, 1));
    ui_t_serverTable->Attach(ui_btn_serverConnect, sf::Rect<unsigned int>(1, 3, 1, 1));
    ui_box->Pack(ui_t_serverTable);
    ui_btn_serverConnect->GetSignal(sfg::Button::OnLeftClick).Connect(&ConnectToServer::on_connectButtonPressed, this);

    ui_window->SetTitle((*CStringContainer::Get())["CONNECT_TO_SERVER"]);
}

ConnectToServer::~ConnectToServer()
{
    //dtor
}

void ConnectToServer::on_connectButtonPressed()
{
    m_game->connectToIp(IPConverter::toUInt(ui_e_serverIP->GetText()), ui_e_serverUsername->GetText(), ui_e_serverPassword->GetText());
}
