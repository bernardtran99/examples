// 11-15-2018 Lecture Notes.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <time.h>
#include <stdlib.h>


using namespace std;

#define MAX 5
#define NULL 0
//a sparse matrix is a matrix inwhich most elements are 0
//elements are nonzero with a probability of 5/100 == 0.05
//A[][] + B[][] = C[][]
//add the matrices together/but we ll dothis without 2d arrays but with linked lists

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

class SparseMatrix {
public:
	MatrixElement **head1;
	int randomNum;

	SparseMatrix()
	{
		head1 = NULL;
		randomNum = 0;
	}

	void createMatrices(MatrixElement** head)
	{
		MatrixElement *current;
		fprintf(stderr, "CREATE MATRIX CALL\n");
		for (int i = 0; i < MAX; i++)
		{
			for (int j = 0; j < MAX; j++)
			{
				randomNum = rand() % 100 + 1;
				if (randomNum <= 5)
				{
					MatrixElement temp;
					temp.value = 1;
					temp.row = i;
					temp.col = j;
					temp.next = NULL;
					if ((*head)->row == -1)
					{
						*head = &temp;
						fprintf(stderr, "new head\n");
					}
					else
					{
						current = *head;
						while (current->next != NULL)
						{
							current = current->next;
						}
						current->next = &temp;
					}
				}
			}
		}
	}

	MatrixElement *addMatrices(MatrixElement *matrix1, MatrixElement *matrix2)
	{
		//matrices should already be sorted in their own order so we take one and go throught the second one to insert it into the slot of another
		//start wiht matrix1 and traverse it until the row is less than or equal to fast
		//we need a fast and slow
		//fast is the one used to compare the next one

		MatrixElement *fast1, *middle1, *slow1, *temp;
		MatrixElement *fast2, *middle2, *slow2;
		fast1 = slow1 = temp = matrix1;
		fast2 = slow2 = matrix2;
		while (fast1->next != NULL)
		{
			fast1 = fast1->next;
			if (slow2->row < slow1->row)
			{
				if (slow2->col < slow1->col)
				{
					slow2->next = slow1;
				}
				else if (slow2->col > slow2->col)
				{

				}
			}
			else if (slow2->row == slow1->row)
			{
				if (slow2->col == slow1->col)
				{
					//add the values and delete
				}
				else if (slow2->col < slow1->col)
				{

				}
			}
			//if not these cases then just add them

		}

	}

	void display(MatrixElement** head)
	{
		MatrixElement *temp;
		temp = *head;

		//temp->col
		//temp->row
		//temp->value
		fprintf(stderr, "%d\n", temp->value);
		if (temp == NULL)
		{

			fprintf(stderr, "BAD HEAD\n");
			//return;
		}
		while(temp->next != NULL)
		{
			for (int i = 0; i < MAX; i++)
			{
				for (int j = 0; j < MAX; j++)
				{
					if (temp->row == i && temp->col == j)
					{
						cout << temp->value << " ";
					}
					else
					{
						cout << "0 ";
					}
				}
				cout << endl;
			}
			temp = temp->next;
		}
	}

};

int main()
{
	MatrixElement falseHead;
	falseHead.row = -1;
	MatrixElement* head1 = &falseHead;
	srand(time(NULL));
	SparseMatrix mySP;
	mySP.createMatrices(&head1);
	mySP.display(&head1);
	return 0;
}

/*
// 2d array of elements
int A[MAX][MAX], B[MAX][MAX], C[MAX][MAX], randomNum;
srand(time(NULL)); //seed code with time

for (int i = 0; i < MAX; i++)
{
	for (int j = 0; j < MAX; j++)
	{
		//generate random numbers and insert into array
		randomNum = rand() % 100 + 1;
		if (randomNum <= 5)
		{
			A[i][j] = 1;
		}
		else
		{
			A[i][j] = 0;
		}
		cout << A[i][j] << " ";
	}
	cout << endl;
}

cout << endl;

// generating B matrix
for (int i = 0; i < MAX; i++)
{
	for (int j = 0; j < MAX; j++)
	{
		//generate random numbers and insert into array
		randomNum = rand() % 100 + 1;
		if (randomNum <= 5)
		{
			B[i][j] = 1;
		}
		else
		{
			B[i][j] = 0;
		}
		cout << B[i][j] << " ";
	}
	cout << endl;
}

cout << endl;

//Matrix C is the sum of A and B
for (int i = 0; i < MAX; i++)
{
	for (int j = 0; j < MAX; j++)
	{
		C[i][j] = A[i][j] + B[i][j];

		cout << C[i][j] << " ";
	}
	cout << endl;
}

return 0;
*/

/*
int main()
{
	int secretNum, guess;
	int attempt = 0;
	srand(time(NULL)); // seeding random number generator with time
		
	// to get a random number from 1 to 10 inclusive (1-10)
	secretNum = rand()%10 + 1;

	// guessing game
	while (attempt <= 3)
	{
		cout << "What is your guess?" << endl;
		cin >> guess;
		if (guess == secretNum)
		{
			cout << "You got the number" << endl;
			exit(1);
		}
		attempt++;
	}

	cout << "This was the secret number: " << secretNum << endl;

	return 0;
}
*/