#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>



typedef struct node {
	int value;          // значение, которое хранит узел 
	struct node *next;  // ссылка на следующий элемент списка
} node;

typedef struct list {
	struct node *head;  // начало списка
} list;


// инициализация пустого списка
void init(list *l)
    {
        l->head = NULL;
    }

// удалить все элементы из списка
void clean(list *l)
    {
        node *tmp = NULL;
        while (l->head->next) 
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
        node *tmp = l->head;
        if (tmp) 
            {
                return 1; 
            }
    }

// поиск элемента по значению. вернуть NULL если элемент не найден
node *find(list *l, int value)
    {
        node *tmp = l->head;
        while ((tmp != NULL)&&(tmp->value != value)) 
        {
            tmp = tmp->next;
        }
        return tmp;
    }

// вставка значения в конец списка, вернуть 0 если успешно
int push_back(list *l, int value)
    {
        if(l->head != NULL)
        {
            node *tmp = l->head;
            while (tmp->next != NULL) 
            {
                tmp = tmp->next;
            }
	tmp->next = malloc(sizeof(node));
	tmp->next->value = value;
	tmp->next->next = NULL;
	return 0;
        }
	else
	{
	node *tmp = malloc(sizeof(node));
	tmp->value = value;
	tmp->next = l->head;
	l->head = tmp;
	return 0;
	}
    }

// вставка значения в начало списка, вернуть 0 если успешно
int push_front(list *l, int value)
    {
        node *tmp = calloc(1, sizeof(node));
        if (!tmp) 
        {
            return -1;
        }
        tmp->value = value;
        tmp->next = l->head;
        l->head = tmp;
        return 0;
    }

// вставка значения после указанного узла, вернуть 0 если успешно
int insert_after(node *n, int value)
    {
        node *tmp = calloc(1, sizeof(node));
        tmp->value = value;
        tmp->next = n->next;
        n->next = tmp;
		return 0;
    }

// удалить первый элемент из списка с указанным значением, 
// вернуть 0 если успешно
int remove_node(list *l, int value)
{
    if(l->head == NULL)
        return -1;
        
    node *tmp = l->head;
    node *pred = NULL;
    while (tmp->next) 
    {
        if (tmp->value == value)
        {
            if (pred == NULL)
            {
                l->head = tmp->next;
                free(tmp);
                return 0;
            }
            
            pred->next = tmp->next;
            free(tmp);
            return 0;
        }
        
        pred = tmp;
        tmp = tmp->next;
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
            printf("%d ", tmp->value);
            tmp = tmp->next;
        }
	printf("\n");
    };

// Проверка наличия элемента
void check_bool(list *l, int value)
    {
        if (find(l, value) != NULL)
            printf("1 ");
        else
            printf("0 ");
            
    }

node *get_at(list *l, int id)
    {
        node * tmp = l->head;
        int nomer = 0;
        while ((tmp != NULL)&&(nomer!= id-1)) 
        {
            tmp = tmp->next;
            nomer++;
        }
        return tmp;
    }

int main() 
    {
        int n, digit, elem;
        int i = 1;
        list l = {0};

        int check = scanf("%d", &n);
        assert(check == 1);
        while (i <= n)
        {
            check = scanf("%d", &digit);
            assert(check == 1);
            push_back(&l, digit);
            i++;
        }
        print(&l);
        printf("\n");

        //Нахождение элементов в списке
        i = 1;
        while (i <= 3)
        {
            check = scanf("%d", &digit);
            assert(check == 1);
            check_bool(&l, digit);
            i++;
        }
        printf("\n");
        
        //Добавление в конец
        check = scanf("%d", &digit);
        assert(check == 1);
        push_back(&l, digit);
        print(&l);
        printf("\n");

        //Добавлние в начало
        check = scanf("%d", &digit);
        assert(check == 1);
        push_front(&l, digit);
        print(&l);
        printf("\n");

        //Добавление после указанного элемента
        check = scanf("%d", &digit);
        assert(check == 1);
        check = scanf("%d", &elem);
        assert(check == 1);
        node * insert_head = get_at(&l, digit);
        insert_after(insert_head, elem);
        print(&l);
        printf("\n");

        //Удалить первый элемент равный введенному
        check = scanf("%d", &digit);
        assert(check == 1);
        remove_node(&l, digit);
        print(&l);
        printf("\n");

        //Очистить список
        clean(&l);

        return 0;
    };
