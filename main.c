#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {
	
	char maxbuf[4096];
	FILE *input_file_max = fopen(argv[1], "r");
	int max = 0;
	int maxtoken1 = 0;
	int maxtoken2 = 0;
	
	//Reading a file for first time to get the size of largest string for each column
	while(fgets(maxbuf, sizeof(maxbuf), input_file_max) != NULL){
		
		char *temp = strdup(maxbuf);
		char *tempcopy = temp;
		
		char *token1 = strsep(&tempcopy, " ");
		int token1size = strlen(token1);
		if (token1size > maxtoken1){
			maxtoken1 = token1size;
		}
		
		char *token2 = strsep(&tempcopy, " ");
		int token2size = strlen(token2);
		if (token2size > maxtoken2){
			maxtoken2 = token2size;
		}
		
		int n = 0;
		//Finds length of largest string excluding single quotes if exists
		for (int i = 0; i < strlen(tempcopy); i = i +1){
			if (tempcopy[i] != 39){
				n = n + 1;
			}
		}
		if (n > max){
			max = n;
		}
		
		free(temp);
	}
	fclose(input_file_max);
	
	//Prints the size of largest string for each column
	//printf("String length of largest string for each column: %d, %d, %d\n", maxtoken1, maxtoken2, max);
	
	char buf[4096];
	
	FILE *input_file = fopen(argv[1], "r");
	
	char *data;
	char *result = fgets(buf, sizeof(buf), input_file);
	data = strdup(buf);
	char *datacopy = data;
	
	if (result == NULL){
		return 0;
	}
	
	//Separting each line into three different columns
	char *token1 = strsep(&datacopy, " ");
	char *token2 = strsep(&datacopy, " ");
	
	for(int i = 0; i < strlen(datacopy); i++){
			
			if (datacopy[i] == '\n'){
				datacopy[i] = '\0';
			}
	}
	
	//Prints the output in the form of table with unlimited rows and three columns
	for(int k = 0; k < maxtoken1 + maxtoken2 + max + 9; k++){
		printf("-");
	}
	printf("\n");
	//Prints the headings only of the table 
	printf("| %*s | %*s | %*s |", -maxtoken1, token1, maxtoken2, token2, -max+1, datacopy);
	
	printf("\n");
	for(int k = 0; k < maxtoken1 + maxtoken2 + max + 9; k++){
		printf("-");
	}
	printf("\n");
	free(data);
	
	
	//Prints the remaining output of the table
	while(fgets(buf, sizeof(buf), input_file) != NULL){
		data = strdup(buf);
		datacopy = data;
		
		char *token1 = strsep(&datacopy, " ");
		char *token2 = strsep(&datacopy, " ");
		
		for(int i = 0; i < strlen(datacopy); i++){
			if (datacopy[i] == '\''){
				datacopy[i] = ' ';
			}
			if (datacopy[i] == '\n'){
				datacopy[i] = '\0';
			}
		}
		
		printf("| %*s | %*s |%*s|\n", -maxtoken1, token1, maxtoken2, token2, -max-1, datacopy);
		
		free(data);
	}
	for(int k = 0; k < maxtoken1 + maxtoken2 + max + 9; k++){
		printf("-");
	}
	printf("\n");
	//printf("%d", max);
	
	fclose(input_file);

	/*Simple test	
	printf("\n---------------------\n");
	
	printf("| %*s |\n", 6, "ABC");
	printf("| ABCDEF |\n");
	printf("\n---------------------\n");
	*/
	return 0;
}