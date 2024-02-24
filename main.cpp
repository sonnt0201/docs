#include <iostream>
#include <stack>

using namespace std;
int main() {

    // khởi tạo 1 stack
    stack<int> stack;

    // lấy số phần tử của stack
    cout<<"size: "<<stack.size()<<"\n"; // 0

    // thêm 1 phần tử vào stack, dùng push()
    stack.push(10); // stack = {10}

    // in ra top của stack
    cout<<"top: "<<stack.top()<<"\n"; // top: 10
    int val = 20;

    stack.push(val); // stack = {20, 10}
    cout<<"top: "<<stack.top()<<"\n"; // top: 20

    stack.push(50);
    stack.push(70); // stack = {70, 50, 20, 10}

    // xóa top của stack, dùng hàm pop()
    stack.pop(); // stack = {50, 20, 10}
    stack.pop(); // stack = {20, 10}

    cout<<"top: "<<stack.top()<<"\n";
}


// callback