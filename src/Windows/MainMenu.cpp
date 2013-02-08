#include "Windows/MainMenu.h"
#include <CStringContainer.h>
#include <IPConverter.h>

#include <CGame.h>

using namespace Window;

MainMenu::MainMenu(sfg::Desktop *desktop, CGame *game) : Default(desktop)
{
    m_game = game;

    ui_t_mainTable = sfg::Table::Create();
    ui_l_welcomeText = sfg::Label::Create((*CStringContainer::Get())["MAINMENU_WELCOMETEXT"]);
    ui_btn_connectToServer = sfg::Button::Create((*CStringContainer::Get())["CONNECT_TO_SERVER"]);
    ui_btn_quit = sfg::Button::Create((*CStringContainer::Get())["QUIT"]);

    ui_t_mainTable->Attach(ui_l_welcomeText, sf::Rect<unsigned int>(0, 0, 1, 1));
    ui_t_mainTable->Attach(ui_btn_connectToServer, sf::Rect<unsigned int>(0, 1, 1, 1));
    ui_t_mainTable->Attach(ui_btn_quit, sf::Rect<unsigned int>(0, 3, 1, 1));

    ui_btn_connectToServer->GetSignal(sfg::Button::OnLeftClick).Connect(&MainMenu::on_connectToServerButtonPressed, this);
    ui_btn_quit->GetSignal(sfg::Button::OnLeftClick).Connect(&MainMenu::on_quitButtonPressed, this);

    ui_box->Pack(ui_t_mainTable);
    ui_window->SetTitle((*CStringContainer::Get())["MAINMENU_TITLE"]);

    m_connectWindow = NULL;
}
MainMenu::~MainMenu()
{
    if(m_connectWindow != NULL)
        delete m_connectWindow;
}
void MainMenu::on_connectToServerButtonPressed()
{
    if(m_connectWindow == NULL)
        m_connectWindow = new Window::ConnectToServer(ui_desktop, m_game);
}
void MainMenu::on_quitButtonPressed()
{
    m_game->quit();
}
