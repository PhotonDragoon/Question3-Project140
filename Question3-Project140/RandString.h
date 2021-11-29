#include "RandGen.h"
#include <string>

#ifndef RANDSTRING_H
#define RANDSTRING_H
class RandString : public RandGen
{
protected:
	string str;
	void setRand() = 0;

public:
	void print() = 0;
};

#endif