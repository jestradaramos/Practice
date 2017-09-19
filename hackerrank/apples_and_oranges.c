#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main(){
	int s;
	int t; 
	scanf("%d %d",&s,&t);
	int a; 
	int b; 
	scanf("%d %d",&a,&b);
	int m; 
	int n; 
	scanf("%d %d",&m,&n);
	int *apple = malloc(sizeof(int) * m);
	for(int apple_i = 0; apple_i < m; apple_i++){
			scanf("%d",&apple[apple_i]);
	}
	int *orange = malloc(sizeof(int) * n);
	for(int orange_i = 0; orange_i < n; orange_i++){
			scanf("%d",&orange[orange_i]);
	}

	register int i;
	int apples = 0;
	int oranges = 0;

	// Dealing with apples
	for (i = 0; i < m ; i++){
			if (s <= apple[i] + a && t >= apple[i] + a)
					apples++;
	}
	// Oranges
	for (i = 0; i < n ; i++){
			if (s <= orange[i] + b && t >= orange[i] + b)
					oranges++;
	}
	printf("%d\n%d", apples, oranges);
	return 0;
}
