
#define MAXQUEUE 10

// очередь целых чисел
typedef int Item;

typedef struct node {
	Item item;
	struct node* next;
}Node;

typedef struct queue {
	Node* front; // указатель на начало очереди 
	Node* rear; // указатель на конец очереди 
	int items; // кол элементов в очереди
}Queue;

bool isFull(const Queue* pq);
bool EmptyQueue(const Queue* pq);
int QueueItemCount(const Queue* pq);
bool EnQueue(Item item, Queue* pq);
static void CopyToItem(Node* pn, Item* pi);
static void CopyToNode(Item item, Node* pn);
bool Dequeue(Item* pitem, Queue* pq);
void EmptyTheQueue(Queue* pq);
void InitializeQueue(Queue* pq); // инициалзиция очереди пустым содержимым,означает установка укзаатель на начало и конец очереди


int main(void)
{
	Queue line;
	Item temp;
	char  ch;
	InitializeQueue(&line);
	printf("Test interface Queue,enter a , to add meaning,");
	printf("enter d,to remove meaning, or enter q for exit of program ");
	while ((ch = getchar()) != 'q')
	{
		if (ch != 'a' && ch != 'd')
			continue;
		if (ch == 'a')
		{
			printf("The whole number for add: ");
			scanf("%d", &temp);
			if (!isFull(&line))
			{
				printf(" %d in queue \n", temp);
				EnQueue(temp, &line);
			}
			else
				printf("Queue full !");
		}
		else {
			if (EmptyQueue(&line))
				printf("Element for remove not ");
			else
			{
				Dequeue(&temp, &line);
				printf("Remove %d of queue \n", temp);
			}
		}
		printf("%d element in queue \n", QueueItemCount(&line));
	}
	EmptyTheQueue(&line);
	printf("Program end \n");
}

void InitializeQueue(Queue* pq)
{
	pq->front=pq->rear = NULL;
	pq->items = 0;
}

// проверка полна ли очередь 
bool isFull(const Queue* pq)
{
	return pq->items == MAXQUEUE;
}

// проверка пуста ли очередь 
bool EmptyQueue(const Queue* pq)
{
	return pq->items == 0;

}

int QueueItemCount(const Queue* pq)
{
	return pq->items;

}

//создаем новый узел, копирование элемента в этот узел,индефицируем узел как последний в списке (Null)
//устаановка указателя next текущего узла так чтобы он ссылался на новый узел связывая его с очередью
// установка указателя rear для ссылки на новый узел,и инкриминтируем 

bool EnQueue(Item item, Queue* pq)
{
	Node* pnew;
	if (isFull(pq))
		return false;

	pnew = (Node*)malloc(sizeof(Node));
	if (pnew == NULL)
	{
		printf("Eror give memory ");
		exit(1);
	}
	CopyToNode(item, pnew);
	pnew->next = NULL;
	if (EmptyQueue(pq))
		pq->front = pnew;
	else
		pq->rear->next = pnew;
	pq->rear = pnew;
	pq->items++;
	return true;

}

// копирование элемента в ожидающую переменную,освобождение памяти,которая используется удаляемым узлом
// переустановка указателя на начало очереди чтобы он ссылался на следующий элемент в очереди 
// Установка указателя на начало и конец очереди в Null,если удален последний элемент,и дикриминтируем 

bool Dequeue(Item* pitem, Queue* pq)
{
	Node* pt;
	if (EmptyQueue(pq))
		return false;
	CopyToItem(pq->front, pitem);
	pt = pq->front;
	pq->front = pq->front->next;
	free(pt);
	pq->items--;

	if (pq->items == 0)
		pq->rear = NULL;
	return true;

}

// для опустошения очереди 
void EmptyTheQueue(Queue* pq)
{
	Item dummy;
	while (!EmptyQueue(pq))
		Dequeue(&dummy, pq);
}

 
static void CopyToNode(Item item,Node *pn)
{

	pn->item = item;
}

static void CopyToItem(Node* pn, Item* pi)
{
	*pi = pn->item;
}
