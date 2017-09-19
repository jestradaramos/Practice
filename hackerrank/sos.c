#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main(){
    char* S = (char *)malloc(10240 * sizeof(char));
    scanf("%s",S);
	int man = 0;
	while(*s != '\0'){
		if (S[0] != 'S') man++;
		if (S[1] != 'O') man++;
		if (S[2] != 'S') man++;

		S += 3;	
	}
	printf("%d", man);
    return 0;
}
