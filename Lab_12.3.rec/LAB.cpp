#include <iostream>
#include <Windows.h>

using namespace std;

typedef int Info;
struct Elem
{
    Elem* next,
        * prev;
    Info info;
};

void enqueue(Elem*& first, Elem*& last, Info value)
{
    Elem* tmp = new Elem; // 1
    tmp->info = value; // 2
    tmp->next = NULL; // 3
    if (last != NULL)
        last->next = tmp; // 4
    tmp->prev = last; // 5
    last = tmp; // 6
    if (first == NULL)
        first = tmp; // 7
}

Info dequeue(Elem*& first, Elem*& last)
{
    Elem* tmp = first->next; // 1
    Info value = first->info; // 2
    delete first; // 3
    first = tmp; // 4
    if (first == NULL)
        last = NULL; // 5
    else
        first->prev = NULL; // 6
    return value; // 7
}

void insertBeforeFirst(Elem*& first, int V1, int V2) {
    if (first == NULL || first->info == V1) {
        Elem* tmp = new Elem;
        tmp->info = V2;
        tmp->prev = NULL;
        tmp->next = first;
        if (first != NULL)
            first->prev = tmp;
        first = tmp;
    }
}

void insertBeforeMiddle(Elem*& first, int V1, int V2) {
    Elem* current = first;
        if (current->next->info == V1) {
            Elem* tmp = new Elem;
            tmp->info = V2;
            tmp->prev = current;
            tmp->next = current->next;
            current->next->prev = tmp;
            current->next = tmp;
        
        }
        else {
            current = current->next;
            insertBeforeMiddle(first->next, V1, V2);
        }
}

void insertBeforeLast(Elem*& first, Elem*& last, int V1, int V2) {
    if (last != NULL && last->info == V1) {
        Elem* tmp = new Elem;
        tmp->info = V2;
        tmp->prev = last->prev;
        tmp->next = last;
        if (last->prev != NULL)
            last->prev->next = tmp;
        last->prev = tmp;
    }
}

void printList(Elem* head)
{
    if (head == NULL) {
        cout << endl;
        return;
    }

    cout << head->info << " ";
    printList(head->next);
}


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Elem* head = NULL;
    Elem* last = NULL;

    enqueue(head, last, 2);
    enqueue(head, last, 1);
    enqueue(head, last, 3);
    enqueue(head, last, 2);
    enqueue(head, last, 0);

  
    cout << "Список: ";
    printList(head);

    insertBeforeFirst(head, 2, 3);
    cout << "Після вставки перед першим елементом: ";
    printList(head);

    insertBeforeMiddle(head, 3, 0);
    cout << "Після вставки перед середнім елементом: ";
    printList(head);

    insertBeforeLast(head, last, 0, 1);
    cout << "Після вставки перед останнім елементом: ";
    printList(head);

    while (head != nullptr)
    {
        Elem* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
