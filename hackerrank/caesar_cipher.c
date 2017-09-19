#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main(){
    int n; 
	scanf("%d",&n);
    char* s = (char *)malloc(10240 * sizeof(char));
    scanf("%s",s);
    int k; 
    scanf("%d",&k);

	char* ret = s;

	while (*s != '\0'){
		if (*s <= 'z' && *s >= 'a'){
			*s = (*s + k - 'a') % 26 + 'a';
		
		} else if (*s <= 'Z' && *s >= 'A') {
			*s = (*s + k - 'A') % 26 + 'A';
		}

		s++;
	}
	printf("%s", ret);
    return 0;
}
