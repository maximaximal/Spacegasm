#include "CTexture.h"

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
    m_texture = new sf::Texture();
    m_texMutex.lock();
    m_texture->loadFromFile(filename);
    m_texMutex.unlock();
    m_dataMutex.lock();
    m_finished = true;
    m_dataMutex.unlock();
}
sf::Texture& CTexture::get()
{
    m_texMutex.lock();
    sf::Texture &tex = *m_texture;
    m_texMutex.unlock();
    return tex;
}
bool CTexture::isFinished()
{
    m_dataMutex.lock();
    bool finished = m_finished;
    m_dataMutex.unlock();
    return finished;
}
