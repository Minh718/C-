#include <iostream>
using namespace std;
class IntSLinkedList
{
public:
    class Node; // Forward declaration

private:
    Node* head;
    Node* tail;
    int count;

public:
    IntSLinkedList() : head(NULL), tail(NULL), count(0) {};
    void add(int element)
    {
        if(this->count == 0)
        {
            Node* p = new Node(element);
            this->head = p;
            this->tail = p;
            this->count++;
        }
        else
        {
            Node *p = new Node(element);
            this->tail->next = p;
            this->tail = p;
            this->count++;
        }
    }

    void add(int index, int element)
    {
        if(index<0||index>this->count)
        {
            throw std::out_of_range("Index is out of range");
        }
        if(this->count == 0)
        {
            this->add(element);
        }
        else if(index == 0)
        {
            Node* p = new Node(element);
            p->next = this->head;
            this->head = p;
            this->count++;
        }
        else if(index == this->count)
        {
            this->add(element);
        }
        else
        {
            Node* prev = this->head;
            for(int i=0; i<index-1; i++)
                prev = prev->next;
            Node* p = new Node(element);
            p->next = prev->next;
            prev->next = p;
            this->count++;
            return;
        }
    }

    int removeAt(int index)
    {
        if(index<0||index>this->count)
        {
            throw std::out_of_range("Index is out of range");
        }
        else if(index==0)
        {
            Node *p = head;
            head = head->next;
            int x = p->data;
            delete p;
            return x;
        }
        else if(index==this->count)
        {
            Node* p;
            for(Node* k = head->next; k!=NULL; k = k ->next)
            {
                if(k==tail)
                {
                    p->next=NULL;
                    tail=p;
                    int x = p->data;
                    delete p;
                    return x;
                }
                p=k;
            }
        }
        else
        {
            Node* p = head;
            Node* k;
            for(int i=0; i<index; i++)
            {
                k=p;
                p = p->next;
            }
            k->next = p->next;
            int x = p->data;
            delete p;
            return x;
        }
    }

    bool removeItem(int item)
    {
        for(Node* k= this->head; k!=NULL; k=k->next)
        {
            Node* p;
            if(k->data==item)
            {
                p->next = k->next;
                delete k;
                return true;
            }
            p=k;
        }
        return false;
    }

    bool empty()
    {

        return this->count==0;
    }


    int size()
    {

        return 0;
    }

    int get(int index)
    {
        if(index<0||index>this->count)
        {
            throw std::out_of_range("Index is out of range");
        }
        else if(index==0)
        {
            return this->head->data;
        }
        else if(index==this->count)
        {
            return this->tail->data;
        }
        else
        {
            Node* p = head;
            for(int i=0; i<index; i++)
            {
                p=p->next;
            }
            return p->data;
        }
        return -1;
    }

    void set(int index, int element)
    {
        if(index<0||index>this->count)
        {
            throw std::out_of_range("Index is out of range");
        }
        else if(index==0)
        {
            this->head->data = element;
        }
        else if(index==this->count)
        {
            this->tail->data = element;
        }
        else
        {
            Node* p = head;
            for(int i=0; i<index; i++)
            {
                p=p->next;
            }
            p->data = element;
        }
    }

    int indexOf(int item)
    {
        int x = 0;
        for(Node* k= this->head; k!=NULL; k=k->next)
        {
            if(k->data==item)
            {
                return x;
            }
            x++;
        }
        return -1;
    }

    bool contains(int item)
    {
        for(Node* k= this->head; k!=NULL; k=k->next)
        {
            if(k->data==item)
            {
                return true;
            }
        }
        return false;
    }

    void clear()
    {

    }

//    string toString();

public:
    class Node
    {
    public:
        int data;
        Node* next;

    public:
        Node() : next(NULL) {};
        Node(int data) :
            data(data), next(NULL) {};
    };
};
int main(){
IntSLinkedList list;
int values[]   = {10, 15, 2,  6,  4,  7,  40,  8};
int index[]    = {0,  0,  1,  3,  2,  3,  5,   0};
for (int idx = 0; idx < 8; idx++){
   list.add(index[idx], values[idx]);
}

list.removeAt(8);
}

//cout << list.toString();}
