#include <stdio.h>
#include <stdlib.h>
/* Name: Maram Ahmer
   Student Number: 250963151
   This program will calculate the smallest number of change from an input, and display it
*/
void pay_amount(int dollars, int *twenties, int *tens, int *fives, int *toonies, int *loonies){
	//Do some error checking on the number to ensure that it is valid 
	if (dollars <= 0 ){
		printf("Error: Invalid dollar number!\n");
		exit(EXIT_FAILURE);
	}
	else{
	//calculate the number of bills using the pointer and modulo division
		
    			*twenties = (dollars/20);
    			*tens = ((dollars%20)/10);
    			*fives = ((dollars%10)/5);
    			*toonies = ((dollars%5)/2);
    			*loonies = (((((dollars%20)%10)%5)%2));
		
		}
	
} 

int main(void){
	int dollars, twenties, tens, fives, toonies, loonies;
	char ch;
	printf("Enter a dollar amount: ");
	scanf("%d", &dollars);
	if( ( ch = getchar() ) != '\n' && ch != EOF ){
                printf("Error: Invalid date format!\n");
		return 1;
        }
	printf("\nThe change for $%d is:\n", dollars);
	//use the function to calculate the change, and print the new values of the pointers
	pay_amount(dollars, &twenties, &tens, &fives, &toonies, &loonies);
	 
	printf("Twenties: %d\n", twenties);
        printf("Tens: %d\n", tens);
        printf("Fives: %d\n", fives);
        printf("Toonies: %d\n", toonies);
        printf("Loonies: %d\n", loonies);
	return 0;
}
