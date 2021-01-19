#include <iostream>

using namespace std;
int main(){
    int tot = 1000000;
    int factors[tot+1];
    for (int i = 0; i <=tot; ++i) {
        factors[i]=1;
    }
    for (int i = 2; i <=tot ; ++i) {
        for (int j = i; j <=tot ; j+=i) {
            factors[j]++;
        }
    }
    int n;
    cin>>n;
    int ar[n];

    int solve_2 = 0;
    int solve_3 = 0;
    int solve_4 = 0;
    int solve_1 = 0;
    for (int i = 0; i < n; ++i) {
        cin>>ar[i];
        int factor = factors[ar[i]];
        if (factor==4){
            solve_4++;
        } else if (factor==3){
            solve_3++;
        } else if (factor==2){
            solve_2++;
        } else if (factor==1){
            solve_1++;
        }
    }
    cout<<solve_3+solve_2-solve_1-solve_4;
}