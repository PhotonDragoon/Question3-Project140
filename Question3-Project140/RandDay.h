#include "RandGen.h"
#include "Date.h"
#include <string>

class RandDay : public RandGen
{
private:
	Date date;
	bool set;
	bool randYr;
protected:
	void setRand();
public:
	RandDay();
	RandDay(int yr);
	void print();
	std::string toString();
	bool operator == (const RandDay&) const;
};
//#endif