#pragma once
#include <iostream>
#include <exception>
#include <string>
using namespace std;
#define POS_END -1
class LinkedList
{

    class Node
    {
    public:
        int value;
        Node *next;
        Node *previous;
        Node(int value, Node *next = NULL, Node *previous = NULL)
        {
            this->value = value;
            this->next = next;
            this->previous = previous;
        }
    };
    Node *first;
    Node *last;
    int count;

    Node * locate(int pos){

        if(pos==POS_END)
            pos=count-1;

        if(pos<0 || pos>=count)
        {
            string message="invalid index ";
            message+=pos;
            throw new out_of_range(message);
        }

        if(pos==count-1)
            return last;

        Node *n=first;

        for(int i=0;i<pos;i++)
            n=n->next;

        return n;
            
    }

public:
    LinkedList()
    {
        first = NULL;
        last=NULL;
        count=0;
    }

    void add(int value)
    {

        Node *newNode = new Node(value);
        
        if (!first)
        {
            first = newNode;
        }
        else
        {
            newNode->previous=last;  //previous to new node will be current last
            last->next=newNode;      //next to current last will be new Node

        }

        last=newNode;           //new node becomes the last
        count++;
        
        return;
    }

    int size()
    {
        return count;
    }


    int get(int pos)
    {
        return locate(pos)->value;
    }

    int set(int pos, int value)
    {
        locate(pos)->value=value;
    }

    int remove(int pos)
    {
        Node * d = locate(pos);

        if(d==first){
            first=d->next;
            first->previous=NULL;
        }
        else
            d->previous->next=d->next; 

        if(d==last){
            last=d->previous;
            last->next=NULL;
        } 
        else
        {
            d->next->previous=d->previous;
        }
            
        int value=d->value;
        delete d;
        count--;
        return value;
       
    }
};