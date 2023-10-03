#include<stdio.h>

#define ROWS 5
#define COLS 4

FILE* file1;

void readMatrix(int table[ROWS][COLS]);
void printMatrix(int table[ROWS][COLS]);
void winnerEachState(int table[ROWS][COLS]);
void determineWinner(int table[ROWS][COLS]);

void main()
{
	int matrix[ROWS][COLS];

	readMatrix(matrix);
	printMatrix(matrix);
	winnerEachState(matrix);
	determineWinner(matrix);
}

void readMatrix(int table[ROWS][COLS])
{
	for (int i = 0; i < ROWS; i++)
	{
		printf("\tState %d\n", (i + 1));
		for (int j = 0; j < COLS; j++)
		{
			printf("Candidate %d:\n", (j + 1));
			scanf("%d", &table[i][j]);
		}
	}
}
//Displays and saves matrix to a file
void printMatrix(int table[ROWS][COLS])
{
	int i, j;
	file1 = fopen("CandidateVotes.txt", "w");
	printf("\t\tA\tB\tC\tD\n\n");
	fprintf(file1, "\t\tA\tB\tC\tD\n\n");
	for (i = 0; i < ROWS; i++)
	{
		printf("State %d \t", (i + 1));
		fprintf(file1, "State %d \t", (i + 1));
		for (j = 0; j < COLS; j++)
		{
			printf("%d\t", table[i][j]);
			fprintf(file1, "%d\t", table[i][j]);
		}
		printf("\n\n\n");
		fprintf(file1, "\n\n\n");
	}
}
//Displays winner of each state
void winnerEachState(int table[ROWS][COLS])
{
	int max = 0;
	int index1, index2, index3, index4, index5 = 0;

	//State 1
	max = 0;
	for (int i = 0; i < COLS; i++)
	{
		if (table[0][i] > max)
		{
			max = table[0][i];
			index1 = i + 1;
		}
	}
	printf("State 1 WINNER: Candidate %d\n", index1);
	//State 2
	max = 0;
	for (int i = 0; i < COLS; i++)
	{
		if (table[1][i] > max)
		{
			max = table[1][i];
			index2 = i + 1;
		}
	}
	printf("State 2 WINNER: Candidate %d\n", index2);
	//State 3
	max = 0;
	for (int i = 0; i < COLS; i++)
	{
		if (table[2][i] > max)
		{
			max = table[2][i];
			index3 = i + 1;
		}
	}
	printf("State 3 WINNER: Candidate %d\n", index3);
	//State 4
	max = 0;
	for (int i = 0; i < COLS; i++)
	{
		if (table[3][i] > max)
		{
			max = table[3][i];
			index4 = i + 1;
		}
	}
	printf("State 4 WINNER: Candidate %d\n", index4);
	//State 5
	max = 0;
	for (int i = 0; i < COLS; i++)
	{
		if (table[4][i] > max)
		{
			max = table[4][i];
			index5 = i + 1;
		}
	}
	printf("State 5 WINNER: Candidate %d\n", index5);
}
//Displays winner
void determineWinner(int table[ROWS][COLS])
{
	int candidate[COLS];
	int max = 0;
	int indexMax = 0;
	for (int i = 0; i < COLS; i++)
	{
		candidate[i] = table[0][i] + table[1][i] + table[2][i];
	}
	for (int i = 0; i < ROWS; i++)
	{
		if (candidate[i] > max)
		{
			max = candidate[i];
			indexMax = i + 1;
		}
	}
	printf("\n\nNew Major of the city is CANDIDATE %d", indexMax);
}