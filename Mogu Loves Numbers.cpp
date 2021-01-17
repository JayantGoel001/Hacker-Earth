#include <iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    int tot = 1000000;
    bool isPrime[tot+1];
    for (int i = 1; i <= tot; ++i) {
        isPrime[i] = true;
    }
    for (int i = 2; i*i <=tot ; ++i) {
        for (int j = i*i; j <tot ; j+=i) {
            isPrime[j]= false;
        }

    }
    for (int i = 0; i < t; ++i) {
        int L,R;
        cin>>L>>R;
        int count = 0;
        for (int j = L; j <=R ; ++j) {
            if(isPrime[j]){
                count++;
            }
        }
        cout<<count<<"\n";
    }
}