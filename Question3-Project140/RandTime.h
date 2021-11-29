#include "RandGen.h"
#include "Time.h"
class RandTime : public RandGen
{
private:
	Time theTime;
protected:
	void setRand();
public:
	RandTime();

	void print();
};