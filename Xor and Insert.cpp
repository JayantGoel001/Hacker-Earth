#include <iostream>
#include <set>
#define ll long long int
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int q;
    cin>>q;
    set<ll> s;
    s.insert(0);
    for (int i = 0; i < q; ++i) {
        int op;
        ll x;
        cin>>op;
        if (op==3){
            cout<<*(s.begin())<<"\n";
        } else{
            cin>>x;
            if (op==1){
                s.insert(x);
            } else{
                set<ll> s2;
                for(auto it=s.begin();it!=s.end();it++){
                    s2.insert((*it)^x);
                }
                s = s2;
            }
        }
    }
}