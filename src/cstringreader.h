#ifndef CSTRINGREADER_H
#define CSTRINGREADER_H

// Використовується функціональний підхід

namespace reader {

// введення рядка до натиснення ctrl + C
// Для не windows потрібен інший _getch()
char* readString();
}

#endif // CSTRINGREADER_H
