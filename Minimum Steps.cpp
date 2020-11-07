#include <iostream>
#include <math.h>
#define ll long long int
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    for (int i = 0; i < t; ++i) {
        ll k,m,n;
        cin>>k>>m>>n;
        ll count = 0;
        while (k<m){
            if (m%n==0){
                m/=n;
                count++;
            }else{
                ll x = (n-(m%n));
                m+= (x/2)*2+x%2;
                count+=x/2+x%2;
            }
        }
        if (k>m){
            count+=(k-m)/2+(k-m)%2;
        }
        cout<<count<<"\n";
    }
}