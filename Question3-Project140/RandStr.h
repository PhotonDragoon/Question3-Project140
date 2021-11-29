#include "RandString.h"
class RandStr : public RandString
{
protected:
	void setRand();

public:
	RandStr();
	int randAscPrintable();
	void print();
};