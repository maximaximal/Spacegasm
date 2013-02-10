#include "CServerConfig.h"
#include <pugixml.hpp>
#include <fstream>
#include <iostream>

using namespace std;

CServerConfig::CServerConfig()
{
    //ctor
}

CServerConfig::~CServerConfig()
{
    //dtor
}

void CServerConfig::load()
{
    ifstream stream("serverConf.xml");
    if(!stream)
        this->create();

    pugi::xml_document doc;
    doc.load_file("serverConf.xml");
    pugi::xml_node config = doc.child("ServerConfig");
    m_serverMessage = config.child("ServerMessage").text().as_string();

    cout << "[SERVER] Loaded Config!" << endl;
}
void CServerConfig::create()
{
    pugi::xml_document doc;
    doc.append_child("ServerConfig");
    pugi::xml_node config = doc.child("ServerConfig");
    config.append_child("ServerMessage").text() = "Welcome to this new Spacegasm server!";
    doc.save_file("serverConf.xml");
    cout << "[SERVER] Created config file serverConf.xml!" << endl;
}
