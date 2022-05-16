#include <stdio.h>
#include <stdlib.h>




// addRecord функция получает указатель на коллекцию стундент карточек
// номер студента и балл и добавляет новую запись с этими даннымми в колекц

//averageRecord функция получает указатель на коллекцию стунденческих карточек и возращает
//среднее значение баллов студентов этой коллекции в формате double 




struct listStudent {
	int numberStudent;
	int colDown;
	listStudent* next;

};

typedef listStudent* OverFolf;



double averageRecord(OverFolf sc){

	int count = 0; // хранит количество пройденых узлов списка 

	double sum = 0;
	listStudent* loopPts = sc;
	while (loopPts != NULL)
	{
		sum += loopPts->colDown;
		count++;
		loopPts = loopPts->next;
	}

	double average = sum / count;
	return average;
}

void addRecord(OverFolf sc, int stuNum, int gr) {
	listStudent* newNode = new listStudent;
	newNode->numberStudent = stuNum;
	newNode->colDown = gr;
	newNode->next = sc;
	sc = newNode;
	printf("Unknown = %d \n", newNode->numberStudent);
}

int main(void)
{
	OverFolf secr;

	listStudent* once =(struct listStudent*)malloc(sizeof(struct listStudent));
		// new listStudent;
		
	
	once->numberStudent = 101;
	once->colDown = 12;

	listStudent* second = (struct listStudent*)malloc(sizeof(struct listStudent));
		
		//new listStudent;
	second->numberStudent = 321;
	second->colDown = 19;

	listStudent* thirth = (struct listStudent*)malloc(sizeof(struct listStudent));
		//new listStudent;

	thirth->numberStudent = 182;
	thirth->colDown = 22;

	secr = once; // 1 узел

	once ->next= second; // 2 узел
	second->next = thirth; //  3 узел

	printf("\nSecond = %d ", second->numberStudent);

	thirth->next= NULL; // присваевываем Null чтобы обозначить окончание структуры 

	 once = second= thirth = NULL; // обнуляем 

	printf("\nOnce = %d ", secr->numberStudent);
	printf("Once = %d\n", secr->colDown);

	addRecord(secr,99,3);
	double  avg = averageRecord(secr);

	printf("D - %lf\n ", avg);

	printf("\nProgramm good working !");

}