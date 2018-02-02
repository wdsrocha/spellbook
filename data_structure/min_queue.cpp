#include <bits/stdc++.h>
using namespace std;
#define ii pair <int, int>
#define fi first
#define se second

struct MinQueue {
    int total, delta;
    deque <ii> mins;
    MinQueue(){
        total = delta = 0;
        mins = deque <ii>();
    }
    void push(int element) {
        total++;
        element -= delta;
        if (mins.empty()) {
            mins.push_back(ii(element, 0));
            return;
        }
        ii& back = *mins.rbegin();
        if (element <= back.fi) {
            back = ii(element, back.se+1);
        } else {
            mins.push_back(ii(element, 0));
        }
    }
    void pop() {
        total--;
        ii& front = *mins.begin();
        if (--front.se == -1) {
            mins.pop_front();
        }
    }
    void add(int value) { delta += value; }
    void clear() { mins.clear(); }
    int size() { return mins.size(); }
    int getMin() { return mins.begin()->fi; }
    void show() {
        for (ii x : mins) {
            printf("(%d, %d) ", x.fi, x.se);
        } cout << endl;
    }
};

int main() {
    MinQueue min_queue;
    int n, k;
    string cmd;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> cmd;
        if (cmd == "pop") {
            min_queue.pop();
        } else if (cmd == "push") {
            cin >> k;
            min_queue.push(k);
        } else if (cmd == "getmin") {
            cout << min_queue.getMin() << endl;
        } else if (cmd == "add") {
            cin >> k;
            min_queue.add(k);
        }
        min_queue.show();
    }

    return 0;
}
