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

int main() {

    std::stack<int> stack;
    stack.push(10);
    stack.push(20);
    stack.push(30);

    print(stack);

    // cout<<stack.size()<<endl;

}


// callbacksd