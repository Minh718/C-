#include <iostream>
using namespace std;
struct TheBook {
//string MS,Name,NSB,Gia;
int NSX;
};
struct Node {
TheBook data;
Node *pNext;
};
struct List {
Node* pHead;
Node* pTail;
};
void Init (List &l){
l.pHead=l.pTail=NULL;
}
Node *getNode (TheBook data){
Node* p = new Node;
if(p==NULL){
    return NULL;
}
p->data = data;
p->pNext = NULL;
return p;
}
void addHead(List &l,Node* p){
if(l.pHead==NULL){
    l.pHead=l.pTail=p;
}else{
p->pNext=l.pHead;
l.pHead=p;
}
}
void NhapSach(TheBook &data){

cout<<"===========Nhap============"<<endl;
//cin>>data.Gia>>data.NSB>>data.Name>>data.MS;
cout<<"nhap Nam San Xuat: ";
cin>>data.NSX;
}
void input(List &l) {
Init(l);
int n;
cout<<"nhap so luong sach: "<<endl;
cin>>n;
for(int i=0;i<n;i++){
    TheBook data;
    NhapSach(data);
    Node *p = getNode(data);
    addHead(l,p);
}
}
void Xuat(Node* p){
//static int i = 1;
//cout<<"Thong Tin Cuon Sach Thu "<<i<<" la: "<<endl;
//cout<<"Gia: "<<p->data.Gia<<endl;
//cout<<"NSB: "<<p->data.NSB<<endl;
//cout<<"Name: "<<p->data.Name<<endl;
//cout<<"MS: "<<p->data.MS<<endl;
cout<<"NSX: "<<p->data.NSX<<endl;
//i++;
}
void output(List l){
for(Node* k = l.pHead;k!=NULL;k=k->pNext){
    Xuat(k);
}
}
//void XoaDauNode(List &l){
//Node* g = l.pHead;
//l.pHead = g->pNext;
//delete g;
//}
//void xoaTruocNode(List &l,Node* p){
//for(Node* k = l.pHead;k!=NULL;k=k->pNext){
//    if(k->data.NSX==p->data.NSX){
//        Node* g;
//        g=k->pNext;
//        p->pNext=g->pNext;
//        delete g;
//        return;
//    }
//}
//}
//void xuly(List &l){
//    Node *p = l.pHead;
//for(Node* k = l.pHead->pNext;k!=NULL;k=k->pNext){
//    if(k->data.NSX<2000){
//        xoaTruocNode(l,p);
//        k=p;
//    }
//    p=k;
//}
//if(l.pHead->data.NSX<2000)
//{
//XoaDauNode(l);
//}
//}
void giaiPhong(List &l){
Node *p;
while(l.pHead!=NULL){
    p = l.pHead;
    l.pHead=l.pHead->pNext;
    delete p;
}
}
int main(){
List l;
input(l);
//xuly(l);
output(l);
giaiPhong(l);
}
