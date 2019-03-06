/** mystruct.c
 * @author Suryansh Goyal
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "mystruct.h"

/** Allocates an Employee struct and fills in its fields
 * @param birth Year the employee was born.
 * @param start Year the employee started with the company.
 * @param name String containing employee's name
 * @return Pointer to Employee struct, newly allocated from the heap.
 */
struct Employee* makeEmployee(int birth, int start, const char *name) {
	struct Employee* e = (struct Employee *) malloc (sizeof (struct Employee));
	struct Employee* e_ptr=e;
	e->birth_year = birth;
	e->start_year = start;
	strncpy(e->name, name, MAX_NAME);
	e->name[MAX_NAME] = '\0';
	return e_ptr; // Replace this with a pointer to the allocated struct
}

/** Prints the given employee
 * @param struct Employee *e, the employee whose info is to be printed
 * @ return void, just prints the details of the employee
 */
void printEmployee(struct Employee *e) {
	// Must fill in
	printf("Birth year = %d\n",e->birth_year);
	printf("Starting year = %d\n",e->start_year);
	printf("Name = %s\n",e->name);
}

/* Generates a new random employee
 * @ return, a pointer to the newly created employee
 */
struct Employee* makeRandomEmployee(){

	int birth=randint(9)+10*randint(9)+100*randint(9)+1000*randint(9);
	int start=randint(9)+10*randint(9)+100*randint(9)+1000*randint(9);
	char* name=randStr(randint(MAX_NAME));
	struct Employee* e_ptr= makeEmployee(birth,start,name);
	return e_ptr;
}

/*Generates a random integer between 0 and max both inclusive
 * @param int max, the max limit of range of integers
 * @return int, an integer between 0 and max both inclusive
 */
int randint(int max){
	int x=rand();
	return x%(max+1);
}
/*Generates a random char
 * @ return char, any alphabetical char
 */
char randChar(){
	char alpha[]={'A','B','C','D','E','F','G','H','I','J','K','L','M',
			      'N','O','P','Q','R','S','T','U','V','W','X','Y','Z',
				  'a','b','c','d','e','f','g','h','i','j','k','l','m',
				  'n','o','p','q','r','s','t','u','v','w','x','y','z'};

	return alpha[randint(51)];
}
/*Generates a random string of n chars terminated by null
 * @param int size, the size of the string
 * @return char* , pointer to the string terminated by null
 */
char* randStr(int size){
	char* str = (char*) malloc(size + 1);
	char* str_ptr=str;
	int i=0;
	while (i<size){
		*str=randChar();
		i++;
		str++;
	}
	str[i]='\0';
	return str_ptr;
}

/*Allocates an array which can store given number of Employee Structs
 * @param int count, the number of pointers to structs
 * @return an array of pointers to structs of specified size
 */
struct Employee** makeArr(int count){
	struct Employee** arr=(struct Employee**)malloc(count*sizeof(struct Employee));
	for(int i=0;i<count;i++){
		arr[i]=makeRandomEmployee();
	}
	return arr;
}
/*Prints out all the pointers in the specified array
 * @param arr, array of pointers to be printed
 * @param count, the size of the array
 * @return void, just prints the pointers
 */
void printEmployeesArr(struct Employee** arr, int count){
	for(int i=0;i<count;i++){
		printEmployee(arr[i]);
	}
}
/*duplicates the array of pointers by duplicating the pointers
 *@param arr, array of pointers to be duplicated
 *@param count, the size of the array
 *@return a new duplicated array
 */
struct Employee** dupArr(struct Employee** arr, int count){
	struct Employee** newArr=(struct Employee**)malloc(count*sizeof(struct Employee));
	for(int i=0;i<count;i++){
		newArr[i]=arr[i];
	}
	return newArr;
}
/*De-Allocates the all the structs pointed to
 * @param arr, the array of pointers to be de-allocated
 * return void
 */
void deAlloc(struct Employee** arr,int count){
	for(int i=0;i<count;i++){
		free(arr[i]);
	}
}
/*duplicates the array of pointers by duplicating the structs
 * @param arr, array of pointers to be duplicated
 * @param count, the size of the array
 * @return a new duplicated array
 */
struct Employee** dupArr1(struct Employee** arr, int count){
	struct Employee** newArr=(struct Employee**)malloc(count*sizeof(struct Employee));
	for(int i=0;i<count;i++){
		newArr[i]=makeEmployee(arr[i]->birth_year,arr[i]->start_year,arr[i]->name);
	}
	return newArr;
}
