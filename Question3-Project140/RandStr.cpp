#include "RandStr.h"

RandStr::RandStr()
{
    setRand();
}
int RandStr::randAscPrintable()
{
    return (32 + rand() % 94);
}
void RandStr::setRand()
{
    srand(time(0));
    str = "";
    int size = rand() % 256 + 1;
    for (int i = 0; i < size; ++i)
        str += static_cast<char>(randAscPrintable());
}
void RandStr::print()
{
    cout << str;
}