#include <iostream>

template <typename T>
struct List_element
{
    T data;
    List_element* list_next;
    List_element* list_prev;
    List_element* list_head;
    List_element* list_end;
};

template <typename T>
void Costructor (T List)
{
    List.list_head = nullptr;
    List.list_end = nullptr;
}

template <typename T>
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

template <typename T>
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

template <typename T>
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

template <typename T>
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

template <typename T>
void Push_for_index (T List)
{

}

int main()
{

    return 0;
}
