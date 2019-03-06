/*
 * mystring.c
 *
 *  Created on: Feb 14, 2019
 *      Author: Suryansh Goyal
 */
#include <stdlib.h>
#include "mystring.h"

/**
 * Calculate the length of the string,
 * excluding the terminating null byte ('\0')
 * @param const char* s
 * @return number of characters in the string pointed to by s
 */
size_t mystrlen1(const char* s)
{
	size_t n = 0;

	// Step through the array, counting up until we find the null terminator
	while (s[n] != '\0') {
		n++;
	}

	return n;
}
/**
 * Calculate the length of the string
 * excluding the terminating null byte ('\0')
 * @param const char* s
 * @return number of characters in the string pointed to by s
 */
size_t mystrlen2(const char* s)
{
	size_t n = 0;

	// Keep incrementing the pointer until we find it is pointing to the null terminator
	while (*s != '\0') {
		n++;
		s++;
	}

	/* Note: This could have been written as:
	 while (*(s++)) n++;
	 */

	return n;
}

/** Duplicates a character string into a freshly-allocated block of memory.
 * @param s The string to duplicate.
 * @return Pointer to the new string.
 *         NULL if unable to allocate memory, errno holds the error code.
 */
char* mystrdup(char* s) {
	size_t length = strlen(s); // Length of the original string

	// Allocate a block of memory big enough to hold all the characters of the original string,
	// plus the null terminator.
	char* newstr = (char*) malloc(length + 1);
	if (newstr) { // If allocation succeeded, copy into it
		strcpy(newstr, s);
	}
	return newstr;
}

/** Copies a character string from src to dest
 * @param char* dest, the destination space pointer where we want the string to be copied
 * @param char* src, the source space pointer which we want to be copied
 * @return Pointer to the new dest string
 */
char* mystrcpy(char* dest, char* src) {

	char* A=dest;
	while(*dest++ = *src++){

	}
	return A;
}

/** Copies a character string from src to dest upto 'n' bytes
 * @param char* dest, the destination space pointer where we want the string to be copied
 * @param char* src, the source space pointer which we want to be copied
 * @param size_t n, the maximum number of bytes to be copied, if less than length of src then
 * 					dest doesn't contain "\0", if more than length of src, everything after will be set to "\0"
 *@return Pointer to the new dest string
 */
char* mystrncpy(char* dest, char* src, size_t n) {
	char* A=dest;// starting pointer to the dest
	size_t i=0;// counter
	while(*src!="\0" && i<n){
		*dest=*src;
		src++;
		dest++;
		i++;
	}
	while(i<n){
		*dest='\0';
		dest++;
		i++;
	}
	return A;
}
/** Concatenates dest and src by overwriting the terminator for dest with first element of src
 * @param char* dest, the pointer to the dest string
 * @param char* src, the pointer to the src string
 * @return the pointer to the dest string concatenated by src and terminated by '\0'
 */
char* mystrcat(char* dest, char* src) {
	char* A=dest;
	size_t len=mystrlen1(dest);


	while(*src!='\0'){
		*(dest+len)=*src;
		src++;
		dest++;
	}
	*(dest+len)='\0';
	return A;
}

/** Concatenates src into dest upto n characters by overwriting the terminator
 *  for dest with the first element of src
 *  @param char* dest,the pointer to the dest string
 *  @param char* src, the pointer to the src string
 *  @param size_t n, the maximum number of bytes to be concatenated. The resulting string dest
 *  				will always be null terminated
 *  @return the pointer to the dest string concatenated by src and terminated by '\0'
 *
 */
char* mystrncat(char* dest, char* src, size_t n) {
	char* A=dest;
	size_t len=mystrlen1(dest);

	size_t i=0;
	while(*src!='\0' && i<n){
		*(dest+len)=*src;
		src++;
		dest++;
		i++;
	}
	*(dest+len)='\0';
	return A;
}
/**Duplicates at most n bytes from a string into a freshly allocated memory
 * followed by a null terminator
 * @param char* s, the character string to be duplicated
 * @param size_t n, the maximum number of bytes that is copied to the string
 * @return the pointer to the duplicated version of the string upto n bytes.
 */
char* mystrndup(char* s,size_t n) {

	// Allocate a block of memory big enough to hold all the characters of the original string,
	// plus the null terminator.
	char* newstr = (char*) malloc(n + 1);
	if (newstr) { // If allocation succeeded, copy into it
		mystrncpy(newstr, s,n);
	}
	return newstr;

}
