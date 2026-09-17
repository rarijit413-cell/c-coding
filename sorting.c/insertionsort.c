#include<stdio.h>
void display(int arr[],int size){//display array
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
}
void insertionsort(int arr[],int size){
    for(int i=1;i<size;i++){
        int curr=arr[i];
        int j=i-1;
        while(j>=0&&curr<arr[j]){
                arr[j+1]=arr[j];
                j--;
        }
        arr[j+1]=curr;
    }
}
int main(){
    int arr[6]={1,5,2,7,8,9};
    int size=sizeof(arr)/sizeof(arr[0]);
    insertionsort(arr,size);
    display(arr,size);
    return 0;
}