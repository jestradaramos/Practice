#include <stdio.h>
#include <stdlib.h>


void insertion(int* list, int size){
	int temp;

	for (int x = 1; x < size; x++){
		int key = list[x];
		int i = x - 1;

		while( i >= 0 && list[i] > key){
			list[i+1] = list[i];
			i--;
		}
		list[i+1] = key;
	}
}

int main(int argc, char*argv){
	int size;
	printf("How many elements in your list? ");
	scanf("%d", &size);
	fflush(stdout);
	
	int array[size];
	printf("Insert Elements:\n");
	for (int x = 0; x < size; x++){
		scanf("%d", &array[x]);
	}

	printf("Sorted List: \n");
	insertion(array, size);

	for (int x = 0; x < size; x++){
		printf("%d ", array[x]);
	}
	printf("\n");
	
}
