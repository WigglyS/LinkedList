#include "Header.h"


void main()
{
	LinkedList<int> linkedList;

	
	int Quit = 0;

	do {
		
		int input;
		linkedList.Display();
		cout << "Press (0) to Add Number to List" << endl;
		cout << "Press (1) to Remove A Number From the list" << endl;
		cout << "Press (2) to Display the List" << endl;
		cout << "Press (3) to Run Diagnostics" << endl;
		cout << "Press (9) to Quit" << endl;
		cin >> input;

		switch (input)
		{
		case 0:
			int AddNum;
			cout << "Enter a Number to Add: ";
			cin >> AddNum;
			linkedList.Insert(AddNum);
			system("CLS");
			break;
		case 1:
			int RemoveNum;
			cout << "Enter a Number to Remove: ";
			cin >> RemoveNum;
			linkedList.Delete(RemoveNum);
			system("CLS");
			break;
		case 2:
			system("CLS");
			linkedList.Display();
			break;
		case 3:
			system("CLS");
			linkedList.Diagnostics();
			break;
		case 9:
			Quit = 1;
			break;
		}

	} while (Quit == 0);
	
}