// 12-08-2018 Lecture Notes.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

#define MAX 1000

class MatrixElement
{
public:
	int row;
	int col;
	int value;
	MatrixElement *next;
	
	MatrixElement()
	{
		row = 0;
		col = 0;
		value = 0;
		next = NULL;
	}
};

class SparseMatrix
{
private:
	MatrixElement *head;
public:
	int randomNum;

	SparseMatrix()
	{
		head = NULL;
		randomNum = 0;
	}

	MatrixElement *getHead()
	{
		return head;
	}

	void setHead(MatrixElement* target)
	{
		head = target;
	}

	void createMatrices()
	{
		MatrixElement *current;
		current = getHead();

		for (int i = 0; i < MAX; i++)
		{
			for (int j = 0; j < MAX; j++)
			{
				randomNum = rand() % 100 + 1;
				if (randomNum <= 5)
				{
					MatrixElement *current;
					current = getHead();

					MatrixElement *temp;
					temp = new MatrixElement;
					temp->value = 1;
					temp->row = i;
					temp->col = j;

					if (current == NULL)
					{
						setHead(temp);
						current = getHead();
					}
					else
					{
						while (current->next != NULL)
						{
							current = current->next;
						}
						current->next = temp;
						current = current->next;
					}
					//current = getHead();
				}
			}
		}
	}

	void addMatrices(SparseMatrix *matrix)
	{
		MatrixElement *traverse1, *traverse2, *current1, *temp; 
		traverse1 = getHead();
		traverse2 = matrix->getHead();
		current1 = traverse1;

		while (traverse2 != NULL)
		{
			//fprintf(stderr, "traverse2\n");
			bool isin = false;
			traverse1 = getHead();
			while (traverse1 != NULL)
			{
				//fprintf(stderr, "traverse1\n");
				//fprintf(stderr, "t1_r: %d t1_c: %d t2_r: %d t2_c: %d\n", traverse1->row, traverse1->col, traverse2->row, traverse2->col);
				if (traverse2->row == traverse1->row && traverse2->col == traverse1->col)
				{
					traverse1->value += traverse2->value;
					isin = true;
				}
				current1 = traverse1;
				traverse1 = traverse1->next;
			}
			if (!isin)
			{
				temp = new MatrixElement;
				temp->row = traverse2->row;
				temp->col = traverse2->col;
				temp->value = traverse2->value;
				temp->next = NULL;
				current1->next = temp;
			}

			traverse2 = traverse2->next;
			//fprintf(stderr, "%d\n", traverse2);
		}
		
	}

	void display()
	{
		MatrixElement *temp;
		

		for (int i = 0; i < MAX; i++)
		{
			for (int j = 0; j < MAX; j++)
			{
				temp = getHead();
				bool isIn = false;
				while (temp != NULL)
				{
					if ((temp->row == i) && (temp->col == j))
					{
						cout << temp->value << " ";
						isIn = true;
					}
						
					temp = temp->next;
				}
				if(!isIn)
					cout << "0 ";
			}
			cout << endl;
		}		
	}
};

int main()
{
	srand(time(NULL));
	/*
	MatrixElement *e2;
	e2 = new MatrixElement;
	e2->row = 3;
	e2->col = 3;
	e2->value = 1;

	MatrixElement *e1;
	e1 = new MatrixElement;
	e1->row = 1;
	e1->col = 2;
	e1->value = 1;
	e1->next = e2;
	*/

	SparseMatrix mySP, mySP2;
	//mySP.setHead(e1);
	mySP.createMatrices();
	mySP.display();
	cout << endl;
	mySP2.createMatrices();
	mySP2.display();
	cout << endl;
	mySP.addMatrices(&mySP2);
	mySP.display();
	return 0;
}