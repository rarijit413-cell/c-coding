#include<stdio.h>
void swap(int *a,int *b){
    int temp=*b;
    *b=*a;
    *a=temp;
}

void display(int arr[],int size){//display array
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
}

void selectionsort(int arr[],int size){
    for(int i=0;i<size-1;i++){
        int min_idx=i;
        for(int j=i+1;j<size;j++){
            if(arr[min_idx]>arr[j]){
                min_idx=j;
            }
        }
        swap(&arr[i],&arr[min_idx]);
    }
}
int main(){
    int arr[6]={1,5,2,7,8,9};
    int size=sizeof(arr)/sizeof(arr[0]);
    selectionsort(arr,size);
    display(arr,size);
    return 0;
}