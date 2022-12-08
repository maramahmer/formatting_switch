#include <stdio.h>
/* Name: Maram Ahmer
   Student Number: 250963151
   This code will take a 10 digit phone number and format it in the way the user chooses.
*/
int main(void){
	// initialize the variables and scan the phone number, making sure to allow for only 10 digits
	int area_code, phone_middle, phone_end;
	char option;
	printf("Input Phone Number: ");
	scanf("%3d%3d%4d", &area_code, &phone_middle, &phone_end);


	printf("Format Options:\nA) Local\nB) Domestic\n");
	printf("C) International\nD) Odd\n");
	printf("Input Option: ");
	scanf(" %c", &option);
	
	// use the switch statement to format the number based on the user input, exit with error if invalid input
	switch(option){
		case 'A':
		case 'a':
			printf("%d-%d\n", phone_middle, phone_end);
			break;
		case 'B':
		case 'b':
			printf("(%d) %d-%d\n", area_code, phone_middle, phone_end);
			break;
		case 'C':
		case 'c':
			printf("+1-%d-%d-%d\n", area_code, phone_middle, phone_end);
			break;
		case 'D':
		case 'd':
			printf("%6.4d%6.4d%6.4d\n", area_code, phone_middle, phone_end);
			break;
		default:
			printf("Error: Invalid Option!\n");
			return 1;
	}
	return 0;
}
