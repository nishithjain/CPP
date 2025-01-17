#include <iostream>
#include <memory>
#include "BST.h"
#include <string>

using namespace std;


void ClearScreen()
{
#ifdef _WIN32
	system("cls");
#endif 
}

void displayMenu(void)
{
	cout << "-----------------" << endl;
	cout << "Operations on BST" << endl;
	cout << "-----------------" << endl;
	cout << "1.Insert Element " << endl;
	cout << "2.Find Element " << endl;
	cout << "3.In-order Traversal" << endl;
	cout << "4.Pre-order Traversal" << endl;
	cout << "5.Post-order Traversal" << endl;
	cout << "6.Display" << endl;
	cout << "7.Quit" << endl;
	cout << "Enter your choice : ";
}

int main(void) 
{ 
	int choice, num;
	BinarySearchTree bst;
	while (true)
	{
		displayMenu();
		cin >> choice;
		ClearScreen();
		switch (choice)
		{
		case 1:
			cout << "Enter the number to be inserted : ";
			cin >> num;
			bst.insert(num);
			bst.insert(num + 1);
			bst.insert(num - 1);
			bst.insert(num - 4);
			bst.insert(num + 3);
			bst.insert(num + 2);
			bst.insert(num - 2);
			bst.insert(num + 4);
			bst.insert(num - 3);
			break;

		case 2:
			cout << "Enter the number to find : ";
			cin >> num;
			if (bst.find(num))
				cout << "The number exists in BST\n";
			else
				cout << "The number doesn't exists in BST\n";
			break;

		case 3:
			cout << "In-order Traversal of BST:" << endl;
			bst.inorder();
			cout << endl;
			break;

		case 4:
			cout << "Pre-order Traversal of BST:" << endl;
			bst.preorder();
			cout << endl;
			break;

		case 5:
			cout << "Post-order Traversal of BST:" << endl;
			bst.postorder();
			cout << endl;
			break;

		case 6:
			cout << "Display BST:" << endl;
			bst.display(1);
			cout << endl;
			break;

		case 7:
			exit(1);

		default:
			cout << "Wrong choice" << endl;
		}
	}
	return 0; 
}