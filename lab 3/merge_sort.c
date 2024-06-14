#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX 10

void merge(int a[],int l,int h,int mid){
    int i, j, k;
    i=l;
    j=mid+1;
    k=l;
    int b[MAX];
    while (i<=mid && j<=h)
    {
        if (a[i]<=a[j])
        {
            b[k]=a[i];
            i++;
            k++;
        }
        else{
            b[k]=a[j];
            j++;
            k++;
        }

    }

    while (i<=mid)
    {
        b[k]=a[i];
        i++;
        k++;
    }

    while (j<=h)
    {
        b[k]=a[j];
        j++;
        k++;
    }
    for (int v = l; v <=h; v++)
    {
        a[v]=b[v];
    }

}


void mergesort(int a[],int l,int h){
    if (l<h)
    {
        int mid=(l+h)/2;
        mergesort(a,l,mid);
        mergesort(a,mid+1,h);
        merge(a,l,h,mid);

    }

}


int main(){
    int n;
    printf("Eter the size of the Array: ");
    scanf("%d",&n);
     if (n>MAX)
        {
         printf("the array size is exceeded\n");
        return 1;
        }

    int a[MAX];
    for (int i = 0; i <n; i++)
    {
        scanf("%d",&a[i]);
    }

    int l=0;
    int h=n-1;
    clock_t start_time, end_time;
double time_taken;

start_time = clock();
mergesort(a,l,h);
end_time = clock();



time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
printf("\nTime taken: %f seconds\n", time_taken);




    printf("the sorted array is: ");
    for(int i=0;i<n;i++){
        printf("%d \t",a[i]);
    }

}
