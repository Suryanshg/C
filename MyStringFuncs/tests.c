/*
 * tests.c
 *
 *  Created on: Feb 14, 2019
 *      Author: Suryansh Goyal
 */

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "tests.h"
#include "production.h"
#include "mystring.h"

bool tests(void)
{
	bool ok = false;
	bool ok1 = testMystrlen1();

	if (ok1) {
		puts("mystrlen1() passed.");
	}

	bool ok2 = testMystrlen2();
	if (ok2) {
		puts("mystrlen2() passed.");
	}

	bool ok3 = testMystrdup();
	if (ok3) {
		puts("mystrdup() passed.");
	}

	bool ok4 = testMystrncpy() && testMystrncpy1();
	if (ok4) {
		puts("mystrncpy() passed.");
	}

	bool ok5 = testMystrcpy() && testMystrcpy1();
	if (ok5) {
		puts("mystrcpy() passed.");
	}

	bool ok6 = testMystrncat() && testMystrncat1();
	if (ok6) {
		puts("mystrncat() passed.");
	}

	bool ok7 = testMystrcat();
	if(ok7){
		puts("mystrcat() passed.");
	}

	bool ok8= testMystrndup();
	if(ok8){
		puts("mystrndup() passed.");
	};

	ok = ok1 && ok2 && ok3 && ok4 && ok5 && ok6 && ok7; // Did all tests pass?
	return ok;
}

/** Tests the mystrlen1() function by comparing it to how the standard strlen() works..
 * @return true if it passes all tests.
 */
bool testMystrlen1(void) {
	bool ok = false; // True if all tests passed
	bool ok1 = false; // Individual test results
	bool ok2 = false;

	char* s1 = "Some sample string."; // String we will take the length of.
	size_t l1a = strlen(s1); // Get the lengths with the two functions.
	size_t l1b = mystrlen1(s1);
	if (l1a == l1b) {
		ok1 = true;
	}

	char* s2 = ""; // Empty string.
	size_t l2a = strlen(s2); // Get the lengths with the two functions.
	size_t l2b = mystrlen1(s2);
	if (l2a == l2b) {
		ok2 = true;
	}

	ok = ok1 && ok2;
	return ok;
}


/** Tests the mystrlen2() function by comparing it to how the standard strlen() works..
 * @return true if it passes all tests.
 */
bool testMystrlen2(void) {
	bool ok = false; // True if all tests passed
	bool ok1 = false; // Individual test results
	bool ok2 = false;

	char* s1 = "Some sample string."; // String we will take the length of.
	size_t l1a = strlen(s1); // Get the lengths with the two functions.
	size_t l1b = mystrlen2(s1);
	if (l1a == l1b) {
		ok1 = true;
	}

	char* s2 = ""; // Empty string.
	size_t l2a = strlen(s2); // Get the lengths with the two functions.
	size_t l2b = mystrlen2(s2);
	if (l2a == l2b) {
		ok2 = true;
	}

	ok = ok1 && ok2;
	return ok;
}

/** Test mystrdup() function by comparing it to the standard strdup().
 * @return true if it passes all tests.
 */
bool testMystrdup() {
	bool ok1 = false;

	char s1[] = "Some sample string."; // String we will duplicate.
	char* s2 = strdup(s1); // Copy it using standard function
	char* s3 = mystrdup(s1); // Copy it using my function

	if (strcmp(s2, s3) == 0) { // Same result!
		ok1 = true;
	}

	char* s4 = "Some other string."; // Another string for testing
	printf("Address of a local variable ok1, on stack:   %p\n", &ok1);
	printf("Address of original string, on stack:        %p\n", s1);
	printf("Address of first duplicate string, on heap:  %p\n", s2);
	printf("Address of second duplicate string, on heap: %p\n", s3);
	printf("Address of other string, on heap?:           %p\n", s4);

	bool ok = ok1;
	return ok;
}

/** Test mystrndup() function by comparing it to the standard strdup().
 * @return true if it passes all tests.
 */
bool testMystrndup() {
	bool ok1 = false;

	char s1[] = "Some sample string."; // String we will duplicate.
	char* s2 = strndup(s1,6); // Copy it using standard function
	char* s3 = mystrndup(s1,6); // Copy it using my function

	if (strcmp(s2, s3) == 0) { // Same result!
		ok1 = true;
	}
	return ok1;
}

/*
 * Test mystrcpy() function.
 * @return true if pass, false if fail.
 */
bool testMystrcpy() {
	bool ok1 = false;
	bool ok2 = false;

	char s1[] = "Some sample string."; // String we will copy.
	char s2[30]; // Empty string we will copy into

	char* s3 = mystrcpy(s2, s1); // Copy the string
	if (strcmp(s1, s2) == 0) { // Does original equal copy?
		ok1 = true; // Yes!
	}

	if (s3 == s2) { // Is the return value correct?
		ok2 = true; // Yes!
	}

	bool ok = ok1 && ok2;
	return ok;
}

/*
 * Test mystrcpy1() function.
 * @return true if pass, false if fail.
 */
