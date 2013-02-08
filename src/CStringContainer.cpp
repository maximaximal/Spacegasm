#include "CStringContainer.h"
#include <iostream>

using namespace std;

CStringContainer::CStringContainer()
{
    //ctor
}

CStringContainer::~CStringContainer()
{
    //dtor
}

void CStringContainer::load(std::string langFile)
{
    pugi::xml_document doc;
    doc.load_file(langFile.c_str());
    pugi::xml_node lang = doc.child("Language");
    for(pugi::xml_node text = lang.child("text"); text; text = text.next_sibling("text"))
    {
        this->addString(text.attribute("id").as_string(), text.attribute("string").as_string());
    }
}

void CStringContainer::addString(std::string ID, std::string text)
{
    if(m_strings.count(ID) == 0)
    {
        m_strings.insert(pair<string, string>(ID, text));
    }
    else if(m_strings.count(ID) > 0)
    {
        cout << "!! The StringContainer already has \"" << ID << "\" in its database! Overwriting..." << endl;
        m_strings.erase(m_strings.find(ID));
        m_strings.insert(pair<string, string>(ID, text));
    }
}

