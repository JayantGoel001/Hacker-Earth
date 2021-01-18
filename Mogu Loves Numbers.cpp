#include <iostream>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    int tot = 1000000;
    bool isPrime[tot+1];
    int ar[tot+1];
    isPrime[1]= false;
    for (int i = 2; i <= tot; ++i) {
        isPrime[i] = true;
        ar[i]=0;
    }
    ar[1] = 0;
    for (int i = 2; i*i <=tot ; ++i) {
        if (isPrime[i]) {
            for (int j = i * i; j <= tot; j += i) {
                isPrime[j] = false;
            }
        }
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
        int maxi = max(L,R);
        int mini = min(L,R);
        int count = ar[maxi] - ar[mini];
        if(isPrime[maxi] ) {
            count++;
        }
        cout << count << "\n";
    }
}