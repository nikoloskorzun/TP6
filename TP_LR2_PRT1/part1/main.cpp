
#include<iostream>
#include<fstream>


#include"train.h"
#include"Marray.h"
using namespace std;


int safeInput(int minInput, int maxInput) {
	while (true)
	{
		int method;
		std::cin >> method;
		if (std::cin.fail() || method <minInput || method >maxInput)
		{
			std::cin.clear();
			std::cout << "err\n";
		}
		else
		{
			std::cin.ignore(32767, '\n');
			std::cin.clear();
			return method;
		}
		std::cin.ignore(32767, '\n');
	}
}






void printMenu();
void addObject(Marray<TRAIN>& trains);
void changeObject(Marray<TRAIN>& trains);
void deleteObject(Marray<TRAIN>& trains);
void deleteAll(Marray<TRAIN>& trains);
void print(Marray<TRAIN>& trains);
void printLast(Marray<TRAIN>& trains);
void searchObjects(Marray<TRAIN>& trains);




int main() {


	Marray<TRAIN> trains;

	bool isExit = false;
	while (!isExit) {
		printMenu();
		int method = safeInput(0, 7);

		
		
		switch (method)
		{
		case 1:
			addObject(trains);
			break;
		case 2:
			changeObject(trains);
			break;
		case 3:
			deleteObject(trains);
			break;
		case 4:
			deleteAll(trains);
			break;
		case 5:
			print(trains);
			break;
		case 6:
			searchObjects(trains);
			break;
		case 7:
			printLast(trains);
			break;
		case 0:

			isExit = true;
			break;

		}
	}

}

void printMenu() {
	cout << "1. add obj" << endl;
	cout << "2. change obj" << endl;
	cout << "3. delete obj" << endl;
	cout << "4. delete all obj's" << endl;
	cout << "5. print all obj's" << endl;
	cout << "6. search obj's" << endl;
	cout << "7. print last obj" << endl;
	cout << "0. exit" << endl;
	cout << "choice item: ";

}

void addObject(Marray<TRAIN>& trains) {
	TRAIN train;
	train.inputFromConsole();
	trains += train;
	trains.sort();
}

void changeObject(Marray<TRAIN>& trains) {
	if (trains.getSize() > 0) {
		print(trains);
		cout << "input pos for change: ";
		trains[safeInput(1, trains.getSize()) - 1].change();
	}
	else
		cout << "empty arr\n";
	trains.sort();
}

void deleteObject(Marray<TRAIN>& trains) {
	if (trains.getSize() > 0) {
		print(trains);
		cout << "input pos for del: ";
		trains -= safeInput(1, trains.getSize()) - 1;
	}
	else
		cout << "empty arr\n";
	trains.sort();
}
void deleteAll(Marray<TRAIN>& trains) {
	if (trains.getSize() > 0)
		trains.clear();
	else
		std::cout << "empty arr\n";
	trains.sort();
}

void print(Marray<TRAIN>& trains) {
	if (trains.getSize() == 0)
		cout << "empty arr\n";
	else {
		cout << "arr:\n";
		for (int i = 0; i < trains.getSize(); i++) {
			cout << i + 1 << ".\n";
			trains[i].printToConsole();
		}
	}
}
void printLast(Marray<TRAIN>& trains) {
	if (trains.getSize() == 0)
		cout << "empty arr\n";
	else {
		cout << "last el:\n";
		int i = trains.getSize() - 1;
		trains[i].printToConsole();
	}
}

void searchObjects(Marray<TRAIN>& trains) {
	if (trains.getSize() == 0)
		cout << "empty arr\n";
	else {
		bool isPrint = false;
		uint64_t number;
		cout << "input number\n";
		cin >> number;

		for (int i = 0; i < trains.getSize(); i++)
			if (trains[i].get_train_number() == number) {
				isPrint = true;
				trains[i].printToConsole();
			}

		if (!isPrint)
			cout << "empty search.\n";
	}
}
