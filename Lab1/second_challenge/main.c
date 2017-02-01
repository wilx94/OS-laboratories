#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int charToInt(char number);
void positionOfWord(char board[][50],int row, int col, char word[999]);

void main(void){

	char c;
	int caseId = NULL;
	

	//board setup
	char rowsDimensionText[999] = "";
	char colsDimensionText[999] = "";
	int rowsDimension;
	int colsDimension;
	int rowPosition = 0;
	int colPosition = 0;
	char board[999][50];

	//search setup
	int numberOfWords =  NULL;
	char numberOfWordsText[99];
	int actualPosition = 0;
	int letterPosition = 0;
	char wordArray[999][999];

	char temp[99];


	bool startGame = false;


	FILE *file;

	if( (file = fopen("files/inputs/test.in","r")) == NULL){

		printf("This files does not exist.");

	}else{
				caseId = charToInt(getc(file));

				while((c = getc(file))=='\n'){
					  printf("hola: %d\n",(int)c);
				}
				while((c = getc(file))=='\r'){
					 printf("hola\n");
				}
				
				
				//this while its used to find numbers with more than one digit
				while((c = getc(file))!= ' '){
					
					temp[0]= c;
					strcat(rowsDimensionText,temp);

				}
				
				//this while its to catch the number with more than one digit
				while((c = getc(file))!= '\n'){
					
					temp[0]= c;
					strcat(colsDimensionText,temp);

				}

	

				rowsDimension = atoi(rowsDimensionText);
				colsDimension = atoi(colsDimensionText);



				// filling the board
				int i;
				int j;


				for(i = 0; i < rowsDimension; i++){

					for(j = 0; j < colsDimension; j++){
						
						board[i][j] = c = getc(file);

					}
					while((c = getc(file))!='\n'){}
				}


				// fill the array with the board
				for(i = 0; i < rowsDimension; i++){

					for(j = 0; j < colsDimension; j++){
						if(board[i][j]==' '){
							board[i][j] = 'e';
						}
						printf("%c",board[i][j]);

					}
					printf("\n");
				}



			while((c = getc(file))!= '\n'){
					
					temp[0]= c;
					strcat(numberOfWordsText,temp);

				}
				
				numberOfWords = atoi(numberOfWordsText);
				
				
				// fill the array with the words to search
				for(i =0; i < numberOfWords; i++){
					
					while((c = getc(file)) !=  '\n'){

						if(c == EOF){

							break;

						}

						temp[0] = c;
						strcat(wordArray[i]	,temp);

					}
					 
				}


				//print the words to be searched
				for( i = 0; i < numberOfWords; i++){

					printf("%s\n",wordArray[i]);

				}


			
				//search all the words
				for(i = 0; i < numberOfWords; i++){
					positionOfWord(board,rowsDimension,colsDimension,wordArray[i]);
				}
			

			}
}





int charToInt(char number){
	return number -'0';
}

void positionOfWord(char board[][50],int row, int col, char word[999]){

	// for variables
	int i;
	int j;
	int k;
	int m; 
	int count;

	// thig that searchPos can be remove
	int searchPos = 0;

	/* This its the length of the word to be search. We need to have in mind that to search its this result - 2.
		that because ex Wil in an array is 'W','i','l','\0' this return 4 but the actual array needs to be from 0-2, that its 4 - 2 */
	int lenWord = strlen(word);

	for(i = 0; i < row; i++){

		for(j = 0; j < col; j++){




			// forward
			for(k = j,count = 0; count < lenWord -1 &&  k < col; k++, count++){

				if(!(tolower((int)board[i][k]) == tolower((int)word[count]))){
					
					break;

				}else{
					
					if(count == lenWord -2 ){

						// print the index where the word its located
						printf("i %d j %d\n",i,j);

						return;

					}
				}
			}// end for




			// backward
			for(k = j,count = 0; count < lenWord -1 &&  k > -1; k--, count++){
					
				if(!(tolower((int)board[i][k]) == tolower((int)word[count]))){

					break;

				}else{

					if(count == lenWord -2 ){

						// print the index where the word its located
						printf("i %d j %d\n",i,j);

						return;

					}
				}
			}// end for




			// downward
			for(k = i,count = 0; count < lenWord -1 &&  k > -1; k++, count++){

				if(!(tolower((int)board[k][j]) == tolower((int)word[count]))){

					break;

				}else{

					if(count == lenWord -2 ){

						// print the index where the word its located
						printf("i %d j %d\n",i,j);

						return;
					}
				}
			}// end for




			// upward
			for(k = i,count = 0; count < lenWord -1 &&  k > -1; k--, count++){
					
				if(!(tolower((int)board[k][j]) == tolower((int)word[count]))){

					break;

				}else{

					if(count == lenWord -2 ){

						// print the index where the word its located
						printf("i %d j %d\n",i,j);

						return;

					}
				}
			}// end for




			// diagonal forward
			for(k = i, m = j,count = 0; count < lenWord -1 &&  k > -1; k++, m++, count++){
					
				if(!(tolower((int)board[k][m]) == tolower((int)word[count]))){

					break;

				}else{

					if(count == lenWord -2 ){

						// print the index where the word its located
						printf("i %d j %d\n",i,j);

						return;

					}
				}
			}// end for




			// diagonal backward
			for(k = i, m = j,count = 0; count < lenWord -1 &&  k > -1; k--, m--, count++){
					
				if(!(tolower((int)board[k][m]) == tolower((int)word[count]))){

					break;

				}else{

					if(count == lenWord -2 ){

						// print the index where the word its located
						printf("i %d j %d\n",i,j);

						return;

					}
				}
			}// end for




			// reverse diagonal forward
			for(k = i, m = j,count = 0; count < lenWord -1 &&  k > -1; k--, m++, count++){
					
				if(!(tolower((int)board[k][m]) == tolower((int)word[count]))){

					break;

				}else{

					if(count == lenWord -2 ){

						// print the index where the word its located
						printf("i %d j %d\n",i,j);

						return;

					}
				}
			}// end for





			// reverse diagonal backward
			for(k = i, m = j,count = 0; count < lenWord -1 &&  k > -1; k++, m--, count++){
					
				if(!(tolower((int)board[k][m]) == tolower((int)word[count]))){

					break;

				}else{

					if(count == lenWord -2 ){

						// print the index where the word its located
						printf("i %d j %d\n",i,j);

						return;
					}
				}
			}// end for

		}
	}
}
	
