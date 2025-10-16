#include <stdio.h>
#include <stdlib.h>
#include "linkedListADT.h"

int main(){
	struct node* header = (struct node*) malloc(sizeof(struct node));
	insertEnd(header,1);
	insertEnd(header,2);
	insertEnd(header,3);
	insertFront(header,4);
	insertFront(header,5);
	insertFront(header,6);
	display(header);
	delete(header, 4);
	display(header);
	insertMiddle(header, 10, 2);
	display(header);
	printf("Element 1 is in the index : %d\n", search(header, 1));
	printf("Element 7 is in the index : %d\n", search(header, 7));
	deleteList(header);

	return 0;
}

