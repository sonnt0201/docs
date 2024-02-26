#include <iostream>
#include <stack>
#include <queue>
using namespace std;

void print(std::stack<int> stack) {

    std::stack<int> temp = stack;
    while(!temp.empty()) {
        cout<<temp.top()<<endl;
        temp.pop();
    }
}

void print(std::queue<int> queue) {

    std::queue<int> temp = queue;
    while(!temp.empty()) {
        cout<<temp.front()<<endl;
        temp.pop();
    }
}

int main() {

    std::queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);

    print(q);
    // cout<<stack.size()<<endl;

}


// callbacksd