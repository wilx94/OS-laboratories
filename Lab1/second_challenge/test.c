#include <stdio.h>
#include <string.h>


void main(void){
	
	char c = '4';
	FILE *file;

	int  test = c;

	
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
	printf("%d\n",test);
}