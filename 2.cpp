#include <iostream>

struct Check
{
    int k;
    float t;
    char a;
    Check operator=(int x)
    {
        int k = x;
        float t = x;
        char a = x;
        return *this;
    }
};

std::ostream& operator<< (std::ostream& out, const Check& Check)
{
    out << Check.k << " " << Check.t << " " << Check.a <<  std::endl;
    return out;
}

template <class T, unsigned int size>
struct List_array
{
    T data[size];
    unsigned int list_size;
};

template <class T, unsigned int size> //1
void Constructor (List_array<T, size>& List)
{
    List.list_size = 0;
    for (int i = 0; i < size; ++i)
    {
        List.data[i] = 0;
    }
}

template <class T, unsigned int size> //2
void Destructor (List_array<T, size>& List)
{
    List.list_size = 0;
    for (int i = 0; i < size; ++i)
    {
        List.data[i] = 0;
    }
}

template <class T, unsigned int size> //3
size_t Size (List_array<T, size>& List)
{
    return List.list_size;
}

template <class T, unsigned int size> //4
void Push_in_back (List_array<T, size>& List, T n)
{
    if (List.list_size < size)
    {
        List.data[List.list_size] = n;
    }
    else
    {
        std::cout << "The list is full.";
    }
}

template <class T, unsigned int size> //5
void Push_for_index (List_array<T, size>& List, T n, unsigned int x)
{
    if ((List.list_size < size) && (x < size))
    {
        for (int i = 0; i < size; ++i)
        {
            T t;
            T k;
            if (i == x)
            {
                t = List.data[i];
                List.data[i] = n;
            }
            if (i > x)
            {
                k = List.data[i];
                List.data[i] = t;
                t = k;
            }
        }
    }
    if (x > size)
    {
        std::cout << "This operation can't be used.";
    }
    if (List.list_size >= size)
    {
        std::cout << "The list is full.";
    }
}

template <class T, unsigned int size> //6
T Pop_from_head(List_array<T, size>& List)
{
    T list_time = List.data[0];
    for (int i = 0; i < List.list_size; ++i)
    {
        List.data[i] = List.data[i+1];
    }
    List.data[List.list_size-1] = 0;
    List.list_size -= 1;
    return list_time;
}

template <class T, unsigned int size> //7
T Pop_from_back(List_array<T, size>& List)
{
    T list_time = List.data[List.list_size-1];
    List.data[List.list_size-1] = 0;
    List.list_size -= 1;
    return list_time;
}

template <class T, unsigned int size> //8
T Pop_for_index (List_array<T, size>& List, unsigned int x)
{
    T list_time;
    if (x > size)
    {
        std::cout << "This operation can't be used.";
    }
    else
    {
        list_time = List.data[x];
        for (int i = 0; i < size; ++i)
        {
            if (i >= x)
            {
                List.data[i] = List.data[i+1];
            }
        List.data[List.list_size-1] = 0;
        List.list_size -= 1;
        }
    }
    return list_time;
}

template <class T, unsigned int size> //9
T Data_for_index (List_array<T, size>& List, unsigned int x)
{
    T list_time = List.data[x];
    return list_time;
}

template <class T, unsigned int size> //10
T Find_index (List_array<T, size>& List, T n)
{
    int x = -1;
    for (int i = 0; i < List.list_size-1; ++i)
    {
        if (List.data[i] == n)
        {
            x = i;
        }
    }
    if (x == -1)
    {
        std::cout << "There aren't needed element.";
    }
    return x;
}

template <class T, unsigned int size> //11
void Print (List_array<T, size>& List)
{
    for (int i = 0; i < List.list_size-1; ++i)
    {
        std::cout << List.data[i] << " ";
    }
    std::cout << std::endl;
}

int main()
{
    //Проверка для пользовательского типа данных
    Check check1, check2, check3, check4;
    List_array<Check, 8> Check;
    Constructor(Check);
    Push_in_back(Check, check2);
    Push_for_index(Check, check3, 2);
    Pop_for_index(Check, 7);
    Print (Check);
    Destructor (Check);
    //Проверка для стандартного типа данных
    List_array<int, 8> Check1;
    Constructor(Check1);
    Push_in_back(Check1, 784);
    Push_for_index(Check1, 333, 3);
    Pop_for_index(Check, 7);
    Print (Check1);
    Destructor (Check1);
    return 0;
}
