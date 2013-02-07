#ifndef CTEXTURE_H
#define CTEXTURE_H

#include <thread>
#include <mutex>
#include <string>
#include <stack>

#include <SFML/Graphics.hpp>

class CTexture
{
    public:
        CTexture();
        virtual ~CTexture();
        sf::Texture& get();
        /**
            @brief Loads the specified texture into the internal memory.
            @param filename Path to the image to be loaded.
        **/
        void load(std::string filename);
        /**
            @brief Loads the specified XML file and uses the contained info to load the texture in combination with the contained rectangles into the internal memory.
            @param filename The path to the XML file containing the texture-defining information.
            @param overwriteTexture If true, then the maybe already loaded texture will be overwritten.
        **/
        void loadDefined(std::string filename, bool overwriteTexture);
        /**
            @brief Sprites added to the texture will be set to that texture after it has been loaded.
            @param Pointer to the sprite you want to set.
        **/
        void addAfterloadSprite(sf::Sprite *sprite);
        /**
            @brief Checks if the texture has finished loading.
            @return Finished-State
        **/
        bool isFinished();
    protected:
    private:
        sf::Texture *m_texture;
        std::mutex m_dataMutex;
        std::mutex m_texMutex;
        std::stack<sf::Sprite*> m_sprites;
        bool m_finished;
};

#endif // CTEXTURE_H
