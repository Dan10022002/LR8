#include <iostream>

struct Check
{
    int k;
    float t;
    char a;
    Check operator=(int(x))
    {
        int k = x;
        float t = x;
        char a = x;
        return *this;
    }
};

std::ostream& operator<< (std::ostream& out, const Check& Check)
{
    out << Check.k << " " << Check.t << " " << Check.a << std::endl;
    return out;
}

template <class T, unsigned int size>
struct List_general
{
    T value[size];
    unsigned int list_size;
};

template <class T, unsigned int size> //1
void Constructor(List_general<T, size>& List)
{
    List.list_size = 0;
    for (int h = 0; h < size; h++)
        List.value[h] = 0;
}

template <class T, unsigned int size> //3
size_t Size(const List_general<T, size>& List)
{
    return List.list_size;
}

template <class T, unsigned int size> //2
void Destructor(List_general<T, size>& List)
{
    for (int h = 0; h < Size(List); h++)
    {
        List.value[h] = 0;
    }
    List.list_size = 0;
}

template <class T, unsigned int size> //4
void Push_in_back(List_general<T, size>& List, T Element)
{
    if (Size(List) == List.list_size)
    {
        std::cout << "The List is full. Operation error.";
    }
    else
    {
        List.value[Size(List)] = Element;
        List.list_size += 1;
    }
}

template <class T, unsigned int size> //5
void Push_for_index(List_general<T, size>& List, T Element, unsigned int n)
{
    if (Size(List) == List.list_size)
    {
        std::cout << "The List is full. Operation error.";
    }
    else if (n > List.list_size)
    {
        std::cout << "The index exceeds the size of the list. Operation error.";
    }
    else 
    {
        while (n < (Size(List) - 1))
        {
            T list_time;
            list_time = List.value[n];
            List.value[n] = Element;
            Element = list_time;
            n += 1;
        }
        if (n < (Size(List) - 1))
        {
            List.list_size += 1;
        }
        else
        {
            List.list_size = n + 1;
        }
    }
}

template <class T, unsigned int size> //6
T Pop_from_head(List_general<T, size>& List)
{
    if (Size(List) == 0)
    {
        std::cout << "The list is clear. Operation error.";
        return  static_cast<char>(32);
    }
    else
    {
        T pop_element = List.value[0];
        for (int h = 0; h < Size(List); h++)
        {
            List.value[h] = List.value[h + 1];
        }
        List.value[Size(List) - 1] = 0;
        List.list_size -= 1;
        return pop_element;
    }
}

template <class T, unsigned int size> //7
T Pop_from_back(List_general<T, size>& List)
{
    if (Size(List) == 0)
    {
        std::cout << "The list is clear. Operation error.";
        return  static_cast<char>(32);
    }
    else
    {
        T pop_element = List.value[Size(List) - 1];
        List.value[Size(List) - 1] = 0;
        List.list_size -= 1;
        return pop_element;
    }
}

template <class T, unsigned int size> //8
T Pop_for_index(List_general<T, size>& List, unsigned int n)
{
    if (Size(List) == 0)
    {
        std::cout << "The list is clear. Operation error.";
        return  static_cast<char>(32);
    }
    else if (n > (Size(List) - 1))
    {
        std::cout << "The index exceeds the size of the list. Operation error.";
        return  static_cast<char>(32);
    }
    else if (Size(List) == 1)
    {
        Pop_from_head(List);
    }
    else
    {
        T pop_element = List.value[n];
        for (int h = n; h < Size(List); h++)
        {
            List.value[h] = List.value[h + 1];
        }
        List.value[Size(List) - 1] = 0;
        List.list_size -= 1;
        return pop_element;
    }
}

template <class T, unsigned int size> //9
T Value_for_index(List_general<T, size>& List, unsigned int n)
{
    if (Size(List) == 0)
    {
        std::cout << "The list is clear. Operation error.";
        return  static_cast<char>(32);
    }
    else if (n > (Size(List) - 1))
    {
        std::cout << "The index exceeds the size of the list. Operation error.";
        return  static_cast<char>(32);
    }
    else
    {
        return List.value[n];
    }
}

template <class T, unsigned int size> //9
T Value_for_index(List_general<T, size>& List, T Element)
{
    if (Size(List) == 0)
    {
        std::cout << "The list is clear. Operation error.";
        return  static_cast<char>(32);
    }
    else
    {
        for (int h = 0; h < Size(List); h++)
        {
            if (List.value[h] == Element)
            {
                return h;
            }
        }
        return -1; //если данного элемента нет в списке
    }
}

template <class T, unsigned int size> //9
void Print(const List_general<T, size>& List)
{
    for (int h = 0; h < Size(List); h++)
    {
        std::cout << List.value[h] << " ";
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
    List_general<Check, 10> Check;
    Constructor(Check);
    Push_in_back(Check, check1);
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
    List_general<int, 10> Check1;
    Constructor(Check1);
    Push_in_back(Check1, 5);
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
