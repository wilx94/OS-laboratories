#include <stdio.h>
#include <stdbool.h>
#include <string.h>
// double value;

/*This is a comment*/
void outputResponse(char board[][4],char printCase[], int run);

int main(void){
	char printCase[99];
	int c;
	int cases = 1;
	int col =0;
	int row = 0; 
	char ticTac[4][4];


	FILE *file;

	if((file = fopen("files/inputs/test.in","r")) == NULL ){	
		printf("This files its not there.");
	}else{
		
		//Just ignore the first line that its the number of board in the file
		//This can be erased because the down case cover it
		// while((c = getc(file)) != '\n'){
		// }
		
		printf("Pass the first\n");
		//Verify every character until the EOF
		while((c = getc(file)) != EOF){

			//If the character its not any letter that we need to use then ignore it
			if(!(c == 'T'|| c == '.' || c == 'X' || c== 'O')){
				//printf("Test 1: %c\n",c);
				continue;
			}
			else{
				//save the letter in the 
				// printf("IN1");
				ticTac[col][row] = c;
			
				if(col == 3 && row == 3){
					//printf("IN\n\n\n\n\n");
					outputResponse(ticTac,printCase,cases);
					printf("testout"  );
					
					col = 0;
					row = 0;
					cases++;
				}
				else if(row == 3){
					//printf("if\n");
					row = 0;

					if(col < 3){

						col++;
						printf("\n");
					}
				}
				else if(col <= 3){
					//printf("else\n");
					row++;
					//printf("row: %d\n",row);
				}
			}
			
			
		}

		fclose(file);
		}
}

void outputResponse(char board[][4],char printCase[], int run){
	bool haveSpace = false;
	char findLetter = NULL;
	int row = 0;
	int col = 0;
	int boardDimensions = 4;
	char temp[] = "Case #";


	//printf("in outputResponse\n");
	for(col; col < boardDimensions; col++){
		
		findLetter = board[col][0];

		
		if(findLetter!='.'){
			for(row; row < boardDimensions; row++){
				printf("board[col][row]: %c, col: %d, row: %d\n",board[col][row],col,row);
				if((findLetter != board[col][row]) && board[col][row] != 'T'){
					break;
				}else if(row == 3){
					switch(findLetter){
						case 'X':
							strcat(temp,": X won");
							printCase = temp;
						default:
							strcat(temp,": O won");
							printCase = temp;
					}
				}
			}
		}else{
			haveSpace = true;
		}
	}

	//Reset values
	col = 0;
	row = 0;

	for(row; row < boardDimensions; row++){
		
		findLetter = board[0][row];
		
		if(findLetter!='.'){
			for(col; col < boardDimensions; col++){
				if((findLetter != board[col][row]) && board[col][row] != 'T'){
					break;
				}else if(col == 3){
					switch(findLetter){
						case 'X':
							strcat(temp,": X won");
							printCase = temp;
						default:
							strcat(temp,": O won");
							printCase = temp;
					}
				}
			}
		}
	}

	//Reset Values
	col = 0;
	row = 0;

	for(col; col < boardDimensions; col++){
		
		findLetter = board[col][row];
		row = col;
		
		if(findLetter!='.'){
			if((findLetter != board[col][row]) && board[col][row] != 'T'){
				break;
			}else if(col == 3){
				switch(findLetter){
						case 'X':
							strcat(temp,": X won");
							printCase = temp;
						default:
							strcat(temp,": O won");
							printCase = temp;
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
							strcat(temp,": X won");
							printCase = temp;
						default:
							strcat(temp,": O won");
							printCase = temp;
					}
			}
		}
	}


	if(haveSpace){
		strcat(temp,":Game has not completed");
		printCase = temp;
	}else{
		strcat(temp,": Draw");
		printCase = temp;
	}


		int i;
		int j;

		printf("start\n");
		for(i=0; i <4;i++){
			for(j=0;j<4;j++){
				printf("%c",board[i][j] );
			}
			printf("\n");
		}
		printf("end: %s\n",printCase);

	


}