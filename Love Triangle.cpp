#include<iostream>
#define ll long long int
using namespace std;

long long int solveRecur(ll x) {
    if (x<9){
        return x;
    } else{
        return x%9 + 10*solveRecur(x/9);
    }
}

int main(){
    ll x ;
    while (cin>>x){
        ll sum = solveRecur(x);
        cout<<sum<<"\n";
    }
}
