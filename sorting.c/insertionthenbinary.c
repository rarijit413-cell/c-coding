#include<stdio.h>
int binarySearch(int arr[],int low,int high,int key){
    if(low<=high){
        int mid= low+(high-low)/2;
        if(key==arr[mid]) return mid;
        if(arr[mid]<key){
            return binarySearch(arr,mid+1,high,key);
        }
        if(arr[mid]>key){
            return binarySearch(arr,low,mid-1,key);
        }
    }
    return -1;
}

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

void insertionsort(int arr[],int size){
    for(int i=1;i<size;i++){
        int curr=arr[i];
        int j=i-1;
        while(j>=0){
            if(arr[j]>curr){
                arr[j+1]=arr[j];
            }
            else{
                break;
            }
            j--;
        }
        arr[j+1]=curr;
    }
}

int main(){
    int arr[]={8,5,9,2,3,7};
    int size = sizeof(arr)/sizeof(arr[0]);
    int el;
    insertionsort(arr,size);
    display(arr,size);
    printf("\nenter the element you want to search :: ");
    scanf("%d",&el);
    int found= binarySearch(arr,0,size-1,el);
    if(found==-1) printf("not found");
    else printf("found");
    return 0;
}