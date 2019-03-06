/*
 * tests.c
 *
 *  Created on: Feb 14, 2019
 *      Author:Suryansh Goyal
 */


#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "tests.h"
#include "production.h"
#include "mystruct.h"

bool tests(void)
{
	bool ok = false;

	bool ok1 = testPrintEmployee();
	if (ok1) {
		puts("printEmployee() passed.");
	}

	bool ok2 = testMakeEmployee();
	if (ok2) {
		puts("makeEmployee() passed.");
	}

	bool ok3 = testRandInt();
	if (ok3){
		puts("randint() passed.");
	}

	bool ok4 = testRandChar();
	if (ok4){
		puts("randChar() passed.");
	}
	bool ok5 = testRandStr();
	if (ok5){
		puts("randStr() passed.");
	}
	bool ok6 = testMakeRandomEmployee();
	if (ok6){
		puts("makeRandomEmployee() passed.");
	}
	bool ok7 = testMakeArr();
	if(ok7){
		puts("makeArr() passed");
	}
	bool ok8 = testPrintEmployeeArr();
	if(ok8){
		puts("printEmployeeArr() passed.");
	}
	bool ok9 = testDupArr();
	if(ok8){
		puts("dupArr() passed.");
	}
	bool ok10 = testDupArr1();
	if(ok10){
		puts("dupArr1() passed.");
	}


	ok = ok1 && ok2; // Did all tests pass?
	return ok;
}

/**
 * Test the printEmployee() function by creating a known struct and printing it.
 * @return true. The only way to tell if it succeeds is to look at the output.
 */

bool testPrintEmployee() {

	struct Employee e; // Variable to hold employee
	e.birth_year = 1952; // Put data into numeric fields
	e.start_year = 1999;
	// Copy into string field. Be sure not to overflow it.
	strncpy(e.name, "Mike Ciaraldi", MAX_NAME);
	e.name[MAX_NAME] = '\0'; // Be sure string is terminated.

	printEmployee(&e);

	return true;
}


/** Test the make Employee() function by making an employee with known data and printing it.
 * @return true. The only way to tell if it succeeds is to look at the output.
 */
bool testMakeEmployee() {
	struct Employee *e;

	e = makeEmployee(1952, 1999, "Mike Ciaraldi");
	printEmployee(e);

	return true;
}

bool testRandInt(){
	printf("randint gives %d\n",randint(9));
	return true;

}
bool testRandChar(){
	printf("randChar() gives %c\n",randChar());
	return true;
}
bool testRandStr(){
	printf("randStr() gives %s\n",randStr(5));
	return true;
}
bool testMakeRandomEmployee(){
	struct Employee* e=makeRandomEmployee();
	printEmployee(e);
	free(e);
	return true;
}
bool testMakeArr(){
	struct Employee** arr=makeArr(5);
	return true;
}
bool testPrintEmployeeArr(){
	struct Employee** arr=makeArr(5);
	printEmployeesArr(arr,5);
	return true;
}
bool testDupArr(){
	struct Employee** arr=makeArr(5);
	struct Employee** newArr=dupArr(arr,5);
	printf("Arr:\n");
	printEmployeesArr(arr,5);
	printf("NewArr:\n");
	printEmployeesArr(newArr,5);
	return true;
}
bool testDupArr1(){
	struct Employee** arr=makeArr(5);
	struct Employee** newArr=dupArr1(arr,5);
	printf("Arr:\n");
	printEmployeesArr(arr,5);
	printf("NewArr:\n");
	printEmployeesArr(newArr,5);
	return true;
}
