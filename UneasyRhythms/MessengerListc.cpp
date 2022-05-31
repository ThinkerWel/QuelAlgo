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





//#ifndef LIST_H_
//#define LIST_H_

#define TSIZE 45

struct film {
    char title[TSIZE];
    int rating;
};
typedef struct film Item;

typedef struct node {
    Item item;
    struct node* next;
}Node;


typedef Node* List;

//typedef struct list {
  //  Node* head;
    //int size;
//}List;


void showmovies(Item item);
char* s_gets(char* st, int n);
void InitializeList(List* plist);

bool ListIsEmpty(const List* plist);
bool ListIsFull(const List *plist);

static void CopyToNode(Item item, Node* pnode);
unsigned int ListItemCount(const List* plist);

bool AddItem(Item item, List* plist);
void Traverse(const List* plist, void(*pfun)(Item item));

void EmptyTheList(List* plist);

// plist указывает на инициализированный список
// pfun указывает на функцию которая примент аргумент item и не имеет возращаемого зн
// Pfun являетсчя указателем на функцию 

int main(void)
{
    List movies;
    Item temp;

    InitializeList(&movies);
    // иниализация 
    if (ListIsFull(&movies))
    {
        fprintf(stderr, "Memory lose ! Programm exit \n");
        exit(1);
    }
    // сбор и сохранение информации 
    puts("Enter name film : ");
    while (s_gets(temp.title, TSIZE) != NULL && temp.title[0] != '\0')
    {
        puts("Enter rait :");
        scanf("%d", &temp.rating);
        while (getchar() != '\n')
            continue;

        if (AddItem(temp, &movies) == false)
        {
            fprintf(stderr, "Problem witch memory ");
            break;
        }
        if (ListIsFull(&movies)) {
            puts("List full ");
            break;
        }
        puts("Enter name next film (or enough string for exit )");
    }
    // отображение 
    if (ListIsEmpty(&movies))
        printf("Date enter't ");
    else
    {
        printf("List film  : \n");
        Traverse(&movies, showmovies);
    }
    printf("You enter %d film \n", ListItemCount(&movies));
    // очистка
    EmptyTheList(&movies);
    printf("\n\nProgram exit !");
    return 0;
    
}
void showmovies(Item item)
{
    printf("Film : %s Rait = %d ", item.title, item.rating);
}

char* s_gets(char* st, int n)
{
    char* ret_val;
    char* find;

    ret_val = fgets(st, n, stdin);
    if (ret_val)
    {
        find = strchr(st, '\n');
        if (find)
            *find = '\0';
        else
            while (getchar() != '\n')
                continue;
    }
    return ret_val;
}




// функция интерфейса 
// устанавливает список в пустое состоние

void InitializeList(List* plist)
{
    *plist= NULL;
}

// возращает true если список пуст
bool ListIsEmpty(const List* plist)
{
    if (*plist == NULL)
        return true;
    else
        false;
}

// возращает true если список полон 
bool ListIsFull(const List* plist)
{
    Node* pt;
    bool full;
    pt = (Node*)malloc(sizeof(Node)); // пытается выделить память, если это не удается список полон 
    if (pt == NULL)
        full = true;
    else
        full = false;
    free(pt);
    return full;

}
 
// возращает количество узлов

unsigned int ListItemCount(const List* plist)
{
    unsigned int count = 0;
    Node* pnode = *plist;// установка начало списка 

    while (pnode != NULL)
    {
        ++count;
        pnode = pnode->next; // установка следущий узел
    }

    return count;
}

// создает узел для хранения элемента и добавляет его в конец
// списка указанного переменой plist (медленая реализация)

bool AddItem(Item item, List* plist)
{
    Node* pnew;
    Node* scan = *plist;

    pnew = (Node*)malloc(sizeof(Node));
    if (pnew == NULL)
        return false; // выход из функции в случае ошибки 
    
    CopyToNode(item, pnew);
        pnew->next = NULL;// это является сигналом того что узел последний в списке 
    if (scan == NULL) // список пуст,поэтому поместить 
        *plist = pnew; // в начало списка 
    else
    {
        while (scan->next != NULL)
            scan = scan->next; // поиск конца списка
        scan->next = pnew; // добавление pnew  в конец 
    }

    return true;
}

// посещает каждый узел и выполняет функцию,указанную pfun

void Traverse(const List* plist, void(*pfun)(Item item))
{
    Node* pnode = *plist; // установка начало списка 
    while (pnode != NULL)
    {
        (*pfun)(pnode->item);  // применение функции к элементу 
        pnode = pnode->next; // переход к следующему элементу 

    }
}
// освобождает память,выделенную функцией malloc()
// устанавливает указатель списка Null

void EmptyTheList(List* plist)
{
    Node* psave;
    while (*plist != NULL)
    {
        psave = (*plist)->next; // сохрн адреса следущего узла
        free(*plist); 
        *plist = psave; // перех к следущему узлу
    }
}

// определение локальной функции 
// копирует элемент в узел
static void CopyToNode(Item item, Node* pnode)
{
    pnode->item = item; // копирование структуры 
}
