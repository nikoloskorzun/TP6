#pragma once


#include <iostream>
#include <string>

using namespace std;



class TRAIN
{
private:
	string destination;
	uint64_t train_number;
	string departure_time;
public:
	TRAIN();
	TRAIN(string destination, uint64_t train_number, string time);
	TRAIN(const TRAIN& note);
	~TRAIN();

	void inputFromConsole();
	void printToConsole();
	void change();

	string get_destination() { return destination; }

	void set_destination(string destination) { this->destination = destination;}

	uint64_t get_train_number() { return train_number; }

	void set_train_number(uint64_t train_number) { this->train_number = train_number; }

	string get_departure_time() { return departure_time; }

	void set_departure_time(string departure_time) { this->departure_time = departure_time; }




	TRAIN& operator=(const TRAIN& train);
	bool operator > (TRAIN& train);
};

