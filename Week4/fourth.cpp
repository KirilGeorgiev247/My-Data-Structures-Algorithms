#include <bits/stdc++.h>
using namespace std;

struct Node {
    pair<int, int> data;
    Node* next;
    Node* prev;

    Node(const pair<int, int>& data,
        Node* prev = nullptr, Node* next = nullptr)
        : data(data), prev(prev), next(next) { }
};

Node* keys[10000] = { nullptr };

class DoublyLinkedList {
    Node* head;
    Node* tail;
    int length = 0;

public:
    DoublyLinkedList() {
        head = tail = nullptr;
    }

    void push_front(const pair<int, int>& value) {
        Node* newNode = new Node(value);
        ++length;
        if (head == nullptr) {
            head = tail = newNode;
            return;
        }

        Node* temp = head;
        newNode->next = temp;
        temp->prev = newNode;
        head = newNode;
    }

    void pop_back() {
        if (head == nullptr) {
            return;
        }

        if (head == tail) {
            head = tail = nullptr;
            delete tail;
            --length;
            return;
        }

        Node* prev = tail->prev;

        prev->next = nullptr;
        delete tail;
        tail = prev;

        --length;
    }

    void pop_front() {
        if (head == nullptr)
            return;

        --length;
        if (head == tail) {
            delete head;
            head = tail = nullptr;
            return;
        }

        Node* next = head->next;
        delete head;
        head = next;
        head->prev = nullptr;
        if (next == tail) {
            tail = head;
        }
    }

    Node* getHead() {
        return head;
    }

    Node* getTail() {
        return tail;
    }

    void remove(Node* toRemove) {
        if (head == toRemove) {
            this->pop_front();
            return;
        }

        --length;

        toRemove->prev->next = toRemove->next;
        if (toRemove == tail) {
            tail = toRemove->prev;
        }
        else {
            toRemove->next->prev = toRemove->prev;
        }
        delete toRemove;
    }

    int getLength() const {
        return length;
    }
};

int getRequest(DoublyLinkedList& list, int key) {
    if (!keys[key - 1])
        return -1;
    int result = -1;

    Node* curr = keys[key - 1];
    result = curr->data.second;
    list.remove(curr);
    list.push_front(pair<int, int>(key, result));
    keys[key - 1] = list.getHead();
    return result;
}

void putRequest(DoublyLinkedList& list, const pair<int, int>& data) {
    if (!keys[data.first - 1]) {
        list.push_front(data);
        keys[data.first - 1] = list.getHead();
    }
    else
    {
        Node* curr = keys[data.first - 1];
        list.remove(curr);
        list.push_front(data);
        keys[data.first - 1] = list.getHead();
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, Q, K;
    DoublyLinkedList l;
    string command;

    cin >> N >> Q >> K;

    for (int i = 0; i < Q; i++)
    {
        cin >> command;

        if (command[0] == 'p')
        {
            int x, y;
            cin >> x >> y;
            putRequest(l, pair<int, int>(x, y));
        }
        else {
            int x;
            cin >> x;
            cout << getRequest(l, x) << endl;
        }

        if ((i + 1) % K == 0 || l.getLength() > N) {
            int key = l.getTail()->data.first;
            l.pop_back();
            keys[key - 1] = nullptr;
        }
    }

    return 0;
}
