/** mystruct.h
 * @author Suryansh Goyal
 * Sample structs
*/

// Struct definition:

// Maximum number of characters in an employee name
#define MAX_NAME (99)

struct Employee {
	int birth_year; // Year the employee was born
	int start_year; // When employee started with the company.
	char name[MAX_NAME + 1];
};

// Function prototype(s):
struct Employee *makeEmployee(int birth, int start, const char* name);
void printEmployee(struct Employee *e);
struct Employee* makeRandomEmployee();
int randint(int max);
char randChar();
char* randStr(int size);
struct Employee** makeArr(int count);
void printEmployeesArr(struct Employee** arr, int count);
struct Employee** dupArr(struct Employee** arr, int count);
void deAlloc(struct Employee** arr,int count);
struct Employee** dupArr1(struct Employee** arr, int count);
