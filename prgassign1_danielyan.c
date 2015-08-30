/*
Authur: Georgiy Danielyan
Class: Comp 222 Computer Organization and Architecture
Professor: George Lazik 
Class Time: T/Th 11:00-12:15
Date completed: 8 - 29 - 15

Program Description: This program measures performance rates such as instructions per cycle, CPU time to complete a program, and
execution of instructions expressed as millions per second.
Input 1: Number of instruction classes
Input 2: MHz 
Input 3: CPI (cycles per instruction) for each class
Input 4: Instruction count per class
Output: Avg CPI, CPU Time, MIPS
*/

#include <stdio.h>
#include <stdlib.h>

void printMenu();
void enterParameters();
void printParameters();
void printPerformance();
void calculatePerformance();

//Global Variables and Pointers
int numberOfClasses;
int mhzFrequency;
int *aryCpiClassesPtr;
int *aryInstructionCountPtr;
float avgCPI;
float cpuTime;
float mips;

//Main menu - Note: printMenu function handles all interaction and execution
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
		printf("\nEnter selection: ");
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
	printf("\nEnter the number of instruction classes: ");
	scanf("%d", &numberOfClasses);
	aryCpiClassesPtr = malloc(sizeof(int)*numberOfClasses);
	aryInstructionCountPtr = malloc(sizeof(int)*numberOfClasses);
	printf("Enter the frequency of the machine (MHz): ");
	scanf("%d", &mhzFrequency);
	for(int i=0; i<numberOfClasses; i++){
		printf("Enter CPI of class %i: ", i+1);
		scanf("%d", &aryCpiClassesPtr[i]);
		printf("Enter instruction count of class %i (millions) : ", i+1);
		scanf("%d", &aryInstructionCountPtr[i]);
	}//for
	printf("\n");
}//enterParameters

void printParameters(){
	printf("-------------------------\n");
	printf("|Class\t|CPI\t|Count\t|\n");
	printf("-------------------------\n");
	for(int i=1; i<=numberOfClasses; i++){
		printf("|%d\t|%d\t|%d\t|\n",i,aryCpiClassesPtr[i-1],aryInstructionCountPtr[i-1]);
		printf("-------------------------\n");
	}//for
	printf("\n");

}//printParameters

void printPerformance(){
	calculatePerformance();
	printf("-------------------------\n");
	printf("|Performance\t|Value\t|\n");
	printf("-------------------------\n");
	printf("|Average CPI\t|%.2f\t|\n", avgCPI);
	printf("-------------------------\n");
	printf("|CPU Time (ms)\t|%.2f\t|\n", cpuTime);
	printf("-------------------------\n");
	printf("|MIPS\t\t|%.2f\t|\n", mips);
	printf("-------------------------\n");
	printf("\n");

}//printPerformance

void calculatePerformance(){
	//Calculate Average CPI - number of instruction executions
	float summationOfInstructionCount = 0.0;
	for(int i=0; i<numberOfClasses; i++){
		summationOfInstructionCount+=(aryCpiClassesPtr[i]*(aryInstructionCountPtr[i]*1000000));
	}
	float sumOfIntstructionCount = 0.0;
	for(int i=0; i<=numberOfClasses; i++){
		sumOfIntstructionCount+=(aryInstructionCountPtr[i]*1000000);
	}
	avgCPI = (summationOfInstructionCount/sumOfIntstructionCount);

	//Calculate CPU Time - processor time needed to execute a given program
	cpuTime = (sumOfIntstructionCount*avgCPI*(1.0/(mhzFrequency*1000000)));
	cpuTime = cpuTime*1000.0;//Convert seconds to milliseconds

	//Calculate MIPS - millions of instructions per second
	mips = ((mhzFrequency*1000000)/(avgCPI*1000000));

}//calculatePerformance