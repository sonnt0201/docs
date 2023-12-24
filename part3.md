 

Con trỏ vỡ lòng (C++ Pointer)
==========================

Tổng quan
---------

- Con trỏ trong C++ rất quan trọng.

- Khi một biến được khai báo: `int a`, chương trình sẽ cấp cho biến `a` một ô nhớ trong bộ nhớ để lưu trữ giá trị của biến đó. Tùy vào kiểu dữ liệu mà biến (cũng như ô nhớ) đó được cấp bao nhiêu bytes (1 byte cho `char`, 4 bytes cho `int`, `float`, 8 bytes cho `double`, v.v.. ).

- Một con trỏ đại diện cho 1 ô nhớ trong bộ nhớ.

- Có thể truy cập, thay đổi giá trị trong 1 ô nhớ thông qua con trỏ.

Chi tiết
---------

### Biến con trỏ, các thao tác cơ bản

#### 1. Khai báo

- Biến con trỏ là thứ để lưu một ô nhớ, là đại diện cho ô nhớ đó.

```cpp
int a;
int *p_a; 
```

- `a` là biến thông thường, `p_a` là biến con trỏ, khi khai báo biến con trỏ thì thêm dấu `*` đằng trước tên biến.



- (Biến con trỏ đặt tên là gì cũng được, giống như biến thông thường. Nhưng các tài liệu người ta hay thêm chữ `p` vào đầu tên biến để ngầm chỉ đấy là biến con trỏ, `p` là viết tắt của `pointer`).

- Cũng có thể khai báo là `int* p_a;`, dấu `*` ở gần `int` hay `p_a` đều được. 


- Khai báo biến con trỏ cũng cần kiểu dữ liệu đi kèm, với `p_a` ở trên là `int*`, tức là **Con trỏ này trỏ tới 1 địa chỉ ô nhớ chứa giá trị integer**.

- `int*` là kiểu con trỏ cho giá trị `int`, `double*` là kiểu con trỏ cho giá trị `double`, `string*` là kiểu con trỏ cho giá trị `string`, v.v..

#### 2. Gán giá trị cho con trỏ

```cpp
p_a = &a;
```
- Lúc này giá trị của `p_a` là địa chỉ ô nhớ của biến a. 

- Thử `cout<<p_a<<endl;` sẽ ra kết quả trông giống kiểu `0x7ffe50758f5c` (giá trị cụ thể sẽ khác nhau do tùy vào bộ nhớ và cách hệ điều hành cấp phát, nhưng dạng giá trị sẽ như trên). Đây chính là địa chỉ ô nhớ của biến `a`, cũng là giá trị biến `p_a`

**Trong quá trình thực hiện các phép toán:** 

- Dấu `&` để lấy địa chỉ ô nhớ của biến, `&a`, `&b` tức là địa chỉ của `a`, địa chỉ của `b`, dùng cho mọi loại biến.

- Dấu `*` để lấy giá trị đang được lưu ở 1 ô nhớ. Nó chỉ được dùng cho các biến con trỏ mà thôi: `*p_a`, `*p_b` tức là lấy giá trị đang được lưu tại ô nhớ (con trỏ) `p_a` và `p_b`.

```cpp
int a = 5, b = 10, *p_a, *p_b; 
p_a = &a;
p_b = &b;
```
Lúc này, `p_a`, `p_b` lần lượt lưu địa chỉ của biến `a` và `b`.

Hãy thử `cout` ra các giá trị:

```cpp
cout<<"Địa chỉ của a là: "<<p_a<<endl; // cũng là &a

cout<<"Địa chỉ của b là: "<<p_b<<endl; // cũng là &b

cout<<"Giá trị được lưu tại ô nhớ p_a là: "<<*p_a<<endl; // in ra 5 - cũng là giá trị của a

cout<<"Giá trị được lưu tại ô nhớ p_a là: "<<*p_b<<endl; // in ra 10 - cũng là giá trị của b
```

#### 3. Thay đổi giá trị của 1 ô nhớ

- Hãy thử gán:
```cpp
*p_a = 100;
cout<<"Giá trị mới tại ô nhớ p_a: "<<*p_a<<endl
    <<"Giá trị mới của biến a: "<<a<<endl;
```

- Lúc này giá trị tại vùng nhớ `p_a` thay đổi thành 100, và dĩ nhiên, do `p_a` cũng là địa chỉ của a, nên giá trị biến a cũng thay đổi theo luôn, cũng thành 100;

#### 4. Con trỏ trỏ đến con trỏ

- Biến con trỏ như `p_a`, `p_b` thì vẫn cứ là một biến. Vì vậy khi khởi tạo biến đó hệ điều hành vẫn cấp phát 1 ô nhớ để lưu giá trị biến đó như thường.

- Vậy **con trỏ trỏ đến con trỏ** cũng chỉ là một ô nhớ để lưu giá trị là dạng con trỏ ( thay vì lưu giá trị dạng `int` hay `double` như các biến con trỏ thường thấy ).

```cpp
int a = 5; //a là số nguyên giá trị 5
int *p_a = &a; // p_a là con trỏ trỏ đến địa chỉ của biến a
int **pp_a = &p_a // pp_a là con trỏ trỏ đến địa chỉ của biến p_a
```

### Hàm với tham số kiểu con trỏ.

- Cũng giống như các hàm bình thường thôi, chỉ khác cái là hàm này nhận các con trỏ là tham số.

```cpp
void doicho(int *p_x, int *p_y) {
    // đổi chỗ hai giá trị lưu trong 2 ô nhớ cho nhau
    int temp = *p_x;
    *p_x = *p_y;
    *p_y = temp;
}

int main() {
    int a = 5, b = 10;
    doicho(&a, &b); // truyền 2 con trỏ kiểu int của a và b vào tham số của hàm.

    cout<<"a: "<<a<<endl
        <<"b: "<<b<<endl;

}
```

Kết quả là `a: 10` và `b: 5`. Ta đạt được một hiệu ứng tương tự như [hàm với tham số kiểu tham chiếu](part2.md) được nêu ra trong phần trước: thay đổi được giá trị 2 biến bên ngoài hàm.

### Con trỏ và mảng 1 chiều

Trong C++ có mối quan hệ chặt chẽ giữa con trỏ và mảng: các phần tử của mảng có thể được xác định nhờ chỉ số hoặc thông qua con trỏ. Em sẽ viết kĩ ở phần sau

* * *
### Các nguồn tham khảo:

- Kỹ Thuật Lập trình C Cơ sở và Nâng cao - Gs.Phạm Văn Ất

- [W3 School Doc](https://www.w3schools.com/cpp/cpp_pointers.asp)

* * *

🧑‍💻🧑‍💻🧑‍💻 Happy coding !!! 🧑‍💻🧑‍💻🧑‍💻
