#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {
	
	char maxbuf[4096];
	FILE *input_file_max = fopen(argv[1], "r");
	int max = 0;
	int maxtoken1 = 0;
	int maxtoken2 = 0;
	while(fgets(maxbuf, sizeof(maxbuf), input_file_max) != NULL){
		
		char *temp = strdup(maxbuf);
		
		char *token1 = strsep(&temp, " ");
		int token1size = strlen(token1);
		if (token1size > maxtoken1){
			maxtoken1 = token1size;
		}
		
		char *token2 = strsep(&temp, " ");
		int token2size = strlen(token2);
		if (token2size > maxtoken2){
			maxtoken2 = token2size;
		}
		
		int n = strlen(temp);
		if (n > max){
			max = n;
		}
	}
	
	printf("%d %d %d\n", maxtoken1, maxtoken2, max);
	
	char buf[4096];
	
	FILE *input_file = fopen(argv[1], "r");
	
	char *data;
	char *result = fgets(buf, sizeof(buf), input_file);
	data = strdup(buf);
	//int s = max - strlen(data) - 1;
	if (result == NULL){
		return 0;
	}
	
	char *token1 = strsep(&data, " ");
	char *token2 = strsep(&data, " ");
	
	for(int i = 0; i < strlen(data); i++){
			
			if (data[i] == '\n'){
				data[i] = ' ';
			}
	}
	
	for(int k = 0; k < maxtoken1 + maxtoken2 + max + 8; k++){
		printf("-");
	}
	printf("\n");
	printf("| %*s | %*s | %*s|", -maxtoken1, token1, maxtoken2, token2, -max+1, data);
	
	printf("\n");
	for(int k = 0; k < maxtoken1 + maxtoken2 + max + 8; k++){
		printf("-");
	}
	printf("\n");
	
	while(fgets(buf, sizeof(buf), input_file) != NULL){
		data = strdup(buf);
		
		char *token1 = strsep(&data, " ");
		char *token2 = strsep(&data, " ");
		
		for(int i = 0; i < strlen(data); i++){
			if (data[i] == '\''){
				data[i] = ' ';
			}
			if (data[i] == '\n'){
				data[i] = ' ';
			}
		}
		
		printf("| %*s | %*s |%*s|\n", -maxtoken1, token1, maxtoken2, token2, -max, data);
		
	}
	for(int k = 0; k < maxtoken1 + maxtoken2 + max + 8; k++){
		printf("-");
	}
	printf("\n");
	printf("%d", max);
	
	
	/*
	char *result = fgets(buf, 4096, input_file);
	data = strdup(buf);
	if (result == NULL){
		return 0;
	}
	char *token1 = strsep(&data, " ");
	char *token2 = strsep(&data, " ");
	char *token3 = strsep(&data, " ");
	printf("%s %s %s", token1, token2, token3);
	
	//printf("%s\n", buf);
	result = fgets(buf, 4096, input_file);
	//printf("%s\n", buf);
	
	*/
	fclose(input_file);
	
	printf("\n---------------------\n");
	
	printf("| %*s |\n", 3, "ABC");
	printf("| ABCDEF |\n");
	printf("\n---------------------\n");
	return 0;
}