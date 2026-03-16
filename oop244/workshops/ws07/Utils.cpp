#include <cstring>
#include "Utils.h"

using namespace std;

namespace seneca {

Utils ut;

char* Utils::alocpy(const char* src) {
    char* dest = nullptr;
    if (src) {
        dest = new char[strlen(src) + 1];
        strcpy(dest, src);
    }
    return dest;
}

}
