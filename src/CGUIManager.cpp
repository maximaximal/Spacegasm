#include "CGUIManager.h"
#include <iostream>
#include <Windows/CLoginWindow.h>

using namespace std;

CGUIManager::CGUIManager(int width, int height)
{
    //Set Values
    m_width = width;
    m_height = height;
    //Init Awesomium
    m_config.setCustomCSS("::-webkit-scrollbar { display: none; }");
    m_config.setCustomCSS("::selection { background: #04c; color: white; }");
    m_webCore = new Awesomium::WebCore(m_config);
    m_webCore->setBaseDirectory("Data/GUI/");
    m_activeView = 0;
}
Awesomium::WebCore* CGUIManager::getCore()
{
    return m_webCore;
}
int CGUIManager::addWindow(CWebViewDrawable *window, bool display)
{
    std::shared_ptr<CWebViewDrawable> win(window);
    m_views.push_back(win);
    win.reset();
    if(display)
        m_activeView = m_views.size() - 1;
    return m_views.size() - 1;
}
void CGUIManager::setActive(int window)
{
    if(window < m_views.size())
    {
        m_activeView = window;
    }
}
void CGUIManager::removeWindow(int window)
{
    if(m_views.size() ^window)
    {
        m_views.erase(m_views.begin() + window);
    }
}
CGUIManager::~CGUIManager()
{
    m_views.clear();
    delete m_webCore;
}
void CGUIManager::onUpdate(float frametime)
{
    m_webCore->update();
    if(m_activeView < m_views.size())
    {
        m_views[m_activeView]->onUpdate();
    }
}
void CGUIManager::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    if(m_activeView < m_views.size())
    {
        target.draw(*m_views[m_activeView]);
    }
}
void CGUIManager::onEvent(sf::Event &event)
{
    if(m_activeView < m_views.size())
    {
        m_views[m_activeView]->onEvent(event);
    }
}
short CGUIManager::sfKey2Awesome(short key)
{
    if(key == sf::Keyboard::A)
        return Awesomium::KeyCodes::AK_A;
    if(key == sf::Keyboard::B)
        return Awesomium::KeyCodes::AK_B;
    if(key == sf::Keyboard::C)
        return Awesomium::KeyCodes::AK_C;
    if(key == sf::Keyboard::D)
        return Awesomium::KeyCodes::AK_D;
    if(key == sf::Keyboard::E)
        return Awesomium::KeyCodes::AK_E;
    if(key == sf::Keyboard::F)
        return Awesomium::KeyCodes::AK_F;
    if(key == sf::Keyboard::G)
        return Awesomium::KeyCodes::AK_G;
    if(key == sf::Keyboard::H)
        return Awesomium::KeyCodes::AK_H;
    if(key == sf::Keyboard::I)
        return Awesomium::KeyCodes::AK_I;
    if(key == sf::Keyboard::J)
        return Awesomium::KeyCodes::AK_J;
    if(key == sf::Keyboard::K)
        return Awesomium::KeyCodes::AK_K;
    if(key == sf::Keyboard::L)
        return Awesomium::KeyCodes::AK_L;
    if(key == sf::Keyboard::U)
        return Awesomium::KeyCodes::AK_U;
    if(key == sf::Keyboard::V)
        return Awesomium::KeyCodes::AK_V;
    if(key == sf::Keyboard::W)
        return Awesomium::KeyCodes::AK_W;
    if(key == sf::Keyboard::M)
        return Awesomium::KeyCodes::AK_M;
    if(key == sf::Keyboard::N)
        return Awesomium::KeyCodes::AK_N;
    if(key == sf::Keyboard::O)
        return Awesomium::KeyCodes::AK_O;
    if(key == sf::Keyboard::P)
        return Awesomium::KeyCodes::AK_P;
    if(key == sf::Keyboard::Q)
        return Awesomium::KeyCodes::AK_Q;
    if(key == sf::Keyboard::R)
        return Awesomium::KeyCodes::AK_R;
    if(key == sf::Keyboard::S)
        return Awesomium::KeyCodes::AK_S;
    if(key == sf::Keyboard::T)
        return Awesomium::KeyCodes::AK_T;
    if(key == sf::Keyboard::X)
        return Awesomium::KeyCodes::AK_X;
    if(key == sf::Keyboard::Y)
        return Awesomium::KeyCodes::AK_Y;
    if(key == sf::Keyboard::Z)
        return Awesomium::KeyCodes::AK_Z;
    if(key == sf::Keyboard::Num0)
        return Awesomium::KeyCodes::AK_0;
    if(key == sf::Keyboard::Num1)
        return Awesomium::KeyCodes::AK_1;
    if(key == sf::Keyboard::Num2)
        return Awesomium::KeyCodes::AK_3;
    if(key == sf::Keyboard::Num3)
        return Awesomium::KeyCodes::AK_3;
    if(key == sf::Keyboard::Num4)
        return Awesomium::KeyCodes::AK_4;
    if(key == sf::Keyboard::Num5)
        return Awesomium::KeyCodes::AK_5;
    if(key == sf::Keyboard::Num6)
        return Awesomium::KeyCodes::AK_6;
    if(key == sf::Keyboard::Num7)
        return Awesomium::KeyCodes::AK_7;
    if(key == sf::Keyboard::Num8)
        return Awesomium::KeyCodes::AK_8;
    if(key == sf::Keyboard::Num9)
        return Awesomium::KeyCodes::AK_9;
    if(key == sf::Keyboard::Numpad0)
        return Awesomium::KeyCodes::AK_NUMPAD0;
    if(key == sf::Keyboard::Numpad1)
        return Awesomium::KeyCodes::AK_NUMPAD1;
    if(key == sf::Keyboard::Numpad2)
        return Awesomium::KeyCodes::AK_NUMPAD2;
    if(key == sf::Keyboard::Numpad3)
        return Awesomium::KeyCodes::AK_NUMPAD3;
    if(key == sf::Keyboard::Numpad4)
        return Awesomium::KeyCodes::AK_NUMPAD4;
    if(key == sf::Keyboard::Numpad5)
        return Awesomium::KeyCodes::AK_NUMPAD5;
    if(key == sf::Keyboard::Numpad6)
        return Awesomium::KeyCodes::AK_NUMPAD6;
    if(key == sf::Keyboard::Numpad7)
        return Awesomium::KeyCodes::AK_NUMPAD7;
    if(key == sf::Keyboard::Numpad8)
        return Awesomium::KeyCodes::AK_NUMPAD8;
    if(key == sf::Keyboard::Numpad9)
        return Awesomium::KeyCodes::AK_NUMPAD9;
    if(key == sf::Keyboard::F1)
        return Awesomium::KeyCodes::AK_F1;
    if(key == sf::Keyboard::F2)
        return Awesomium::KeyCodes::AK_F2;
    if(key == sf::Keyboard::F3)
        return Awesomium::KeyCodes::AK_F3;
    if(key == sf::Keyboard::F4)
        return Awesomium::KeyCodes::AK_F4;
    if(key == sf::Keyboard::F5)
        return Awesomium::KeyCodes::AK_F5;
    if(key == sf::Keyboard::F6)
        return Awesomium::KeyCodes::AK_F6;
    if(key == sf::Keyboard::F7)
        return Awesomium::KeyCodes::AK_F7;
    if(key == sf::Keyboard::F8)
        return Awesomium::KeyCodes::AK_F8;
    if(key == sf::Keyboard::F9)
        return Awesomium::KeyCodes::AK_F9;
    if(key == sf::Keyboard::F10)
        return Awesomium::KeyCodes::AK_F10;
    if(key == sf::Keyboard::F11)
        return Awesomium::KeyCodes::AK_F11;
    if(key == sf::Keyboard::F12)
        return Awesomium::KeyCodes::AK_F12;
    if(key == sf::Keyboard::BackSpace)
        return Awesomium::KeyCodes::AK_BACK;
    if(key == sf::Keyboard::Comma)
        return Awesomium::KeyCodes::AK_OEM_COMMA;
    if(key == sf::Keyboard::Period)
        return Awesomium::KeyCodes::AK_OEM_PERIOD;
}
const char* CGUIManager::sfKey2Char(short key, bool shift)
{
    if(shift)
    {
        if(key == sf::Keyboard::A)
            return "A";
        if(key == sf::Keyboard::B)
            return "B";
        if(key == sf::Keyboard::C)
            return "C";
        if(key == sf::Keyboard::D)
            return "D";
        if(key == sf::Keyboard::E)
            return "E";
        if(key == sf::Keyboard::F)
            return "F";
        if(key == sf::Keyboard::G)
            return "G";
        if(key == sf::Keyboard::H)
            return "H";
        if(key == sf::Keyboard::I)
            return "I";
        if(key == sf::Keyboard::J)
            return "J";
        if(key == sf::Keyboard::K)
            return "K";
        if(key == sf::Keyboard::L)
            return "L";
        if(key == sf::Keyboard::M)
            return "M";
        if(key == sf::Keyboard::N)
            return "N";
        if(key == sf::Keyboard::O)
            return "O";
        if(key == sf::Keyboard::P)
            return "P";
        if(key == sf::Keyboard::Q)
            return "Q";
        if(key == sf::Keyboard::U)
            return "U";
        if(key == sf::Keyboard::V)
            return "V";
        if(key == sf::Keyboard::W)
            return "W";
        if(key == sf::Keyboard::R)
            return "R";
        if(key == sf::Keyboard::S)
            return "S";
        if(key == sf::Keyboard::T)
            return "T";
        if(key == sf::Keyboard::X)
            return "X";
        if(key == sf::Keyboard::Y)
            return "Y";
        if(key == sf::Keyboard::Z)
            return "Z";
    }
    else
    {
        if(key == sf::Keyboard::A)
            return "a";
        if(key == sf::Keyboard::B)
            return "b";
        if(key == sf::Keyboard::C)
            return "c";
        if(key == sf::Keyboard::D)
            return "d";
        if(key == sf::Keyboard::E)
            return "e";
        if(key == sf::Keyboard::F)
            return "f";
        if(key == sf::Keyboard::G)
            return "g";
        if(key == sf::Keyboard::H)
            return "h";
        if(key == sf::Keyboard::I)
            return "i";
        if(key == sf::Keyboard::J)
            return "j";
        if(key == sf::Keyboard::K)
            return "k";
        if(key == sf::Keyboard::L)
            return "l";
        if(key == sf::Keyboard::M)
            return "m";
        if(key == sf::Keyboard::N)
            return "n";
        if(key == sf::Keyboard::O)
            return "o";
        if(key == sf::Keyboard::P)
            return "p";
        if(key == sf::Keyboard::Q)
            return "q";
        if(key == sf::Keyboard::U)
            return "u";
        if(key == sf::Keyboard::V)
            return "v";
        if(key == sf::Keyboard::W)
            return "w";
        if(key == sf::Keyboard::R)
            return "r";
        if(key == sf::Keyboard::S)
            return "s";
        if(key == sf::Keyboard::T)
            return "t";
        if(key == sf::Keyboard::X)
            return "x";
        if(key == sf::Keyboard::Y)
            return "y";
        if(key == sf::Keyboard::Z)
            return "z";
    }
    if(key == sf::Keyboard::Num0 || key == sf::Keyboard::Numpad0)
        return "0";
    if(key == sf::Keyboard::Num1 || key == sf::Keyboard::Numpad1)
        return "1";
    if(key == sf::Keyboard::Num2 || key == sf::Keyboard::Numpad2)
        return "2";
    if(key == sf::Keyboard::Num3 || key == sf::Keyboard::Numpad3)
        return "3";
    if(key == sf::Keyboard::Num4 || key == sf::Keyboard::Numpad4)
        return "4";
    if(key == sf::Keyboard::Num5 || key == sf::Keyboard::Numpad5)
        return "5";
    if(key == sf::Keyboard::Num6 || key == sf::Keyboard::Numpad6)
        return "6";
    if(key == sf::Keyboard::Num7 || key == sf::Keyboard::Numpad7)
        return "7";
    if(key == sf::Keyboard::Num8 || key == sf::Keyboard::Numpad8)
        return "8";
    if(key == sf::Keyboard::Num9 || key == sf::Keyboard::Numpad9)
        return "9";
    if(key == sf::Keyboard::BackSpace)
        return "\b";
    if(key == sf::Keyboard::Comma)
        return ",";
    if(key == sf::Keyboard::Period)
        return ".";
    if(key == sf::Keyboard::Add)
        return "+";
    if(key == sf::Keyboard::Dash)
        return "-";
    if(key == sf::Keyboard::Space)
        return " ";
    if(key == sf::Keyboard::Return)
        return "\n";
    if(key == sf::Keyboard::Tab)
        return "\t";
    return "";
}
//Just a little test commit.
