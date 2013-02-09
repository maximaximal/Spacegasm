#ifndef CSTRINGEXT_H
#define CSTRINGEXT_H

#include <string>
#include <vector>

class CStringExt
{
    public:
        CStringExt();
        virtual ~CStringExt();
        static std::vector<std::string> explode(const std::string& str, const char* ch);
        static std::string getFileExtension(const std::string& FileName);
    protected:
    private:
};

#endif // CSTRINGEXT_H
