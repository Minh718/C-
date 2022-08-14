#include <iostream>
#include <math.h>
#include <string>
using namespace std;
long int digitExtraction(long int seed,int* extractDigits,int size)
{
string s = to_string(seed);
long int ans = 0;
for(int i = 0;i<size;i++){
    ans = ans*10 + (s[extractDigits[i]]-'0');
}
return ans;
}
int main(){
int a[]={1,2,5};
cout << digitExtraction(122443,a,3);
}
