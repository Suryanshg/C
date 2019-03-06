/*
 * production.c
 *
 *  Created on: Feb 3, 2019
 *      Author: Suryansh Goyal
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "production.h"
#include <math.h>
#include <string.h>

bool production(int argc, char* argv[])
{
	bool results = false;
	bool ok2; //for opening file
	bool done = false;
	int nRows=-1;
	int nCols = -1;
	char* ptr=0;
	long gens_l=strtol(argv[3],&ptr,10);
	int gens= (int)gens_l; //number of generations to play
	int howManyLinesInFile = 0;
	int maximumWidth = 0;
	char filename[100];
	for(int i= 0; i<100; i++)
	{
		filename[i]='\0';
	}
	char print = 'n';
	char pause = 'n';
	//etc.
	//get the NR NC gens input [print] [pause], Usage as needed.
	if(argc<5)//not all mandatory args provided
	{

		usage();
		done=true;
	}
	else if (argc >= 7)
	{
		pause = argv[6][0];
	}
	if (!done && (argc >= 6))
	{
		print = argv[5][0];
	}

	if(!done)//must be greater than or equal to 5, so get the mandatory vals
	{

		char* ptr=0;
		long nr_l = strtol(argv[1],&ptr,10);//get the NR
		nRows = (int)nr_l;
		if(nRows<1)
		{
			printf("Usage: Rows should be greater than 0, received %d.\n",nRows);
			done = true;
		}


		char* ptr1=0;
		long nc_l=strtol(argv[2],&ptr1,10);//get the NC
		nCols= (int)nc_l;
		if(nCols<1)
		{
			printf("Usage: Columns should be greater than 0, received %d.\n",nCols);
			done= true;
		}

		strcpy(filename, argv[4]);
		//now we have the command line
		//Let's read the input file
		FILE* fp = fopen(filename, "r"); //we try to read it
		if (fp != false)
		{//it opened, yay!
			printf("Opened %s.\n",filename);
			ok2 = true;
			//can we read the data?
			char oRow[100];
			//Let's find out how many lines there are, and
			//find out the maximum width
			bool doneReadingFile = false;
			int prevWidth=0;
			while(!doneReadingFile)
			{
				oRow[0]='\0';
				fscanf(fp, "%s", oRow);


				if(strlen(oRow)!=0)
				{
					howManyLinesInFile++;

					if (strlen(oRow)>prevWidth){
						maximumWidth=strlen(oRow);// update maximumWidth

					}
					else{
						maximumWidth=prevWidth;
					}

				}
				else
				{
					doneReadingFile = true;
					fclose(fp);
				}
			}
			if(howManyLinesInFile>nRows || maximumWidth>nCols){
						puts("Error: the dimensions of board should match dimensions of file.");
			}


		}//can read filename


		else
		{
			puts("Cannot find that file,");
			done = true;
		}

		if(!done)
		{
			char A[nRows][nCols];
			char B[nRows][nCols];
			char C[nRows][nCols];
			char* old_p=&A[0][0];
			char* new_p=&B[0][0];
			char* other_p=&C[0][0];

			for(int row = 0; row< nRows; row++)
			{
				for(int col = 0; col<nCols; col++)
				{
					//initialize elements of A, B and C
					A[row][col]='o';
					B[row][col]='o';
					C[row][col]='o';


				}
			}
			FILE* fp = fopen(filename, "r");//we read it before, we expect we can read it again
			readFileIntoArray(nRows, nCols, howManyLinesInFile,  maximumWidth, old_p, fp);

			printf("\n");

			int howManyGens = generate(gens,  nRows,  nCols,  old_p, new_p, other_p, print, pause);
			printf("Ran %d generations\n", howManyGens);
		}

	}//not done
	results = !done;
	return results;

}
/**
 * PlayOne carries out one generation
 * @param unsigned int nr, the number of rows in the petri dish
 * @param unsigned int nc, the number of columns in the petri dish
 * @param char* Old, the location of the upper left of starting petri dish
 * @param char* New, the location of the upper left of the ending petri dish
 * @return There is none, because results are in New array
 */
