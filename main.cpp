#include <iostream>
using namespace std;
struct list
{
    int id;
    list* next;
};
void push(list*& head, int x)
{
    list* tmp = new list;
    tmp->id = x;
    tmp->next = head;
    head = tmp;

}
void print(list* head)
{
    while (head != NULL)
    {
        cout << head->id << " ";
        head = head->next;
    }
    cout << endl;
}
void push_in_end(list*& head, int x)
{
    list* tmp = head;
    if (!head)
    {
        push(head,x);
    }
    else
    {
        while (tmp->next != NULL)
        {
            tmp = tmp->next;
        }
        list* ptr = new list;
        ptr->id = x;
        ptr->next = tmp->next;
        tmp->next = ptr;

    }
}
void push_new_prev_elem(list*& head, int x1, int x2)
{
    list* tmp;
    tmp = head;
    list* ptr = new list;
    ptr->id = x2;
    if(tmp->id == x1)
    {
        push(head,x2);
    }
    else
    {
        while (tmp->next->id != x1)
        {
            tmp = tmp->next;
        }

        ptr->next = tmp->next;
        tmp->next = ptr;
    }

}
void push_new_af_elem(list*& head, int x1, int x2)
{
    list* tmp;
    tmp = head;
    while (tmp->id != x1)
    {
        tmp = tmp->next;
    }
    list* ptr = new list;
    ptr->id = x2;
    ptr->next = tmp->next;
    tmp->next = ptr;
}
int pop(list *&head)
{
    list *tmp = head;
    int k = head->id;
    head = head->next;
    delete(tmp);
    return k;

}
int pop_last(list *&head)
{
    list *tmp = head;

    if(tmp->next == NULL)
    {
        pop(head);
    }
    else
    {
        while(tmp->next->next != NULL)
        {
            tmp = tmp->next;
        }
        int k = tmp->next->id;
        delete(tmp->next);
        tmp->next = NULL;
        return k;
    }

}
int pop_current(list *&head,int x)
{
    list *tmp = head;
    if(tmp->id == x)
    {
        pop(head);
    }
    else if(tmp->next == NULL)
    {
        pop_last(head);

    }
    else
    {
        while(tmp ->next->id != x)
        {
            tmp = tmp->next;
        }
        int k = tmp ->next->id;
        list *ptr = tmp->next;
        tmp->next = ptr->next;
        delete(ptr);
        return k;
    }
}
void maxs(list *&head,int *x,int* x1)
{
    *x = head->id;
    list *tmp = head;
    int temp = 0;
    while(tmp->next!=NULL)
    {

        if(tmp->next->id > *x)
        {
            *x = tmp->next->id;
            *x1 = temp+1;
        }
        temp++;
        tmp = tmp->next;
    }
}
int main()
{
    int x,x1,x2;
    int k = 1;
    setlocale(LC_ALL, "Rus");
    list* head = NULL;
    for (int i = 0; i < 5; i++) {
        push(head, rand() % 10);
    }
    while (k)
    {
        cout << " ¬ведите 0 дл€ окончани€ программы." << endl;
        cout << " ¬ведите 1 дл€ вставки элемента в начало списка." << endl;
        cout << " ¬ведите 2 дл€ того,чтобы распечатать список." << endl;
        cout << " ¬ведите 3 дл€ того,чтобы вставить элемент в конец списка." << endl;
        cout << " ¬ведите 4 дл€ того,чтобы вставить в список элемент до заданного элемента." << endl;
        cout << " ¬ведите 5 дл€ того,чтобы вставить в список элемент после заданного элемента." << endl;
        cout << " ¬ведите 6 дл€ того,чтобы удалить из списка первый элемент." << endl;
        cout << " ¬ведите 7 дл€ того,чтобы удалить из списка последний элемент." << endl;
        cout << " ¬ведите 8 дл€ того,чтобы удалить из списка заданный элемент." << endl;
        cout << " ¬ведите 9 дл€ того,чтобы найти максимальный элемент списка и вывести его пор€дковый номер." << endl;
        cin >> k;
        switch (k)
        {
        case 1:
            cout << "¬ведите число,которое нужно вставить." << endl;
            cin >> x;
            push(head, x);
            break;

        case 2:
            print(head);
            break;
        case 3:
            cout << "¬ведите элемент,который нужно добавить в конец." << endl;
            cin >> x;
            push_in_end(head, x);
            break;
        case 4:
            cout << "¬ведите элемент,до которого нужно вставить новый элемент и сам элемент." << endl;
            cin >> x1 >> x2;
            push_new_prev_elem(head, x1, x2);
            break;

        case 5:
            cout << "¬ведите элемент,после которого нужно вставить новый элемент и сам элемент." << endl;
            cin >> x1 >> x2;
            push_new_af_elem(head, x1, x2);
            break;

        case 6:
            cout <<"”даленный элемент = " << pop(head) << endl;
            break;
        case 7:
            cout <<"”даленный элемент = " << pop_last(head) << endl;
            break;


        case 8:
            cout << "¬ведите элемент,который нужно удалить." << endl;
            cin >> x;
            cout <<"”даленный элемент = " << pop_current(head,x) << endl;
            break;
        case 9:
            x = x1 = 0;
            maxs(head,&x,&x1);
            cout <<"ћаксимальный элемент: "<< x <<" " <<"≈го индекс: " << x1 << endl;
            break;
        }

    }
    return 0;
}

