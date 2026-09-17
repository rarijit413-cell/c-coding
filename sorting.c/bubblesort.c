#include<stdio.h>
void swap(int *a,int *b){
    *a+=*b;
    *b=*a-*b;
    *a-=*b;
}
void display(int arr[],int size){//display array
    for(int i=0;i<size;i++){
        printf("%d",arr[i]);
    }
}
void bubblesort(int arr[],int size){
    for(int i=0;i<size-1;i++){
        for(int j=0;j<size-1-i;j++){
            if(arr[j]>arr[j+1]){
                swap(&arr[j],&arr[j+1]);
            }
        }
    }
}
int main(){
    int arr[6]={1,5,2,7,8,9};
    int size=sizeof(arr)/sizeof(arr[0]);
    bubblesort(arr,size);
    display(arr,size);
    return 0;
}