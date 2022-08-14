#include <iostream>
#include <string>
using namespace std;
int compareString(string s1,string s2){
    size_t i= 0;
    while(true){
        if(i==s1.length()&&i==s2.length()) return 0;
       else if(i==s1.length()) return -1;
        else if(i==s2.length()) return 1;
        if(s1[i]>s2[i]) return 1;
        else if(s1[i]<s2[i]) return -1;
        else i++;
    }
    return 0;
}
int main(){
string s = "suml";
string s1 = "sumM";

cout<<compareString(s,s1);
}
