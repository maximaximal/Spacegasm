#ifndef CTEXTUREMANAGER_H
#define CTEXTUREMANAGER_H

#include <CSingleton.h>
#include <map>
#include <string>
#include <CTexture.h>
#include <SFML/Graphics.hpp>
#include <mutex>

class CTextureManager : public TSingleton<CTextureManager>
{
    public:
        CTextureManager();
        virtual ~CTextureManager();
        void setWindowActive(bool active = true);
        void setRenderWindow(sf::RenderWindow *window);

    protected:
        std::map<std::string, CTexture*> m_textures;
        sf::RenderWindow *m_window;
        std::mutex m_windowMutex;
    private:
};

#endif // CTEXTUREMANAGER_H
