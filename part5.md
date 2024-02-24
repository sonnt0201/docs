 

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
- Miễn là tuân heo nguyên tắc trên, ta sẽ có Stack. Như vậy, ta hoàn toàn có thể tự tạo ra kiểu Stack trong `C++` với những công cụ đã biết (`Array` hoặc `Vector` hoặc Danh sách liên kết) và các hàm ta tự viết. Hoặc chúng ta có thể dùng sẵn thư viện `stack` của `C++`:
```cpp
#include <stack>
```

- Tạo 1 Stack mới chứa các giá trị cùng kiểu(với ví dụ dưới là kiểu `int`).

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
}


// callback
```


### Lưu ý về `vector`

- `vector` vẫn khác với mảng truyền thống. Nếu một hàm nhận một `vector` làm tham số, giá trị tham số (đối số) khi được truyền vào sẽ là truyền kiểu **tham trị**.

- Bản thân tên biến của 1 `vector` ( như ví dụ trên là `vec` ) cũng không phải là con trỏ trỏ đến phần tử đầu tiên của mảng đó. Nó là tên và chỉ là tên mà thôi.

- Do đó nếu muốn trỏ đến các phần tử của 1 `vector` thì người ta dùng phép lấy con trỏ (`&vec[0]`, `&vec[1]`) hoặc cách được khuyến khích hơn là dùng `iterator`.

### Các nguồn tham khảo:

- Kỹ Thuật Lập trình C Cơ sở và Nâng cao - Gs.Phạm Văn Ất

- [W3 School Doc](https://www.w3schools.com/cpp/cpp_pointers.asp)

- [Tổng hợp vector trong C++](https://topdev.vn/blog/vector-trong-c/)
* * *

🧑‍💻🧑‍💻🧑‍💻 Happy coding !!! 🧑‍💻🧑‍💻🧑‍💻


Chi tiết
---------

### Tên mảng là một hằng địa chỉ
***
- Bản thân `a` nếu không đi kèm với bất cứ chỉ số nào, nó luôn là **Con trỏ trỏ đến phần tử đầu tiên của mảng `a`**

-  Khi khai báo 1 mảng `int a[10]`, máy sẽ cung cấp 10 vùng nhớ liên tiếp để lưu trữ giá trị của mảng đó, bắt đầu bằng `&a[0]` hay `a`

```cpp
cout<<(&a[0] == a)<<endl; // true - 1

cout<<(a[0] == *a)<<endl; // cũng là true - 1
```

Các con trỏ kế tiếp `a` (hay `&a[0]`) lần lượt là các phần tử tiếp theo của mảng.

Có thể dịch tới con trỏ kế tiếp (hoặc trước đó) bằng các phép cộng, trừ biến con trỏ cho một số nguyên

```cpp
int a[5] = {7, 5, 4, 8, 9 }; // mảng với 5 phần tử

int *pa = a; //con trỏ trỏ đến phần tử đầu tiên của mảng a;

cout<<"i = 0: "<<*pa<<endl; // 7 - phần tử đầu tiên, cũng là a[0]

pa++; // dịch con trỏ tới vùng nhớ tiếp theo, cũng là vùng nhớ của a[1]

cout<<"i = 1: "<<*pa<<endl; // 5, cũng là a[1]

pa = pa + 2; //dịch 2 vùng nhớ tiếp, cũng là  dịch tới vùng nhớ của a[3]

cout<<"i = 3: "<<*pa<<endl; // 8, cũng là a[3]

```



Như vậy, với mảng thông thường:
- `a` tương đương với `&a[0]`
- `a + i` tương đương với `&a[i]`
- `*(a + i)` tương đương với `a[i]`

### Hàm với tham số của hàm là 1 mảng

- Quay trở lại với ví dụ của phần [**Tham trị và tham chiếu**](part2.md)
```cpp
void doicho(int x, int y)
{
    int temp = x;
    x = y;
    y = temp;
}
```

- Hiển nhiên 2 tham số của hàm trên là truyền kiểu **tham trị**, không gây ảnh hưởng tới các biến bên ngoài. Phải có dấu `&` mới là truyền **tham chiếu**

- Nhưng nếu tham số của 1 hàm là mảng 

```cpp

// hàm đổi chỗ giá trị 2 phần tử đầu tiên của mảng
void doicho(int arr[2]) // arr là array - mảng được truyền vào hàm
{
    int temp = arr[0];
    arr[0] = arr[1];
    arr[1] = temp;
}

