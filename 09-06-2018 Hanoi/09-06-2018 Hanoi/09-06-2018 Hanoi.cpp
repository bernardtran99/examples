// 09-06-2018 Hanoi.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

using namespace std;

void hanoi(int N, int S, int I, int D)
{
	static int counter = 0;
	if (N == 1)
	{
		cout << counter++ << "Move disc " << N << " from " << S << "--->" << D << endl;
		counter++;
	}
	else
	{
		hanoi(N - 1, S, D, I);
		cout << counter		 ++ << "Move disc " << N << " from " << S << "--->" << D << endl;
		counter++;
		hanoi(N - 1, I, S, D);
	}
}

int main()
{
	int N;
	char S = 'S', I = 'I', D = 'D';
	cout << "Give me number of disks: " << endl;
	cin >> N;

	hanoi(N, S, I, D);
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
