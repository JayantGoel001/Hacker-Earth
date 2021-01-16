#include <iostream>
#include <cmath>

using namespace std;
int main(){
    int n;
    cin>>n;
    for (int i = 0; i < n; ++i) {
        int x;
        cin>>x;
        int count = 0;
        for (int j = 1; j <= (sqrt(x)); ++j) {
            if (x%j==0){
                if (x/j==j){
                    count++;
                } else{
                    count+=2;
                }
            }
        }
        cout<<count<<"\n";
    }
}