void PlayOne (unsigned int nr, unsigned int nc, char* Old, char* New)
{
	int nRows = nr;
	int nCols = nc;
	//loop over all locations in the new dish
	//figure out whether occupied or not
	for(int row=0;row<nRows;row++)
	{
		for(int col=0; col<nCols; col++)
		{
			//There are three rules,
			// use occupied in old
			//use neighbors in old
			bool occupied = true;
			occupied = 	(getLetter(row,col,nCols, Old)=='x');

			if(occupied
					&&((HowManyNeighbors(row, col, nRows, nCols, Old)<2)
							|| (HowManyNeighbors(row, col, nRows, nCols, Old)>3)))
			{//Death rule
				*(New + (row * nCols) + col)='o';
			}
			else if(occupied)
			{//Survival rule
				*(New + (row * nCols) + col)='x';
			}
			else if(HowManyNeighbors(row, col, nRows, nCols, Old)==3)
			{//Birth rule
				*(New + (row * nCols) + col)='x';

			}
			else
			{
				*(New + (row * nCols) + col)='o';
			}
		}
	}
}
/*
 * usage prints the instructions to provide command to proceed Game of Life if not provided properly
 * @param void, no arguments needed
 * @return void, just prints the instructions
 */
void usage(void)
{
	puts("Usage: HW2 NR NC gens input [print] [pause]");
}
/*
 * getLetter returns the letter at a specified position on the board
 * @param int row, the current row of the board
 * @param int col, the current column of the board
 * @param int nCols, the total number of columns of the board
 * @param char* Old, the previous generation board
 * @return char, 'x' for occupied, 'o' for unoccupied
 */
char getLetter(int row, int col, int nCols, char* Old)
{
	return *(Old+ (row*nCols)+col);
}
/*
 * HowManyNeighbors calculates the neighbors of the specified position on board
 * @param int row, the current row of the board
 * @param int col, the current column of the board
 * @param int nRows, the total number of rows of the board
 * @param int nCols, the total number of columns of the board
 * @param char* Old, the previous generation board
 * @return int, the number of adjacent neighbors in all 8 directions
 */
int HowManyNeighbors(int row, int col, int nRows, int nCols, char* Old)
{
	int howManyN = 0;
	//there could be as many as 8 neighbors
	//cells on an edge or corner have fewer neighbors
	//we will search for neighbors clockwise from NorthWest
	if (row>0)
	{
		if(col>0)
		{
			if(getLetter(row-1, col-1,nCols, Old)=='x')//NW
			{
				howManyN++;
			}
		}
		if(getLetter(row-1, col,nCols, Old)=='x')//N
		{
			howManyN++;
		}
		if(col<(nCols-1))
		{
			if(getLetter(row-1, col+1,nCols, Old)=='x')//NE
			{
				howManyN++;
			}
		}
	}//can look north
	if(col>0)
	{
		if(getLetter(row, col-1,nCols, Old)=='x')//W
		{
			howManyN++;
		}
	}
	if(col<(nCols-1))
	{
		if(getLetter(row, col+1,nCols, Old)=='x')//E
		{
			howManyN++;
		}
	}
	if(row<nRows-1)
	{
		if(col>0)
		{
			if(getLetter(row+1, col-1,nCols, Old)=='x')//SW
			{
				howManyN++;
			}
		}
		if(getLetter(row+1, col,nCols, Old)=='x')//S
		{
			howManyN++;
		}
		if(col<(nCols-1))
		{
			if(getLetter(row+1, col+1,nCols, Old)=='x')//SE
			{
				howManyN++;
			}
		}
	}//can look south

	return howManyN;
}
/*
 * readFileIntoArray converts a  file's data into an array
 * @param int nRows, the total number of rows of the board
 * @param int nCols, the total number of columns of the board
 * @param int howManyLinesInFile, the number of lines in the file
 * @param int maximumWidth, the max length of a line
 * @param char* ar_p, pointer to the array which stores that content of the file
 * @param FILE* fp,pointer to the file which is to be read in the array
 * @return void, nothing as it updates the given array
 */
