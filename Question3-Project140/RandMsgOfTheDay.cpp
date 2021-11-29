#include "RandMsgOfTheDay.h"

RandMsgOfTheDay::RandMsgOfTheDay()
{
    setRand();
}
void RandMsgOfTheDay::setRand()
{
    srand(time(0));
    int randLine = rand() % 100 + 1;
    str = ReadNthLine("messages.txt", randLine);
}
string RandMsgOfTheDay::ReadNthLine(const string& filename, int N)
{
    ifstream in(filename.c_str());
    string s;
    s.reserve(100);
    for (int i = 0; i < N; ++i)
        getline(in, s);
    getline(in, s);
    return s;
}
void RandMsgOfTheDay::print()
{
    cout << str;
}