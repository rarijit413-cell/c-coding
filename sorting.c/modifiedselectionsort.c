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
    for(int i=0;i<size/2;i++){
        int min_idx=i,max_idx=i;
        for(int j=i+1;j<size-i;j++){
            if(arr[min_idx]>arr[j]){
                min_idx=j;
            }
            if(arr[max_idx]<arr[j]){
                max_idx=j;
            }
            
        }
        if(max_idx == i){
            max_idx = min_idx;
        }
        swap(&arr[i],&arr[min_idx]);
        swap(&arr[size-1-i],&arr[max_idx]);
        display(arr,size);
        printf("\n");
    }
}
int main(){
    int arr[6]={6,4,7,8,1,9,5};
    int size=sizeof(arr)/sizeof(arr[0]);
    selectionsort(arr,size);
    display(arr,size);
    return 0;
}