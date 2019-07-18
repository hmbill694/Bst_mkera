#include "Part_2.h"
#include "M_BST.h"
#include <iostream>
using namespace std;

Part_2::Part_2()
{
}

Part_2::~Part_2()
{
}

void Part_2::run_part_2()
{
    cout << "\n\n";
    cout << "-----------------------------------------------------------------" << endl;
    cout << "Welcome to part two of the Home Work 4" << endl;
    cout << "This will be an application of a Binary Search Tree to a Air Traffic Control Situations" << endl;
    cout << "-----------------------------------------------------------------" << endl;

    M_BST tree;
    M_BST::node *temp = NULL;
    bool is_over = false;
    int time_gap = 0;

    cout << "What is the requried time gap for this sitauation: " << endl;
    cin >> time_gap;

    while (is_over != true)
    {
        char choice;
        int key;
        std::string plane_name = "";

        cout << "---------------------------" << endl;
        cout << "Menu" << endl;
        cout << "a). Request Landing" << endl;
        cout << "b.) Withdraw Landing Request" << endl;
        cout << "c.) List Landing Times and Flight numbers" << endl;
        cout << "d.) Exit" << endl;
        cin >> choice;
        cout << "---------------------------" << endl;

        switch (choice)
        {
        case 'a':
            cout << "Please enter the planes landing time request in minutes" << endl;
            cin >> key;
            cout << "Please enter the flight name" << endl;
            cin >> plane_name;
            if (tree.find_node(tree.root, key) != NULL)
            {
                cout << "There is already a plane with this landing time, Permission denied" << endl;
            }
            else if (tree.validate_time_gap(tree.root, time_gap, key) == false)
            {
                cout << "There must be an at least " << time_gap << " minutes between each flight" << endl;
            }
            else
            {
                tree.insert(key, plane_name);
            }
            break;

        case 'b':
            cout << "Please enter the requested landing time for the plane you are removing" << endl;
            cin >> key;
            cout << "Please enter the flight name" << endl;
            cin >> plane_name;
            temp = tree.find_node(tree.root, key);
            if (temp == NULL)
            {
                cout << "This flight does not exist" << endl;
            }
            else if (temp->data != plane_name)
            {
                cout << "A flight with the entered name and time does not exist" << endl;
            }
            else
            {
                tree.delete_node(temp);
            }
            break;

        case 'c':
            tree.in_order_traversal(tree.root);
            cout << "\n";
            break;

        case 'd':
            is_over = true;
            cout << "Have a Nice Day" << endl;
            break;
        default:
            cout << "Please enter valid choice" << endl;
            break;
        }
    }
}