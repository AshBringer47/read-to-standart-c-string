#include <iostream>
    using std::cout;
#include <cstring>
#include "cstringreader.h"

int main()
{
    cout << "Enter string (CTRL+C for end):\n";

    char *c = reader::readString();
    cout << c;

    return 0;
}

