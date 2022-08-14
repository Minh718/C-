#include <iostream>
#include <stack>
#include <math.h>
using namespace std;
string solve(int n) {
    stack<char> s;
    while(n>0){
        s.push(n%3 + '0');
    }
    return " ";
}
int main(){
string s = "abba";
cout<<solve(s);
}
