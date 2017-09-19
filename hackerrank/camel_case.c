#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main(){
    char* s = (char *)malloc(100240 * sizeof(char));
	scanf("%s",s);
    int count = 1;
	while (*s != '\0'){
		if (*s <= 'Z' && *s >= 'A'){
			count++;	
		}
		s++;
	}
	printf("%d", count);
	
	
	return 0;
}
