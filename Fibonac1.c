#include <stdio.h>
#include <stdlib.h>

int funcFub(int N);

int main(void)
{
   int N;

   printf(" N = ");
   scanf("%d",&N);
   for(int i=1;i<=N;i++)

   printf(" %d ",funcFub(i));
   return 0;
}
int funcFub(int N)
{
    if(N==1 || N==2)
        return 1;
    return funcFub(N-1)+funcFub(N   -2);

}

//
long factorial(long n)
{
	if (n==0 || n==1)
		return 1;
	return factorial(n - 1) * n;
}
//
