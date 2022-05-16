#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n[5];
    int min; // для поиска мин элемента
    int temp;

    printf("Введите числа \n");
    for(int i=0;i<5;i++){
       scanf("%d",&n[i]);
    }
    int i,j;
 
    for(i=0;i<5-1;i++) // орган цикл для всех элементов кроме последнего 
    {
        min=i; // запоминаем идекс текущего элемента 
        
        for(j=i+1;j<5;j++) 
            if(n[j]<n[min]) // если элемент меньше минимального 
            min=j; // запонимаем его 

        temp=n[i];
        n[i]=n[min];
        n[min]=temp;
    }
    printf("\n");
    printf("Массив после сорт : \n ");
    for(int i=0;i<5;i++)
        printf(" %d \n",n[i]);
    }
