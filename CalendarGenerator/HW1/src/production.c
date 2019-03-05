/*
 * production.c
 *
 *  Created on: Nov 3, 2018
 *      Author: Suryansh Goyal
 *      @author Student's name goes here
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "production.h"
#include <math.h>


/** Your production code goes in this function.
 *
 * @param argc Number of words on the command line
 * @param argv Array of pointers to character strings representing the words on the command line.
 * @return true if Program was able to print a calendar.
 *         false if User entered bad input.
 */

bool production(int argc, char* argv[])
{
	bool results = false;
	bool done = false;
	//get the year, Usage as needed.
	int year = -1;
	puts("CALENDAR");
	if(argc<2)
	{
		puts("Enter a year");
		scanf("%d",&year);
		if(year<1752)
		{
			printf("Usage: Year should be greater than 1751, received %d.\n",year);
			done = true;
		}
	}
	else
	{
		char* ptr=0;
		long year_l = strtol(argv[1],&ptr,10);
		year = (int)year_l;
		if(year<1752)
		{
			printf("Usage: Year should be greater than 1751, received %d.\n",year);
			done = true;
		}
	}
	if(!done)
	{
		//print month name
					//print the days of the week text
					//print the weeks

		char months[12][10]={"January","February","March","April","May","June","July","August","September","October","November","December"};
		char weekdays[7][4]={"Sun","Mon","Tue","Wed","Thu","Fri","Sat"};

		for(int m=0;m<12;m++){
			printf("%s\n",months[m]);//print month

			for(int i=0;i<7;i++){
				printf("%s",weekdays[i]);//print day name
				if(i<6){
					printf("%2s", "");

				}
			}
			printf("\n");

			int spaces= calculate_day_of_week(1,m,year);
			for(int j=0;j<spaces;j++){
				printf("%5s", "");//blank spaces
			}
			int counter=spaces;
			int days= calculate_days_in_month(year, m);

			for(int day=1;day<days+1;day++){
				printf("%3d",day);
				counter++;
				if(counter==7 || day==days){
					counter=0;
					printf("\n");
				}
				else{
					printf("%2s","");
				}

			}
				if(counter!=0)
					printf("\n");
		}


	}
	if(!done)
	{
		results=true;
	}
	return results;
}


/** Calculates how many days are in a given month for a given year.
 * @param day Day of the month, counting from 1.
 * @param month Range 0 through 11, where January = 0.
 * @param year The year.
 * @return -1 for invalid input (e.g., year < 1752, month out of range,
 *            day < 1 or > appropriate for that month & year
 *         0 through 6, where Sunday = 0.
 *
 */
int calculate_days_in_month(int year, int month)
{
	if (year<1752){
		return -1;
	}
	else if(month==1){
		if (is_leap_year(year)){
			return 29;
		}
		else{
			return 28;
		}
	}
	else if(month<=6 && month>=0){
		if(month%2==0){
			return 31;
		}
		else{
			return 30;
		}
	}
	else if(month>6 && month<=11){
		if(month%2==0){
			return 30;
		}
		else{
			return 31;
		}
	}
	else{
		return -1;
	}
}
/** Test if a given year is a leap year or not.
 * @param year The year we are testing
 * @return 1 if it is a valid leap year.
 *         0 if a valid year, but not a leap year.
 *        -1 if not a valid year (i.e. before the calendar rule changed in 1752).
 */

int is_leap_year(int year)
{
	if (year<1752){
		return -1;
	}
	else if (year%4==0 && year%100==0){
		if(year%400==0){
			return 1;
		}
		else{
			return 0;
		}

	}
	else if (year%4==0){
		return 1;
	}
	else{
		return 0;
	}



}
/** Determines what day of the week a particular date falls on.
 * @param year The year we are checking.
 * @param month The month we are checking. Range 0 through 11, where January = 0.
 * @return Day of the week. Range 0 through 6, where Sunday = 0.
 *         -1 if invalid input (e.g., year < 1752, month out of range).
 */
int calculate_day_of_week(int day, //first day of month is 1
		int month, //uses 0 for January
		int year)
{//invalid input gets a -1 answer

	int d=day;
	int m;
	int Y;
	if (month<0){
		return -1;
	}
	else if (year<1752){
		return -1;
	}
	else if (day < 1 || day > calculate_days_in_month(year, month)){
		return -1;
	}
	else if (month>=2){
		m=month-1;
		Y=year;
	}
	else if (month>=0 && month<2) {
		m=month+11;
		Y=year-1;
	}
	int y=Y%100;
	int c=Y/100;
	double f= d+floor(2.6*m-0.2)+y+floor(y/4)+floor(c/4)-2*c;
	int w= (int)f%7;


	if(w<0){
		w=w+7;
	}

	return w;
}


