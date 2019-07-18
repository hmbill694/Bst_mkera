#include "Part_1.h"
#include "Part_2.h"
#include <iostream>

using namespace std;

int main()
{
    bool is_over = false;
    while (is_over != true)
    {
        int choice;
        cout << "-----------------------------------------------------------------" << endl;
        cout << "Welcome to Home Work 4. What part would you like to do?" << endl;
        cout << "1). Do Part One, Full BST Implementation" << endl;
        cout << "2.) Do Part Two, BST Application through an airport traffic control problem" << endl;
        cout << "3.) Quit Program" << endl;
        cout << "-----------------------------------------------------------------" << endl;

        cin >> choice;

        switch (choice)
        {
        case 1:
            Part_1::run_part_1();
            break;

        case 2:
            Part_2::run_part_2();
            break;

        case 3:
            is_over = true;
            break;

        default:
            break;
        }
    }

    return 0;
}