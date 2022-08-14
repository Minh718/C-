//
//  thirdBattle.h
//  KTLT ASS 3
//
//  Created by Nhân Nguyễn on 17/05/2021.

// Students can remove the final initial return of the functions

#ifndef thirdBattle_h
#define thirdBattle_h

#include "SLLDataController.h"
#include "ArrayDataController.h"
#include <vector>
#include <string>

//////////////////////////////////////////////////////
/// TASK 1
//////////////////////////////////////////////////////

bool push(Array& array, Soldier soldier){
if(soldier.ID>="A"&&soldier.ID<="Z"){
ensureCapacity(array,array.capacity+1);
array.arr[array.size]=soldier;
array.size++;
return true;
}
    return false;
}

bool pop(Array& array){
if(array.size>0){
    array.size--;
    return true;
}
    return false;
}

Soldier top(Array& array){
if(array.size>0){
    return array.arr[array.size-1];
}
    return Soldier();//return this if cannot get top
}
//
//////////////////////////////////////////////////////
/// TASK 2
//////////////////////////////////////////////////////

bool enqueue(SLinkedList& list, Soldier soldier){
    if(soldier.ID>="A"&&soldier.ID<="Z"){
    SoldierNode* head = list.head;
    if(list.head==NULL){
            SoldierNode* x = new SoldierNode();
        list.head=x;
        x->data=soldier;
        x->next=NULL;
        list.size++;
        return true;
    }
    for(int i=0;i<list.size;i++){
        if(head->next==NULL){
            SoldierNode* x = new SoldierNode();
            head->next=x;
            x->data=soldier;
            x->next=NULL;
            list.size++;
            return true;
        }
        head=head->next;
    }
    }
    return false;
}

bool dequeue(SLinkedList& list){
    if(list.size>0){
    SoldierNode* head = list.head;
    list.head=head->next;
    delete head;
    list.size--;
    return true;
    }
    return false;
}

Soldier front(SLinkedList& list){
if(list.size>0){
return list.head->data;
}
return Soldier();//Return this if cannot get front
//    return Soldier();//Return this if cannot get front
}

//////////////////////////////////////////////////////
/// TASK 3
//////////////////////////////////////////////////////

void reverse(SLinkedList& list){
    SoldierNode* head = list.head;
    SoldierNode* y= list.head;
    head=head->next;
    for(int i=1;i<list.size;i++){
    SoldierNode* x;
    x=head;
    head=head->next;
    x->next=y;
    y=x;
    }
    list.head->next=NULL;
    list.head = y;
}

//////////////////////////////////////////////////////
/// TASK 4
//////////////////////////////////////////////////////

SLinkedList merge(SLinkedList& list1, SLinkedList& list2){
    SLinkedList s;
    SoldierNode* head;
    int list;
    int m = 0 ;
    if(list1.size==0&&list2.size==0){
        return s;
    }
    else if(list1.size==0){
            list1=list2;
         list =list1.size;
        s.size=list;
        head=list1.head;
    }
    else if(list2.size==0){
        list=list1.size;
        s.size=list;
        head=list1.head;
    }
    else{
    list = list1.size+list2.size;
    s.size = list;
       head = list1.head;
    for(int i=0;i<list1.size;i++){
        if(head->next==NULL){
            head->next=list2.head;
        }
        head=head->next;
    }
    }
    head=list1.head;
    Soldier linh = head->data;
    int h=0;
    SoldierNode* kk=new SoldierNode();
    for(int i=1;i<list;i++){
         head=head->next;
    if((linh.HP>head->data.HP)||(linh.HP==head->data.HP&&linh.isSpecial>head->data.isSpecial)||(linh.HP==head->data.HP&&linh.isSpecial==head->data.isSpecial&&linh.ID>=head->data.ID)){
        h=i;
        linh=head->data;
        kk = head;
    }
   if(i==list-1){
        SoldierNode* y=list1.head;
        head=list1.head;
        if(h==0){
             kk=head;
            list1.head=head->next;
//            delete head;
            head=list1.head;
            linh = head->data;
            list--;
        }
    for(int j=1;j<=h;j++){
        head=head->next;
        if(j==h){
        y->next=head->next;
            head=list1.head;
            list--;
            linh=list1.head->data;
        }
        y = head;
    }
    h=0;
SoldierNode* head1=s.head;
        for(int j=0;j<m;j++){
        if(head1->next==NULL){
        head1->next=kk;
        kk->next=NULL;
        m++;
        break;
        }
        head1=head1->next;
        }
        if(m==0){
        s.head = kk;
        head1 = s.head;
        head1->next=NULL;
        m++;
    }
    if(list==1){
                head1=s.head;
            for(int i=0;i<m;i++){
                    if(head1->next==NULL){
                    head1->next=list1.head;
                    list1.head->next=NULL;
                    }
                head1=head1->next;
            }
        }
    i=0;
   }
    }
return s;
//    return SLinkedList();
}

//You can write your own functions here
//
//End your own functions

#endif /* thirdBattle_h */
