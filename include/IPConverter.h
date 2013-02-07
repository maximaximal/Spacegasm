#ifndef IPCONVERTER_H
#define IPCONVERTER_H

#include <string>

class IPConverter
{
    public:
        IPConverter();
        virtual ~IPConverter();
        static std::string toString(unsigned int ip);
        static unsigned int toUInt(std::string ip);
    protected:
    private:
};

#endif // IPCONVERTER_H
