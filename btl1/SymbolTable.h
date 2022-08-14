#ifndef SYMBOLTABLE_H
#define SYMBOLTABLE_H
#include "main.h"

class SymbolTable
{
public:
    class Node
    {
    public:
        string identifier_name;
        string type;
        int STT;
        Node* next;
        Node* prev;
    public:
        Node():next(NULL),prev(NULL){};
        Node(string identifier_name,string type,int STT):
            identifier_name(identifier_name),type(type),STT(STT),next(NULL),prev(NULL){};
    };
private:
    Node* head;
    Node* tail;
    int count;
public:
    SymbolTable():head(NULL),tail(NULL),count(0) {};
    void run(string filename);
};
#endif
