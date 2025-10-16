#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *next;
};

void insertEnd(struct node* header, int x){
	struct node* ptr;
	ptr = header;

	while(ptr->next != NULL){
		ptr = ptr->next;
	}

	struct node* tmp = (struct node*) malloc(sizeof(struct node));
	tmp->data = x;
	tmp->next = NULL;

	ptr->next = tmp;
}

void insertFront(struct node* header, int x){
	struct node* tmp = (struct node*) malloc(sizeof(struct node));
	tmp->data = x;
	tmp->next = header->next;
	header->next = tmp;
}

void insertMiddle(struct node* header, int x, int k){
	struct node *ptr;
	ptr = header->next;

	while(ptr->next != NULL && ptr->data != k){
		ptr = ptr->next;
	}

	struct node* tmp = (struct node*) malloc(sizeof(struct node));
	tmp->data = x;
	tmp->next = ptr->next;
	ptr->next = tmp;
}

void delete(struct node* header, int k){
	struct node* ptr = header->next;
	struct node* prev = header;
	
	while(ptr!=NULL && ptr->data != k){
		ptr = ptr->next;
		prev = prev->next;
	}

	if(ptr == NULL){
		printf("Element not found!");
		return;
	}

	prev->next = ptr->next;

	free(ptr);

}

void display(struct node* header){
	struct node* ptr = header->next;

	printf("Elements of the list : ");

	while(ptr!=NULL){
		printf("%d  ",ptr->data);
		ptr = ptr->next;
	}

	printf("\n");
}

int search(struct node* header, int k){
	struct node* ptr = header->next;
	int i = 0;

	while(ptr != NULL){
		if(ptr->data == k)
			return i;
		i++;
		ptr = ptr->next;
	}
	return -1;
}

void deleteList(struct node* header){
	struct node* ptr = header->next;
	struct node* prev = header;

	while(ptr!=NULL){
		free(prev);
		prev = ptr;
		ptr = ptr->next;
	}

	free(ptr);

}

