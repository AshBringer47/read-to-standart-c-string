#include "cstringreader.h"
#include <conio.h>
#include <iostream>
using std::cout;

namespace reader {

struct cString {
    char *string;
    unsigned int length;
    unsigned int realLength;
};


void raiseSize(cString &s, unsigned int newLength, unsigned int elementsNumber) {
    if(elementsNumber > s.length + 1 || newLength < elementsNumber) {
                        // string + '\n'
        throw;
    }

    char *newString = new char[newLength];
    memcpy(newString, s.string, elementsNumber * sizeof(char));
    delete s.string;

    s.realLength = newLength;
    s.string = newString;
}


void raiseSize(cString &s) {
    raiseSize(s, s.realLength * 2, s.realLength);
}

void reduceToLength(cString &s) {
    raiseSize(s, s.length + 1, s.length + 1);  // string + '\n'
}


char *readString()
{
    cString str;

    str.length = 0;
    str.realLength = 8;
    str.string = new char[str.realLength];

    char c = -1;
    while(c != 3) {   //  Для введення рядка до натиснення ctrl + C
        c = _getch();

        switch (c) {
        case 0:
            _getch();
            // no break;
        case 3:
            continue;
            // replaced break;
        case '\b':
            // перемістити каретку до попереднього символу - переписати цей символ - повернутись
            cout << "\b \b";
            if(str.length != 0) {
                str.length--;
            }
            continue;
            // replaced break;
        default:
            if(c == 13) {     // Для запису в рядок '\n', а не '\r' при натисненні enter
                str.string[str.length] = '\n';
            } else {
                str.string[str.length] = c;
            }
            cout << str.string[str.length];
            break;
        }

        str.length++;
        if(str.length >= str.realLength) {
            raiseSize(str);
        }
    }

    cout << "\n";
    str.string[str.length] = '\0';
    reduceToLength(str);

    if(str.length == 0) {
        return 0;
    }

    return str.string;
}

}
