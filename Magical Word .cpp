#include <iostream>
#include <map>
#include <string>
int genNearPrime(bool *ar,int x){
    for (int i = 0; i < 26; ++i) {
        if (ar[x-i]){
            return x-i;
        }
        if (ar[x + i]){
            return x+i;
        }
    }
    return x;
}
using namespace std;
int main(){
    bool isPrime[122];
    for (int i = 0; i < 122; ++i) {
        isPrime[i]= true;
    }
    for (int i = 2; i*i < 122; i++) {
        for (int j = i*i; j < 122; j+=i) {
            isPrime[j]= false;
        }
    }
    map<char,char> m;
    for (int i = 0; i <65 ; ++i) {
        m.insert(make_pair(i,'C'));
    }
    for (int i = 65; i <91 ; ++i) {
        m.insert(make_pair(i,genNearPrime(isPrime,i)));
    }
    for (int i = 91; i <96 ; ++i) {
        m.insert(make_pair(i,'C'));
    }
    for (int i = 96; i <123 ; ++i) {
        m.insert(make_pair(i,genNearPrime(isPrime,i)));
    }
    for (int i = 123; i <165 ; ++i) {
        m.insert(make_pair(i,'C'));
    }
    int n;
    cin>>n;
    for (int i = 0; i < n; ++i) {
        int len;
        cin>>len;
        string str;
        cin>>str;
        for (int j = 0; j < len; ++j) {
            if(str[j]=='^' || str[j]=='_'){
                cout<<"a";
            }else if(str[j]=='|' || str[j]=='}'||str[j]=='{'){
                cout<<"q";
            }else if (str[j]==']'||str[j]=='['||str[j]=='\\') {
                cout<<"Y";
            }else {
                cout << m[str[j]];
            }
        }
        cout<<"\n";
    }
}
