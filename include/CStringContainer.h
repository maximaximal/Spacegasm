#ifndef CSTRINGCONTAINER_H
#define CSTRINGCONTAINER_H

#include <string>
#include <map>
#include <iostream>
#include <CSingleton.h>
#include <pugixml.hpp>

class CStringContainer : public TSingleton<CStringContainer>
{
    public:
        CStringContainer();
        virtual ~CStringContainer();
        void load(std::string langFile);
        void addString(std::string ID, std::string text);
        const std::string operator[](std::string ID) const
        {
            if(m_strings.count(ID) == 0)
            {
                std::cout << "!! No string with ID \"" << ID << "\" found!" << std::endl;
                return "";
            }
            else if(m_strings.count(ID) == 1)
            {
                return(m_strings.find(ID)->second);
            }
        }
    protected:
    private:
        std::map<std::string, std::string> m_strings;
};

#endif // CSTRINGCONTAINER_H
