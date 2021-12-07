#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node * link;
}*l1=NULL;

void creat(int val){
    l1 = (struct Node*)malloc(sizeof(struct Node));
    l1->data = val;
    l1->link=NULL;
}

void Display(struct Node *p){
    printf("\nLinked List : ");
    while(p!=NULL){
        printf("%d ",p->data);
        p=p->link;
    }
}

void insert(struct Node *p, int val){
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->link = l1;
    l1 = newNode;
}

void reverse(struct Node *p){
    struct Node* q = NULL;
    struct Node* r = NULL;
    while(p!=NULL){
        r = q;
        q = p;
        p= p->link;
        q->link = r;
        
    }
    l1= q;
}

int main(void) {
   creat(29);
   insert(l1,22);
  insert(l1,20);
insert(l1,18);
insert(l1,17);
insert(l1,8);

  //before reversing
  printf("\n Before reversing the linked list");
  Display(l1);

reverse(l1);

  printf("\n\n After reversing the linked list");

Display(l1);
  

  return 0;
}
