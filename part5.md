 

Ngăn xếp và hàng đợi (Stack and Queue)
==========================

Tổng quan
---------

Ngăn xếp và hàng đợi (Stack and Queue) là 2 loại cấu trúc dữ liệu.

Ngăn xếp là kiểu danh sách được trang bị 2 phép toán: **thêm 1 phần tử vào cuối danh sách** và **Bỏ 1 phần tử ở cuối danh sách**.

Hàng đợi là kiểu danh sách được trang bị 2 phép toán: **thêm một phần tử vào cuối danh sách** và **bỏ 1 phần tử ở đầu danh sách**.


Ngăn xếp (Stack)
---------

### Khái niệm
***
Ngăn xếp giống như 1 chồng sách đặt lên bàn. Quyển sách được đưa vào trước thì sẽ ở dưới, đưa vào sau thì sẽ ở phía trên chồng.

Quyển đưa vào sau cùng thì sẽ ở đỉnh của chồng (Top). Do là chồng sách, khi lấy sách ra, ta luôn phải lấy sách ở đỉnh chồng trước.

Do đó, quyển nào **đưa vào sau** sẽ được **lấy ra trước**. Vào sau ra trước, đây là kiểu **LIFO** (Last In First Out).

Khi mô tả Stack: 
- Việc bổ sung 1 phần tử vào Stack tương đương với việc thêm 1 phần tử vào cuối mảng. Thao tác này gọi là **push**.
- Loại bỏ 1 phần tử của Stack tương đương với loại bỏ phần tử ở cuối mảng. Thao tác này gọi là **pop**
- Stack bị tràn khi bổ sung vào mảng đã đầy.
- Stack rỗng (**empty**) khi số phần tử là 0.
- Nguyên tắc là **LIFO**.
- Phần tử cuối là **Top**.

### Stack với `C++` 
***
- Miễn là tuân theo nguyên tắc trên, ta sẽ có Stack. Như vậy, ta hoàn toàn có thể tự tạo ra kiểu Stack trong `C++` với những công cụ đã biết (`Array` hoặc `Vector` hoặc Danh sách liên kết) và các hàm ta tự viết. Hoặc chúng ta có thể dùng sẵn thư viện `stack` của `C++`:
```cpp
#include <stack>
```

- Tạo 1 Stack mới chứa các giá trị cùng kiểu (với ví dụ dưới là kiểu `int`).

```cpp
stack<int> stack;
```

- **push**, **pop** và lấy giá trị **top**: 

```cpp
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

```

- Một vài hàm khác:
    
    `empty()` để kiểm tra stack có rỗng hay không.
    
    `swap()`  để đổi giá trị 2 stack cho nhau.

```cpp
  
std::stack<int> stack2;
stack2.push(100);
stack2.push(200); // stack2 = {200, 100}

stack2.swap(stack); // stack2 = {20, 10}, stack = {200, 100}
```
### In ra các phần tử

- Do đặc trưng của stack, nếu muốn in ra tuần tự các phần tử trong stack thì không duyệt vòng `for` thông thường được. Thay vào đó phải tự làm 1 hàm để **pop** từng phần tử stack, rồi in ra:

```cpp
void print(std::stack<int> stack) {
    std::stack<int> temp = stack;

    while(!temp.empty()) {
        cout<<temp.top()<<endl;
        temp.pop();
    }
}
```

Hàng đợi (Queue)
--------

### Khái niệm
Hàng đợi giống như một đoàn người xếp hàng đợi mua đồ: ai đến trước thì mua trước và ra trước, ai đến sau thì ra sau. 

Khi thêm 1 người vào hàng, ta sẽ thêm ở cuối hàng. Khi loại bỏ 1 người, ta sẽ loại người ở đầu hàng.

Như vậy hàng đợi là kiểu danh sách với 2 phép toán: **thêm phần tử ở cuối hàng** và **bỏ phần tử ở đầu hàng**.

Một vài khái niệm:
- Phần tử cuối hàng được gọi là **rear** hoặc **back**.
- Phần tử đầu hàng được gọi là **front**.
- Việc thêm phần tử được gọi là **push**.
- Việc xóa phần tử được gọi là **pop**

### Hàng đợi với C++

Thêm thư viện:
```cpp
#include <queue>
```

Khởi tạo 1 hàng đợi rỗng:

```cpp
// khởi tạo 1 queue
std::queue<int> q;
cout<<"size: "<<q.size()<<endl; //0
```

`push` và `pop` cùng với `front` và `back`:

```cpp
 // thêm phần tử vào back
q.push(10);
q.push(20);
q.push(30); // q = {10, 20, 30}

cout<<"front: "<<q.front()<<endl; //10
cout<<"back: "<<q.back()<<endl; //30

// xóa phần tử ở front:
q.pop();

cout<<"new front: "<<q.front()<<endl; //20;
```

C++ queue cũng có hàm `empty()` và `swap()` với chức năng giống với bên stack: 
    
- `empty()` để kiểm tra queue có rỗng hay không.
    
- `swap()`  để đổi giá trị 2 queue cho nhau.

### In ra các phần tử

- Do đặc trưng của queue, nếu muốn in ra tuần tự các phần tử trong queue thì không duyệt vòng `for` thông thường được. Thay vào đó phải tự làm 1 hàm để **pop** từng phần tử queue, rồi in ra:

```cpp
void print(std::queue<int> queue) {

    std::queue<int> temp = queue;
    while(!temp.empty()) {
        cout<<temp.front()<<endl;
        temp.pop();
    }
}

```

## Các nguồn tham khảo:

- Giải Thuật và Lập Trình - Lê Minh Hoàng.

- [Stack in C++ STL](https://www.geeksforgeeks.org/stack-in-cpp-stl/)

- [Queue in C++ STL](https://www.geeksforgeeks.org/queue-cpp-stl/)
* * *

🧑‍💻🧑‍💻🧑‍💻 Happy coding !!! 🧑‍💻🧑‍💻🧑‍💻

| [Bài trước: Con trỏ và mảng 1 chiều (C++ Pointer)](part4.md)  | |
| ------------- | ------------- |


