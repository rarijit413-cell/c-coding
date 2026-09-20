#include<stdio.h>
#define max 5
int queue[max];
int front=-1;
int rear=-1;

int isEmpty(){
    return front==-1 && rear== -1;
}

int isFull(){
    return rear== max-1;
}

void enqueue(int value){
    if(isFull()){
        printf("stack overflow");
        return;
    }
    else{
        if(front=-1) front=0;
        rear++;
        queue[rear]=value;
    }
}

void dequeue(){
    if(isEmpty()){
        printf("stack empty");
        return ;
    }
    else{
        front++;
    }
    
}

void display(){
    printf("queue is -> ");
    for(int i=front;i<=rear;i++){
        printf("%d ",queue[i]);
    }
    printf("\n");
}

int main(){
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    display();
    dequeue();
    display();
    return 0;
}