#pragma once

class Node{
    public:
    int value;
    Node * next;
    Node(int value){
        this->value=value;
        this->next=NULL;
    }
};


Node * list=NULL;

void add(Node * node){
    
    
    if(!list){
        list=node;
        return ;
    }


    Node* n=list;
    while(n->next)
        n=n->next;

    n->next=node;
}


int main(int argc, char const *argv[])
{
  
    add(new Node(5));
    add(new Node(20));
    add(new Node(15));


    for(Node *n=list; n; n=n->next)
        cout<<n->value<<endl;

    return 0;
}

