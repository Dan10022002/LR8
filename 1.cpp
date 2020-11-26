#include <iostream>

struct Check
{
    int k;
    float t;
    char a;
};

std::ostream& operator<< (std::ostream& out, const Check& Check)
{
    out << Check.k << " " << Check.t << " " << Check.a <<  std::endl;
    return out;
}

template <class T>
struct List_element
{
    T data;
    List_element* list_next;
    List_element* list_prev;
};

template <class T>
struct List_general
{
    List_element<T>* list_begin;
    List_element<T>* list_end;
};

template <typename T> //1
void Constructor (List_general<T>& List)
{
    List.list_begin = nullptr;
    List.list_end = nullptr;
}

template <typename T> //2
void Destructor (List_general<T>& List)
{
    List_element<T>* list_time = new List_element<T>;
    list_time = List.list_begin;
    unsigned int kolvo = Size(List);
    unsigned int counter = 0;
    while (counter != kolvo)
    {
        list_time = list_time->list_next;
        List.list_begin = list_time;
        counter+=1;
    }
    delete list_time;
}

template <typename T> //3
size_t Size (const List_general<T>& List)
{
    size_t list_size = 0;
    List_element<T>* list_time = new List_element<T>;
    list_time = List.list_begin;
    while (list_time != nullptr)
    {
        list_time = list_time -> list_next;
        list_size += 1;
    }
    delete list_time;
    return list_size;
}

template <typename T> //4
void Push_in_head (List_general<T>& List, T n)
{
    if (List.list_begin == nullptr)
    {
        List_element<T>* list_time = new List_element<T>;
        list_time -> data = n;
        List.list_begin = list_time;
        List.list_end = list_time;
        list_time -> list_next = list_time;
        list_time -> list_prev = list_time;
        delete list_time;
    }
    else
    {
        List_element<T>* list_time = new List_element<T>;
        list_time -> data = n;
        List.list_begin -> list_prev = list_time;
        List.list_begin = list_time;
        list_time -> list_next = List.list_begin;
        list_time -> list_prev = List.list_end;
        delete list_time;
    }
}

template <typename T> //5
void Push_in_back (List_general<T>& List, T n)
{
    if (List.list_begin == nullptr)
    {
        List_element<T>* list_time = new List_element<T>;
        list_time -> data = n;
        List.list_begin = list_time;
        List.list_end = list_time;
        list_time -> list_next = list_time;
        list_time -> list_prev = list_time;
        delete list_time;
    }
    else
    {
        List_element<T>* list_time = new List_element<T>;
        list_time -> data = n;
        List.list_end -> list_next = list_time;
        List.list_end = list_time;
        list_time -> list_next = List.list_begin;
        list_time -> list_prev = List.list_end;
        delete list_time;
    }
}

template <typename T> //6
void Push_for_index (List_general<T>& List, T x, unsigned int n)
{
    unsigned int counter = 0;
    List_element<T>* list_time = new List_element<T>;
    list_time = List.list_begin;
    while (counter != n)
    {
        list_time = list_time -> list_next;
        counter+=1;
    }
    List_element<T>* list_time1 = new List_element<T>;
    list_time1 -> data = x;
    list_time1 -> list_prev = list_time -> list_prev;
    list_time -> list_prev -> list_next = list_time1;
    list_time -> list_prev = list_time1;
    list_time1 -> list_next = list_time;
    delete list_time;
    delete list_time1;
}

template <typename T> //7
void Push_for_pointer (List_general<T>& List, T n, List_element<T>* Point)
{
    List_element<T>* list_time = new List_element<T>;
    list_time = List.list_begin;
    while (list_time != Point)
    {
        list_time = list_time -> list_next;
    }
    List_element<T>* list_time1 = new List_element<T>;
    list_time1 -> data = n;
    list_time1 -> list_prev = list_time -> list_prev;
    list_time -> list_prev -> list_next = list_time1;
    list_time -> list_prev = list_time1;
    list_time1 -> list_next = list_time;
    delete list_time;
    delete list_time1;
}

template <typename T> //8
T Pop_from_head (List_general<T>& List)
{
    List_element<T>* list_time = new List_element<T>;
    List.list_end -> list_next = List.list_begin -> list_next;
    List.list_begin -> list_next -> list_prev = List.list_end;
    T rez = List.list_begin -> data;
    list_time = List.list_begin -> list_next;
    List.list_begin = list_time;
    delete list_time;
    return rez;
}

template <typename T> //9
T Pop_from_back (List_general<T>& List)
{
    List_element<T>* list_time = new List_element<T>;
    List.list_end -> list_prev -> list_next = List.list_begin;
    List.list_begin -> list_prev = List.list_end -> list_prev;
    T rez = List.list_end -> data;
    list_time = List.list_end -> list_prev;
    List.list_end = list_time;
    delete list_time;
    return rez;
}

template <typename T> //10
T Pop_for_index (List_general<T>& List, unsigned int n)
{
    unsigned int counter = 0;
    List_element<T>* list_time = new List_element<T>;
    list_time = List.list_begin;
    while (counter != n)
    {
        list_time = list_time -> list_next;
        counter+=1;
    }
    T rez = list_time -> data;
    list_time -> list_prev -> list_next = list_time -> list_next;
    list_time -> list_next -> lsit_prev = list_time -> list_prev;
    delete list_time;
    return rez;
}

template <typename T> //11
T Pop_for_pointer (List_general<T>& List, List_element<T>* Point)
{
    List_element<T>* list_time = new List_element<T>;
    list_time = List.list_begin;
    while (list_time != Point)
    {
        list_time = list_time -> list_next;
    }
    T rez = list_time -> data;
    list_time -> list_prev -> list_next = list_time -> list_next;
    list_time -> list_next -> list_prev = list_time -> list_prev;
    delete list_time;
    return rez;
}

template <typename T> //12
T Data_for_index (List_general<T>& List, unsigned int n)
{
    unsigned int counter = 0;
    List_element<T>* list_time = new List_element<T>;
    list_time = List.list_begin;
    while (counter != n)
    {
        list_time = list_time -> list_next;
        counter+=1;
    }
    return list_time -> data;
}

template <typename T> //13
T Find_index (List_general<T>& List, T n)
{
    List_element<T>* list_time = new List_element<T>;
    list_time = List.list_begin;
    unsigned int index=0;
    while (list_time -> data != n)
    {
        list_time = list_time -> list_next;
        index+=1;
        if (index == Size(List))
        {
            return std::cout << "There aren't this element.";
        }
    }
    delete list_time;
    return index;
}

template <typename T> //14
void Print (const List_general<T>& List)
{
    List_element<T>* list_time = new List_element<T>;
    list_time = List.list_begin;
    for (int h=0; h<Size(List); h++)
    {
        std::cout << h << ": " << list_time -> data << "/t";
        list_time = list_time -> list_next;
    }
    delete list_time;
}

int main()
{
    //Проверка для пользовательского типа данных
    Check check1, check2, check3, check4;
    List_general<Check> Check;
    Constructor(Check);
    Push_in_head(Check, check1);
    Push_in_back(Check, check2);
    Push_for_index(Check, check3, 2);
    Print (Check);
    Destructor (Check);
    //Проверка для стандартного типа данных
    List_general<int> Check1;
    Constructor(Check1);
    Push_in_head(Check1, 156);
    Push_in_back(Check1, 784);
    Push_for_index(Check1, 333, 3);
    Print (Check1);
    Destructor (Check1);
    return 0;
}
