#include<stdio.h>
#include<stdlib.h>
#include <time.h>


void swap(int a[],int i, int j){
    int temp =a[i];
    a[i]=a[j];
    a[j]=temp;
}

int par(int a[],int l,int h){
    int start=l;
    int end=h;
    int pivot=a[l];

    while(start<end){
        while(a[start]<=pivot){
            start++;

        }
        while(a[end]>pivot){
            end--;
        }
        if(start<end){
            swap(a,start,end);
        }
    }

    swap(a,l,end);
    return end;
}

void quick(int a[],int l,int h){

    if(l<h){
        int loc=par(a,l,h);
        quick(a,l,loc-1);
        quick(a,loc+1,h);

    }

}



int main(){

    int n;
    printf("enter the size of the array: ");
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++){
        printf("Enter the %d element: ",i);
        scanf("%d",&a[i]);
    }
   clock_t start_time, end_time;
    double time_taken;

    start_time = clock();
    quick(a, 0, n - 1);
    end_time = clock();

    printf("Sorted array: \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }

    time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
    printf("\nTime taken: %f seconds\n", time_taken);

    return 0;

}
