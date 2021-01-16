#include <iostream>
#define ll long long int
using namespace std;
int main(){
    int t;
    cin>>t;
    int tot = 1000000;
    ll nc2[tot];
    nc2[1] = 0;
    nc2[2] = 1;
    for (int i = 3; i <tot ; ++i) {
        nc2[i]=nc2[i-1] * i/(i-2);
    }
    for (int i = 0; i < t; ++i) {
        int n;
        cin>>n;
        cout<<nc2[n]<<"\n";
    }
}