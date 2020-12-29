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
    T value;
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

template <typename T> //3
size_t Size (const List_general<T>& List)
{
    size_t counter = 0;
    if (List.list_begin == nullptr)
    {
        return counter;
    }
    else
    {
        counter += 1;
        List_element<T>* list_time;
        list_time = List.list_begin;
        while (list_time -> list_next != List.list_begin)
        {
            list_time = list_time -> list_next;
            counter += 1;
        }
        return counter;
    }
}

template <typename T> //2
void Destructor (List_general<T>& List)
{
    List_element<T>* list_time;
    for (int h = 0; h < (Size(List) - 1); h++)
    {
        list_time = List.list_begin;
        List.list_begin = List.list_begin -> list_next;
        delete list_time;
    }
    delete List.list_begin;
}

template <typename T> //4
void Push_in_head (List_general<T>& List, T Element)
{
    if(List.list_begin == nullptr)
    {
        List_element<T>* list_time = new List_element<T>;
        list_time -> value = Element;
        list_time -> list_next = list_time;
        list_time -> list_prev = list_time;
        List.list_begin = list_time;
        List.list_end = List.list_begin;
    }
    else
    {
        List_element<T>* list_time = new List_element<T>;
        list_time -> value = Element;
        list_time -> list_next = List.list_begin;
        list_time -> list_prev = List.list_end;
        List.list_begin -> list_prev = list_time;
        List.list_end -> list_next = list_time;
        List.list_begin = list_time;
    }
}

template <typename T> //5
void Push_in_back (List_general<T>& List, T Element)
{
    if(List.list_begin == nullptr)
    {
        List_element<T>* list_time = new List_element<T>;
        list_time -> value = Element;
        list_time -> list_next = list_time;
        list_time -> list_prev = list_time;
        List.list_begin = list_time;
        List.list_end = List.list_begin;
    }
    else
    {
        List_element<T>* list_time = new List_element<T>;
        list_time -> value = Element;
        list_time -> list_prev = List.list_end;
        list_time -> list_next = List.list_begin;
        List.list_begin -> list_prev = list_time;
        List.list_end -> list_next = list_time;
        List.list_end = list_time;
    }
}

template <typename T> //6
void Push_for_index (List_general<T>& List, T Element, unsigned int n)
{
    if (n >= Size(List))
    {
        std::cout << "The element will be pushed in back of the List.";
        Push_in_back(List, Element);
    }
    else if (n == 0)
    {
        std::cout << "The element will be pushed in head of the List.";
        Push_in_head(List, Element);
    }
    else                                                                 //здесь нам не надо рассматривать случай, когда
    {                                                                    //List.list_begin == nullptr, т.к. его забирает первый if
        int counter = 0;
        List_element<T>* list_time1; //элемент, после которого будет добавлен необходимый элемент
        List_element<T>* list_time2; //элемент, до которого будет добавлен необходимый элемент
        list_time2 = List.list_begin;
        do
        {
            list_time2 = list_time2 -> list_next;
            counter += 1;
        } while (counter != n);
        list_time1 = list_time2 -> list_prev;
        List_element<T>* list_index = new List_element<T>; //необходимый элемент
        list_index -> value = Element;
        list_index -> list_next = list_time2;
        list_index -> list_prev = list_time1;
        list_time2 -> list_prev = list_index;
        list_time1 -> list_next = list_index;
    }
}

template <typename T> //7
void Push_for_pointer (List_general<T>& List, T Element, List_element<T>* pointer)
{
    List_element<T>* list_time1; //аналогично
    List_element<T>* list_time2;
    list_time1 = List.list_begin;
    do
    {
        list_time1 = list_time1 -> list_next;
    } while (list_time1 != pointer);
    list_time2 = list_time1 -> list_next;
    List_element<T>* list_pointer = new List_element<T>; //необходимый элемент
    list_pointer -> value = Element;
    list_pointer -> list_next = list_time2;
    list_pointer -> list_prev = list_time1;
    list_time1 -> list_next = list_pointer;
    list_time2 -> list_prev = list_pointer;
}

template <typename T> //8
T Pop_from_head (List_general<T>& List)
{
    if (List.list_begin == nullptr)
    {
        std::cout << "The List is clear.";
    }
    else
    {
        List_element<T>* list_time;
        list_time = List.list_begin;
        List.list_begin = List.list_begin -> list_next;
        List.list_begin -> list_prev = List.list_end;
        List.list_end -> list_next = List.list_begin;
        return list_time -> value;
        delete list_time;
    }
}

