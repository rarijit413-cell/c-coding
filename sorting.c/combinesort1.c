#include<stdio.h>
void bubbleSort(int arr[],int size);
void swap(int *a, int *b);
void display(int arr[],int size);
void quicksort(int arr[],int low,int high);
int searchpivot(int arr[],int low,int high);
void mergeSort(int arr[],int low,int high);
void merge(int arr[],int low,int mid,int high);

void display(int arr[],int size){
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
}

void swap(int *a, int *b){
    int temp = *a;
    *a=*b;
    *b=temp;
}

void mergeSort(int arr[],int low,int high){
    int mid= low+(high-low)/2;
    if(low<high){
        mergeSort(arr,low,mid);
        mergeSort(arr,mid+1,high);
        merge(arr,low,mid,high);
    }
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


void bubbleSort(int arr[],int size){

    int ch;
    printf("do you want to print outerloop -- \n1. yes\n2. no");
    printf("\nenter your choice : ");
    scanf("%d",&ch);

    int check = 0;
    for(int i=0;i<size-1;i++){
        for(int j=0;j<size-1-i;j++){
            if(arr[j]>arr[j+1]){
                swap(&arr[j],&arr[j+1]);
                check=1;
            }
        }
        if(ch==1){
            display(arr,size);
            printf("\n");
        }
        if(check==0) return;
    }
    if(ch==2) return;
}

void selectionSort(int arr[],int size){

    int ch;
    printf("do you want to print outerloop -- \n1. yes\n2. no");
    printf("\nenter your choice : ");
    scanf("%d",&ch);

    for(int i=0;i<size-1;i++){
        int min_idx=i;
        for(int j=i+1;j<size;j++){
            if(arr[min_idx]>arr[j]){
                min_idx=j;
            }
        }
        swap(&arr[min_idx],&arr[i]);
        if(ch==1){
            display(arr,size);
            printf("\n");
        }
    }
    if(ch==2) return;
}

void insertionSort(int arr[],int size){
    int ch;
    printf("do you want to print outerloop -- \n1. yes\n2. no");
    printf("\nenter your choice : ");
    scanf("%d",&ch);

    for(int i=0;i<size;i++){
        int curr = arr[i],j=i-1;
        while(j>=0&&arr[j]>curr){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=curr;
        if(ch==1){
            display(arr,size);
            printf("\n");
        }
    }
    if(ch==2) return;
}

void chart(int arr[], int size){
    printf("1.insertonSort\n2.selectionSort\n3.bubbleSort\n4.quickSort\n5.mergeSort\n");
    int ch;
    printf("\nenter your choice : ");
    scanf("%d",&ch);
    switch(ch){
        case 1: 
                insertionSort(arr,size);
                break;
        case 2: 
                selectionSort(arr,size);
                break;
        case 3:
                bubbleSort(arr,size);
                break;
        case 4: 
                quicksort(arr,0,size-1);
                break;
        case 5: 
                mergeSort(arr,0,size-1);
                break;
        default:
                printf("wrong input");

    }

}
int main (){
    int arr[]={5,6,10,4,1,2,3,7,9,1};
    int size = sizeof(arr)/sizeof(arr[0]);
    chart(arr,size);
    printf("sorted array is --");
    display(arr,size);
    return 0;
}