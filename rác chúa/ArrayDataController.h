//
//  ArrayDataController.h
//  KTLT ASS 3
//
//  Created by Nhân Nguyễn on 17/05/2021.
//

// Students can remove the final initial return of the functions

#ifndef ArrayDataController_h
#define ArrayDataController_h

#include "dataStructure.h"
#include <vector>
#include <string>
//Functions used to manage Array
void print(Array& array){
    if (!array.size) {
        std::cout << "Array is empty" << endl;
        return;
    }
    std::cout <<"[";
    for(int i=0;i<array.size;i++){
        std::cout << array.arr[i].ID << " ";
    }
    std::cout <<"]" << endl;
}

void initArray (Array& array, int cap){
    array.capacity=cap;
    array.arr = new Soldier[cap];

}
bool insertAt(Array& array, Soldier element, int pos){
if(element.ID>="A"&&element.ID<="Z"){
    if(array.size==array.capacity&&array.capacity>0){
        void ensureCapacity(Array&,int);
        ensureCapacity(array,array.capacity+1);
    }
    if(pos<=array.size&&array.size<array.capacity&&pos>=0){
        if(pos==array.size){
        array.arr[pos]=element;
        array.size++;
        return true;
        }
        else{
        for(int i=0;i<array.size;i++){
        if(i==pos){
         for(int j=array.size;j>=i;j--){
                if(j==i){
                    array.arr[j]=element;
         array.size++;
        return true;
                }
            array.arr[j]=array.arr[j-1];
         }
        }
        }
    }
    }
}
    return false;
}

bool removeAt (Array& array, int idx){
    if(array.size>idx&&idx>=0){
        for(int i=0;i<array.size;i++){
            if(i==idx){
                for(;i<array.size-1;i++){
                    array.arr[i]=array.arr[i+1];
                }
                array.size--;
                return true;
            }
        }
    }

    return false;
}

bool removeFirstItemWithHP (Array& array, int HP){
    for(int i=0;i<array.size;i++){
        if(array.arr[i].HP==HP){
            for(;i<array.size-1;i++){
                array.arr[i]=array.arr[i+1];
            }
            array.size--;
            return true;
        }
    }

    return false;
}

void ensureCapacity(Array& array, int newCap){
    array.capacity=newCap;
    Soldier* x = new Soldier[newCap];
    for(int i=0;i<newCap-1;i++){
        x[i]=array.arr[i];
    }
    delete[] array.arr;
    array.arr=x;
}

int indexOf(Array& array, Soldier soldier){
    for(int i=0;i<array.size;i++){
        if(array.arr[i].HP==soldier.HP&&array.arr[i].ID==soldier.ID&&array.arr[i].isSpecial==soldier.isSpecial){
            return i;
        }
    }

    return -1;
}

int size(Array& array){
    return array.size;
}

bool empty(Array& array){
    if(!array.size){
        return true;
    }

    return false;
}

string getIDAt(Array& array, int pos){
    if(pos>=0&&pos<array.size){
        return array.arr[pos].ID;
    }

    return "-1";
}

int getHPAt(Array& array, int pos){
    if(pos>=0&&pos<array.size){
        return array.arr[pos].HP;
    }

    return -1;
}

bool setHPAt(Array& array, int HP, int pos){
    if(pos>=0&&pos<array.size){
        array.arr[pos].HP=HP;
        return true;
    }

    return false;
}

void clear(Array& array){
    if(array.capacity!=0){
    array.capacity=0;
    array.size=0;
    delete[] array.arr;
    }
}

bool contains (Array& array, Soldier soldier){
     for(int i=0;i<array.size;i++){
        if(array.arr[i].HP==soldier.HP&&array.arr[i].ID==soldier.ID&&array.arr[i].isSpecial==soldier.isSpecial){
            return true;
        }
    }

    return false;
}

//You can write your own functions here

//End your own functions

#endif /* ArrayDataController_h */
