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

void generateBinary(int n, string prefix) {
    if (n == 0) {
        cout << prefix << endl;
        return;
    }

    generateBinary(n - 1, prefix + "0"); // Gọi đệ quy
    generateBinary(n - 1, prefix + "1"); // Gọi đệ quy
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