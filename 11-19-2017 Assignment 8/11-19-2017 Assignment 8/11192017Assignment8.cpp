#include "stdafx.h"
#include <iostream>

using namespace std;

class VendingMachine {

public:

	int numberOfCans;



	VendingMachine() {
	}

	void coke() {
		cout << "Coke has been dispensed." << endl;
	}

	void sprite() {
		cout << "Sprite has been dispensed." << endl;
	}

	void fanta() {
		cout << "Fanta has been dispensed." << endl;
	}

	void pepsi() {
		cout << "Pepsi has been dispensed." << endl;
	}

};



int main() {
	VendingMachine myMachine;
	while (1) {
		int response = 0;
		cout << "Press 1 to dispense Coke." << endl;
		cout << "Press 2 to dispense Sprite" << endl;
		cout << "Press 3 to dispense Fanta." << endl;
		cout << "Press 4 to dispense Pepsi" << endl;
		cout << "Press any other number to exit" << endl;
		cin >> response;

		switch (response) {
		
		case 1: myMachine.coke();
			break;
		case 2: myMachine.sprite();
			break;
		case 3: myMachine.fanta();
			break;
		case 4: myMachine.pepsi();
			break;

		default: exit(1);

		}
		
	}
	cout << "Thank You and Have a Great Day." << endl;

	return 0;
}