#include"train.h"
using namespace std;
TRAIN::TRAIN() : destination("Не задано"), train_number(NULL), departure_time("Y:M:D h:m:s")
{
	cout << "constructor without params TRAIN" << endl;
}

TRAIN::TRAIN(string destination_, uint64_t train_number_, string time) :
	destination(destination), train_number(train_number_), departure_time(time)
{
	
	cout << "constructor with params TRAIN" << endl;
}

TRAIN::TRAIN(const TRAIN& train)
{

	this->departure_time = train.departure_time;
	this->destination = train.destination;
	this->train_number = train.train_number;

	cout << "copy constructor TRAIN" << endl;
}

TRAIN::~TRAIN()
{
	cout << "destructor TRAIN" << endl;
}

void TRAIN::inputFromConsole()
{
	cout << "Input destination: ";
	getline(cin, destination);

	cout << "Input departure time: ";
	getline(cin, departure_time);

	int flag = 1;
	while(flag)
	try
	{
	cout << "Input train number: ";
	cin >> train_number;
	flag = 0;
	}
	catch (const char* er)
	{
		cout << er << endl;
		cout << "exception catch!" << endl;
	}

	
}

void TRAIN::printToConsole()
{
	cout << "destination: " << destination << endl;
	cout << "train_number: " << train_number << endl;
	cout << "departure_time: " << departure_time<< endl;
}

void TRAIN::change()
{
	cout << "input new param\n";
	inputFromConsole();
}

TRAIN& TRAIN::operator=(const TRAIN& train) {
	if (this == &train)
		return *this;
	destination = train.destination;
	train_number = train.train_number;
	departure_time = train.departure_time;
	return *this;
}

bool TRAIN::operator>(TRAIN& train){

	return this->train_number > train.train_number;
}
