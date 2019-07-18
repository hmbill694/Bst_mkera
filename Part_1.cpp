#include "iostream"
#include "BST.h"
#include "Part_1.h"

using namespace std;
Part_1::Part_1()
{
}

Part_1::~Part_1()
{
}
void Part_1::run_part_1()
{
	cout << "-----------------------------------------------------------------" << endl;
	cout << "Welcome to part one of the Home Work 3" << endl;
	cout << "This will be an implementation of a Binary Search tree" << endl;
	cout << "-----------------------------------------------------------------" << endl;

	BST tree;
	BST::node *temp = NULL;
	bool is_over = false;

	while (is_over != true)
	{
		char choice;
		int key;

		cout << "Menu" << endl;
		cout << "---------------------------" << endl;
		cout << "a) Insert" << endl;
		cout << "b) Pre Order Traversal" << endl;
		cout << "c) In Order Traversal" << endl;
		cout << "d) Post Order Traversal" << endl;
		cout << "e) Find Max" << endl;
		cout << "f) Remove Max" << endl;
		cout << "g) Successor" << endl;
		cout << "h) Delete" << endl;
		cout << "x) End Program" << endl;
		cout << "Please make your choice: ";
		cin >> choice;
		cout << "---------------------------" << endl;
		switch (choice)
		{
		case 'a':
			cout << "Please enter the key value you will be inserting: " << endl;
			cin >> key;
			tree.insert(key);
			break;

		case 'b':
			cout << "Preorder Traversal " << endl;
			tree.pre_order_traversal(tree.root);
			cout << endl;
			break;

		case 'c':
			cout << "Inorder Traversal " << endl;
			tree.in_order_traversal(tree.root);
			cout << endl;
			break;

		case 'd':
			cout << "Postorder Traversal " << endl;
			tree.post_order_traversal(tree.root);
			cout << endl;
			break;

		case 'e':
			cout << "Finding Maximum of tree" << endl;
			tree.find_max(tree.root);
			break;

		case 'f':
			cout << "Deleting Maximum" << endl;
			tree.delete_max(tree.root);
			break;

		case 'g':
			cout << "Finding Successor of: " << endl;
			cin >> key;
			temp = tree.find_node(tree.root, key);
			temp = tree.find_successor(temp);
			cout << "The successor of " << key << " is " << temp->key << endl;
			break;

		case 'h':
			cout << "Delete node with key of:  " << endl;
			cin >> key;
			temp = tree.find_node(tree.root, key);
			temp = tree.delete_node(temp);
			cout << "The the node with a key of " << key << " has been deleted" << endl;
			break;

		case 'x':
			cout << "Have a nice day" << endl;
			is_over = true;
			break;

		default:
			cout << "Please enter a valid choice" << endl;
			break;
		}
	}
}
