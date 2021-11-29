#include "RandDay.h"
#include "RandLotto.h"
#include "RandMsgOfTheDay.h"
#include "RandStr.h"
#include "RandTime.h"

#include <map>
#include <iomanip>

//prototype
void printRandom(RandDay randDay, RandTime randTime, RandLotto randLotto, RandMsgOfTheDay randMsg, RandStr randStr);

void birthdaySimulation();
void lotterySimulation();

using namespace std;

int main()
{
    //creating all the random objects
    RandDay randDay;
    RandTime randTime;
    RandLotto randLotto;
    RandMsgOfTheDay randMsg;
    RandStr randStr;
    char user;
    printRandom(randDay, randTime, randLotto, randMsg, randStr);
    cout << endl;
    cout << "Would you like to run the birthday simulation? (y/n): ";
    cin >> user;
    if (tolower(user) == 'y')
    {
        cout << "Running Birthday Simulation...\n\n";
        birthdaySimulation();
    }
    cout << "\nWould you like to run the lottery simulation? (y/n): ";
    cin >> user;
    if (tolower(user) == 'y')
    {
        cout << "Running Lottery Simulation... (this will take some time)\n\n";
        lotterySimulation();
    }
    return 0;
}
void printRandom(RandDay randDay, RandTime randTime, RandLotto randLotto, RandMsgOfTheDay randMsg, RandStr randStr)
{
    cout << "Random Day: " << endl;
    randDay.print();
    cout << "\n\n";
    cout << "Random Time: " << endl;
    randTime.print();
    cout << "\n\n";
    cout << "Random Lottery Numbers: " << endl;
    randLotto.print();
    cout << "\n\n";
    cout << "Random Message of The Day: " << endl;
    randMsg.print();
    cout << "\n\n";
    cout << "Random String: " << endl;
    randStr.print();
    cout << "\n\n";
}
void birthdaySimulation()
{
    RandDay birthday(2000);
    map<string, int> bdCounter;
    int birthdayRepeats;
    for (int classSize = 20; classSize <= 25; ++classSize)
    {
        cout << "Class Size: " << classSize << endl;
        birthdayRepeats = 0;

        for (int j = 0; j < 10000; ++j)
        {
            bdCounter.clear();
            for (int i = 0; i < classSize; ++i)
            {
                birthday.generate();
                if (bdCounter.find(birthday.toString()) == bdCounter.end())
                    bdCounter[birthday.toString()] = 1;
                else
                    goto end;
            }
            continue;
        end:
            ++birthdayRepeats;
        }
        cout << "Percent of times birthdays repeated: " << birthdayRepeats / 100 << "%" << endl;
    }
}
void lotterySimulation()
{
    RandLotto winner;
    RandLotto generator;
    long sum = 0;
    int reached = 1;
    const int times = 100;
    winner.generate();
    cout << "Winning Lotto Numbers: ";
    winner.print();
    cout << endl;
    for (int i = 0; i < times; ++i)
    {
        reached = 1;
        while (!(generator == winner))
        {
            ++reached;
            generator.generate();
        }
        cout << "Winner Found after " << reached << endl;
        sum += reached;
        winner.generate();
        generator.generate();
        cout << "New winning numbers: ";
        winner.print();
        cout << endl;
    }
    cout << "Average: " << fixed << setprecision(2) << 1.0 * sum / times << endl;
    cout << "Probability: " << fixed << setprecision(15) << 100.0 * times / sum << '%' << endl;
}