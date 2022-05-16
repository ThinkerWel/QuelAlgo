#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int arr[6]={10,11,12,13,15,18};
    int left=0,right=6;
    int number;
    int middle=0;
    int b=-1;

   

    for(int i=0;i<6;i++)
    printf("Массив : %d ",arr[i]);

    printf("Введите искомый элемент ->\n");
    scanf("%d",&number);

        while(left<=right) 
        {
            middle=(left+right)/2;
            if(number==arr[middle]){
                b=middle;
            printf("Искомый элемент есть в списке !\n");
            }


        if(number<arr[middle])
            right=middle-1;


            else
            left=middle+1; 
        }

        if(b==-1)
            printf("элемент не найден !\n");
}
