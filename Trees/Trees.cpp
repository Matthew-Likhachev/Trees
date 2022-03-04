
//Вариант 1
    //Название - Оптимальное дерево двоичного поиска
    //Реализация - Левый сын, правый брат (указатели)
    //Операция - A=A ⋃симB Операция A=A ⋃симB означает, что элементы дерева В будут добавлены в дерево А в симметричном обходе дерева В
    //Вывод деревьев на экран - А– прямой, В – симметричный
#include <Windows.h>
#include <string>
#include <vector>
#include <stdio.h>
#include <conio.h>   // для getche()
#include<stack>
#include <locale>
#include "tree.h"
#include <iostream>
#include <map>
using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "russian");

    Tree<int> tree;
    int n, weight;
    int item;

    cout << "Введите количество элементов в дереве: ";
    cin >> n;
    cout << endl;
    //weight -> value
    multimap <int, int> arr;
    multimap <int, int>::iterator i_arr;

    for (int i = 0; i < n; i++)
    {
       // cout << "Введите элемент дерева : ";
        cin >> item;
        //cout << "Введите вес элемента дерева : ";
        cin >> weight;
        arr.emplace(weight, item);
    }
    //add from the end (biggest weight)
    for (auto i_arr = arr.rbegin(); i_arr != arr.rend(); i_arr++)
    {
        tree.Add((*i_arr).second, (*i_arr).first);
    }

    cout << endl;


    cout << "Высота дерева: " << tree.GetHeight() << endl;



    system("pause >>NULL");
    return 0;
}