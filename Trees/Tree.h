#pragma once

template <class T>

class Tree
{
    struct Node
    {
        T item;
        T weight;
        Node* son;
        Node* brother;

        Node(T i, T w, Node* s = NULL, Node* b = NULL )
        {
            item = i;
            son = s;
            brother = b;
            weight = w;
        }
    };
    Node* root;

public:
    Tree()
    {
        root = NULL;
    }

    ~Tree()
    {
        DeleteSubtree(root);
    }

    int GetHeight()
    {
        return GetHeight(root);
    } 

    void Add(const T& elem, const T& weight)
    {
        Add(root, elem, weight,false);
    }
    

private:
    void Add(Node*& node, const T& elem, const T& weight, bool check = false);
    /*
    //for brother
    void Add(Node*& node, const T& elem, const T& weight, bool check);
    */
    void DeleteSubtree(Node* node);
    int GetHeight(Node* node);
};


template <class T>
void Tree<T>::DeleteSubtree(Node* node)
{
    if (node)
    {
        DeleteSubtree(node->son);
        DeleteSubtree(node->brother);
        delete node;
    }
}

template <class T>
int Tree<T>::GetHeight(Node* node)
{
    if (node == NULL)
    {
        return 0;
    }
    int max = 0;
    for (Node* current = node->son; current; current = current->brother)
    {
        int curHeight = GetHeight(current);
        if (curHeight > max)
        {
            max = curHeight;
        }
    }
    return max + 1;
}

int check_Papka;
int for_bro = -10000;
template <class T>
void Tree<T>::Add(Node*& node, const T& item, const T& weight, bool check)
{
    if (node == NULL)
    {   
        //проверка левого брата, что он пустой (NULL)
        if (check)
        {
            node = new Node(for_bro, for_bro);//установка спец значений для будущих проверок
            Add(node->brother, item, weight);
            //node->item = 0;
            //node->weight = 0;
        }
        else
            node = new Node(item, weight);
        
    }
    //left son
    else if (item < node->item)
    {
        check_Papka = node->item;
        Add(node->son, item, weight);        
    }
    //right son
    else
    {
        //проверка на спец значения и то что отец больше чем данное значение тогда мы нашли место для данной ноды и ставим
        if (node->item == for_bro && node->weight == for_bro && check_Papka>item )
        {
            node->item = item;
            node->weight = weight;
        }
        //we need go to right brother
        else if (check) 
        {
            Add(node->brother, item, weight);
        }
        else
        {
            check_Papka = node->item;
            Add(node->son, item, weight, true);
        }
    }
} 
/*
//for brother
template <class T>
void Tree<T>::Add(Node*& node, const T& item, const T& weight, bool check)
{
    Add(root, for_bro, 0);
}
*/