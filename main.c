#include <stdio.h>
#include <stdlib.h>
 #include <time.h>
#define N 9

void BinarySort(int *arr,int right,int left);

int main(void)

{

    int arr[N]={11,-4,9,6,22,-1,19,20,97};
    printf("Массив изначально : ");
    for(int i=0;i<N;i++)
        printf(" %d ",arr[i]);

        printf("\n");

    BinarySort(arr,0,N-1);
    printf("Массив после сортировки : ");
     for(int i=0;i<N;i++)
    printf(" %d ",arr[i]);

}
void BinarySort(int *arr,int first,int last)
{
    if(first<last){

        int left=first;
    int right=last;
    int middle=arr[(left+right)/2];

    do{
            while(arr[left]<middle)
            left++;
    while(arr[right]>middle)
        right--;
    if(left<=right)
    {
        int tmp=arr[left];
        arr[left]=arr[right];
        arr[right]=tmp;
        left++;
        right--;

    }
        }while(left<right);

    BinarySort(arr,first,right);
    BinarySort(arr,left,last);
    }
    return 0;
}

