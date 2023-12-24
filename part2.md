 

Tham trị và tham chiếu
==========================

Tổng quan
---------

Bài này nói về tham trị và tham chiếu trong `C++`

Chi tiết
---------

### Tham trị

Các thao tác gán giá trị mình thường làm là tham trị:

```cpp
int a = 5;
int b = a;
```

Lúc này hiển nhiên `b` cũng bằng `5`.

Hãy thử thay đổi giá trị của `b`: 
```cpp
b = 10;
cout<<"a: "<<a<<endl;
cout<<"b: "<<b<<endl;
```

Kết quả là `a: 5` và `b: 10`. Nếu mình thay đổi giá trị của b thì a không ảnh hưởng gì, vì sau phép gán `b = a` thì 2 biến không liên quan đến nhau nữa.

Phép `b = a` này là gán kiểu tham trị (chỉ lấy giá trị). Biến b chỉ lấy 1 bản sao giá trị của a cho riêng nó tại thời điểm được gán.

### Tham chiếu

#### Ví dụ

Thay vì `int b = a`, ta sẽ làm như sau:
```cpp
int a = 5;
int& b = a;
```

Thêm dấu `&`, khi đó nếu thay đổi giá trị của `b` thì `a` cũng thay đổi theo và ngược lại.

```cpp
b = 100;
cout<<"a: "<<a<<endl;
cout<<"b: "<<b<<endl;
```

Kết quả là `a: 100` và `b: 100`, tương tự nếu gán giá trị mới cho `a` thì b cũng thay đổi theo.

=> Đây là gán kiểu tham chiếu.

#### Giải thích
***
Khi khai báo 1 biến mới `int a = 5`, chương trình cấp phát cho biến đó 1 vùng nhớ và lưu các giá trị của biến vào vùng nhớ đó. Nếu chỉ khai báo biến kiểu tham trị `a = 5, b = a`, bộ nhớ sẽ cho 2 biến vào 2 vùng nhớ khác nhau (dù ***giá trị tại vùng nhớ*** là giống nhau do gán `b = a`).

Khai báo theo kiểu tham chiếu giúp ***2 hay nhiều biến cùng trỏ tới 1 vùng nhớ duy nhất***. Do đó, khi thay đổi 1 giá trị của biến, các biến tham chiếu khác đồng loạt thay đổi theo.

#### Truyền tham số kiểu tham chiếu cho hàm
***
Giả sử mình muốn code 1 hàm để đổi giá trị của 2 biến cho nhau.
```cpp
void doicho(int x, int y)
{
    int temp = x;
    x = y;
    y = temp;
}
```
Sau đó sử dụng nó trong chương trình chính:

```cpp
int main() {
    int a = 10, b = 20;
    doicho(a, b);
    cout<<"a: "<<a<<endl<<"b: "<<b;
}
```

Kết quả vẫn cứ là `a: 10` và `b: 20`, dù rõ ràng mình đã gọi hàm đổi chỗ và truyền `a` và `b` vào rồi.

Lí do là hàm trên chỉ cho truyền các tham số theo kiểu tham trị, khi mình gọi `doicho(a, b)`, hàm tạo 1 bản sao giá trị 2 biến `a` và `b` để truyền vào và xử lý. Còn `a` và `b` cũ vẫn giữ nguyên

**`Thứ được xử lý trong hàm chỉ là bản sao của các biến truyền vào mà thôi !`**
 *** 
Nếu muốn thực sự đổi chỗ `a` và `b` bằng hàm trên, phải nói với hàm rằng tôi muốn truyền kiểu tham chiếu:

```cpp
void doicho(int& x, int& y)
{
    int temp = x;
    x = y;
    y = temp;
}

int main() {
    int a = 10, b = 20;
    doicho(a, b); 
    cout<<"a: "<<a<<endl<<"b: "<<b;
}
```

Kết quả sẽ như ý muốn : `a: 20` `b: 10`.

#### Nhìn lại [Ví dụ về Set và Map](part1.md)
***
 ```cpp
 for (auto &phantu : taphop) { /* Lưu ý đây là lấy kiểu THAM CHIẾU */ 
        cout << phantu << endl;
} 
 ```
Đoạn code sử dụng `auto& phantu : taphop` thay vì chỉ `auto phantu : taphop`. Đây cũng là lấy kiểu tham chiếu, nếu bên trong vòng `for` thay đổi giá trị của `phantu` chẳng hạn

```cpp
for (auto &phantu : taphop) { /* Lưu ý đây là lấy kiểu THAM CHIẾU */ 
        phantu++;
} 
```

Thì phần tử bên trong `taphop` sẽ thực sự tăng lên 1.
***

Nếu dùng tham trị:
```cpp
for (auto phantu : taphop) { /* Lưu ý đây là lấy kiểu THAM CHIẾU */ 
        phantu++;
} 
```

Thì ở mỗi bước của vòng `for` nó chỉ tạo 1 bản sao của phần tử `taphop` rồi gán vào biến mới tinh `phantu` mà thôi.

Chi tiết về con trỏ và bộ nhớ sẽ nói trong phần sau.
  
* * *

### Các nguồn tham khảo:

[Tham trị và tham chiếu](https://howkteam.vn/course/khoa-hoc-lap-trinh-c-can-ban/bien-tham-chieu-trong-creference-variables-2790)  
[W3 School Doc](https://www.w3schools.com/cpp/cpp_references.asp)

* * *

🧑‍💻🧑‍💻🧑‍💻 Happy coding !!! 🧑‍💻🧑‍💻🧑‍💻
