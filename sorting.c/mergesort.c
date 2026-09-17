#include<stdio.h>
void mergeSort(int arr[],int low,int high);
void display(int arr[],int size);
void merge(int arr[],int low,int mid,int high);

void mergeSort(int arr[],int low,int high){
    int mid= low+(high-low)/2;
    if(low<high){
        mergeSort(arr,low,mid);
        mergeSort(arr,mid+1,high);
        merge(arr,low,mid,high);
    }
}

void display(int arr[],int size){
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

void merge(int arr[],int low,int mid,int high){
    int n1=mid-low+1;
    int n2= high-mid;
    int l[n1],r[n2];
    for(int i=0;i<n1;i++){
        l[i]=arr[low+i];
    }
    for(int i=0;i<n2;i++){
        r[i]=arr[mid+1+i];
    }
    int i=0,j=0,k=low;
    while(i<n1&&j<n2){
        if(l[i]<r[j]){
            arr[k]=l[i];
            i++;
        }
        else{
            arr[k]=r[j];
            j++;
        }
        k++;
    }
    while(i<n1){
        arr[k]=l[i];
        k++;
        i++;
    }
    while(j<n2){
        arr[k]=r[j];
        j++;
        k++;
    }
}

int main(){
    int arr[]={5,6,7,8,1,2,3,4};
    int size= sizeof(arr)/sizeof(arr[0]);
    mergeSort(arr,0,size-1);
    display(arr,size);
}