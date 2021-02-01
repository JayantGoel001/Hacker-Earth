#include<iostream>
#define ll long long int
using namespace std;
class Node{
public:
    ll data;
    Node *next;
    Node(){
        this->data = 0ll;
        this->next= nullptr;
    }
    Node(ll data){
        this->data = data;
        this->next = nullptr;
    }
};

int main(){
    int n;
    cin>>n;
    Node *head = nullptr;
    Node *temp = head;
    for (int i = 0; i < n; ++i) {
        ll x;
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
    Node *evenPtr = nullptr;
    Node *evenPtrHead = nullptr;
    Node *prev = nullptr;
    Node *prevEven = nullptr;

    while (temp){
        if ((temp->data)%2==0){
            if (evenPtrHead){
                evenPtr->next = new Node(temp->data);
                evenPtr = evenPtr->next;
            } else{
                evenPtr = new Node(temp->data);
                evenPtrHead = evenPtr;
                prevEven = prev;
            }

        } else {
            if (evenPtrHead) {
                Node *tail = evenPtrHead;
                while (tail->next) {
                    tail = tail->next;
                }
                while (evenPtrHead && evenPtrHead != tail) {
                    Node *nextValue = tail->next;
                    Node *dataValue = new Node(evenPtrHead->data);
                    tail->next = dataValue;
                    dataValue->next = nextValue;

                    evenPtrHead = evenPtrHead->next;
                }
                if (prevEven) {
                    prevEven->next = tail;
                    while (tail->next) {
                        tail = tail->next;
                    }
                    tail->next = temp;
                } else {
                    head = tail;
                    while (tail->next) {
                        tail = tail->next;
                    }
                    tail->next = temp;

                }
                evenPtrHead = nullptr;
                evenPtr = nullptr;
            }
        }
        prev = temp;
        temp = temp->next;
    }
    if(evenPtrHead){
        Node *tail = evenPtrHead;
        while (tail->next) {
            tail = tail->next;
        }
        while (evenPtrHead && evenPtrHead != tail) {
            Node *nextValue = tail->next;
            Node *dataValue = new Node(evenPtrHead->data);
            tail->next = dataValue;
            dataValue->next = nextValue;

            evenPtrHead = evenPtrHead->next;
        }
        if (prevEven) {
            prevEven->next = tail;
            while (tail->next) {
                tail = tail->next;
            }
            tail->next = temp;
        } else {
            head = tail;
            while (tail->next) {
                tail = tail->next;
            }
            tail->next = temp;
        }
    }
    while (head){
        cout<<head->data<<" ";
        head = head->next;
    }
}