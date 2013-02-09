#ifndef CTEXTUREMANAGER_H
#define CTEXTUREMANAGER_H

#include <CSingleton.h>
#include <map>
#include <string>
#include <CTexture.h>
#include <SFML/Graphics.hpp>
#include <mutex>
#include <memory>

class CTextureManager : public TSingleton<CTextureManager>
{
    public:
        CTextureManager();
        virtual ~CTextureManager();
        void setWindowActive(bool active = true);
        void setRenderWindow(sf::RenderWindow *window);

        void loadTexture(std::string filename, std::string textureID);
        sf::Texture* getTexture(std::string textureID);
        bool isFinished(std::string textureID);
        /**
            @brief Adds a sprite to the sprite-stack of the selected texture.
            @param textureID The texture to be applied to the sprite.
            @param sprite The sprite to be added to the stack.
            @param textureRect The name of the texture rect that is specified in the XML file of the texture.
            @param textureNumber The sub-ID of the texture rectangle defined in the XML file of the texture.
            This adds a sprite to the texture-internal sprite stack. The sprite-stack will set the texture to all the added sprites after
            the texture-loading has completed. The texture-rect will be applied too (if set & the rect exists)
        **/
        void addSprite(std::string textureID, sf::Sprite *sprite, std::string textureRect = "", unsigned int textureNumber = 0);
    protected:
        std::map<std::string, std::shared_ptr<CTexture> > m_textures;
        sf::RenderWindow *m_window;
        std::mutex m_windowMutex;
    private:
};

#endif // CTEXTUREMANAGER_H
