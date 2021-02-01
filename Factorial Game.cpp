#include <iostream>
#include <map>
#define ll long long int
using namespace std;
int main(){
    int n;
    cin>>n;
    map<int,ll> m;
    ll maxi = 1;
    ll mod = 1000000007;
    m.insert(make_pair(1,1ll));
    for (int i = 0; i < n; ++i) {
        int x;
        cin>>x;
        if (x>maxi){
            for (int j = maxi+1; j <=x ; ++j) {
                m[j] = (m[j-1]*(ll)j)%mod;
            }
            cout<<m[x]<<"\n";
            maxi = (ll)x;
        } else{
            cout<<m[x]<<"\n";
        }
    }
}