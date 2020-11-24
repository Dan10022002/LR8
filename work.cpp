#include <iostream>

template <class T>
struct List_element
    {
    T data;
    List_element* next;
    List_element* prev;
    List_element* head;
    List_element* curr;
    };

template <typename T> //1
void Costructor (T List)
{
    List.head = nullptr;
    List.curr = nullptr;
}

template <typename T> //2
void Destructor (T List)
{
    while (List.list_head != nullptr)
    {
        T list_time = new T;
        list_time = List.list_head;
        List.list_head = List.list_head -> list_next;
        delete list_time;
    }
}

template <typename T> //3
size_t Size (const T List)
{
    size_t list_size = 0;
    T list_time = new T;
    list_time = List.list_head;
    while (list_time != nullptr)
    {
        list_time = list_time -> list_next;
        list_size += 1;
    }
    delete list_time;
    return list_size;
}

template <typename T> //4
void Push_in_head (T List)
{
    if (List.list_head == nullptr)
    {
        T list_time = new T;
        list_time -> data = List.data;
        List.list_head = list_time;
        List.list_end = list_time;
        delete list_time;
    }
    else
    {
        T list_time = new T;
        list_time -> data = List.data;
        List.list_head -> list_prev = list_time;
        List.list_head = list_time;
        delete list_time;
    }
}

template <typename T> //5
void Push_in_back (T List)
{
    if (List.list_head == nullptr)
    {
        T list_time = new T;
        list_time -> data = List.data;
        List.list_head = list_time;
        List.list_end = list_time;
        delete list_time;
    }
    else
    {
        T list_time = new T;
        list_time -> data = List.data;
        List.list_end -> list_next = list_time;
        List.list_end = list_time;
        delete list_time;
    }
}

template <typename T> //6
void Push_for_index (T List, unsigned int n)
{
    if (n>Size(List))
    {
        Push_in_back (List);
    }
    else
    {
        for(int i=0; i<n; i++)
        {
            T list_time = new T;
            list_time -> data = List.data;

        }
    }
}

int main()
{
    return 0;
}
