#ifndef CSTRINGCONTAINER_H
#define CSTRINGCONTAINER_H

#include <string>
#include <map>
#include <CSingleton.h>
#include <pugixml.h>

class CStringContainer : public TSingleton<CStringContainer>
{
    public:
        CStringContainer();
        virtual ~CStringContainer();
        void load(std::string langFile);
        void addString(std::string ID, std::string text);
        const std::string operator[](const std::string ID) const;
    protected:
    private:
        std::map<std::string, std::string> m_strings;
};

#endif // CSTRINGCONTAINER_H
