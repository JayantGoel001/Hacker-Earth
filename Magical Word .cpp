#include <iostream>
#include <map>
#include <string>
int genNearPrime(bool *ar,int x){
    for (int i = 0; i < 13; ++i) {
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
    bool isPrime[92];
    for (int i = 0; i < 92; ++i) {
        isPrime[i]= true;
    }
    for (int i = 2; i*i < 92; i++) {
        for (int j = i*i; j < 92; j+=i) {
            isPrime[j]= false;
        }
    }
    map<char,char> m;
    for (int i = 65; i <91 ; ++i) {
        m.insert(make_pair(i,genNearPrime(isPrime,i)));
    }
    int n;
    cin>>n;
    for (int i = 0; i < n; ++i) {
        int len;
        cin>>len;
        string str;
        cin>>str;
        for (int j = 0; j < len; ++j) {
            cout<<m[str[j]];
        }
    }
}
