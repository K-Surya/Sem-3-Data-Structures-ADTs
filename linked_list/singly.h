struct node
{
    int data;
    struct node *next;
};

struct node *search(struct node *header, int value)
{
    struct node *temp = header->next;
    while (temp != NULL)
    {
        if (temp->data != value)
        {
            temp = temp->next;
        }
        else
        {
            printf("The element %d is found \n",temp->data);
            return temp;
        }
    }
    printf("The element %d is not found \n", value);
    return NULL;
}
void insertfront(struct node *header, int value)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node ));
    temp->data = value;
    temp->next = header->next;
    header->next = temp;
}

void insertEnd(struct node *header,int value){
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->data=value;
    temp->next=NULL;
    struct node* ptr =header;
    while(ptr->next!=NULL){
        ptr=ptr->next;
    }
    ptr->next=temp;
}



void delete(struct node* header,int ele){
    struct node* ptr=header;
    struct node *temp;
    while (ptr->next != NULL)
    {
        if(ptr->next->data!=ele){
            ptr=ptr->next;
        }
        else{
            break;
        }
    }
    temp=ptr->next;
    ptr->next=ptr->next->next;
    free(temp);
}

int insertAfter(struct node *header, int target, int value)
{
    struct node *target_node = search(header, target);
    if (target_node == NULL)
    {
        printf("target value not found\n");
        return 1;
    }
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = value;
    temp->next = target_node->next;
    target_node->next = temp;
    return 0;
}

void display(struct node *header)
{
    struct node *temp = header->next;
    while (temp != NULL)
    {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void reverse(struct node *header)
{
    struct node *prev = NULL;
    struct node *curr = header->next;
    struct node *next = NULL;

    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    header->next = prev;
}
