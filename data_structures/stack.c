#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

struct Stack{
	int data;
	struct Stack* next;
};

void push(struct Stack** root, int data);
int pop(struct Stack** root);
int display(struct Stack* root);

int main(int argc, char* argv){
	struct Stack* root = NULL;
	push(&root, 10);
	push(&root, 11);
	push(&root, 12);
	pop(&root);
	pop(&root);
	pop(&root);

}


void push (struct Stack** root, int data){
	struct Stack* temp = (struct Stack*) malloc (sizeof(struct Stack));
	temp->data = data;
	temp->next = *root;
	*root = temp;

	printf("Pushed %d onto the stack.\n", (*root)->data);

}

int pop(struct Stack** root){
	if (!*root){
		return -1;
	}
	struct Stack* temp = *root;
	*root = (*root)->next;
	printf("Popped %d from the stack.\n", temp->data);
	free(temp);

}

int display(struct Stack* root){
	if (!root){
		return -1;
	}
	return root->data;

}
