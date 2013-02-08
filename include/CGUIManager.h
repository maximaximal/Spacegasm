#ifndef CGUIMANAGER_H
#define CGUIMANAGER_H

#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
#include <memory>

class CGUIManager : public sf::Drawable
{
    public:
        CGUIManager(int width, int height);
        virtual ~CGUIManager();
        void onUpdate(float frametime);
        void onEvent(sf::Event &event);
        static short sfKey2Awesome(short key);
        static const char* sfKey2Char(short key, bool shift);

        int addWindow(CWebViewDrawable *window, bool display = true);
        void setActive(int window);
        void removeWindow(int window);
        Awesomium::WebCore* getCore();
    protected:
        virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
    private:
        short m_activeView;
        Awesomium::WebCoreConfig m_config;
        Awesomium::WebCore *m_webCore;
        int m_width, m_height;

        std::vector<std::shared_ptr<CWebViewDrawable> > m_views;
};

#endif // CGUIMANAGER_H
