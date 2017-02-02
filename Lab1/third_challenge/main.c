#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>



struct student{

	char name[50];
	double gpa;

};

void sort(struct student studentStruc[], int total);

void main(void){
	struct student studentStruc[20];
	int i = 0;
	int j;
	bool flag = true;
	char stringInput[100];
	char original[100];
	char *strPtr;
	double test;
	const char delim[2] = ",";

	printf("Hello, you can insert a maximun of 20 students\n");

	do{
		printf("Enter name and GPA separate by comma.\n"
				"Ex. Wilson, 3.50\n"
				"Input: %d\n\n",i+1);
		scanf("%s",stringInput);
		strcpy(original,stringInput);
		
			if((strPtr = strtok(stringInput,delim)) == NULL){

				printf("Have to enter real information\n");

			}else{
				if(strcmp(original,"-1") !=0){

					strcpy(studentStruc[i].name, strPtr);

				}

			
				
			}
			if((strPtr = strtok(NULL,delim)) == NULL){

				printf("Have to enter real information\n");

			}else{
				if(strcmp(original,"-1") !=0 ){

					studentStruc[i].gpa = atof(strPtr);

				}
				
			}

			i++;

		
	} while(strcmp(original,"-1") !=0 && i < 20);

	sort(studentStruc,i);


	for(j = 1; j < i; j++){
		printf("%s %.2f\n",studentStruc[j].name, studentStruc[j].gpa);
	}
}




void sort(struct student studentStruc[], int total){
	int i;
	int j;

	for(i = 1; i < total; i++){
		struct student temp =studentStruc[i];
		j = i;

		while(j > 0 && studentStruc[j-1].gpa>temp.gpa){
			studentStruc[j] = studentStruc[j-1];
			j--;
		}
		studentStruc[j] = temp;
	}
}

