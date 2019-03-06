/*
 * tests.c
 *
 *  Created on: Feb 3, 2019
 *      Author: Suryansh Goyal
 */
#include <stdbool.h>
#include "tests.h"
#include "production.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h> //for strncmp

bool tests(void)
{
	bool results=false;
	puts("During tests");
	bool ok1 = testReadInput();
	if(ok1)puts("Found and read the test file.");
	bool ok2 = testMakeArrays();
	if(ok2)puts("Was able to allocate the arrays ok.");
	bool ok3 = testPlayOne();
	if(ok3)puts("playOne is ok.");
	bool ok4 = testSameContent();
	if(ok4)puts("sameContent is ok");
	bool ok5 = testAnyX();
	if(ok5)puts("anyX is ok");
	bool ok6 = testPrintThis();
	if(ok6)puts("printThis is ok");
	bool ok7 = testGetLetter();
	if(ok7)puts("getLetter is ok");
	bool ok8 = testHowManyNeighbors();
	if(ok8)puts("HowManyNeighbors is ok");
	bool ok9 = testReadFileIntoArray();
	if(ok9)puts("readFileIntoArray is ok");
	bool ok10 = testGenerate();
	if(ok10)puts("generate is ok");
	puts("end of tests");
	results = ok1 && ok2 && ok3 && ok4 && ok5 && ok6 && ok7 && ok8 && ok9 && ok10;
	printf("tests returning %d.\n",results);
	return results;
}
bool testReadInput(void)
{
	//the plan is:
	//create a file
	//make sure it can be opened.
	//try a file that should not exist
	//check that we notice it does not exist

	bool results = false;
	bool ok1 = false;
	bool ok2 = false;
	bool ok3 = false;
	//
	//Here goes: create a file
	FILE* fp;
	fp = fopen("/tmp/LifeInput.txt", "w"); //we write it first for later reading
	if (fp != false)
	{//it opened, yay!
		//file containing a sequence of lines,
		//each consisting of a sequence of 'x' and 'o' characters,
		//indicating the occupied and unoccupied cells
		//of the initial configuration, e.g.
		//oxo
		//xox
		//xox
		//oxo
		int w1 = fprintf(fp, "oxo\n");//returns the number of chars excluding null
		int w2 = fprintf(fp, "xox\n");
		int w3 = fprintf(fp, "xox\n");
		int w4 = fprintf(fp, "oxo\n");
		if ((w1 == w2) && (w2 == w3) && (w3 == w4) && (w4 == 4))
		{
			ok1 = true;
		}
		fclose(fp);
	}
	fp = fopen("/tmp/LifeInput.txt", "r"); //we try to read it
	if (fp != false)
	{//it opened, yay!
		ok2 = true;
		//can we read the correct data?
		char oRow[4]; //test case, we know a string of 3 chars terminated by null
		int count =  fscanf(fp, "%s", oRow);
		//printf("First row is %s\n", oRow);
		if(0==strncmp(oRow, "oxo", 4))//0 means match
		{//got the right data
			ok3 = true;
		}
		fscanf(fp, "%s", oRow);
		//printf("Second row is %s\n", oRow);
		if(0==strncmp(oRow, "xox", 4))
		{//got the right data
			ok3 = true;
		}
		fscanf(fp, "%s", oRow);
		//printf("Third row is %s\n", oRow);
		if(0==strncmp(oRow, "xox", 4))
		{//got the right data
			ok3 = true;
		}
		fscanf(fp, "%s", oRow);
		//printf("Fourth row is %s\n", oRow);
		if(0==strncmp(oRow, "oxo", 4))
		{//got the right data
			ok3 = true;
		}
	}
	results = ok1 && ok2 && ok3;
	return results;
}
bool testMakeArrays(void)
{
	bool results = false;
	bool ok1 = false;
	//we need to allocate and populate arrays
	//In this test case we set our arrays to 4 rows x3 columns
	int nRows = 4;
	int nCols = 4;
	char boardBefore[4][4]={
			{'o','x','o','\0'},
			{'x','o','x','\0'},
			{'x','o','x','\0'},
			{'o','x','o','\0'}
	};

	char boardAfter[nRows][nCols];
	//here's the test
	for(int row=0;row<nRows;row++)
	{
		for(int col=0; col<nCols; col++)
		{
			boardAfter[row][col]=boardBefore[row][col];
		}
	}
	ok1 = true;
	for(int row=0;row<nRows;row++)
	{
		for(int col=0; col<nCols; col++)
		{
			if (boardAfter[row][col]!=boardBefore[row][col])
			{
				ok1=false;
			}
		}
	}

	results = ok1;
	return results;
}
bool testPlayOne(void)
{
	bool results = false;
	bool ok1 = false;
	bool ok2 = false;


	int nRows = 4;
	int nCols = 3;
	char boardBefore[4][3]={
			{'o','x','o'},
			{'x','o','x'},
			{'x','o','x'},
			{'o','x','o'}
	};
	char correctBoardAfter[4][3]={
			{'o','x','o'},
			{'x','o','x'},
			{'x','o','x'},
			{'o','x','o'}
	};

	char boardAfter[nRows][nCols];
	//here's the invocation
	PlayOne(nRows, nCols, (char*)boardBefore, (char*)boardAfter);
	//here's the check
	ok1 = true; //no errors found yet
	for(int row=0;row<nRows;row++)
	{
		for(int col=0; col<nCols; col++)
		{
			if(boardAfter[row][col]!=correctBoardAfter[row][col])
			{//error found
				ok1 = false;
			}
		}
	}
	results = ok1;
	return results;

}
bool testSameContent(void)
{
	bool results=false;
	char A[3][3]={'x','x','x',
			      'x','x','x',
				  'x','x','x'};

	char B[3][3]={'x','x','x',
				      'x','x','x',
					  'x','x','x'};


	results=sameContent(A,B,3,3);



	return results;
}
bool testAnyX(void){
	bool results=false;
	char A[3][3]={'x','x','x',
			      'x','x','x',
				  'x','x','x'};
	results=anyX(A,3,3);

	return results;
}
bool testPrintThis(void){

	char A[3][3]={'x','o','x',
				  'o','x','o',
				  'x','o','x'};
	printThis(3,3,A);

	return true;

}
bool testGetLetter(void){
	char A[3][3]={'x','o','x',
				  'o','x','o',
			      'x','o','x'};
	return getLetter(0,0,3,A)=='x';

}
bool testHowManyNeighbors(void){
	char A[3][3]={'x','o','x',
				  'o','x','o',
				  'x','o','x'};
	return HowManyNeighbors(1,2,3,3,A)==3;

}
bool testReadFileIntoArray(void){
	FILE* fp = fopen("Assignment2_testcases/block.txt", "r");
	char arr[4][4];
	char A[4][4]={'o','o','o','o',
			      'o','x','x','o',
				  'o','x','x','o',
	              'o','o','o','o'};
	readFileIntoArray(4,4,4,4,arr,fp);
	return sameContent(arr,A,4,4);


}
bool testGenerate(void){

	FILE* fp = fopen("Assignment2_testcases/acorn.txt", "r");
	char old[10][10];
	char new[10][10];
	char other[10][10];
	readFileIntoArray(10,10,3,8,old,fp);
	return generate(100,10,10,old,new,other,'n','n')==55;


}
