#include "RandGen.h"
class RandLotto : public RandGen
{
private:
	int numbers[6];
	bool set;

protected:
	void setRand();
public:
	RandLotto();
	void print();
	bool operator == (const RandLotto&);
};