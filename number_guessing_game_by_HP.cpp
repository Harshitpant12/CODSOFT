#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    //random number
    srand((unsigned int)time(NULL));
    int number = (rand() % 100) + 1;

    int guess;

    while (guess != number)
    {
        cout << "Guess a number between 1 to 100: " << endl;
        cin >> guess;

        if (guess > number)
        {
            cout << "Your guess is higher, guess a low number." << endl;
        }
        else if (guess < number)
        {
            cout << "Your guess is lower, guess a high number." << endl;
        }
        else
        {
            cout << "You got it, You WON!!!" << endl;
        }
    }

    return 0;
}
