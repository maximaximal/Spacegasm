#include "CTexture.h"
#include <CStringExt.h>
#include <pugixml.hpp>
#include <iostream>

using namespace std;

CTexture::CTexture()
{
    m_finished = false;
    m_texture = NULL;
}
CTexture::~CTexture()
{
    if(m_texture != NULL)
        delete m_texture;
}
void CTexture::load(std::string filename)
{
    if(CStringExt::getFileExtension(filename) == "xml")
    {
        string texturepath;
        pugi::xml_document doc;
        doc.load_file(filename.c_str());
        pugi::xml_node rects = doc.child("rectangles");
        for(pugi::xml_node rect = rects.child("rect"); rect; rect = rects.next_sibling("rect"))
        {
            m_rectangles[rect.attribute("N").as_string()][0] = sf::IntRect(  rect.attribute("X").as_uint(),
                                                                        rect.attribute("Y").as_uint(),
                                                                        rect.attribute("W").as_uint(),
                                                                        rect.attribute("H").as_uint());
        }
        for(pugi::xml_node rectset = rects.child("set"); rectset; rects.next_sibling("set"))
        {
            for(pugi::xml_node rect = rectset.child("rect"); rect; rect = rectset.next_sibling("rect"))
            {
                m_rectangles[rectset.attribute("N").as_string()][rect.attribute("N").as_uint()] = sf::IntRect(rect.attribute("X").as_uint(),
                                                                                                            rect.attribute("Y").as_uint(),
                                                                                                            rect.attribute("W").as_uint(),
                                                                                                            rect.attribute("H").as_uint());
            }
        }
        texturepath = doc.child("filename").text().as_string();
        m_texture = new sf::Texture();
        m_texture->loadFromFile(texturepath);

        m_spriteMutex.lock();
        while(m_sprites.size() > 0)
        {
            m_sprites.top().sprite->setTexture(*m_texture);
            if(m_rectangles.count(m_sprites.top().rect) > 0)
            {
                if(m_rectangles[m_sprites.top().rect].count(m_sprites.top().Number) > 0)
                {
                    m_sprites.top().sprite->setTextureRect(m_rectangles[m_sprites.top().rect][m_sprites.top().Number]);
                }
            }
            m_sprites.pop();
        };
        m_spriteMutex.unlock();
        m_finished = true;
    }
    else
    {
        m_texture = new sf::Texture();
        m_texMutex.lock();
        m_texture->loadFromFile(filename);
        m_texMutex.unlock();
        m_dataMutex.lock();
        m_finished = true;
        m_dataMutex.unlock();
    }
}
void CTexture::addAfterloadSprite(sf::Sprite *sprite, std::string rect, unsigned int Number)
{
    if(!isFinished())
    {
        SSpriteCache cache;
        cache.sprite = sprite;
        cache.rect = rect;
        cache.Number = Number;
        m_spriteMutex.lock();
        m_sprites.push(cache);
        m_spriteMutex.unlock();
    }
    else
    {
        m_texMutex.lock();
        sprite->setTexture(*m_texture);
        if(m_rectangles.count(rect) > 0)
        {
            if(m_rectangles[rect].count(Number) > 0)
            {
                sprite->setTextureRect(m_rectangles[rect][Number]);
            }
        }
        m_texMutex.unlock();
    }
}
sf::IntRect CTexture::getRect(std::string rect, unsigned int Number)
{
    if(m_rectangles.count(rect) > 0)
    {
        if(m_rectangles[rect].count(Number) > 0)
        {
            return m_rectangles[rect][Number];
        }
    }
    return sf::IntRect(0, 0, m_texture->getSize().x, m_texture->getSize().y);
}
sf::Texture& CTexture::get(bool wait)
{
    if(wait)
    {
        m_texMutex.lock();
        sf::Texture &tex = *m_texture;
        m_texMutex.unlock();
        return tex;
    }
    else if(isFinished())
    {
        return *m_texture;
    }
    else if(!isFinished())
    {
        cout << "[CTextureManager] Texture is not completely loaded!" << endl;
    }
}
bool CTexture::isFinished()
{
    m_dataMutex.lock();
    bool finished = m_finished;
    m_dataMutex.unlock();
    return finished;
}
