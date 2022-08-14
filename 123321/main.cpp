#include <iostream>

using namespace std;
int daonguoc(int p){
    int x{};
while(p!=0){
    int n = p%10;
    p/=10;
    x=x*10 + n;
}
return x;
}
int removeNumber1(int min, int n){
int x, p= 0 , i = 0;
n = daonguoc(n);
while(n!=0){
    x=n%10;
    n/=10;
    if(x==min&&i==0){
       i++;
        continue;
    }
    p=p*10+x;
}
return p;
}
int removeNumber(int n, int k)
{
    while(k!=0){
            int p = n;
            int min{10};
        while(p!=0){
            int x = p%10;
            p/=10;
            if(min>x){
                min = x;
            }
        }
        n = removeNumber1(min,n);
        cout<<min<<" "<<n<<endl;;
        k--;
    }
    return n;
}
int main()
{
int n = 191921612;
int k = 5;
cout << removeNumber(n,k);

    return 0;
}
