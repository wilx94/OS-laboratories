#include <stdio.h>
#include <string.h>



int charToInt(char number);



void main(void){
	
	char c;
	FILE *file;

	

	
	// if((file = fopen("files/inputs/test.in","r")) == NULL ){	
	// 	printf("This files its not there.");
	// }else{
		
	// 	printf("Pass the first\n");
	// 	//Verify every character until the EOF
	// 	while((c = getc(file)) != EOF){

	// 	if(c == "\n"){

	// 		printf("space");

	// 	}else {

	// 		printf("%c",c);

	// 	}

	// }
// }
	printf("hola\n");
	printf("test\n");


	file = fopen("files/inputs/test.in","r");

	while((c = getc(file)) != EOF){
		if(c == '\n'){
			printf("newline\n");
		}else{
			printf("%c - %d\n",c,(int)c);
		}
	}



	int lenWord = strlen(word);
	int count;

	for(i = 0; i < row; i++){
		for(j = 0; j < col; j++){
			for(k = j,count = 0; count < lenWord &&  k < col; k++, count++){
				if(!(tolower((int)board[i][k]) == tolower((int)word[searchPos]))){
					break;
				}else{
					
					if(count == lenWord){
						colIndex = col;
						rowIndex = row;
						return;
					}
					count++;
				}
			}
		}
	}

}

