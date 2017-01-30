#include <stdio.h>
#include <stdbool.h>
#include <string.h>
// double value;

/*This is a comment*/
void outputResponse(const char board[][4],char printCase[]);

int main(void){
	char printCase[20];
	char caseText[6] = "Case#";
	char c;
	int cases = 1;
	int col =0;
	int row = 0; 
	char ticTac[4][4];


	FILE *file;

	if((file = fopen("files/inputs/test.in","r")) == NULL ){	
		printf("This files its not there.");
	}else{
		
		printf("Pass the first\n");
		//Verify every character until the EOF
		while((c = getc(file)) != EOF){

			//If the character its not any letter that we need to use then ignore it
			if(!(c == 'T'|| c == '.' || c == 'X' || c== 'O')){
				continue;
			}
			else{
				//save the letter in the file
				ticTac[col][row] = c;
			
				if(col == 3 && row == 3){
					outputResponse(ticTac,printCase);

					//print the board
					int i;
					int j;
		
					printf("start\n");
					for(i=0; i <4;i++){
						for(j=0;j<4;j++){
							printf("%c",ticTac[i][j] );
						}
						printf("\n");
					}// end print the board

					//print the answer
					printf("%s%d %s\n",caseText,cases,printCase);

					//reset values
					col = 0;
					row = 0;

					//increase case id
					cases++;
				}
				else if(row == 3){
					
					row = 0;

					if(col < 3){

						col++;
						printf("\n");

					}
				}
				else if(col <= 3){

					row++;

				}
			}
			
			
		}

		fclose(file);
		}
}

void outputResponse(const char board[][4],char printCase[]){
	bool haveSpace = false;
	char findLetter = NULL;
	int row;
	int col;
	int boardDimensions = 4;
	


	//printf("in outputResponse\n");
	for(col = 0; col < boardDimensions; col++){
		
		findLetter = board[col][0];

		
		if(findLetter!='.'){
			for(row = 0; row < boardDimensions; row++){

				if((findLetter != board[col][row]) && board[col][row] != 'T'){

					break;

				}else if(row == 3){

					switch(findLetter){
						case 'X':
							strcpy(printCase,": X won");
							return ;
						default:
							strcpy(printCase,": O won");
							return;
					}

				}

			}
		}else{

			haveSpace = true;

		}
	}


	for(row = 0; row < boardDimensions; row++){
		
		findLetter = board[0][row];
		
		if(findLetter!='.'){

			for(col = 0; col < boardDimensions; col++){

				if((findLetter != board[col][row]) && board[col][row] != 'T'){

					break;

				}else if(col == 3){

					switch(findLetter){
						case 'X':
							strcpy(printCase,": X won");
							
							return ;
						default:
							strcpy(printCase,": O won");
							
							return;
					}

				}

			}

		}
	}
	

	for(col = 0; col < boardDimensions; col++){
		
		findLetter = board[col][row];
		row = col;
		
		if(findLetter!='.'){
			if((findLetter != board[col][row]) && board[col][row] != 'T'){

				break;

			}else if(col == 3){

				switch(findLetter){
						case 'X':
							strcpy(printCase,": X won");
							
							return ;
						default:
							strcpy(printCase,": O won");
							
							return;
				}

			}
		}
	}

	//Reset Values
	col = 0;
	row = 3;

	for(col; col < boardDimensions; col++){
		row = row - col;

		findLetter = board[col][row];
		row = col;
		
		if(findLetter!='.'){

			if((findLetter != board[col][row]) && board[col][row] != 'T'){

				break;

			}else if(col == 3){

				switch(findLetter){
						case 'X':
							strcpy(printCase,": X won");
							
							return;
						default:
							strcpy(printCase,": O won");
							
							return;
				}

			}

		}
	}


	if(haveSpace){

		strcpy(printCase,": Game has not completed");
		

	}else{

		strcpy(printCase,": Draw");
		

	}


}