#ifndef CWEBVIEWDRAWABLE_H
#define CWEBVIEWDRAWABLE_H

#include <Awesomium/WebCore.h>
#include <Awesomium/WebView.h>
#include <Awesomium/WebViewListener.h>
#include <SFML/Graphics.hpp>

class CWebViewDrawable : public sf::Drawable
{
    public:
        CWebViewDrawable(int x, int y, Awesomium::WebCore *core);
        virtual ~CWebViewDrawable();
        void onUpdate();
        void onEvent(sf::Event &event);
        static std::string wstring2String(const std::wstring &convert);
    protected:
        Awesomium::WebView *m_view;
        Awesomium::WebViewListener *m_listener;

        sf::Image *m_image;
        sf::Texture *m_texture;
        sf::Sprite *m_sprite;

        virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
    private:
};

class CWebViewDrawableListener : public Awesomium::WebViewListener
{
    public:
        CWebViewDrawableListener() {}
        virtual ~CWebViewDrawableListener() {}

        //Events
            virtual void onBeginNavigation (Awesomium::WebView *caller, const std::string &url, const std::wstring &frameName) {}
            virtual void onBeginLoading (Awesomium::WebView *caller, const std::string &url, const std::wstring &frameName, int statusCode, const std::wstring &mimeType) {}
            virtual void onFinishLoading (Awesomium::WebView *caller) {}
            virtual void onCallback (Awesomium::WebView *caller, const std::wstring &objectName, const std::wstring &callbackName, const Awesomium::JSArguments &args) {}
            virtual void onReceiveTitle (Awesomium::WebView *caller, const std::wstring &title, const std::wstring &frameName) {}
            virtual void onChangeTooltip (Awesomium::WebView *caller, const std::wstring &tooltip){}
            virtual void onChangeCursor (Awesomium::WebView *caller, Awesomium::CursorType cursor){}
            virtual void onChangeKeyboardFocus (Awesomium::WebView *caller, bool isFocused){}
            virtual void onChangeTargetURL (Awesomium::WebView *caller, const std::string &url){}
            virtual void onOpenExternalLink (Awesomium::WebView *caller, const std::string &url, const std::wstring &source){}
            virtual void onRequestDownload (Awesomium::WebView *caller, const std::string &url){}
            virtual void onWebViewCrashed (Awesomium::WebView *caller){}
            virtual void onPluginCrashed (Awesomium::WebView *caller, const std::wstring &pluginName){}
            virtual void onRequestMove (Awesomium::WebView *caller, int x, int y){}
            virtual void onGetPageContents (Awesomium::WebView *caller, const std::string &url, const std::wstring &contents){}
            virtual void onDOMReady (Awesomium::WebView *caller){}
            virtual void onRequestFileChooser (Awesomium::WebView *caller, bool selectMultipleFiles, const std::wstring &title, const std::wstring &defaultPath){}
            virtual void onGetScrollData (Awesomium::WebView *caller, int contentWidth, int contentHeight, int preferredWidth, int scrollX, int scrollY){}
            virtual void onJavascriptConsoleMessage (Awesomium::WebView *caller, const std::wstring &message, int lineNumber, const std::wstring &source){}
            virtual void onGetFindResults (Awesomium::WebView *caller, int requestID, int numMatches, const Awesomium::Rect &selection, int curMatch, bool finalUpdate){}
            virtual void onUpdateIME (Awesomium::WebView *caller, Awesomium::IMEState imeState, const Awesomium::Rect &caretRect){}
            virtual void onShowContextMenu (Awesomium::WebView *caller, int mouseX, int mouseY, Awesomium::MediaType type, int mediaState, const std::string &linkURL, const std::string &srcURL, const std::string &pageURL, const std::string &frameURL,
                const std::wstring &selectionText, bool isEditable, int editFlags) {}
            virtual void onRequestLogin (Awesomium::WebView *caller, int requestID, const std::string &requestURL, bool isProxy, const std::wstring &hostAndPort, const std::wstring &scheme, const std::wstring &realm){}
            virtual void onChangeHistory (Awesomium::WebView *caller, int backCount, int forwardCount){}
            virtual void onFinishResize (Awesomium::WebView *caller, int width, int height){}
            virtual void onShowJavascriptDialog (Awesomium::WebView *caller, int requestID, int dialogFlags, const std::wstring &message, const std::wstring &defaultPrompt, const std::string &frameURL){}
    protected:
    private:
};
#endif // CWEBVIEWDRAWABLE_H
