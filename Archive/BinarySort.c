#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int arr[6]={10,11,12,13,15,18};
    int left=0,right=6;
    int number;
    int middle=0;
    int b=-1;

    // left указывает на 1 элемент массивa,a right на последний

    for(int i=0;i<6;i++)
    printf("Массив : %d ",arr[i]);

    printf("Введите искомый элемент ->\n");
    scanf("%d",&number);

        while(left<=right) // будет работать до такого момента покa right не станет меньше чем left,или пока left не станет больше чем right
        {
            middle=(left+right)/2; // указывает на центральное число
            if(number==arr[middle]){
                b=middle;
            printf("Искомый элемент есть в списке !\n");
            }


        if(number<arr[middle])
            right=middle-1; //  правая часть


            else
            left=middle+1; // левая часть
        }

        if(b==-1)
            printf("элемент не найден !\n");
}
