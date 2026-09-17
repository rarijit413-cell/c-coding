#include<stdio.h>
void quicksort(int arr[],int low,int high);
int searchpivot(int arr[],int low,int high);
void display(int arr[],int size);
void swap(int *a,int *b);

int main(){
    int arr[6]={5,8,4,7,2,6};
    int size=sizeof(arr)/sizeof(arr[0]);
    quicksort(arr,0,size-1);
    display(arr,size);
    return 0;
}

void display(int arr[],int size){
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
}

void quicksort(int arr[],int low,int high){
    if(low>=high) return ;
    int part = searchpivot(arr,low,high);
    quicksort(arr,low,part-1);
    quicksort(arr,part+1,high);
}

int searchpivot(int arr[],int low,int high){
    int i=low-1,pivot=arr[high];
    for(int j=low;j<high;j++){
        if(arr[j]<=pivot){
            i++;
            swap(&arr[i],&arr[j]);
            display(arr,high+1);
            printf("\n");
        }
    }
    swap(&arr[i+1],&arr[high]);
    return i+1;
}

void swap(int *a,int *b){
    int temp = *a;
    *a=*b;
    *b=temp;
}