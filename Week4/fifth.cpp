#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next = nullptr;
    Node* prev = nullptr;

    Node(int data,
        Node* prev = nullptr, Node* next = nullptr)
        : data(data), prev(prev), next(next) { }
};

class DoublyLinkedList {
    Node* head;
    Node* tail;
    Node* middle;
    int length = 0;

public:
    DoublyLinkedList() {
        head = tail = middle=nullptr;
    }

    void push_back(int value) {
        if (!tail) {
            head = tail =middle= new Node(value);
            length = 1;
            return;
        }

        Node* newNode = new Node(value, tail);
        tail->next = newNode;
        tail = newNode;
        length++;
        if(length%2!=0&&length!=1) {
            middle=middle->next;
        } 
    }

    void pop_back() {
        if (head == nullptr) {
            return;
        }

        if (head == tail) {
            head = tail = nullptr;
            --length;
            return;
        }

        Node* prev = tail->prev;

        prev->next = nullptr;
        tail = prev;
        
        --length;
        if(length%2==0&&length!=1) {
            middle=middle->prev;
        }
    }

    int getLength() const {
        return length;
    }

    void print() const {
        Node* curr = head;

        while (curr)
        {
            cout << curr->data;
            curr = curr->next;

            if (curr)
                cout << " ";
        }
    }

    void milen() {
        tail->next=head;
        head->prev=tail;
        if(length%2==0) {
            head=middle->next;
        }
        else {
            head=middle;
        }
        head->prev->next=nullptr;
        middle=tail;
        tail=head->prev;
    }
};

int N;
int x;
DoublyLinkedList l;
string command;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    cin >> N;

    for (int i = 0; i < N; ++i)
    {
        cin >> command;

        if (command[0] == 'a')
        {
            cin >> x;
            l.push_back(x);
        }
        else if (command[0] == 'g')
        {
            l.pop_back();
        }
        else
        {
            l.milen();
        }
    }

    cout << l.getLength() << '\n';
    l.print();

    return 0;
}
