#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    int a[n];
    int b[n];
    int minEL = INT16_MAX;
    int minPos = -1;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] < minEL) {
            minEL = a[i];
            minPos = i;
        }
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    int count = 0;
    for (int i = 0; i < n; ++i) {
        while (a[i]>minEL){
            a[i]-=b[i];
            count++;
            if (a[i]==minEL){
                break;
            }
        }
        if (minEL>a[i]){
            minEL=a[i];
            i=-1;
        }
        if (a[i]<0){
            count=-1;
            break;
        }
    }
    cout<<count<<"\n";
}