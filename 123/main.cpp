#include <iostream>

using namespace std;
int sizze = 20, c1 = 3, c2 = 5, level = 0;
int linearProbing(int key, int i)
{
    return ((key % sizze) + c1 * i) % sizze;
}
int quadraticProbing(int key, int i)
{
    return ((key % sizze) + c1 * i + c2 * i * i) % sizze;
}
int doubleHashing(int key, int i)
{
    int h1 = key % sizze;
    int h2 = 1 + key % (sizze - 2);
    return (h1 + c1 * i * h2) % sizze;
}
int convert(string s)
{
    string ans;
    ans = to_string(level);
    for (size_t i = 0; i < s.length(); i++)
    {
        ans += to_string((int)s[i] - 48);
    }
    return stoi(ans);
}
int main()
{
string s[] = {"a1","g2", "vf", "fd", "es", "ff", "re", "rr", "ok", "rr"};
for(int i = 0;i<10;i++){
        int valueHash = convert(s[i]);
cout<<s[i]<<" "<<valueHash<<" ";
    for(int j = 0;j<sizze;j++){
        cout<<linearProbing(valueHash,j)<<" ";
    }
    cout<<endl;
}
}
