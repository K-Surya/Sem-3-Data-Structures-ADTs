struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

struct node *createNode()
{
    struct node *node = (struct node *)malloc(sizeof(struct node));
    node->next = NULL;
    node->prev = NULL;
    return node;
}

void insertFront(struct node *header, int value)
{
    struct node *temp = createNode();
    temp->data = value;
    temp->next = header->next;
    header->next = temp;
    temp->prev = header;
}

void insertEnd(struct node *header, int value)
{
    struct node *temp = createNode();
    temp->data = value;
    struct node *ptr = header;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    temp->next = ptr->next;
    temp->prev = ptr;
    ptr->next = temp;
}

void display(struct node *header)
{
    struct node *ptr = header->next;
    printf("Header<->");
    while (ptr != NULL)
    {
        printf("%d<->", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}

struct node *search(struct node *header, int value)
{
    struct node *ptr = header->next;
    while (ptr != NULL)
    {
        if (ptr->data == value)
        {
            return ptr;
        }
        ptr = ptr->next;
    }
    return ptr;
}

void insertAfter(struct node *header, int target, int value)
{
    struct node *temp = createNode();
    temp->data = value;
    struct node *ptr = search(header, target);
    if (ptr == NULL)
    {
        printf("failed");
        return;
    }
    if (ptr->next != NULL)
    {
        (ptr->next)->prev = temp;
    }
    temp->next = ptr->next;
    ptr->next = temp;
    temp->prev = ptr;
}

void deleteFront(struct node *header)
{
    if (header->next == NULL)
    {
        printf("failed");
    }
    struct node *ptr = header;
    header->next = (header->next)->next;
    if (header->next->next != NULL)
    {
        ((header->next)->next)->prev = header;
    }
}

void deleteEnd(struct node *header)
{
    if (header->next == NULL)
    {
        printf("failed");
    }
    struct node *ptr = header;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    (ptr->prev)->next = NULL;
}

void delete(struct node *header, int target)
{

    struct node *ptr = search(header, target);
    if (ptr == NULL)
    {
        printf("Failed");
        return;
    }
    if (ptr->prev != NULL)
    {
        (ptr->prev)->next = ptr->next;
    }
    if (ptr->next != NULL)
    {
        (ptr->next)->prev = ptr->prev;
    }
}
