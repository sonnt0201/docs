# JavaScript Callback

> I will call back later !

## Tổng quan

**Callback** là 1 loại hàm trong JS. Hàm đó được truyền vào với vai trò là tham số trong 1 hàm khác.

Sử dụng **callback** cho phép một hàm gọi ra một hàm khác.

**Callback** cũng là 1 hàm bình thường trong javascript thôi, nhưng cách sử dụng nó, cụ thể là việc biến nó thành tham số của hàm khác, khiến nó trở thành 1 **callback**.

## Chi tiết

Bình thường hàm của mình trông như sau:

```javascript
// index.js
function example(a, b) {
  // your code goes here
}
```

Nếu hàm có 1 callback thì trông hàm sẽ như sau:

```javascript
function example(a, b, callback) {
  // your code goes here
}
```

Với `callback` là 1 hàm, như vậy về khai báo `callback`, cứ coi hàm `callback` như một tham số bình thường và truyền tên hàm đó vào là được.

Hàm bên ngoài (với ví dụ trên là hàm `example`) có thể gọi `callback` bên trong thân hàm.

```javascript
function example(a, b, callback) {
  // your code goes here
  // ...
  // ...

  //run callback function
  callback();
}
```

Nếu `callback` có tham số thì cứ truyền vào giá trị tham số đó lúc gọi. Tóm lại, gọi hàm như bình thường mình hay làm.

```javascript
function example(a, b, callback) {
  // your code goes here
  // ...
  // ...

  // run callback with parameter(s)
  callback(value0, value1);
}
```

## Ví dụ với 1 hàm tính tổng có `callback`

### Tạo một hàm tính tổng đơn giản (không `callback`) trước.

Tôi sẽ tạo 1 hàm tính tổng và `log` ra tổng đó.

```javascript
// index.js
// define function
function printSum(a, b) {
  const s = a + b;
  console.log(s);
}

// call that func
const x = 2,
  y = 3;
printSum(x, y);
```

Chạy file trên, hiển nhiên màn hình `log` in ra tổng

```shell
>> 5
```

### Tạo một hàm tính tổng có `callback`

Tôi muốn sau khi cộng lấy tổng `s` trong hàm `printSum` kia thì tôi sẽ làm một vài tác vụ khác với cái tổng `s` kia nữa, không chỉ dừng lại ở việc `log` ra màn hình. Khi đấy tôi sẽ khai báo 1 `callback` để làm những tác vụ kia.

```js
function printSum(a, b, callback)
```

Gọi `callback` bên trong thân hàm `printSum` với giá trị `s` được truyền vào:

```js
function printSum(a, b, callback) {
  const s = a + b;
  console.log(s);

  // callback
  callback(s);
}
```

Như vậy sau khi tổng `s` được tính và in ra thì `callback` sẽ được gọi để xử lý tiếp cái `s` kia. Việc `callback` làm gì với `s` sẽ **tùy vào cách mình chọn trong lúc gọi hàm `printSum`**

Giả sử mình muốn tính bình phương thằng `s` rồi `log` ra cái bình phương đó sau khi tính tổng `s` xong. Mình sẽ định nghĩa 1 hàm tính bình phương:

```js
function printSquare(x) {
  console.log(x * x);
}
```

Gọi hàm `printSum` với `callback` là `printSquare`

```js
// index.js

function printSquare(x) {
  const square = x + x;
  console.log("Bình phương của tổng là: " + square);
}

function printSum(a, b, callback) {
  const s = a + b;
  console.log(s);

  // callback
  callback(s);
}

// main: call the function
const a = 2,
  b = 3;

printSum(a, b, printSquare);
```

Màn hình `log` trông như sau:

```shell
>> 5
>> Bình phương của tổng là: 10
```

Mình cũng có thể khai báo trực tiếp `callback` trong lúc gọi hàm `printSum`

```js
function printSum(a, b, callback) {
  const s = a + b;
  console.log(s);

  // callback
  callback(s);
}

// main: call the function
const a = 2,
  b = 3;

printSum(a, b, function (x) {
  const square = x * x;
  console.log("Bình phương của tổng là: " + square);
});
```

Cách khai báo trực tiếp này là cách thông dụng khi dùng `callback`.

Dĩ nhiên cũng không nhất thiết phải gọi `callback` ở cuối hàm, tùy vào ý đồ của người code mà gọi `callback` ở đâu trong thân hàm.

## Tại sao phải có `callback`

Xét đoạn code trên, rõ ràng thay vì phải viết hàm lồng hàm cồng kềnh thì hoàn toàn có thể gọi tuần tự từng hàm 1 là được.

```js
//  vẫn cứ khai báo 2 hàm trước
function printSquare(x) {
  const square = x + x;
  console.log("Bình phương của tổng là: " + square);
}

function printSum(a, b) {
  const s = a + b;
  console.log(s);

  // thay vì callback thì cứ trả về tổng
  return s;
}

// main: call the function
// rồi gọi tuần tự
const a = 2,
  b = 3;

const s = printSum(a, b);
printSquare(s)
```

Kết quả in ra y hệt mà không cần `callback`

**Tại sao vẫn dùng `callback`, và dùng nhiều là đằng khác ?**

- `Callback` rất tiện khi viết các hàm thao tác với mảng như là `map`, `filter`, `foreach`, ...

- Việc dùng `callback` rất quan trọng khi code JS và các ngôn ngữ hiện đại, khi mà cần sử dụng hàm bất đồng bộ và lập trình theo kiểu hướng sự kiện.

* * *

🧑‍💻🧑‍💻🧑‍💻 Happy coding !!! 🧑‍💻🧑‍💻🧑‍💻

