#include "CTextureManager.h"
#include <iostream>
#include <CTexture.h>
#include <CStringExt.h>

using namespace std;

CTextureManager::CTextureManager()
{
    //ctor
}
CTextureManager::~CTextureManager()
{
    //dtor
}
void CTextureManager::loadTexture(std::string filename, std::string textureID)
{
    if(m_textures.count(textureID) > 0)
    {
        cout << "!! Texture named " << textureID << " is already loaded! Doing nothing...." << endl;
        return;
    }
    else
    {
        shared_ptr<CTexture> texture(new CTexture());
        std::thread texthread(&CTexture::load, texture.get(), filename);
        m_textures.insert(pair<string, shared_ptr<CTexture> >(textureID, texture));
        texture.reset();
    }
}
sf::IntRect CTextureManager::getRect(std::string textureID, std::string rect, unsigned int Number)
{
    if(m_textures.count(textureID) > 0)
    {
        return m_textures[textureID]->getRect(rect, Number);
    }
}
void CTextureManager::addSprite(std::string textureID, sf::Sprite *sprite, std::string textureRect, unsigned int textureNumber)
{
    if(m_textures.count(textureID) > 0)
    {
        m_textures[textureID]->addAfterloadSprite(sprite, textureRect, textureNumber);
    }
    else
    {
        cout << "!! There is no Texture named " << textureID << "!" << endl;
    }
}
void CTextureManager::setRenderWindow(sf::RenderWindow *window)
{
    m_window = window;
}
void CTextureManager::setWindowActive(bool active)
{
    m_window->setActive(active);
}
sf::Texture& CTextureManager::getTexture(std::string textureID)
{
    if(m_textures.count(textureID) > 0)
    {
        return m_textures[textureID]->get();
    }
    else
    {
        cout << "!! There is no Texture named " << textureID << "!" << endl;
    }
}
