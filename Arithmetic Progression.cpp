#include <iostream>
#define ll long long int
using namespace std;
int main() {
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        ll a,b,c;
        cin>>a>>b>>c;
        ll x = abs(2*b-a-c);
        cout<<(x/2+x%2)<<"\n";
    }
}
