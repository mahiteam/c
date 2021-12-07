#include <stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *link;
}*l1=NULL;

void creat(int val){   
    l1 = (struct Node*)malloc(sizeof(struct Node));
    l1->data = val;
    l1->link=NULL;

}

//inserting at begining of the list
void insert(int val){
    struct Node *t ;
    t = (struct Node*)malloc(sizeof(struct Node));
    t->data = val;
    t->link = l1;
    l1 = t;
}

void Display(){
    struct Node *t = l1;
    printf("\nLinked List: ");
    while(t!=NULL){
        printf("%d ",t->data);
        t=t->link;
    }
    printf("\n");
}

void insertAtSoretedPlace(int val){
    struct Node *t = l1;
    int count=0;
    while(1){           // till all
     struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
        if(val<=t->data && count==0){ //checking is it smallest and the places to be in begining?
     
            newNode->data = val;
            newNode->link = t;
            l1 = newNode;
            
           
           break;
        }else if(t->link==NULL){   //checking if there are no node after this node

            newNode->data = val; // if not then assigning at last in the list
            newNode->link = NULL;
            t->link = newNode;
            break;
        }else if(val>=t->data && val<= t->link->data){ // in between
       
            newNode->data = val;
            newNode->link = t->link;
            t->link = newNode;
                break;
            
            }
         t = t->link;
            count=1;
    }
}


int main(void) {

    //creating linked list
  creat(24);
  insert(22);
  insert(20);
  insert(10);
  insert(3);
  //sorted linked list
  Display();

  //after inserted at sorted place
  printf("\n inserting 2");
  insertAtSoretedPlace(2);    // inserting the smallest element
   Display(); 
  printf(" \n inserting 9 ");
  insertAtSoretedPlace(10);     // in between
   Display(); 
  printf(" \n inserting 49 ");
insertAtSoretedPlace(49);      // inserting larger one
 Display(); 
}
