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
 // 1 2 3 4 5 6 7 8 9 10
    if(first<last){

        int left=first;  // 0 (1)
    int right=last;   // 10(9)
    int middle=arr[(left+right)/2]; // (5)

    do{
            while(arr[left]<middle) // пока left [0] - (1) будет меньше чем middle [4] - (5) будем увеличивать left 
            left++;
    while(arr[right]>middle)
        right--;
    if(left<=right) // проверка [0] before [9]
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

