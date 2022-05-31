typedef struct Node {
	int price;
	int numberStudent;
	struct Node* next;
}Node;

Node* create(int prc, int num)
{
	Node* add = (struct Node*)malloc(sizeof(struct Node));
	add->price = prc;
	add->numberStudent = num;
	add->next =NULL;

	return add;
}

void AddElement(Node** newS,int prc,int num)
{
	Node* add = create(prc, num);
	add->next = *newS;
	*newS = add;
}

void AddEnd(Node** newS, int prc, int num)
{
	Node* enough = create(prc, num);
	Node* copy = *newS;

	while (copy->next != NULL)
	{
		copy = copy->next;

	}
	copy->next = enough;
}


int  MidleElement(Node** mid)
{
	int number=0;
	int sum = 0;
	Node* f = *mid;
	while (f->next != NULL)
	{
		sum += f->price;
		sum += f->numberStudent;
		number++;
		f = f->next;
	}

	int average = sum / number;
	printf("Middle = %d\n ", average);
	return average;
}


int main(void)
{
	Node* addly = create(115, 11);
	AddElement(&addly,270,19);

	AddEnd(&addly, 540, 6);
	MidleElement(&addly);

	Node* copy = addly;

	while (copy->next != NULL)
	{
		if (copy->numberStudent == 19 || copy->price==115) {
			Node* newS = create(22, 88);
			newS->next = copy->next;
			copy->next = newS;
		}
		copy = copy->next;
	}


	while (addly != NULL)
	{
		printf("P = %d   N = %d ", addly->price, addly->numberStudent);
		addly = addly->next;
	}
}

