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
    int nodes;
    Trie(){
        root = new Node('\0');
        nodes=1;
    }
    void add_word(string str){
        Node *temp = root;
        for (int i = 0; i < str.length(); ++i) {
            char ch = str[i];
            if (temp->hashMap.count(ch)==0){
                temp->hashMap.insert(make_pair(ch,new Node(ch)));
                nodes++;
            }
            temp = temp->hashMap[ch];
            temp->total_branch++;
        }
        temp->isTerminal= true;
    }
};
int main(){
    int n;
    cin>>n;
    Trie *t = new Trie();
    for (int i = 0; i < n; ++i) {
        string word;
        cin>>word;
        t->add_word(word);
    }
    cout<<t->nodes;
}