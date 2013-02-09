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
CTextureManager::loadTexture(std::string filename, std::string textureID)
{
    if(CStringExt::getFileExtension(filename) == "xml")
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
    else
    {
        cout << "!! Only load textures defined with XML!" << endl;
        return;
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
