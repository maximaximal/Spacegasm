#include "IPConverter.h"
#include <string>
#include <sstream>
#include <stdio.h>

using namespace std;

IPConverter::IPConverter()
{
    //ctor
}

IPConverter::~IPConverter()
{
    //dtor
}

string IPConverter::toString(unsigned int ip)
{
    stringstream address;
    address << (ip & 0xff) << ".";
    address << ((ip & (0xff << 8)) >> 8) << ".";
    address << ((ip & (0xff << 16)) >> 16) << ".";
    address << ((ip & (0xff << 24)) >> 24);
    return address.str();
}
unsigned int IPConverter::toUInt(string ip)
{
    unsigned char a, b, c, d;
    sscanf(ip.c_str(), "%hhu.%hhu.%hhu.%hhu", &d, &c, &b, &a );
    unsigned int address = ( a << 24 ) | ( b << 16 ) | ( c << 8 ) | d;
    return address;
}
