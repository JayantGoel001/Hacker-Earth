#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;
class Node{
public:
    int data;
    unordered_map<int,Node*> hashMap;
    int total_branch;
    bool isTerminal;
    Node(int data){
        this->data = data;
        this->isTerminal= false;
        total_branch = 0;
    }
};
class Trie{
public:
    Node* root;
    Trie(){
        root = new Node('\0');
    }
    void add_word(string str){
        Node *temp = root;
        for (int i = 0; i < str.length(); ++i) {
            char ch = str[i];
            if (temp->hashMap.count(ch)==0){
                temp->hashMap.insert(make_pair(ch,new Node(ch)));
            }
            temp = temp->hashMap[ch];
            temp->total_branch++;
        }
        temp->isTerminal= true;
    }
    int getResult(string str){
        Node *temp = root;
        for (int i = 0; i < str.length(); ++i) {
            char ch = str[i];
            if (temp->hashMap.count(ch)==0){
                return 0;
            } else{
                temp=temp->hashMap[ch];
            }
        }
        return temp->total_branch;
    }
};
int main(){
    int n;
    cin>>n;
    Trie *t = new Trie();
    for (int i = 0; i < n; ++i) {
        string op,word;
        cin>>op>>word;
        if (op=="add"){
            t->add_word(word);
        }else{
            cout<<t->getResult(word)<<"\n";
        }
    }
}