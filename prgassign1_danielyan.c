#include <stdio.h>
#include <stdlib.h>

void printMenu();
void enterParameters();
void printParameters();
void printPerformance();

//Global Variables
int numberOfClasses;

int main(){
	printMenu();
	return 0;
}//Main

void printMenu(){
	int choice;
	do{
		printf("Performance assessment:\n");
		printf("-----------------------\n");
		printf("1) Enter parameters\n");
		printf("2) Print table of parameters\n");
		printf("3) Print table of performance\n");
		printf("4) Quit\n");
		scanf("%d", &choice);
		switch(choice){
			case 1:
				enterParameters();
				break;
			case 2:
				printParameters();
				break;
			case 3:
				printPerformance();
				break;
			case 4:
				exit(0);
				break;
			default:
				printf("Invalid selection\n\n");
				//Clear the input stream in case of erroneous inputs
				while ((choice = getchar()) != '\n' && choice != EOF);
				break;	
		}//Switch
	}while(choice != 4);
}//printMenu

void enterParameters(){
	printf("Enter the number of instruction classes:\n");
	scanf("%d", &numberOfClasses);
	printf("Enter the frequency of the machine (MHz):\n");
	for(int i=1; i<=numberOfClasses; i++){
		printf("Enter CPI of class %i \n", i);
	}

}//enterParameters

void printParameters(){

}//printParameters

void printPerformance(){

}//printPerformance