#include <iostream>
#include <random>
#include <set>
using namespace std;

// A game has three doors. Initially, you choose a random door. Then, the host will reveal one of the remaining doors to be false. Choose to switch. Measure success rates.

int main()
{
    srand(time(NULL));
    const int GAMES = 100;

    bool playing = true;
    while (playing)
    {
        cout << "There are three doors. One is the winning door. Initially, you pick a random one." << endl;
        cout << "After this, the host will reveal that one of the remaining doors is false." << endl
             << endl;

        cout << "So, should you swap your original door to the remaining door?" << endl
             << endl;

        cout << "We will play 100 games and measure the success rate." << endl;
        cout << "Do you choose to swap your door? Enter (y/n)." << endl;

        bool inputting = true;
        string input;
        while (inputting)
        {
            cout << "> ";
            getline(std::cin, input);
            if (input == "y" || input == "n")
            {
                inputting = false;
            }
        }

        bool switch_door;
        input == "y" ? switch_door = true : switch_door = false; // Input is confined to y or n by prior logic

        int victories = 0;

        for (int i = 0; i < GAMES; i++)
        {
            set<int> doors = {1, 2, 3};

            int correct_door = rand() % 3 + 1;

            srand(rand());
            int my_door = rand() % 3 + 1;
            int false_door;
            for (int i = 1; i <= 3; i++)
            {
                if (i != correct_door && i != my_door)
                {
                    false_door = i;
                    break;
                }
            }

            cout << "Chosen door: " << my_door << endl;
            cout << "Door " << false_door << " is false. Do you swap?" << endl;

            if (switch_door)
            {
                for (int i = 1; i <= 3; i++)
                {
                    if (i != my_door && i != false_door)
                    {
                        my_door = i;
                        break;
                    }
                }

                cout << "Yes, new door: " << my_door << endl;
            }
            else
            {
                cout << "No swap." << endl;
            }

            cout << "Correct door was: " << correct_door << endl;
            if (my_door == correct_door)
            {
                cout << "You win!" << endl;
                victories += 1;
            }
            else
            {
                cout << "You lose." << endl;
            }
            cout << endl;
        }

        cout << endl
             << "Final win total: " << victories << endl;
        cout << "Win percentage: " << (float)victories / (float)GAMES * 100.00 << "%" << endl
             << endl;

        cout << "Try again? Enter (y/n)." << endl;

        inputting = true;
        while (inputting)
        {
            cout << "> ";
            getline(std::cin, input);
            if (input == "y" || input == "n")
            {
                inputting = false;
            }
        }

        if (input == "n")
        {
            return 0;
        }

    } // End of main "playing" loop
}