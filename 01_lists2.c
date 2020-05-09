#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

typedef struct node {
int value;
struct node *next;
struct node *prev;
} node;

typedef struct list {
struct node *head;
struct node *tail;
} list;

// инициализация пустого списка
void init(list *l) 
{
    l->head = l->tail = NULL;
}
// удалить все элементы из списка
void clean(list *l)
{
    node * tmp = NULL;
    while ((l->head->next) != NULL) 
    {
        tmp = l->head;
        l->head = l->head->next;
        free(tmp);
    }

    free(l->head);
}
// проверка на пустоту списка
bool is_empty(list *l)
{
    node * tmp = l->head;
    if (tmp != NULL) 
    {
        return (1); 
    }
}
// поиск элемента по значению. вернуть NULL если элемент не найден
node *find(list *l, int value)
{
    node * tmp = l->head;
    while ((tmp != NULL)&&(tmp->value != value)) 
    {
        tmp = tmp->next;
    }
    return tmp;
}
// вставка значения в конец списка, вернуть 0 если успешно
int push_back(list *l, int value)
{
    node *tmp = (node*) malloc(sizeof(node));
    if (tmp == NULL) 
    {
        exit(3);
    }

    tmp->value = value;
    tmp->next = NULL;
    tmp->prev = l->tail;

    if (l->tail)
    {
        l->tail->next = tmp;
    }

    l->tail = tmp;
 
    if (l->head == NULL) 
    {
        l->head = tmp;
    }
}
// вставка значения в начало списка, вернуть 0 если успешно
int push_front(list *l, int value)
{
    node *tmp = (node*) malloc(sizeof(node));
    if (tmp == NULL)
    {
        exit(1);
    }

    tmp->value = value;
    tmp->next = l->head;
    tmp->prev = NULL;

    if (l->head)
    {
        l->head->prev = tmp;
    }

    l->head = tmp;

    if (l->tail == NULL)
    {
        l->tail = tmp;
    }
}
// вставка значения после указанного узла, вернуть 0 если успешно
int insert_after(list *l, node *n, int value)
{
	if (n && n -> next)
	{
        node * tmp = malloc(sizeof(node));
        tmp->value = value;
        tmp->next = n->next;
        tmp->prev = n;
	    n -> next = tmp;
	    n -> next ->next -> prev = tmp;		
	    return 0;
	}

	else
	{
	    push_back(l, value);
	}

	return -1;
}
// вставка значения перед указанным узлом, вернуть 0 если успешно
int insert_before(list *l, node *n, int value)
{
	if (n && n -> prev)
	{
        node * tmp = malloc(sizeof(node));
        tmp->value = value;
        tmp->prev = n->prev;
        tmp->next = n;
	    n -> prev = tmp;
	    n -> prev ->prev -> next = tmp;		
	return 0;
	}

	else
	{
	    push_front(l, value);
	}

	return -1;
}
// удалить первый элемент из списка с указанным значением, 
// вернуть 0 если успешно
int remove_first(list *l, int value)
{
	if(l->head == NULL)
    {
	    return -1;
    }

	node * tmp = l->head;

	while (tmp->next)
	{
		if (tmp->value == value)
	    {
	        if (tmp->prev == NULL)
	        {
		        l->head = tmp->next;
		        tmp -> next -> prev = NULL;
		        free(tmp);
		        return 0;
	        }

	        if (tmp->next == NULL)
	        {
		        l->tail = tmp->prev;
		        tmp->prev->next = NULL;
		        free(tmp);
		        return 0;
	        }

	        tmp->prev->next = tmp->next;
	        tmp->next->prev = tmp->prev;
	        free(tmp);
	        return 0;

	    }

	    tmp = tmp->next;
	}
	return -1;
}
// удалить последний элемент из списка с указанным значением,
// вернуть 0 если успешно
int remove_last(list *l, int value)
{
	if(l->tail == NULL)
    {
	    return -1;
    }

	node *tmp = l->tail;

	while (tmp->prev)
	{
	    if (tmp->value == value)
	    {
	        if (tmp->next == NULL)
	        {
		        l->tail = tmp->prev;
		        tmp->prev->next = NULL;
		        free(tmp);
		        return 0;
	        }

	        if (tmp->prev == NULL)
	        {
		        l->head = tmp->next;
		        tmp -> next -> prev = NULL;
		        free(tmp);
		        return 0;
	        }

	        tmp->prev->next = tmp->next;
	        tmp->next->prev = tmp->prev;
	        free(tmp);
	        return 0;
	    }

	    tmp = tmp->prev;
	}
	return -1;
}
// вывести все значения из списка в прямом порядке через пробел,
// после окончания вывода перейти на новую строку

void print(list *l)
{
    node *tmp = l->head;
    while (tmp != NULL)
    {
        printf ("%d ", tmp -> value);
        tmp = tmp->next;
    }
    printf (" ");
}
// вывести все значения из списка в обратном порядке через пробел,
// после окончания вывода перейти на новую строку
void print_invers(list *l)
{
    node *tmp = l->tail;
    do
    {
        printf ("%d ", tmp -> value);
        tmp = tmp->prev;
    } while (tmp != NULL);
    printf (" ");
}

void check_bool(list *l, int value)
{
    if (find(l, value) != NULL)
    {
        printf("1 ");
    }
    else
    {
        printf("0 ");
    }
}
//Поиск номера элемента
node *number(list *l, int idx)
{
    node * tmp = l->head;
    int nomer = 0;

    while ((tmp != NULL)&&(nomer!= idx-1)) 
    {
        tmp = tmp->next;
        nomer++;
    }
    return tmp;
}
    
int main()    
{
    int n, x, elem;
    int i = 1;
    list l = {0};

    int check = scanf("%d", &n);
    assert(check == 1);
    while (i <= n)
    {
        check = scanf("%d", &x);
        assert(check == 1);
        push_back(&l, x);
        i++;
    }
    print(&l);
    printf("\n");

//Нахождение элементов в списке
    i = 1;
    while (i <= 3)
    {
        check = scanf("%d", &x);
        assert(check == 1);
        check_bool(&l, x);
        i++;
    }
    printf("\n");
        
//Добавление в конец
    check = scanf("%d", &x);
    assert(check == 1);
    push_back(&l, x);
    print_invers(&l);
    printf("\n");

//Добавлние в начало
    check = scanf("%d", &x);
    assert(check == 1);
    push_front(&l, x);
    print(&l);
    printf("\n");

//Добавление после указанного элемента
    check = scanf("%d", &x);
    assert(check == 1);
    check = scanf("%d", &elem);
    assert(check == 1);
    node * insert_head = number(&l, x);
    insert_after(&l, insert_head, elem);
    print_invers(&l);
    printf("\n");

//Добавление перед указанным элементом
    check = scanf("%d", &x);
    assert(check == 1);
    check = scanf("%d", &elem);
    assert(check == 1);
    node * insert_tail = number(&l, x);
    insert_before(&l, insert_tail, elem);
    print(&l);
    printf("\n");

//Удалить первый элемент равный введенному
    check = scanf("%d", &x);
    assert(check == 1);
    remove_first(&l, x);
    print_invers(&l);
    printf("\n");

//Удалить последний элемент равный введенному
    check = scanf("%d", &x);
    assert(check == 1);
    remove_last(&l, x);
    print(&l);
    printf("\n");

//Очистить список
    clean(&l);
    return 0;
}
