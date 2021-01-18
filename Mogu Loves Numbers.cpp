#include <iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    int tot = 1000;//000;
    bool isPrime[tot+1];
    isPrime[1]= false;
    for (int i = 2; i <= tot; ++i) {
        isPrime[i] = true;
    }
    for (int i = 2; i*i <=tot ; ++i) {
        for (int j = i*i; j <tot ; j+=i) {
            isPrime[j]= false;
        }
    }
    int ar[tot+1];
    for (int i = 0; i <=tot; ++i) {
        ar[i]=0;
    }
    for (int i = 2; i <=tot; ++i) {
        if (isPrime[i-1]){
            ar[i]=ar[i-1]+1;
        }else{
            ar[i]=ar[i-1];
        }
    }

    for (int i = 0; i < t; ++i) {
        int L,R;
        cin>>L>>R;
        int count = ar[max(L,R)] - ar[min(L,R)];
        if(isPrime[max(L,R)] ) {
            count++;
        }
        cout << count << "\n";
    }
}