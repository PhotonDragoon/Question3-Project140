#include "RandLotto.h"

RandLotto::RandLotto()
{
    set = false;
    setRand();
    set = true;
}
void RandLotto::setRand()
{
    if (!set)
        srand(time(0));
    for (int i = 0; i < 5; ++i)
        numbers[i] = rand() % 47 + 1;
    numbers[5] = rand() % 27 + 1;
}
void RandLotto::print()
{
    for (int i = 0; i < 6; ++i)
        cout << numbers[i] << " ";
}
bool RandLotto::operator == (const RandLotto& other)
{
    for (int i = 0; i < 5; ++i)
        if (numbers[i] != other.numbers[i])
            return false;
    return true;
}