#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int* solve(int grades_size, int* grades, int *result_size){
	// Complete this function
	*result_size = grades_size;
	int* answer = (int*) malloc(sizeof(int) * grades_size);
	for(int i = 0; i < *result_size; i ++){
		int round = (5 - (grades[i] % 5));
		if (grades[i] < 38){
			answer[i] = grades[i];
		} else if (round < 3){
			answer[i] = grades[i] + round;
		} else {
			answer[i] = grades[i];
		}
	}
	return answer;
}

int main() {
	int n; 
	scanf("%d", &n);
	int *grades = malloc(sizeof(int) * n);
	for(int grades_i = 0; grades_i < n; grades_i++){
			scanf("%d",&grades[grades_i]);
	}
	int result_size;
	int* result = solve(n, grades, &result_size);
	for(int result_i = 0; result_i < result_size; result_i++) {
			if(result_i) {
					printf("\n");
			}
			printf("%d", result[result_i]);
	}
	puts("");


	return 0;
}
