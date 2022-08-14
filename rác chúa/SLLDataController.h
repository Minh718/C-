//
//  SLLDataControler.h
//  KTLT ASS 3
//
//  Created by Nhân Nguyễn on 17/05/2021.
//

// Students can remove the final initial return of the functions

#ifndef SLLDataController_h
#define SLLDataController_h

#include "dataStructure.h"
#include <vector>
#include <string>

//Functions used to manage Singly Linked List
void print(SLinkedList& list){
    if (!list.size) {
        std::cout << "List is empty" << endl;
        return;
    }
    SoldierNode* head = list.head;
    while (head){
        std::cout << head->data.ID << "->";
        head = head->next;
    }
    std::cout << "NULL"<<endl;
}

bool insertAt (SLinkedList& list, Soldier element, int pos){
    if(element.ID>="A"&&element.ID<="Z"){
    if(pos==list.size){
            SoldierNode* head = list.head;
            SoldierNode* x = new SoldierNode();
            if(list.head==NULL){
                list.head=x;
                x->next=NULL;
                x->data=element;
                list.size++;
                return true;
            }
            for(int i=0;i<list.size;i++){
                if(head->next==NULL){
                    head->next=x;
                    x->next=NULL;
                    x->data=element;
                    list.size++;
                return true;
                }
                    head=head->next;
            }
    }
    else if(pos<list.size&&pos>=0){
            SoldierNode* head = list.head;
            SoldierNode* x = new SoldierNode();
            SoldierNode* y=head;
            if(pos==0){
                x->data = element;
                x->next=head;
                list.head=x;
                list.size++;
            return true;
            }
            else{
            for(int i=1;i<list.size;i++){
                    head=head->next;
                if(i==pos){
                   x->data=element;
                   x->next=head;
               y->next=x;
               list.size++;
               return true;
                }
                y=head;
            }
    }
    }
    }
    return false;
}

bool removeAt (SLinkedList& list, int idx){
    if(idx<list.size&&idx>=0){
            SoldierNode* head = list.head;
    if(idx==0){
        list.head=head->next;
        delete head;
        list.size--;
        return true;
    }
    else{
            SoldierNode* y=head;
        for(int i=1;i<list.size;i++){
            head=head->next;
            if(idx==i){
                y->next=head->next;
                delete head;
                list.size--;
                return true;
            }
    y=head;
        }
    }
    }

    return false;
}

bool removeFirstItemWithHP (SLinkedList& list, int HP){
    if(list.size>0){
    SoldierNode* head = list.head;
    SoldierNode* x = new SoldierNode();
    SoldierNode* y=head;
    if(head->data.HP==HP){
        list.head=head->next;
        delete head;
        list.size--;
        return true;
    }
    for(int i=0;i<list.size;i++)
    {
        if(head->data.HP==HP){
            y->next=head->next;
            delete head;
            list.size--;
            return true;
        }
        y=head;
        head=head->next;
    }
    }
    return false;
}

int indexOf(SLinkedList& list, Soldier soldier){
    SoldierNode* head = list.head;
    for(int i=0;i<list.size;i++){
        if(head->data.HP==soldier.HP&&head->data.ID==soldier.ID&&head->data.isSpecial==soldier.isSpecial){
            return i;
        }
        head=head->next;
    }

    return -1;

}

int size(SLinkedList& list){
    return list.size;
}

bool empty(SLinkedList& list){
    if(!list.size){
        return true;
    }

    return false;
}

void clear(SLinkedList& list){
    for(int i=0;i<list.size;i++){
        SoldierNode* head = list.head;
        list.head=head->next;
       delete head;
    }
    list.size=0;
}

string getIDAt(SLinkedList& list, int pos){
    SoldierNode* head= list.head;
    for(int i =0;i<list.size;i++){
        if(i==pos){
            return head->data.ID;
        }
        head=head->next;
    }

    return "-1";
}

int getHPAt(SLinkedList& list, int pos){
    if(pos<list.size&&pos>=0){
   SoldierNode* head= list.head;
    for(int i =0;i<list.size;i++){
        if(i==pos){
            return head->data.HP;
        }
        head=head->next;
    }
    }

    return -1;
}

bool setHPAt(SLinkedList& list, int HP, int pos){
    if(pos<list.size&&pos>=0){
     SoldierNode* head= list.head;
    for(int i =0;i<list.size;i++){
        if(i==pos){
           head->data.HP=HP;
           return true;
        }
        head=head->next;
    }
    }

    return false;
}

bool contains (SLinkedList& list, Soldier soldier){
    SoldierNode* head = list.head;
    for(int i=0;i<list.size;i++){
        if(head->data.HP==soldier.HP&&head->data.ID==soldier.ID&&head->data.isSpecial==soldier.isSpecial){
            return true;
        }
        head=head->next;
    }

    return false;
}

//You can write your own functions here

//End your own functions

#endif /* SLLDataControler_h */
