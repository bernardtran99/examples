#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
	ofstream writer;

	writer.open("text.txt", ios::app);

	writer << "Programming is epic" << endl;

	writer.close();
	return 0;
}
