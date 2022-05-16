#include <stdio.h>
#include <stdlib.h>



struct study {
	int estimation;
	int numberStudy;

	study* next;
};

typedef study *CollectionOne;


double midleElement(CollectionOne sc)
{
	int number = 0;
	double sum = 0;
	study* four = sc;
	while (four != NULL)
	{
		sum += four->estimation;
		number++;
		four = four->next;
	}
	double average = sum / number;
	return average;
}



void newRecord(CollectionOne sc, int estN, int numberN)
{
	study* oneN = (struct study*)malloc(sizeof(struct study*));

	oneN->estimation = estN;
	oneN->numberStudy =numberN;
	oneN->next = sc;

	sc=oneN;
	printf("More - %d \n", oneN->estimation);
	printf("Better - %d \n", oneN->numberStudy);
}


int main()
{
	CollectionOne sc;

	study* one = (struct study*)malloc(sizeof(struct study*));
	one->estimation = 5;
	one->numberStudy = 182;

	study* two = (struct study*)malloc(sizeof(struct study*));
	two->estimation = 9;
	two->numberStudy = 137;

	study* three = (struct study*)malloc(sizeof(struct study*));
	three->estimation = 6;
	three->numberStudy = 88;

	sc = one;

	one->next = two;
	two->next = three;
	three->next = NULL;

	one = two = three = NULL;

	newRecord(sc, 12, 101);
	
	double age = midleElement(sc);
	printf("Lest - %lf \n ", age);

}