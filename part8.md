Đệ quy với bài toán xuất ra các số nhị phân n chữ số
======================

Đề bài
-----------------
Cho số n (0 <= n <= 20), in ra tất cả các số nhị phân có n chữ số 

VD:

```
Input: n = 3
Output:
000
001
010
011
100
101
110
111
```

Code mẫu 
----

```cpp
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void gen(int n, string prefix) {
    if (n == 0) {
        cout << prefix << endl;
        return;
    }

    gen(n - 1, prefix + "0"); // Gọi đệ quy
    gen(n - 1, prefix + "1"); // Gọi đệ quy
}

int main() {
    int n;
    cin >> n;

    generateBinary(n, "");

    return 0;
}
```

Ý tưởng 
-----
Biến `prefix` dùng để lưu xâu đầu ra. Cứ mỗi 1 lần gọi đệ quy:

```cpp
generateBinary(n - 1, prefix + "0"); // Gọi đệ quy
```

```cpp
generateBinary(n - 1, prefix + "1"); // Gọi đệ quy
```
Biến `prefix` ban đầu là xâu rỗng.

Biến `prefix` được cộng thêm `0` hoặc `1` ra đằng sau, đồng thời `n` được truyền vào sẽ được bớt đi 1.

Có `n` lần tham số `n` bị giảm đi 1, cũng là có `n` lần biến `prefix` được nối đuôi `0` hoặc `1` ra đằng sau.

Đến khi `n` giảm còn `0` thì biến `prefix` đấy cũng đủ số kí tự.

Sơ đồ luồng gọi với n = 3
-------
**Lưu ý `p` viết tắt cho `prefix`**


```mermaid
graph TD

a[gen<3, ''>
  n = 3; p = rỗng] --> a0{gen<2, '0'>
  n = 2; p = 0}

a --> a1{gen<2, '1'>
  n = 2; p = 1}

a0 --> a00{gen<1, '00'>
  n = 1; p = 00}

a0 --> a01{gen<1, '01'>
  n = 1; p = 01}

a1 --> a10{gen<1, '10'>
  n = 1; p = 10}

a1 --> a11{gen<1, '11'>
  n = 1; p = 11}

a00 --> a000{gen<0, '000'>
  n = 0; in ra p}

a00 --> a001{gen<0, '001'>
  n = 0; in ra p}

a01 --> a010{gen<0, '010'>
  n = 0; in ra p}

a01 --> a011{gen<0, '011'>
  n = 0; in ra p}

a10 --> a100{gen<0, '100'>
  n = 0; in ra p}

a10 --> a101{gen<0, '101'>
  n = 0; in ra p}

a11 --> a110{gen<0, '110'>
  n = 0; in ra p}

a11 --> a111{gen<0, '111'>
  n = 0; in ra p}

```

![console](binrary-tree.svg) 

* * *

🧑‍💻🧑‍💻🧑‍💻 Happy coding !!! 🧑‍💻🧑‍💻🧑‍💻

| [Bài trước: Đệ quy vỡ lòng](part6.md)  | |
| ------------- | ------------- |