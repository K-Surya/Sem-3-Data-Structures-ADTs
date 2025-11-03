#include <stdio.h>
#include <stdlib.h>

struct avltree{
    int data;
    int height;
    struct avltree *left;
    struct avltree *right;
};

int height(struct avltree *t){
    if(t == NULL){
        return -1;
    } else {
        return t->height;
    }
}

int max(int a, int b){
    if(a > b){
        return a;
    } else {
        return b;
    }
}

struct avltree* singleRotateLeft(struct avltree *k2){
    struct avltree *k1;
    k1 = k2->left;
    k2->left = k1->right;
    k1->right = k2;
    k2->height = max(height(k2->left), height(k2->right)) + 1;
    k1->height = max(height(k1->left), height(k1->right)) + 1;
    return k1;
}

struct avltree* singleRotateRight(struct avltree *k2){
    struct avltree *k1;
    k1 = k2->right;
    k2->right = k1->left;
    k1->left = k2;
    k2->height = max(height(k2->left), height(k2->right)) + 1;
    k1->height = max(height(k1->left), height(k1->right)) + 1;
    return k1;
}

struct avltree* doubleRotateLeft(struct avltree *k3){
    k3->left = singleRotateRight(k3->left);
    return singleRotateLeft(k3);
}

struct avltree* doubleRotateRight(struct avltree *k3){
    k3->right = singleRotateLeft(k3->right);
    return singleRotateRight(k3);
}

struct avltree* insert(struct avltree *t, int x){
    if(t == NULL){
        t = (struct avltree*)malloc(sizeof(struct avltree));
        t->data = x;
        t->height = 0;
        t->left = NULL;
        t->right = NULL;
    } else if(x < t->data){
        t->left = insert(t->left, x);
        if(height(t->left) - height(t->right) == 2){
            if(x < t->left->data){
                t = singleRotateLeft(t);
            } else {
                t = doubleRotateLeft(t);
            }
        }
    } else if(x > t->data){
        t->right = insert(t->right, x);
        if(height(t->right) - height(t->left) == 2){
            if(x > t->right->data){
                if(x > t->right->data){
                    t = singleRotateRight(t);
                } else {
                    t = doubleRotateRight(t);
                }
            }
        }               
    }
    t->height = max(height(t->left), height(t->right)) + 1;
    return t;
}

int search(struct avltree* t, int k){
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

void inorderDisplay(struct avltree* t){
	if (t->left != NULL) inorderDisplay(t->left);
	printf("%d ",t->data);
	if (t->right != NULL) inorderDisplay(t->right);
}

void preorderDisplay(struct avltree* t){
	printf("%d ", t->data);
	if (t->left != NULL) preorderDisplay(t->left);
	if (t->right != NULL) preorderDisplay(t->right);
}

void postorderDisplay(struct avltree* t){
	if (t->left != NULL) postorderDisplay(t->left);
	if (t->right != NULL) postorderDisplay(t->right);
	printf("%d ",t->data);
}

void levelorderDisplay(struct avltree* t, int level){
	for(int i=0;i<level;i++)
		printf("-");
	printf("%d \n", t->data);
	if(t->left != NULL) levelorderDisplay(t->left, level+1);
	if(t->right != NULL) levelorderDisplay(t->right, level+1);
}
