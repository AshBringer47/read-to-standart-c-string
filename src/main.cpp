#include <iostream>
#include <cstring>
#include "cstringreader.h"

using namespace std;

int main()
{
    cout << "Enter string (CTRL+C for end):\n";

    char *c = reader::readString();
    cout << c;

    return 0;
}

