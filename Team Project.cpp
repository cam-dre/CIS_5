#include <iostream>
using namespace std;

int getNumDays();
double getDepartureTime();
double getArrivalTime();
double getConferenceFees();
bool Validate(double, double);
bool ValidateTime(double);

int main()
{

	double days = getNumDays();
	double depTime = getDepartureTime();
	double arrTime = getArrivalTime();
	double conFees = getConferenceFees();

	cout << days << depTime << arrTime << conFees;

	return 0;
}

int getNumDays()
{
	bool isValid;
	double days;
	double invalidNum = 0;

	cout << "What is the total number of days spent on the trip?" << endl;
	cin >> days;

	isValid = Validate(days, invalidNum);

	while (!isValid)
	{
		cout << "What is the total number of days spent on the trip?" << endl;
		cin >> days;

		isValid = Validate(days, invalidNum);
	}

	return days;
}

double getDepartureTime()
{
	bool isValid;
	double departureTime;

	cout << "When does the flight depart from the airport? (Please use 24 hour clock time)" << endl;
	cin >> departureTime;

	isValid = ValidateTime(departureTime);

	while (!isValid)
	{
		cout << "When does the flight depart from the airport? (Please use 24 hour clock time)" << endl;
		cin >> departureTime;

		isValid = ValidateTime(departureTime);
	}

	return departureTime;
}

double getArrivalTime()
{
	bool isValid;
	double arrivalTime;

	cout << "When does the flight arrive to the airport? (Please use 24-hour clock time)" << endl;
	cin >> arrivalTime;

	isValid = ValidateTime(arrivalTime);

	while (!isValid)
	{
		cout << "When does the flight arrive to the airport? (Please use 24-hour clock time)" << endl;
		cin >> arrivalTime;

		isValid = ValidateTime(arrivalTime);
	}

	return arrivalTime;
}

double getConferenceFees()
{
	bool isValid;
	double conferenceFees;
	double invalidNum = -1;

	cout << "How much were conference fees during the trip?" << endl;
	cin >> conferenceFees;

	isValid = Validate(conferenceFees, invalidNum);

	while (!isValid)
	{
		cout << "How much were conference fees during the trip?" << endl;
		cin >> conferenceFees;

		isValid = Validate(conferenceFees, invalidNum);
	}

	return conferenceFees;
}
bool Validate(double input, double low)
{
	bool validInput = false;

	if (input > low)
	{
		validInput = true;
	}
	return validInput;
}

bool ValidateTime(double input)
{
	bool validInput = false;

	if (input >= 00.00 && input < 24.00)
	{
		validInput = true;
	}
	return validInput;
}