#include <stdio.h>
#include<stdlib.h>
struct Stack {
    int size;
    int top1;
    int top2;
    int *arr;         //one array
};

void createStack(struct Stack *st){
    printf("Enter stack size ");
    scanf("%d",&st->size);
    st->top1=-1;
    st->top2 = st->size;         //pointing the top
    st->arr = (int*)malloc(st->size*sizeof(int));


}
void Display1(struct Stack st){
    printf("\n Stack 1 :  ");
    for(int i=st.top1;i>=0; --i){
        printf("%d ", st.arr[i]);
    }
    printf("\n");
}
void Display2(struct Stack st){
      printf("\n Stack 2 :  ");
    for(int i=st.top2;i<st.size; ++i){
        printf("%d ", st.arr[i]);
    }
    printf("\n");
}

int isEmpty1(struct Stack *st){
    if(st->top1==-1){
        return 1;          //true
    }else{
        return 0;          //false
    }
}
int isEmpty2(struct Stack *st){
    if(st->top2==st->size){
        return 1;          //true
    }else{
        return 0;          //false
    }
}

int isFull(struct Stack *st){
    
    if(st->top1==st->top2-1){
        return 1;          //true
    }else{
        return 0;          //false
    }
}

void Push1(struct Stack *st, int val){
    if(isFull(st)){
        printf("Stack is Full\n");
    }else{
        st->top1++;
        st->arr[st->top1]=val;
    }
}
void Push2(struct Stack *st, int val){
    if(isFull(st)){
        printf("Stack is Full\n");
    }else{
        st->top2--;
        st->arr[st->top2]=val;
    }
}

int Pop1(struct Stack*st){
    int x=-1;
    if(isEmpty1(st)){
        printf("Stack 1 is Empty \n");
    }else{
       
        x = st->arr[ st->top1--];
    }
    return x;
}

int Pop2(struct Stack*st){
    int x=-1;
    if(isEmpty2(st)){
        printf("Stack 2 is Empty \n");
    }else{
       
        x = st->arr[ st->top1++];
    }
    return x;
}



int main(void) {
   struct Stack st;
   createStack(&st);

   Push1(&st, 9);
  Push1(&st, 4);
  
  Push2(&st, 11);

  Push1(&st, 7);
  Push1(&st, 2);

  Push2(&st, 8);   
    
   Push2(&st, 32);  // here stack will full if size=6, 
   Display1(st);
    Display2(st);

    printf("%d\n",Pop1(&st));
 printf("%d\n",Pop1(&st));
  printf("%d\n",Pop1(&st));
printf("%d\n",Pop1(&st));
printf("%d\n",Pop1(&st));  //stack1 should underflow here

//after pop
Display1(st);
Display2(st);
  return 0;
}
