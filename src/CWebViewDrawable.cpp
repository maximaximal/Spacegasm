#include "CWebViewDrawable.h"
#include <CGUIManager.h>
#include <CTextureManager.h>

CWebViewDrawable::CWebViewDrawable(int x, int y, Awesomium::WebCore *core)
{
    m_view = core->createWebView(x, y);
    m_view->setTransparent(true);
    CTextureManager::Get()->setWindowActive();
    m_image = new sf::Image();
    m_texture = new sf::Texture();
    m_sprite = new sf::Sprite;
    CTextureManager::Get()->setWindowActive(false);
}

CWebViewDrawable::~CWebViewDrawable()
{
    m_view->destroy();
    delete m_image;
    delete m_texture;
    delete m_sprite;
}

void CWebViewDrawable::onUpdate()
{
    if(m_view->isDirty())
    {
        unsigned char *rgbaBuf;
        const Awesomium::RenderBuffer *buffer = m_view->render();
        rgbaBuf = new unsigned char[buffer->width * 4 * buffer->height * 4];
        buffer->copyTo(rgbaBuf, buffer->width * 4, 4, true, false);
        CTextureManager::Get()->setWindowActive();
        m_image->create(buffer->width, buffer->height, rgbaBuf);
        m_texture->loadFromImage(*m_image);
        m_sprite->setTexture(*m_texture);
        CTextureManager::Get()->setWindowActive(false);
        delete rgbaBuf;
    }
}

void CWebViewDrawable::onEvent(sf::Event &event)
{
    if(event.type == sf::Event::MouseMoved)
    {
        m_view->injectMouseMove(event.mouseMove.x, event.mouseMove.y);
    }
    if(event.type == sf::Event::MouseButtonPressed)
    {
        m_view->injectMouseMove(event.mouseButton.x, event.mouseButton.y);
        if(event.mouseButton.button == sf::Mouse::Left)
            m_view->injectMouseDown(Awesomium::MouseButton::LEFT_MOUSE_BTN);
        if(event.mouseButton.button == sf::Mouse::Middle)
            m_view->injectMouseDown(Awesomium::MouseButton::MIDDLE_MOUSE_BTN);
        if(event.mouseButton.button == sf::Mouse::Right)
            m_view->injectMouseDown(Awesomium::MouseButton::RIGHT_MOUSE_BTN);
    }
    if(event.type == sf::Event::MouseButtonReleased)
    {
        m_view->injectMouseMove(event.mouseButton.x, event.mouseButton.y);
        if(event.mouseButton.button == sf::Mouse::Left)
            m_view->injectMouseUp(Awesomium::MouseButton::LEFT_MOUSE_BTN);
        if(event.mouseButton.button == sf::Mouse::Middle)
            m_view->injectMouseUp(Awesomium::MouseButton::MIDDLE_MOUSE_BTN);
        if(event.mouseButton.button == sf::Mouse::Right)
            m_view->injectMouseUp(Awesomium::MouseButton::RIGHT_MOUSE_BTN);
    }
    if(event.type == sf::Event::KeyPressed)
    {
        if(event.key.code != sf::Keyboard::Key::LShift && event.key.code != sf::Keyboard::Key::LShift)
        {
            Awesomium::WebKeyboardEvent keyEvent;
            keyEvent.isSystemKey = false;
            keyEvent.virtualKeyCode = CGUIManager::sfKey2Awesome(event.key.code);
            keyEvent.type = Awesomium::WebKeyboardEvent::Type::TYPE_CHAR;
            keyEvent.unmodifiedText[0] = (short unsigned int) CGUIManager::sfKey2Char(event.key.code, event.key.shift)[0];
            keyEvent.text[0] = (short unsigned int) CGUIManager::sfKey2Char(event.key.code, event.key.shift)[0];
            if(event.key.control)
                keyEvent.modifiers = Awesomium::WebKeyboardEvent::Modifiers::MOD_CONTROL_KEY;
            if(event.key.alt)
                keyEvent.modifiers = Awesomium::WebKeyboardEvent::Modifiers::MOD_ALT_KEY;
            if(event.key.system)
                keyEvent.modifiers = Awesomium::WebKeyboardEvent::Modifiers::MOD_META_KEY;
            m_view->injectKeyboardEvent(keyEvent);
        }
    }
    if(event.type == sf::Event::KeyPressed)
    {
        if(event.key.code != sf::Keyboard::Key::LShift && event.key.code != sf::Keyboard::Key::LShift)
        {
            Awesomium::WebKeyboardEvent keyEvent;
            keyEvent.isSystemKey = false;
            keyEvent.virtualKeyCode = CGUIManager::sfKey2Awesome(event.key.code);
            keyEvent.type = Awesomium::WebKeyboardEvent::Type::TYPE_KEY_DOWN;
            keyEvent.unmodifiedText[0] = (short unsigned int) CGUIManager::sfKey2Char(event.key.code, event.key.shift)[0];
            keyEvent.text[0] = (short unsigned int) CGUIManager::sfKey2Char(event.key.code, event.key.shift)[0];
            if(event.key.control)
                keyEvent.modifiers = Awesomium::WebKeyboardEvent::Modifiers::MOD_CONTROL_KEY;
            if(event.key.alt)
                keyEvent.modifiers = Awesomium::WebKeyboardEvent::Modifiers::MOD_ALT_KEY;
            if(event.key.system)
                keyEvent.modifiers = Awesomium::WebKeyboardEvent::Modifiers::MOD_META_KEY;
            m_view->injectKeyboardEvent(keyEvent);
        }
    }
    if(event.type == sf::Event::KeyReleased)
    {
        if(event.key.code != sf::Keyboard::Key::LShift && event.key.code != sf::Keyboard::Key::LShift)
        {
            Awesomium::WebKeyboardEvent keyEvent;
            keyEvent.isSystemKey = false;
            keyEvent.virtualKeyCode = CGUIManager::sfKey2Awesome(event.key.code);
            keyEvent.type = Awesomium::WebKeyboardEvent::Type::TYPE_KEY_UP;
            keyEvent.unmodifiedText[0] = (short unsigned int) CGUIManager::sfKey2Char(event.key.code, event.key.shift)[0];
            if(event.key.control)
                keyEvent.modifiers = Awesomium::WebKeyboardEvent::Modifiers::MOD_CONTROL_KEY;
            if(event.key.alt)
                keyEvent.modifiers = Awesomium::WebKeyboardEvent::Modifiers::MOD_ALT_KEY;
            if(event.key.system)
                keyEvent.modifiers = Awesomium::WebKeyboardEvent::Modifiers::MOD_META_KEY;
            m_view->injectKeyboardEvent(keyEvent);
        }
    }
    if(event.type == sf::Event::GainedFocus)
    {
        m_view->focus();
    }
    if(event.type == sf::Event::Resized)
    {
        if(!m_view->isResizing())
            m_view->resize(event.size.width, event.size.height, true, 300);
    }
}
std::string CWebViewDrawable::wstring2String(const std::wstring &convert)
{
    std::string converted(convert.begin(), convert.end());
    return converted;
}
void CWebViewDrawable::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(*m_sprite);
}
