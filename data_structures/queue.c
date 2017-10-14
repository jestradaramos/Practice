#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DATA_SIZE 20

struct Node {
	char data[DATA_SIZE];
	struct Node* next; 

};

struct Node* front = NULL;
struct Node* back = NULL;

void enqueue(char* data){
	struct Node* tempNode = (struct Node*) malloc (sizeof(struct Node));
	strcpy(tempNode->data, data);
	tempNode->next = NULL;

	if (front == NULL && back == NULL){
		front = tempNode;
		back = tempNode;
		return;
	} else {
		back->next = tempNode;
		back = tempNode;
		return;
	}

}

struct Node* dequeue(){
	struct Node* tempNode = front;
	if (front == NULL) return tempNode;

	if (front == back){
		front = NULL;
		back = NULL;
	} else {
		front = front->next;
	}

	return tempNode;
}

void stringify (struct Node* aNode){
	printf("Data: %s\nNext Pointer: %p\n", aNode->data, aNode->next);
}

int main(int argc, char* argv){
	printf("Testing out the queue\n");

	printf("Enque my name: Jeffrey\n");
	enqueue("Jeffrey");
	printf("Enqueue roommates name: Jack\n");
	enqueue("Jack");
	printf("Enqueue friends name: Mariana\n");
	enqueue("Mariana");

	printf("Dequeue my name: Jeffrey\n");
	stringify(dequeue());
	printf("Dequeue roommate name: Jack\n");
	stringify(dequeue());
	printf("Enqueue myself again\n");
	enqueue("Jeffrey");
	printf("Dequeue friends name: Mariana\n");
	stringify(dequeue());
	printf("Dequeue myself\n");
	stringify(dequeue());
	return 0;	

}
