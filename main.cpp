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
        cout << " ������� 0 ��� ��������� ���������." << endl;
        cout << " ������� 1 ��� ������� �������� � ������ ������." << endl;
        cout << " ������� 2 ��� ����,����� ����������� ������." << endl;
        cout << " ������� 3 ��� ����,����� �������� ������� � ����� ������." << endl;
        cout << " ������� 4 ��� ����,����� �������� � ������ ������� �� ��������� ��������." << endl;
        cout << " ������� 5 ��� ����,����� �������� � ������ ������� ����� ��������� ��������." << endl;
        cout << " ������� 6 ��� ����,����� ������� �� ������ ������ �������." << endl;
        cout << " ������� 7 ��� ����,����� ������� �� ������ ��������� �������." << endl;
        cout << " ������� 8 ��� ����,����� ������� �� ������ �������� �������." << endl;
        cout << " ������� 9 ��� ����,����� ����� ������������ ������� ������ � ������� ��� ���������� �����." << endl;
        cin >> k;
        switch (k)
        {
        case 1:
            cout << "������� �����,������� ����� ��������." << endl;
            cin >> x;
            push(head, x);
            break;

        case 2:
            print(head);
            break;
        case 3:
            cout << "������� �������,������� ����� �������� � �����." << endl;
            cin >> x;
            push_in_end(head, x);
            break;
        case 4:
            cout << "������� �������,�� �������� ����� �������� ����� ������� � ��� �������." << endl;
            cin >> x1 >> x2;
            push_new_prev_elem(head, x1, x2);
            break;

        case 5:
            cout << "������� �������,����� �������� ����� �������� ����� ������� � ��� �������." << endl;
            cin >> x1 >> x2;
            push_new_af_elem(head, x1, x2);
            break;

        case 6:
            cout <<"��������� ������� = " << pop(head) << endl;
            break;
        case 7:
            cout <<"��������� ������� = " << pop_last(head) << endl;
            break;


        case 8:
            cout << "������� �������,������� ����� �������." << endl;
            cin >> x;
            cout <<"��������� ������� = " << pop_current(head,x) << endl;
            break;
        case 9:
            x = x1 = 0;
            maxs(head,&x,&x1);
            cout <<"������������ �������: "<< x <<" " <<"��� ������: " << x1 << endl;
            break;
        }

    }
    return 0;
}