int main() {
    int a[2] = {5, 10}; // mảng với 2 giá trị là 5 và 10

    doicho(a);

    cout<<"i = 0: "<<a[0]<<endl;
    cout<<"i = 1: "<<a[1]<<endl;
}
```

- Thật bất ngờ 😎, giá trị 2 phần tử đầu tiên của mảng đã đổi chỗ cho nhau. Cho dù ta không dùng dấu `&` tham trị ở phần khai báo hàm : `void doicho(int a[2])`.

- **Lý do**: `a` chính là con trỏ trỏ đến phần tử đầu tiên của mảng, cũng là con trỏ trỏ tới mảng đó. Truyền `a` vào hàm cũng chính là truyền con trỏ vào hàm, do đó có thể thay đổi được giá trị của `a` bên trong hàm đó.

=> Hiệu ứng đem lại giống như hàm với tham số kiểu tham chiếu

=> Nếu tham số của hàm là 1 mảng, thì khi gọi hàm sẽ luôn truyền mảng theo kiểu **tham chiếu**.

### Mảng động và cấp phát mảng động
***
- Mảng động là một mảng, nhưng chưa được cố định trước số phần tử, khi nào mình muốn thêm phần tử thì mình xin thêm vùng nhớ.

=> Chỉ lấy chính xác lượng vùng nhớ mình cần.

- Việc cấp phát mảng động bằng C++ có thể thực hiện như [**hướng dẫn sau**](https://howkteam.vn/course/khoa-hoc-lap-trinh-c-can-ban/cap-phat-mang-dong-dynamically-allocating-arrays-2743). Tuy nhiên em muốn gợi ý 1 cách tốt hơn để làm mảng động là dùng `vector`

#### Sử dụng `std::vector` 

- Cần thêm thư viện `<vector>`

```cpp
#include <vector>
using namespace std;
int main()
{
    vector<int> vec = {2, 3, 5};
    // Thêm 1 phần tử vào cuối 
    vec.push_back(10); 
    vec.push_back(15); // => {2, 3, 5, 10, 15}

    // xóa 1 phần tử ở cuối
    vec.pop_back(); // => {2, 3, 5, 10}

}
```

### Iterator 
***
- `Iterator` là một đối tượng trỏ tới một phần tử trong `vector`. Thông qua Iterator, ta có thể duyệt lần lượt các phần tử của mảng.

- Có thể hiểu Iterator là **Một loại con trỏ**, trỏ đến các phần tử của mảng đó.

- Với `vector`, có 2 Iterator hay gặp nhất: `vec.begin()` trỏ tới phần tử đầu tiên của mảng và `vec.end()` trỏ tới **vị trí ngay sau phần tử cuối cùng của mảng**.

(Vị trí **ngay sau** phần tử cuối cùng chứ không phải phần tử cuối cùng)

- `vec.begin()` và `&vec[0]` có vẻ rất giống nhau, đều để trỏ đến phần tử đầu tiên của mảng, nhưng thực ra chúng có khác nhau. Một vài trường hợp có thể hai cái giống nhau, ví dụ với vòng `for`:

```cpp
    vector<int> vec = {1, 3, 5, 9, 4};
    int n = 5; // số phần tử mảng
    sort(&vec[0], &vec[0] + n); // sắp xếp
    for (vector<int>::iterator it = vec.begin; i != vec.end(); it++) {
        cout<<*it;
    }
```

Sẽ giống hệt với đoạn code sau:

```cpp
 vector<int> vec = {1, 3, 5, 9, 4};

int n = 5;
     
sort(vec.begin(), vec.end()); // sắp xếp
for (int* p = &vec[0]; p <= &vec[4]; p++) {
        cout<<*p<<endl;
}
```

- Những hầu hết các trường hợp khác, con trỏ thuần và `iterator` là hai thứ khác nhau. Có nhiều hàm chỉ nhận `iterator` (không phải con trỏ) làm tham số :

    - `vec.size()` lấy kích cỡ - số phần tử.

    - `vec.insert(position, value)`: chèn 1 phần tử có giá trị `value` vào vị trí trước vị trí được trỏ bởi `position`. `position` là kiểu `iterator`

    ```cpp
    vec.insert(vec.begin(), 10); // chèn 10 vào đầu vector, những phần tử cũ bị đẩy hết về phía sau 1 đơn vị

    // vector mới: {10, 1, 3, 5, 9, 4}

    vec.insert(vec.begin() + 3, 100); // chèn 100 vào vị trí i = 3, những giá trị đằng sau đều bị đẩy đi 1 đơn vị

    // vector mới: {10, 1, 3, 100, 5, 9, 4}
    ```

    - `vec.erase(position)`: xóa 1 phần tử của `vec` ở vị trí `position`, `position` là `iterator`

    - `vec.erase(start, end)`: xóa 1 khoảng phần tử của `vec` từ `start` tới `end`. ` start` và `end` đều là `iterator`.

    ```cpp
    // vector là: {10, 1, 3, 100, 5, 9, 4}

    vec.erase(vec.begin()) // xóa phần tử đầu tiên

    // vec mới: {1, 3, 100, 5, 9, 4}

    vec.erase(vec.begin() + 1, vec.begin() + 3) //xóa 1 khoảng từ i = 1 tới i = 3

    //vec mới: {1, 9, 4}
    ```

    - Một vài hàm khác xem [**tại đây**](https://topdev.vn/blog/vector-trong-c/).




### Lưu ý về `vector`

- `vector` vẫn khác với mảng truyền thống. Nếu một hàm nhận một `vector` làm tham số, giá trị tham số (đối số) khi được truyền vào sẽ là truyền kiểu **tham trị**.

- Bản thân tên biến của 1 `vector` ( như ví dụ trên là `vec` ) cũng không phải là con trỏ trỏ đến phần tử đầu tiên của mảng đó. Nó là tên và chỉ là tên mà thôi.

- Do đó nếu muốn trỏ đến các phần tử của 1 `vector` thì người ta dùng phép lấy con trỏ (`&vec[0]`, `&vec[1]`) hoặc cách được khuyến khích hơn là dùng `iterator`.

### Các nguồn tham khảo:

- Kỹ Thuật Lập trình C Cơ sở và Nâng cao - Gs.Phạm Văn Ất

- [W3 School Doc](https://www.w3schools.com/cpp/cpp_pointers.asp)

- [Tổng hợp vector trong C++](https://topdev.vn/blog/vector-trong-c/)
* * *

🧑‍💻🧑‍💻🧑‍💻 Happy coding !!! 🧑‍💻🧑‍💻🧑‍💻