bool testMystrcpy1() {
	bool ok1 = false;
	bool ok2 = false;

	char s1[] = "Some sample string."; // String we will copy.
	char s2[10]; // Empty string we will copy into

	char* s3 = mystrcpy(s2, s1); // Copy the string
	char* s4 = strcpy(s2,s1);
	if (strcmp(s2, s4) == 0) { // Does original equal copy?
		ok1 = true; // Yes!
	}

	if (s3 == s4) { // Is the return value correct?
		ok2 = true; // Yes!
	}

	bool ok = ok1 && ok2;
	return ok;
}

/*
 * Test mystrncpy() function.
 * @return true if pass, false if fail.
 */

bool testMystrncpy() {
	bool ok1 = false;
	char s1a[] = "012345678901234567890123456789"; // A long string
	char s2a[] = "ABCDEF"; // A short string we will copy into it.
	char* s3a = strncpy(s1a, s2a, 6); // The result

	printf("In testMystrncpy(): s3a = /%s/\n", s3a);

	char s1b[] = "012345678901234567890123456789"; // A long string
	char s2b[] = "ABCDEF"; // A short string we will copy into it.
	char* s3b = mystrncpy(s1b, s2b, 6); // The result

	if (strcmp(s3a, s3b) == 0) {
		ok1 = true;
	}

	return ok1;
}

/*
 * Test mystrncpy1() function.
 * @return true if pass, false if fail.
 */

bool testMystrncpy1() {
	bool ok1 = false;
	char s1a[] = "012345678901234567890123456789"; // A long string
	char s2a[] = "ABCDEF"; // A short string we will copy into it.
	char* s3a = strncpy(s1a, s2a, 8); // The result

	printf("In testMystrncpy(): s3a = /%s/\n", s3a);

	char s1b[] = "012345678901234567890123456789"; // A long string
	char s2b[] = "ABCDEF"; // A short string we will copy into it.
	char* s3b = mystrncpy(s1b, s2b, 8); // The result

	if (strcmp(s3a, s3b) == 0) {
		ok1 = true;
	}

	return ok1;
}

/*
 * Test mystrncat() function.
 * @return true if pass, false if fail.
 */
bool testMystrncat() {
	bool ok1 = false;
	bool ok2 = false;

	char s1a[] = "012345678901234567890123456789"; // A long string
	char s2a[] = "ABCDEF"; // A short string we will copy into it twice.
	char* s3a = strcpy(s1a, s2a);
	char* s4a =	strncat(s1a, s2a, 6); // The result

	printf("In testMystrncat(): s1a = /%s/\n", s1a);
	printf("In testMystrncat(): s4a = /%s/\n", s4a);

	char s1b[] = "012345678901234567890123456789"; // A long string
	char s2b[] = "ABCDEF"; // A short string we will copy into it twice.
	char* s3b = strcpy(s1b, s2b);
	char* s4b = mystrncat(s1b, s2b, 6); // The result

	if (strcmp(s1a, s1b) == 0) {
		ok1 = true;
	}

	if (strcmp(s4a, s4b) == 0) {
		ok2 = true;
	}

	return ok1 && ok2;
}

/*
 * Test mystrncat1() function.
 * @return true if pass, false if fail.
 */
bool testMystrncat1() {
	bool ok1 = false;
	bool ok2 = false;

	char s1a[] = "012345678901234567890123456789"; // A long string
	char s2a[] = "ABCDEF"; // A short string we will copy into it twice.
	char* s3a = strcpy(s1a, s2a);
	char* s4a =	strncat(s1a, s2a, 4); // The result

	printf("In testMystrncat(): s1a = /%s/\n", s1a);
	printf("In testMystrncat(): s4a = /%s/\n", s4a);

	char s1b[] = "012345678901234567890123456789"; // A long string
	char s2b[] = "ABCDEF"; // A short string we will copy into it twice.
	char* s3b = strcpy(s1b, s2b);
	char* s4b = mystrncat(s1b, s2b, 4); // The result

	if (strcmp(s1a, s1b) == 0) {
		ok1 = true;
	}

	if (strcmp(s4a, s4b) == 0) {
		ok2 = true;
	}

	return ok1 && ok2;
}
/*
 * Test mystrcat() function.
 * @return true if pass, false if fail.
 */
bool testMystrcat() {
	bool ok1 = false;
	bool ok2 = false;

	char s1a[] = "012345678901234567890123456789"; // A long string
	char s2a[] = "ABCDEF"; // A short string we will copy into it twice.
	char* s3a = strcpy(s1a, s2a);
	char* s4a =	strcat(s1a, s2a); // The result

	printf("In testMystrcat(): s1a = /%s/\n", s1a);
	printf("In testMystrcat(): s4a = /%s/\n", s4a);

	char s1b[] = "012345678901234567890123456789"; // A long string
	char s2b[] = "ABCDEF"; // A short string we will copy into it twice.
	char* s3b = strcpy(s1b, s2b);
	char* s4b = mystrcat(s1b, s2b); // The result

	if (strcmp(s1a, s1b) == 0) {
		ok1 = true;
	}

	if (strcmp(s4a, s4b) == 0) {
		ok2 = true;
	}

	return ok1 && ok2;
}

