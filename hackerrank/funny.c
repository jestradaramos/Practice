#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

char* funnyString(char* s){
    // Complete this function
	
	int i = 0;
	int* differences = (int*)malloc(sizeof(int));
	while(*s != '\0'){
		s++;
		if(*s != '\0'){
			differences = (int*) realloc(differences,sizeof(int) * (i + 1));
			differences[i] = abs(*s - *(s-1));
			i++;
		}
	}
	s--;
	while (i > 1){
		int diff =abs(*s - *(s - 1));
		if (diff != *differences){
			return ("Not Funny");
		}
		differences++;
		i--;
		s--;
	}
	return ("Funny");

}

int main() {
	int q; 
	scanf("%i", &q);
	for(int a0 = 0; a0 < q; a0++){
		char* s = (char *)malloc(512000 * sizeof(char));
		scanf("%s", s);
        int result_size;
        char* result = funnyString(s);
        printf("%s\n", result);
    }
	return 0;
}

