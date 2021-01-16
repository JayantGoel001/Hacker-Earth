#include <iostream>
#include <set>
#include <algorithm>
#include <cmath>

#define ll long long int
using namespace std;
int main(){
    int n;
    cin>>n;
    ll maxEl = -1;
    ll ar[n];
    for (int i = 0; i < n; ++i) {
        cin>>ar[i];
        maxEl = max(maxEl,ar[i]);
    }
    sort(ar,ar+n);
    int diff = ar[1]-ar[0];
    set<int> factors;
    for (int i = 1; i <=sqrt(diff) ; ++i) {
        if (diff%i==0){
            if (diff/i==i) {
                factors.insert(i);
            } else{
                factors.insert(i);
                factors.insert(diff/i);
            }
        }
    }
    factors.erase(factors.begin());
    for(auto it=factors.begin();it!=factors.end();it++){
        int i = *it;
        bool isTrue = true;
        int constValue = ar[0]%i;
        for (int j = 0; j < n; ++j) {
            if (ar[j]%i!=constValue){
                isTrue = false;
                break;
            }
        }
        if (isTrue){
            cout<<i<<" ";
        }
    }
}