#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <list>
using namespace std;

class MyQueue {
private:
    list<long> data;

public:
    void push(long el) {
        data.push_back(el);
    }

    long pop() {
        long popped = data.front();
        data.pop_front();
        return popped;
    }

    long peek() {
        return data.front();
    }

    bool isEmpty() const {
        return data.empty();
    }
};

class ModifiedStack {
private:
    list<long> data;

public:
    void push(long el) {
        data.push_back(el);
    }

    long pop() {
        long popped = data.back();
        data.pop_back();
        return popped;
    }

    long popFron() {
        long popped = data.front();
        data.pop_front();
        return popped;
    }

    long peek() {
        return data.back();
    }

    bool isEmpty() const {
        return data.empty();
    }
};

ModifiedStack posStack;
MyQueue warriors;
bool any = false;

int N;
long curr;

int main() {

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> curr;
        warriors.push(curr);
    }

    while (!warriors.isEmpty())
    {
        long curr = warriors.peek();

        if (curr < 0) {
            if (posStack.isEmpty()) {
                cout << warriors.pop() << ' ';
                if(!any) any = true;
            }
            else
            {
                long enemy = posStack.peek();

                if (enemy > curr * (-1))
                    warriors.pop();
                else if (enemy < curr * (-1))
                    posStack.pop();
                else {
                    warriors.pop();
                    posStack.pop();
                }
            }
        }
        else if (curr > 0) {
            posStack.push(curr);
            warriors.pop();
        }
    }

    if (posStack.peek())
    {
        any = true;
        while (posStack.peek()) {
            cout << posStack.popFron() << ' ';
        }
    }

    if (!any)
        cout << '\n';

    return 0;
}