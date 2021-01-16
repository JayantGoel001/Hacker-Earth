#include <iostream>
#include <cmath>
#define ll long long int
using namespace std;
ll power(ll a,ll b,ll mod){
    if (b==0){
        return 1;
    } else{
        if (b%2==0){
            return power((a*a)%mod,b/2,mod);
        } else{
            return (a*power((a*a)%mod,(b-1)/2,mod))%mod;
        }
    }
}
int main(){
    ll a,b;
    cin>>a>>b;
    ll mod = pow(10,9)+7;
    cout<<power(a,b,mod);
}