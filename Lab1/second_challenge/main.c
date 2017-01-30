#include <stdio.h>
#include <string.h>
#include <stdbool.h>



void main(void){

	char c;
	char caseId = NULL;
	

	//board setup
	int rowsDimension;
	int colsDimension;
	int rowPosition = 0;
	int colPosition = 0;
	char board[999][50];

	//search setup
	int numberOfWords =  NULL;
	int actualPosition = 0;
	int letterPosition = 0;
	char wordArray[999][999];


	bool startGame = false;


	FILE *file;

	if( (file = open("files/inputs/test.in","r")) == NULL){

		printf("This files does not exist.");

	}else{

		while( (c = getc(file)) != EOF){
			
			if(caseId == NULL){

				caseId = c;
				printf("%d",caseId);


			}else if(c != " " && rowsDimension == NULL){

				rowsDimension = c;


			}else if (c != " " && colsDimension == NULL){

				colsDimension = c;

			}else {
				
				// if(!startGame){

					board[rowPosition][colPosition++] = c;

					if(colPosition == colsDimension && rowPosition == rowsDimension){

						if(numberOfWords == NULL){
						
							numberOfWords = c;

						}else if(actualPosition != numberOfWords){
							wordArray[actualPosition][letterPosition];

						}

					}else if(colPosition == colsDimension){

						colPosition = 0;
						rowPosition++;

					}
				// }


				


			}
		}

	}

}

		
