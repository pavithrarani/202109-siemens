#pragma once
#include <exception>


class Node
{
public:
    int value;
    Node *next;
    Node(int value)
    {
        this->value = value;
        this->next = NULL;
    }

    void add(Node *node)
    {
        Node *n = this;
        while (n->next)
            n = n->next;

        n->next = node;
    }

    int get(int pos){
        Node *n=this;
        for(int i=0;i<pos;i++)
            n=n->next;        

        if(n)
            return n->value;
        else
            throw new std::out_of_range("invalid index");
    }
};



int main(int argc, char const *argv[])
{
    Node *list1 = new Node(1);
    Node *list2 = new Node(10);

    for(int i=2;i<=5;i++){
        list1->add(new Node(i));  //2 3 4 5
        list2->add(new Node(i*10)); //20 30 40 50
    }

    for(int i=0;i<5;i++){
        cout<< i<<"\t"
            << list1->get(i)<<"\t"
            << list2->get(i)<<endl;
    }



    return 0;
}
