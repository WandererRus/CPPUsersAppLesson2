// CPPUsersAppLesson2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
//функция определяет длину строки.
int mystrlen(const char* str)
{
    int counter = 0;
    while (*(str + counter) != '\0')
    {
        counter++;
    }
    return counter;
}
int mystrlen(char* str)
{
    int counter = 0;
    while (*(str + counter) != '\0')
    {
        counter++;
    }
    return counter;
}
// функция копирует строку str2 в буфер, адресуемый через str1.
//Функция возвращает указатель на первую строку str1.
char* mystrcpy(char* str1, const char* str2)
{
    int size = mystrlen(str2);
    str1 = new char[size];
    for (int i = 0; i <= size; i++)
    {
        *(str1 + i) = *(str2 + i);
    }
    return str1;
    
}
// функция присоединяет строку str2 к строке str1.
//Функция возвращает указатель на первую строку str1.
char* mystrcat(char* str1, const char* str2)
{
    int size1 = mystrlen(str1);
    int size2 = mystrlen(str2);
    char* massive = new char[size1 - 1 + size2];
    for (int i = 0; i < size1; i++)
    {
        *(massive + i) = *(str1 + i);
    }
    for (int i = 0; i <= size2; i++)
    {
        *(massive + size1 + i) = *(str2 + i);
    }
    return massive;
}
// функция осуществляет поиск символа s в строке str.
//Функция возвращает указатель на первое вхождение символа в строку, в противном случае 0.
char* mystrchr(char* str, char s)
{
    int len = mystrlen(str);
    char* result = 0;
    for (int i = 0; i < len; i++)
    {
        if (*(str + i) == s)
        {
            result = (str + i);
            break;
        }            
    }
    return result;
}
// функция осуществляет поиск подстроки str2 в строке str1.
//Функция возвращает указатель на первое вхождение подстроки str2 в строку str1, в противном случае 0.*/
char* mystrstr(char* str1, char* str2)
{
    char* result = 0;
    int stringsize = mystrlen(str1);
    int substringsize = mystrlen(str2);
    for (int i = 0; i < stringsize - substringsize; i++)
    {
        if (result == 0)
        { 
            for (int k = 0; k < substringsize; k++)
            {
                if (*(str1 + i + k) != *(str2 + k))
                {
                    break;
                }
                else if (k == substringsize-1)
                {
                    result = (str1 + i);
                }
            }
        }
        else
        {
            break;
        }
    }

    return result;
}

int main()
{
    //1
    std::cout << mystrlen("string string") << "\n";

    //2
    const char* source = "string for copy";
    char* destination = nullptr;
    destination = mystrcpy(destination, source);
    source = nullptr;
    std::cout << destination << "\n";

    //3
    const char* source2 = "adding string";
    destination = mystrcat(destination, source2);
    std::cout << destination << "\n";
    
    //4
    char* findChar = nullptr;
    findChar = mystrchr(destination, 'p');
    std::cout << findChar << "\n";

    //5
    char* sub = new char[4]{ 'f','o','r','\0'};
    char* findsub = nullptr;
    findsub = mystrstr(destination, sub);
    if (findsub != nullptr)
    {
        std::cout << findsub << "\n";
    }
    else
    {
        std::cout << "No substring this";
    }
    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
