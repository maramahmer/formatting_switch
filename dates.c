#include <stdio.h>
#include <math.h>
/*
	Name: Maram Ahmer
	Student Number: 250963151
	This program determines which entered dates come later in the calendar
*/

int main(void){
	// initialize the values of the dates, and take the first input

	int month, day, year, largest_month  ,largest_day  ,largest_year  ;
	printf("Enter a date (mm/dd/yy): ");
	scanf("%d/%d/%d", &month, &day, &year);
	char ch;

	if( ( ch = getchar() ) != '\n' && ch != EOF ){
		printf("Error: Invalid date format!\n");
	}
	goto askagain;
	largest_month = month;
	largest_day = day;
	largest_year = year;

	if( month == 00 && day == 00 && year == 00 ){
		printf("Error: At least one date must be input!\n");
		return;
	}

	// check that the dates are valid, and continue to ask for input until the user enters 0/0/0
	while ( month != 0 && ( day != 0 && year != 0 )){
		
		if ( month > 12 || month < 1){
                	printf("Error: Invalid month number!\n");

		}
        	if ( day > 31 || day < 1){
                	printf("Error: Invalid day number!\n");

        	}
        	if ( year > 99 || year < 00 ){
                	printf("Error: Invalid year number!\n");

        	}

		if( largest_month == 00 && largest_day == 00 && largest_year == 00 ){
                	printf("Error: At least one date must be input!\n");
                	return;

        	}
		askagain:
		printf("Enter a date (mm/dd/yy): ");
		scanf("%d/%d/%d", &month, &day, &year);
		
		//clear the input buffer
		char ch;
		if( ( ch = getchar() ) != '\n' && ch != EOF ){
			printf("Error: Invalid date format!\n");
		}

		if ( month > largest_month && day > largest_day && year > largest_year ){
			largest_month = month;
        		largest_day = day;
        		largest_year = year;
			
		}
	}	

	printf("%02d/%02d/%02d is the latest date\n", largest_month, largest_day, largest_year); 
	return 0;
}