template <typename T> //9
T Pop_from_back (List_general<T>& List)
{
    if (List.list_begin == nullptr)
    {
        std::cout << "The List is clear.";
    }
    else
    {
        List_element<T>* list_time;
        list_time = List.list_end;
        List.list_end = List.list_end -> list_prev;
        List.list_end -> list_next = List.list_begin;
        List.list_begin -> list_prev = List.list_end;
        return list_time -> value;
        delete list_time;
    }
}

template <typename T> //10
T Pop_for_index (List_general<T>& List, unsigned int n)
{
    if (List.list_begin == nullptr)
    {
        std::cout << "The List is clear.";
    }
    else if (n == 0)
    {
        std::cout << "A needed element is the first in List.";
        Pop_from_head(List);
    }
    else if (n >= Size(List))
    {
        std::cout << "A needed element is the last in List.";
        Pop_from_back(List);
    }
    else
    {
        int counter = 0;
        List_element<T>* list_time;
        list_time = List.list_begin;
        do
        {
            list_time = list_time -> list_next;
            counter += 1;
        } while (counter != n);
        (list_time -> list_next) -> list_prev = list_time -> list_prev;
        (list_time -> list_prev) -> list_next = list_time -> list_next;
        return list_time -> value;
        delete list_time;
    }
}

template <typename T> //11
T Pop_for_pointer (List_general<T>& List, List_element<T>* pointer)
{
    if (List.list_begin == nullptr)
    {
        std::cout << "The List is clear.";
    }
    else
    {
        List_element<T>* list_time;
        list_time = List.list_begin;
        do
        {
            list_time = list_time -> list_next;
        } while (list_time != pointer);
        (list_time -> list_next) -> list_prev = list_time -> list_prev;
        (list_time -> list_prev) -> list_next = list_time -> list_next;
        return list_time;
        delete list_time;
    }
}

template <typename T> //12 - тот же самый код, что и 10, только без извлечения
T Value_for_index (List_general<T>& List, unsigned int n)
{
    if (List.list_begin == nullptr)
    {
        std::cout << "The List is clear.";
    }
    else if (n == 0)
    {
        std::cout << "A needed element is the first in List.";
        return List.list_begin->value;
    }
    else if (n >= (Size(List) - 1))
    {
        std::cout << "A needed element is the last in List.";
        return List.list_end->value;
    }
    else
    {
        int counter = 0;
        List_element<T>* list_time;
        list_time = List.list_begin; //аналогично
        do
        {
            list_time = list_time -> list_next;
            counter += 1;
        } while (counter != n);
        return list_time -> value;
        delete list_time;
    }
}

template <typename T> //13
T Find_index (List_general<T>& List, T Element)
{
    int counter = 0;
    List_element<T>* list_time;
    list_time = List.list_begin;
    List_element<T>* list_index;
    list_index -> value = Element;
    do
    {
        list_time = list_time -> list_next;
        counter += 1;
    } while ((list_time -> value) != (list_index -> value));
    return counter;
}

template <typename T> //14
void Print (const List_general<T>& List)
{
    List_element<T>* list_time;
    list_time = List.list_begin;
    for (int h = 0; h < Size(List); h++)
    {
        std::cout << list_time -> value << " ";
        list_time = list_time -> list_next;
    }
}

int main()
{
    //Проверка для пользовательского типа данных
    Check check1, check2, check3, check4;
    check1.k = 12;
    check1.t = 111.12;
    check1.a = 'a';
    check2.k = 995;
    check2.t = 166.404;
    check2.a = 'b';
    check3.k = 1;
    check3.t = 13.1313;
    check3.a = 'c';
    check4.k = 0;
    check4.t = 0.333;
    check4.a = 'd';
    List_general<Check> Check;
    Constructor(Check);
    Push_in_head(Check, check1);
    std::cout << "\n";
    Print(Check);
    Push_in_back(Check, check2);
    std::cout << "\n";
    Print(Check);
    Push_for_index(Check, check3, 1);
    std::cout << "\n";
    Print(Check);
    Pop_from_head(Check);
    std::cout << "\n";
    Print(Check);
    Pop_from_back(Check);
    std::cout << "\n";
    Print(Check);
    std::cout << Size(Check) << "\n";
    Destructor(Check);
    //Проверка для стандартного типа данных
    List_general<int> Check1;
    Constructor(Check1);
    Push_in_head(Check1, 5);
    Print(Check1);
    std::cout << "\n";
    Push_in_back(Check1, 3);
    Print(Check1);
    std::cout << "\n";
    Push_for_index(Check1, 17, 1);
    Print(Check1);
    std::cout << "\n";
    Pop_from_head(Check1);
    Print(Check1);
    std::cout << "\n";
    Pop_from_back(Check1);
    Print(Check1);
    std::cout << "\n";
    std::cout << Size(Check1) << "\n";
    Destructor(Check1);
    return 0;
}
