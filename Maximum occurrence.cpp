#include <iostream>
#include <map>
#include <string>
using namespace std;
int main(){
    string str;
    getline(cin,str);
    map<char,int> m;
    for (int i = 0; i < str.length(); ++i) {
        if (m.count(str[i])!=0){
            m[str[i]]+=1;
        } else{
            m[str[i]] = 1;
        }
    }
    int maxi = -1;
    char character = ' ';
    for(auto it=m.begin();it!=m.end();it++){
        if (it->second>maxi){
            character = it->first;
            maxi = it->second;
        } else if (it->second == maxi){
            if (character>it->first){
                character = it->first;
            }
        }
    }
    cout<<character<<" "<<maxi;
}