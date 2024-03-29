Đệ quy vỡ lòng
=========

Tổng quan
-----

Hàm đệ quy là một hàm tự gọi lại chính nó.

Một ví dụ đần độn cho hàm đệ quy 

```cpp
void hello () {
    std::cout<<"hello world in recursion !\n";
    hello();

}
    
```

Đừng gọi hàm này, nó sẽ chạy vô hạn lần hàm `hello()`, vì cứ đến cuối hàm nó lại tự gọi lại chính nó.

Tuy nhiên hàm đệ quy hữu dụng trong trường hợp bài toán giải được bằng quy nạp. Giả sử bài toán bắt tính `f(n)`, dùng được đệ quy nếu:

- Tính trước được kết quả của `f(n)` với `n = 0`, hoặc `n = 1`, hoặc `n` hữu hạn nào đó

- Tính được kết quả của `f(n)` dựa vào `f(n - 1)` ( hoặc `f(n - k)` nếu nói theo kiểu tổng quát).

Khi đó, nếu sử dụng đệ quy thì với `n` nào cũng ta cũng tính được `f(n)`.

Ví dụ với bài tìm giai thừa
-------------------

```
Cho số n, tìm n! (n giai thừa).
```

Hàm `f(n)` sẽ là `n!`:

```cpp
    f(n) = 1 x 2 x 3 x ... x n = f(n - 1) x n
```

Rõ ràng tính được `f(n)` dựa vào `f(n - 1)`, chỉ cần lấy `f(n - 1) x n` là được.

Và ta cũng tự tính được `f(1) = 1! = 1`.

Vậy nên:

- `f(2) = 2 x f(1) = 2`
- `f(3) = 3 x f(2) = 6`
- ...

```cpp
using namespace std;
// n không âm
int f(int n) {

    if (n == 1) return 1; // giai thừa của 1 


    // nếu n lớn hơn 1
    return (f(n - 1) * n); // giai thừa của (n - 1) rồi nhân n.
}
;
int main() {
    int n = 3;
    cout<<f(n)<<endl;

}
```

Khi gọi `f(3)` ở chương trình chính:

- Nó check n khác 1 nên cố gọi `f(2)` để lấy kết quả đó nhân với 3.
- Nhưng khi chạy hàm `f(2)` nó lại cố gọi tiếp `f(1)`.
- Khi gọi `f(1)` thì nó chạy hàm `if` kia rồi, nên nó trả về `f(1) = 1`.
- Nó dùng kết quả đấy tính ngược dần lên trên `f(2)` -> `f(3)`. Cuối cùng có kết quả.


* * *

🧑‍💻🧑‍💻🧑‍💻 Happy coding !!! 🧑‍💻🧑‍💻🧑‍💻

| [Bài trước: Tìm dãy con có tổng lớn nhất](part6.md)  |[Bài tiếp: Đệ quy với bài toán xuất ra các số nhị phân n chữ số](part8.md)  |
| ------------- | ------------- |