#pragma once
#include <iostream>
#include <exception>
#include <string>
using namespace std;


class Node
{
    public:
        int value;
        Node * next;
        Node * previous;
        Node(int value,Node *next=NULL,Node *previous=NULL){
            this->value=value;
            this->next=next;
            this->previous=previous;
        }
};

class LinkedList
{
    Node* first;
    
    public:

    LinkedList(){
        first=NULL;
    }

    void add(int value) 
    {
        
        Node *n= new Node(value);
        //if the list is currently empty
        if(!first){
            first=n;
            return ;
        }

        //Add to the end of a non-empty list
        Node *p=first;
        while(p->next){
            p=p->next;
        }
        n->previous=p;
        p->next= n;

        return ;
    }

    int size(){
        int count=0;
        for(Node * n=first;n;n=n->next){
            count++;
        }

        return count;
    }

    int get(int pos){
        
        Node *n=first;
        for(int i=0;i<pos && n ;i++,n=n->next)
            ;

        if(n)
            return n->value;
        else
            throw out_of_range("index out of range ");
        
    }

    int set(int pos,int value){
        
        Node *n=first;
        for(int i=0;i<pos && n ;i++,n=n->next)
            ;

        if(n)
            n->value=value;
        else
            throw out_of_range("index out of range ");
        
    }

    int remove(int pos){
        
        if(pos==0)
        {
            Node *d= first;
            first=d->next;
            int v=d->value;
            delete d;
            return v;
        }

        Node *n=first;
        for(int i=0;i<pos-1 && n ;i++,n=n->next)
            ;

        if(n){
            Node *d=n->next; //delete next item
            int v=d->value; //collect value to return

            if(d->previous)
                d->previous->next= d->next;
            else
                first=d->next;  //deleting the first item

            if(d->next)  //if not the last item
                d->next->previous=d->previous;


            delete d;

            return v;
        }            
        else
            throw out_of_range("index out of range ");
        
    }

};