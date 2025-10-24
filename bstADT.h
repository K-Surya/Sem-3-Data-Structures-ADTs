#include <stdio.h>
#include <stdlib.h>

struct tree{
	int data;
	struct tree* left;
	struct tree* right;
};

struct tree* insert(struct tree* t, int x){
	if(t==NULL){
		t = (struct tree*) malloc(sizeof(struct tree));
		t->data = x;
		t->left = NULL;
		t->right = NULL;
	} else if(x > t->data){
		t->right = insert(t->right, x);
	}else if(x < t->data){
		t->left = insert(t->left, x);
	}
	return t;
}

int search(struct tree* t, int k){
	if(t == NULL){
		printf("Element not in the tree!\n");
		return 0;
	}
	if(k > t->data)
		return search(t->right, k);
	else if(k < t->data)
		return search(t->left, k);
	else if(k == t->data){
		printf("Element found in the tree!!\n");
		return 1;
	}
}

struct tree* findMin(struct tree* t){
	while(t != NULL && t->left != NULL)
		t = t->left;
	return t;
}

struct tree* findMax(struct tree* t){
	while(t != NULL && t->right != NULL)
		t = t->right;
	return t;
}

struct tree* delete(struct tree* t, int k){
	struct tree* tmp;
	if (t == NULL) {
		return t; 
	} else if(k < t->data){
		t->left = delete(t->left, k);
	} else if(k > t->data){
		t->right = delete(t->right, k);
	} else if(t->left != NULL && t->right != NULL){
		tmp = findMin(t->right);
		t->data = tmp->data;
		t->right = delete(t->right, tmp->data);
	} else if(t->left == NULL && t->right == NULL){
		free(t);
		t = NULL;
	} else {
		tmp = t;
		if(t->right == NULL)
			t = t->left;
		else
			t = t->right;
		free(tmp);
	}
	return t;
}

void inorderDisplay(struct tree* t){
	if (t->left != NULL) inorderDisplay(t->left);
	printf("%d ",t->data);
	if (t->right != NULL) inorderDisplay(t->right);
}

void preorderDisplay(struct tree* t){
	printf("%d ", t->data);
	if (t->left != NULL) preorderDisplay(t->left);
	if (t->right != NULL) preorderDisplay(t->right);
}

void postorderDisplay(struct tree* t){
	if (t->left != NULL) postorderDisplay(t->left);
	if (t->right != NULL) postorderDisplay(t->right);
	printf("%d ",t->data);
}

void levelorderDisplay(struct tree* t, int level){
	for(int i=0;i<level;i++)
		printf("-");
	printf("%d \n", t->data);
	if(t->left != NULL) levelorderDisplay(t->left, level+1);
	if(t->right != NULL) levelorderDisplay(t->right, level+1);
}
