#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<ctype.h>
#include<string.h>

typedef struct node{
    char data;
    struct node* left;
    struct node* right;
} node;

node* CreateNode(char data){
    node* temp = (node*)malloc(sizeof(node));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

bool isOperator(char c){
    return (c=='+'||c=='-'||c=='*'||c=='/'||c=='^');
}

node* CreateExpressionTree(char* postfix){
    node* stack[100];
    int top=-1;
    for(int i=0;postfix[i]!='\0';i++){
        char c=postfix[i];
        if(isspace(c)) continue;
        if(!isOperator(c)){
            stack[++top]=CreateNode(c);
        }else{
            node* t=CreateNode(c);
            t->right=stack[top--];
            t->left=stack[top--];
            stack[++top]=t;
        }
    }
    return stack[top];
}

void inorder(node* root){
    if(root==NULL) return;
    if(isOperator(root->data)) printf("(");
    inorder(root->left);
    printf("%c",root->data);
    inorder(root->right);
    if(isOperator(root->data)) printf(")");
}

void preorder(node* root){
    if(root==NULL) return;
    printf("%c",root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(node* root){
    if(root==NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%c",root->data);
}
