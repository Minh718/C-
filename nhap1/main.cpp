    #include <iostream>
using namespace std;
struct node
{
int data;
node *pNext;
};
struct list{
node *pHead;
node *pTail;
};
void khoitao(list &l){
l.pHead=NULL;
l.pTail=NULL;
}
node *khoitaoNODE(int x){
node *p = new node;
p->data = x;
p->pNext=NULL;
return p;
}
void themvaodau(list &l,node *p){
    if(l.pHead==NULL){
        l.pHead=l.pTail=p;
    }
    else{
            cout<<p->pNext<<" ";
        p->pNext=l.pHead;
    cout<<p->pNext<<" ";
    cout<<l.pHead<<" ";
        l.pHead = p;
        cout<<p<<" ";
        cout<<l.pHead->pNext<<" ";
        cout<<l.pHead<<" ";
    }
}
void xuatdanhsach(list l){
for(node *k=l.pHead;k!=NULL;k=k->pNext){
        cout<<k->pNext;

    }
}
int main(){
    list l;
    khoitao(l);
    for(int i=0;i<5;i++){
        int x;
        cin>>x;
        node *p = khoitaoNODE(x);
        themvaodau(l,p);
    }
//xuatdanhsach(l);
}