void readFileIntoArray(int nRows, int nCols, int howManyLinesInFile, int maximumWidth, char* ar_p, FILE* fp)
{
	for(int row = 0; row< nRows; row++)
	{
		for(int col = 0; col<nCols; col++)
		{
			*(ar_p+(row*nCols)+col) = 'o';

		}
	}//initializing array with unoccupied spaces

	for(int frow=0; frow< howManyLinesInFile; frow++)
	{
		char fromFile[maximumWidth];

		for(int i = 0; i<maximumWidth; i++)
		{
			fromFile[i]='o';
		}
		fscanf(fp, "%s", fromFile);
		for(int fcol=0; fcol<maximumWidth; fcol++)
		{
			if(fromFile[fcol]=='x')
			{
				int targetRow = frow+(nRows-howManyLinesInFile)/2;
				int targetCol = fcol+(nCols-maximumWidth)/2;
				*(ar_p+(targetRow*nCols)+targetCol) = 'x';
			}
		}
	}// reading from file line by line and then writing it to array, centering it
}
/*
 * generate plays the game for the given amount of generations until the terminal conditions are met
 * @param int gens, the number of generations to be played
 * @param int nRows, the total number of rows of the board
 * @param int nCols, the total number of columns of the board
 * @param char* old_p, the pointer to the last generation board
 * @param char* new_p, the pointer to the new generation board
 * @param char* other_p, the pointer to the generation before old
 * @param char print, the character for deciding whether to print the board after every generation
 * 'y' for yes, 'n' for no
 * @param char pause, the character for deciding whether to pause the board after every generation
 * 'y' for yes, 'n' for no
 * @return int, the number of generations it generated
 */
int generate(int gens,  int nRows,  int nCols,  char* old_p, char* new_p, char* other_p, char print, char pause)
{
	int g = 0;
	bool allOrganismsDead = false;
	bool patternRepeated = false;
	bool done = false;
	bool firstTime=true;

	for(int gensDone = 0; !done && (gensDone<gens); gensDone++)
	{
		if(!anyX(old_p, nRows, nCols))
		{//all organisms are dead
			allOrganismsDead =  true;
			done = true;
			puts("All organisms dead.");
			printThis(nRows, nCols, old_p);
		}
		PlayOne(nRows, nCols, old_p, new_p);
		g++;
		if(sameContent(old_p,new_p,nRows,nCols))
		{
			patternRepeated = true;
			done = true;
			puts("Pattern repeated in one generation.");
			printThis(nRows, nCols, old_p);
		}
		if(firstTime)
		{
			firstTime = false;
		}
		else
		{
			if(sameContent(other_p,new_p,nRows,nCols)) //what goes here?
			{
				patternRepeated = true;
				puts("Pattern repeated after two generations.");
				printThis(nRows, nCols, other_p);
				done= true;

			}
		}
		if(!done)
		{
			if(print=='y')
			{
				puts("New generation");
				printThis(nRows, nCols, new_p);
			}
			if(pause=='y')
			{
				puts("Paused waiting for input.");
				getc(stdin);//just waits for user input
			}

			char* temp=old_p;
			old_p=new_p;
			new_p=other_p;
			other_p=temp;
		}


	}//end of generations

	return g;
}
/*
 * anyX checks for the presence of any occupied cell on the board
 * @param char* arr, the pointer to the array representing the board
 * @param int nRows, the total number of rows of the board
 * @param int nCols, the total number of columns of the board
 * @return bool, true for presence of any 'x', false otherwise
 */
bool anyX(char* arr, int nRows, int nCols)
{
	bool any = false;
	for(int row=0; !any && (row<nRows); row++)
	{
		for(int col=0; !any && (col< nCols); col++)
		{
			if(getLetter(row,col,nCols,arr)=='x')
			{
				any=true;//if any element is 'x' then set to true

			}
		}
	}
	return any;
}
/*
 * sameContent checks whether two given boards are equal or not
 * @param char* one_p, the first board
 * @param char* another_p, the second board
 * @param int nRows, the total number of rows on the board
 * @param int nCols, the total number of columsn on the board
 * @return bool, true if they are same, false otherwise
 */
bool sameContent(char* one_p, char* another_p, int nRows, int nCols)
{
	bool same = true; //for all the comparisons that have been made so far

	for(int row=0; same && (row<nRows); row++)
	{
		for(int col=0; same && (col< nCols); col++)
		{
			if(getLetter(row,col,nCols,one_p)!=getLetter(row,col,nCols,another_p))
			{
				same=false;// if any element is different, set to false
			}
		}
	}
	return same;

}
/*
 * printThis prints out the current board
 * @param int nRows, the total number of rows of the board
 * @param int nCols, the total number of columns of the board
 * @param  char* arr, the pointer to the board to be printed
 * @return void, just prints the board
 */
void printThis(int nRows, int nCols, char* arr)
{
	for(int row=0;row<nRows;row++)
	{
		for(int col=0;col<nCols;col++)
		{
			char x = getLetter(row,col,nCols,arr);
			if(x=='x'){
				printf("%c",x);// if 'x' print 'x'
			}
			else{
				printf(" ");// else print ' ' for 'o'
			}


		}
		printf("\n");
	}
}
