#include<stdio.h>
#define max 5
int stack[max];
int top = -1;

int isFull(){
    return top==max-1;
}

int isEmpty(){
    return top == -1;
}

void push(int value){
    if(isFull()){
        printf("stack overflow");
        return;
    }
    else{
        stack[++top]= value;
        printf("\n%d value pushed successfully",value);
    }
}

void pop(){
    if(isEmpty()){
        printf("stack empty");
        return;
    }
    else{
        printf("\n%d popped successful",top--);
    }
}

void peak(){
    if(isEmpty()){
        printf("stack empty");
        return;
    }
    else{
        printf("top element = %d",top);
    }
}

void display(){
    printf("\nstack is -> \n");
    for(int i=top;i>=0;i--){
        printf("%d ",stack[i]);
        printf("\n");
    }
}

int main(){
    push(10);
    push(20);
    push(30);
    push(40);
    push(50);
    display();
    pop();
    pop();
    display();
    peak();
    return 0;
}