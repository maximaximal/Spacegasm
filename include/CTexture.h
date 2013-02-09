#ifndef CTEXTURE_H
#define CTEXTURE_H

#include <thread>
#include <mutex>
#include <string>
#include <stack>
#include <map>
#include <SFML/Graphics.hpp>

class CTexture
{
    public:
        CTexture();
        virtual ~CTexture();
        sf::Texture& get();
        /**
            @brief Loads the specified XML file and uses the contained info to load the texture in combination with the contained rectangles into the internal memory.
            @param filename The path to the XML file containing the texture-defining information.
        **/
        void load(std::string filename);
        /**
            @brief Sprites added to the texture will be set to that texture after it has been loaded.
            @param Pointer to the sprite you want to set.
        **/
        void addAfterloadSprite(sf::Sprite *sprite, std::string rect = "", unsigned int Number = 0);
        /**
            @brief Checks if the texture has finished loading.
            @return Finished-State
        **/
        bool isFinished();
    protected:
    private:
        struct SSpriteCache {
            sf::Sprite *sprite;
            std::string rect;
            unsigned int Number;
        };
        sf::Texture *m_texture;
        std::mutex m_dataMutex;
        std::mutex m_texMutex;
        std::stack<sf::Sprite*> m_sprites;

        std::map<std::string, std::map<unsigned int, sf::IntRect> > m_rectangles;
        bool m_finished;
};

#endif // CTEXTURE_H
