#include "CStringExt.h"
#include <vector>

using namespace std;

CStringExt::CStringExt()
{
    //ctor
}

CStringExt::~CStringExt()
{
    //dtor
}

//Thanks to Eric Scrivner - http://stackoverflow.com/questions/890164/how-can-i-split-a-string-by-a-delimiter-into-an-array
vector<string> CStringExt::explode(const string& str, const char* ch)
{
    string next = "";
    vector<string> result;

    // For each character in the string
    for (string::const_iterator it = str.begin(); it != str.end(); it++) {
    	// If we've hit the terminal character
    	if (*it == *ch) {
    		// If we have some characters accumulated
    		if (next.length() > 0) {
    			// Add them to the result vector
    			result.push_back(next);
    			next = "";
    		}
    	} else {
    		// Accumulate the next character into the sequence
    		next += *it;
    	}
    }
    return result;
}
//http://stackoverflow.com/a/4505931
std::string CStringExt::getFileExtension(const std::string& FileName)
{
    if(FileName.find_last_of(".") != std::string::npos)
        return FileName.substr(FileName.find_last_of(".")+1);
    return "";
}
