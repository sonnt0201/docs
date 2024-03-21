Tìm dãy con có tổng lớn nhất
============================

Đề bài
--------------
Cho một dãy số nguyên `a = [ a0, a1, a2, ..., an]`. Một dãy con liên tiếp của a là dãy `sub_a = [ ai, ... , aj]` với `i` và `j` nằm trong khoảng từ 0 đến n.
Tìm dãy con liên tiếp có tổng các phần tử trong dãy là lớn nhất.

Khái niệm
----------------
### **Dãy con liên tiếp**: 
Là dãy mà các phần tử **thuộc dãy mẹ** và ở **liên tiếp nhau**

VD: (đề bài):

| i | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 |
| - | - | - | - | - | - | - | - | - | - | 
| a[] | 3 | -1 | -3 | 5 | 2 | 5 | 0 | -1 | 5 | 4 |

thì `[3, -1, -3]` là 1 dãy con liên tiếp, `[-3, 5, 2, 5]` là 1 dãy con liên tiếp, vân vân.

### **Dãy con liên tiếp kết thúc bằng a[i]**: 

Cũng là dãy con liên tiếp của mẹ thôi, nhưng yêu cầu dãy này phải có phần tử kết thúc là `a[i]`.

VD: lấy `i = 2` đi, tức là `a[i] = -3`, thì dãy con liên tiếp kết thúc bằng `a[2]` có thể là `[3, -1, -3]` hoặc `[-1, -3]` hoặc chỉ có `[-3]`.

### Tổng của 1 dãy con liên tiếp kết thúc bằng `a[i]`

Thì đúng như tên gọi của nó, cộng các phần tử dãy con đấy thì được tổng thôi.


Vẫn lẫy `i = 2` ( `a[i] = -3` ). Nếu dãy con là `[3, -1, -3]` thì tổng là `-1`. Với `[-1, -3]` thì tổng là `-4`, ...

Cách tư duy
-----------

Đề bài bắt "Tìm dãy con liên tiếp có tổng các phần tử trong dãy là lớn nhất". Vậy ta sẽ quy về:
- Tìm **Từng dãy con liên tiếp kết thúc bằng `a[i]`**.
- Trong những dãy con liên tiếp kết thúc bằng `a[i]`, chọn ra dãy con có **tổng các phần tử** là **lớn nhất**.
- Gọi tổng đó là `f[i]`
``` 
f[i] là tổng lớn nhất của dãy con liên tiếp có kết thúc là a[i]
``` 
- Trong các `f[i]` (từ `f[0]` đến `f[n]`) cái `f` to nhất là kết quả cần tìm.

### Ví dụ đề bài:

Lấy `i = 2` <=> `a[i] = -3`:

- Dãy con liên tiếp kết thúc bằng `a[2]` có thể là `[ 3, -1, -3 ]` hoặc `[ -1, -3 ]` hoặc chỉ có `[ -3 ]`.

- Tổng của các dãy con trên lần lượt là `-1`, `-4` và `-3`.

- Trong các tổng đó, chỉ có `-1` là lớn nhất => Chọn dãy `[ 3, -1, -3 ]` và `f[2] = -1`.

Làm thế nào để tìm được `f`
------------

Cứ giả sử như tôi tìm được `f[i - 1]` rồi đi, giờ nếu tôi tìm được cách tính `f[i]` từ `f[i - 1]` nữa là được. Như vậy, ban đầu tôi chỉ cần tính mỗi `f[0]` bằng tay, rồi làm 1 vòng `for` chạy từ 1 -> n để tính những `f` còn lại.


| i | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 |
| - | - | - | - | - | - | - | - | - | - | 
| a[] | 3 | -1 | -3 | 5 | 2 | 5 | 0 | -1 | 5 | 4 |
| f[] | 3 | ? | ? | ? | ? | ? | ? | ? | ? |

`f[0]` chắc chắn là `3` rồi, khỏi bàn. Tự tính chay `f[1]` sẽ ra kết quả là `2` và **Dãy con có tổng lớn nhất kết thúc tại `a[1]`** sẽ là `b = [3, -1]` 

