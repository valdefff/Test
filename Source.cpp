#include<iostream>
#include<stdio.h>
using namespace std;

class People {
public:
	char firstname[128];
	char lastname[128];
	int years_old;
	People* pointertoNextGuy;
};
People* pointertoHeadGuy;

void addGuy(People* pointerToClass) {//pnds
	pointerToClass->pointertoNextGuy = 0;
	if (pointertoHeadGuy == 0) {
		pointertoHeadGuy = pointerToClass;
		return;
	}

	People* pointertoCurrentGuy = pointertoHeadGuy;
	while (pointertoCurrentGuy->pointertoNextGuy) {
		pointertoCurrentGuy = pointertoCurrentGuy->pointertoNextGuy;
	}
	pointertoCurrentGuy->pointertoNextGuy = pointerToClass;
}

People* getData() {
	People* pointerToClass = new People;
	cout << "¬ведите им€: ";
	cin >> pointerToClass->firstname;
	if ((stricmp(pointerToClass->firstname, "exit")) == 0) {
		delete pointerToClass;
		return 0;
	}
	cout << "¬ведите фамилию: ";
	cin >> pointerToClass->lastname;

	cout << "¬ведите возраст: ";
	cin >> pointerToClass->years_old;
	pointerToClass->pointertoNextGuy = 0;
	return pointerToClass;
}


void diplayData(People* pointerToClass) {
	cout << pointerToClass->firstname << "\t" << pointerToClass->lastname << "\t" << pointerToClass->years_old << endl;
}

int main() {
	setlocale(LC_ALL, "ru");
	People* pointerToClass;
	while (pointerToClass = getData()) {
		addGuy(pointerToClass);
	}

	pointerToClass = pointertoHeadGuy;
	while (pointerToClass) {
		diplayData(pointerToClass);
		pointerToClass = pointerToClass->pointertoNextGuy;
	}
	return 0;
}


void diplayData(People* pointerToClass) {
	cout << pointerToClass->firstname << "\t" << pointerToClass->lastname << "\t" << pointerToClass->years_old << endl;
}

int main() {
	setlocale(LC_ALL, "ru");
	People* pointerToClass;
	while (pointerToClass = getData()) {
		addGuy(pointerToClass);
	}

	pointerToClass = pointertoHeadGuy;
	while (pointerToClass) {
		diplayData(pointerToClass);
		pointerToClass = pointerToClass->pointertoNextGuy;
	}
	return 0;
}
