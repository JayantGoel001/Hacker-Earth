#include <iostream>
#include <stack>
using namespace std;
class Node{
public:
    int data;
    Node *next;
    Node(){
        this->data = 0;
        this->next = nullptr;
    }
    Node(int data){
        this->data = data;
        this->next = nullptr;
    }
};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    for (int i = 0; i < t; ++i) {
        int n;
        int k;
        cin>>n>>k;
        Node *head = nullptr;
        Node *temp = head;
        for (int j = 0; j < n; ++j) {
            int x;
            cin>>x;
            if (temp){
                temp->next = new Node(x);
                temp = temp->next;
            } else{
                temp = new Node(x);
                head = temp;
            }
        }
        temp = head;
        stack<Node *> prev;
        while (temp && temp->next && k) {
            if (temp->data < temp->next->data) {
                Node *tempValue = temp->next;
                if (prev.size()!=0) {
                    Node *prevTemp = prev.top();

                    prev.pop();
                    prevTemp->next = tempValue;

                    temp = prevTemp;
                } else {
                    head = tempValue;
                    temp = temp->next;
                }
                k--;
            } else {
                prev.push(temp);
                temp = temp->next;
            }
        }
        while (head){
            cout<<head->data<<" ";
            head = head->next;
        }
        cout<<"\n";
    }
}