#include <iostream>
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
        Node *prev = nullptr;
        while (temp && temp->next && k){
            if (temp->data < temp->next->data){
                Node *tempValue = temp->next;
                if (prev){
                    prev->next = tempValue;
                    temp = tempValue;
                } else{
                    head = tempValue;
                    prev = nullptr;
                }
                k--;
            } else {
                prev = temp;
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