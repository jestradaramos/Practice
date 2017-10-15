#include <stdio.h>
#include <stdlib.h>
#include <strings.h>


struct Node{

	int data;
	struct Node* left;
	struct Node* right;

};

struct Node* newNode(int data){
	struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

// Will not consider duplicates 
struct Node* insert(struct Node* node, int data){
	if (node == NULL) {
		return newNode(data); 
	} else if (node->data < data){
		node->right = insert(node->right, data);
	} else {
		node->left = insert(node->left, data);
	}
	return node;
}

void orderPrint(struct Node* node){
	if (node != NULL) {
		orderPrint(node->left);
		printf("%d\n", node->data);
		orderPrint(node->right);

	}
}


// Create a function for removing a node

// Create two function for searching for a node (BFS + DFS)

int main(int argv, char* argc){
	struct Node* root = NULL;
	root = insert(root, 50);
	insert(root, 30);
	insert(root, 60);
	insert(root, 10);
	insert(root, 20);
	insert(root, 40);
	insert(root, 100);
	orderPrint(root);
return 0;

}
