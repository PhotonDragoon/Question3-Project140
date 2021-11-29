#include "RandString.h"
#include <fstream>
class RandMsgOfTheDay : public RandString
{

protected:
	void setRand();
public:
	RandMsgOfTheDay();

	string ReadNthLine(const string& filename, int N);
	void print();
};