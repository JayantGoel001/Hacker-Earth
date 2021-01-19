#include <iostream>
#include <cmath>
#define ll long long int
using namespace std;

ll prodPowGCD(long long int x, long long int y, long long int mod) {
    if (y==0){
        return 1;
    } else{
        if (y%2==0){
            return prodPowGCD((x*x)%mod,y/2,mod);
        } else{
            return (x*prodPowGCD((x*x)%mod,(y-1)/2,mod))%mod;
        }
    }
}
int GCD(int a,int b){
    if (b==0){
        return a;
    } else{
        return GCD(b,a%b);
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    ll ar[n];
    ll prod = 1ll;
    ll mod = pow(10, 9) + 7;
    for (int i = 0; i < n; ++i) {
        cin>>ar[i];
        prod=(prod*ar[i])%mod;
    }
    ll gcd;
    if (n>=2) {
        gcd = GCD(max(ar[0], ar[1]), min(ar[0], ar[1]));
        for (int i = 2; i < n; ++i) {
            gcd = GCD(max(gcd, ar[i]), min(gcd, ar[i]));
        }
    } else{
        gcd = ar[0];
    }
    cout<<prodPowGCD(prod,gcd,mod)<<"\n";
}