**Biết `f[1]`, tức `f[i - 1]`  rồi giờ mình sẽ tìm `f[2]` ứng với `i`**

Xét `a[2] = -3`. Sẽ có 2 TH với **dãy con có tổng lớn nhất kết thúc bằng `a[2]`** này:
 - Hoặc là mình sẽ nhét nối tiếp thằng `a[2]` vào chuỗi `b = [3, -1]` ở trên. Bởi thằng `b` nó vốn là **dãy con tổng lớn nhất kết thúc tại `a[1]`** rồi.
 
 - Hoặc là mình sẽ cho thằng `a[2]` đứng riêng 1 dãy.

 Do `b = [3, -1]` vốn dĩ là dãy con ngon nhất khi xét tới `i - 1` rồi nên là chỉ có 1 trong hai cách ghép trên thôi. Hoặc là ông đứng vào **cái cũ ngon nhất**, hoặc ông tự đứng 1 mình.

 - => Chọn 1 trong 2 cách trên mà ra được con tổng ngon hơn.

 ```cpp
 f[2] = max(f[1] + a[2], a[2]);
 ```

 Tổng quát:

 ```cpp
 f[i] = max(f[i - 1] + a[i], a[i]);
 ```

Sau đó, Duyệt 1 vòng `for`, tính hết từ `f[0]` đến `f[n]`, trong những con `f` đó, chọn ra con to nhất, đấy chính là đáp số bài toán.

Duyệt thử vài lượt
--
- Với `i = 2`, hoặc là ta ghép vào con `b` cũ được `[3, -1, -3]`, hoặc tách hẳn ra thành dãy mới `[ -3 ]`, lựa chọn số 1 cho tổng `-1` ngon hơn => `f[2] = f[1] + (-3) = -1 `, dãy con `b` ngon nhất lúc này là `[3, -1, -3]`.

- Với `i = 3` và `a[i] = 5`, hoặc là ta ghép vào con `b` cũ được `[3, -1, -3, 5]`, hoặc tách hẳn ra thành dãy mới `[ 5 ]`, lựa chọn số 2 cho tổng `5` ngon hơn => `f[3] = 5`, dãy con `b` ngon nhất lúc này là `[5]`.

- Với `i = 4` và `a[i] = 2`, hoặc là ta ghép vào con `b` cũ được `[5, 2]`, hoặc tách hẳn ra thành dãy mới `[ 2 ]`, lựa chọn số 1 cho tổng `7` ngon hơn => `f[4] = f[3] + 2 = 7`, dãy con `b` ngon nhất lúc này là `[5, 2]`.
- Tiếp tục với những `i` sau.

| i | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 |
| - | - | - | - | - | - | - | - | - | - | - |
| a[] | 3 | -1 | -3 | 5 | 2 | 5 | 0 | -1 | 5 | 4 |
| f[] | 3 | 2 | -1 | 5 | 7 | 12 | 12 | 11 | 16 | 20 |

Phải tìm `max` trong cái `f` nhé chứ không phải là lấy luôn `f` cuối cùng đâu. Ở đây TH đề bài nó đặc biệt là `max(f)` cũng là `f` cuối thôi

```cpp
int max_f = -1000000000;

for (int i = 0; i < n; i ++) {
    max_f = max(max_f, f[i]);

}

std::cout<<max_f; // kết quả cuối
```

Tổng kết lại
--------

```cpp
#include <iostream>
#include <math.h>

using namespace std;

int main() {
    int n, a[100000], f[100000], max_f = -10000000; // n la so phan tu

    cin>>n;
    // nhap du lieu vao
    for (int i = 0; i < n; i ++)
        cin>> a[i];

    // tinh f
    f[0] = a[0];
    for (int i = 1; i < n; i++)  
        f[i] = max(f[i - 1] + a[i], a[i]);

    // tim f max
    for (int i = 0; i < n; i++)  
        max_f = max(max_f, f[i]);

    cout<<max_f;
}
```