#include <stdlib.h>
#include <stdio.h>


struct  bee {
    int key;
    char data;
};

struct bee *array;
int size=0;
int tabl=10;

int HashFunct(int n)
{
    return (n%tabl);

}
int checkPrime( int n)
{
    int i;
    if(n==1||n==0)
    {
        return 0;
    }
    for(i=2;i<n/2;i++){
        if(n%i==0)
        {
            return 0;
        }
    }
    return 1;
}
int getPrime(int n)
{
    if(n%2==0)
    {
        n++;
    }
    while(!checkPrime(n))
    {
        n+=2;
    }
    return n;
}

void init_array()
{
    tabl=getPrime(tabl);
    array=(struct bee*)malloc(tabl*sizeof(struct bee));
    for(int i=0;i<tabl;i++)
    {
        array[i].key=0;
        array[i].data=0;
    }
}

void initTabl(int key,int data)
{
      int index=HashFunct(key);
      if(array[index].data==0)
      {
          array[index].key=key;
          array[index].data=data;

          size++;
          printf("\n Ключ(%d) вставлен \n",key);
      }
      else if(array[index].key==key)
      {
          array[index].data=data;
      }
      else
      {
          printf("\n Возникла коллизия\n");
      }
}

void remove_key(int key)
{
     int index=HashFunct(key);
     if(array[index].data==0)
     {
         printf("Данного ключа не существует \n");
     }
     else
     {
         array[index].key=0;
         array[index].data=0;
         size--;
         printf("\nКлюч (%d) удален\n",key);
     }
}

void display()
{
    int i=0;
    for(i=0;i<tabl;i++)
    {
        if(array[i].data==0){
            printf("\n array[%d]:/",i);
        }
        else
        {
            printf("\nКлюч :%d array[%d]:%d \t",array[i].key,i,array[i].data);
        }
    }

}
int sizeHashTabl()
{
    return size;
}

int main(void)
{
    int data,key;
    int choice;
    int n;
    int pasr=0;
    init_array();

    do{
    printf("1.Узнать размер Хэш функции "
           "\n2. Удалить элемент из хэш-таблицы "
           "\n3.Вставить элемент в хэш таблицу "
           "\n4.Вывести хэш таблицу");
           printf("\n");


    scanf("%d",&choice);
    switch(choice){
     case 1:

    n=sizeHashTabl();
    printf("Размер хэш функции = %d \n",n);
    break;

     case 2 :
         printf("Введите ключ который хотите удалить \n");
         scanf("%d",&key);
        remove_key(key);
        break;

     case 3 :
        printf("Введите ключ :/t");
        scanf("%d",&key);
        printf("Введите номер игрока  :\t");
        scanf("%d",&data);

       initTabl(key,data);
       break;

     case 4:
        display();
        break;
     default:
        printf("NO\n");
    }
    printf("\nПродолжить?(нажмите 1,если да):");
    scanf("%d",&pasr);
        }while(pasr==1);
}
