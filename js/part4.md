# JS Promise

## Tổng quan

- `Promise` được dùng để tránh **callback hell**.

- Nó có tác dụng giống việc sử dụng **callback**: đấy là giúp đảm bảo một hàm B sẽ được gọi ra sau khi hàm A thực hiện xong. Tuy nhiên, nó cú pháp của nó không dùng **callback** lồng nhau mà gọi tuần tự sử dụng method `then`.

- Muốn dùng `Promise`, ta sẽ tạo một `Promise Object`(giống giống kiểu hướng đối tượng ấy).

## Từng bước để tạo 1 `Promise Object`

### Một hàm với 2 tham số `resolve` và `reject`

Ta cần chuẩn bị 1 hàm để đưa vào `Promise Object`. Để viết 1 hàm mà về sau có thể đưa vào `Promise` thì hàm đó phải có 2 tham số là `resolve` và `reject`.

Giả sử hàm ta muốn viết tên là `foo()`

```js
const foo = (resolve, reject) => {
  // do something
};
```

Hai tham số này đều là `callback`, hay nói cách khác, chúng cũng đều là các hàm.

Ta chưa cần định nghĩa ngay 2 hàm `resolve` và `reject` này làm gì, cứ đưa tên 2 chúng nó vào hàm `foo` và trong quá trình code thân hàm `foo` chúng ta có thể thoải mái *gọi* nó:

Trong thân hàm `foo`, hãy sử dụng hàm `reject` và `resolve`:

- Trong thân hàm `foo`, ở cái đoạn tính toán logic các kiểu đã xong, đã có kết quả hợp lệ mà mình mong muốn rồi thì gọi hàm `resolve` ra, đồng thời truyền kết quả đã tính xong kia vào tham số của hàm `resolve`.

```js
// call resolve in `foo` function body
resolve(resultWeWant);
```

- Trong thân hàm `foo`, đoạn nào mình để bắt những trường hợp kết quả không ưng ý, không hợp lệ thì mình sẽ gọi hàm `reject` ở đó, đồng thời truyền cái kết quả mình không được ưng ý kia vào tham số của `reject`

```js
// call reject in `foo` function body
resolve(resultWeWant);
```

### Ví dụ về hàm `foo`

Giả sử mình muốn làm 1 hàm check xem tổng 2 số có lớn hơn 10 hay không, tổng cần check là tổng của 2 biến thuộc scope ngoài function `foo`:

Mình muốn tổng lớn hơn 10 nên:

- Mình sẽ gọi `resolve` khi tổng lớn hơn 10.

- Mình sẽ gọi `reject` trong TH còn lại.

```js
const a = 4,
  b = 5;

const sumIsMoreThanTen = (resolve, reject) => {
  const sum = a + b;

  // TH tốt, thỏa mãn:
  if (sum > 10) resolve(sum);

  // TH xấu, không thỏa mãn
  if (sum <= 10) reject(sum);
};
```

Dĩ nhiên không nhất thiết là tham số của cả `resolve` và `reject` phải giống nhau. Mình muốn truyền vào cái gì cũng được, tùy vào mục đích mình code.

Như vậy mình đã tạo xong một hàm để truyền vào `Promise`, hàm này có 2 callback là `resolve` và `reject`. `resolve` được gọi ra khi kết quả tính toán thỏa mãn và `reject` được gọi ra khi mình muốn bắt lỗi, xử lý những TH không mong muốn

### Tạo `Object Promise` đầu tiên

Trong JS có một class (class là để nói cho dễ hiểu, chứ thực ra nó là constructor function) là `Promise()` với tham số truyền vào là hàm `foo` ta đã viết phía trên.

Khởi tạo với `Promise()` ta sẽ được một object (đối tượng) mới thuộc kiểu `Promise`:

```js
const firstPromise = new Promise(foo);
```

Hay với ví dụ hàm `sumIsMoreThanTen` đã viết ở trên:

```js
const firstPromise = new Promise(sumIsMoreThanTen);
```

`firstPromise` là 1 object có 2 phương thức `.then()` và `.catch()`. Nếu gọi hai thằng này ra thì code trông như thế này:

```js
firstPromise
    .then(callback1)
    .catch(callback2)
;
```

### Viết `then`và `catch`

`callback1` và `callback2` làm cái quái gì.

Hãy nhớ lại hàm `resolve` và `reject` ở trên, ta mới chỉ nếu tên nó và gọi nó trong đoạn code của `sumIsMoreThanTen`, chứ chưa hề định nghĩa xem nó sẽ làm gì. Ta vẫn chưa viết code cho thân hàm `resolve()` và `reject()`.

`then` và `catch` chính là để ta viết code cho hàm `resolve` và `reject` đó.

`then` và `catch` để ta quyết định xem chương trình sẽ làm gì khi gọi `resolve` hay `reject`

```js
firstPromise
    .then(resolve)
    .catch(reject)
```

Ta viết trực tiếp phần code cho `resolve` và `reject` ngay trong `then` và `catch`, như thế này:

```js
firstPromise
    .then((sum) => {
        // code when resolve
        console.log("Ok, this sum is bigger than 10. Sum is " + sum);
    })
    .catch((sum) => {
        console.log("Nah man!, this sum cannot even reach 10. Sum is " + sum)
    })
```

Cái hàm trong then kia có thể `return` hoặc `throw`.

- Nếu `return`, mình có thể tiếp tục `then` ở phía dưới, với tham số là giá trị được `return` ở phía trên.

- Nếu `throw` một giá trị ở `then`, thằng `catch` sẽ là thằng hứng giá trị đó.

```js
firstPromise
    .then((sum) => {
        // code when resolve
        console.log("Ok, this sum is bigger than 10. Sum is " + sum);

        // lấy bình phương của sum
        const result = sum * sum;

        // return để truyền result cho thằng then tiếp theo
        return result;
    })
    .catch((sum) => {
        console.log("Nah man!, this sum cannot even reach 10. Sum is " + sum)
    })
    .then(result => {
        console.log("The square of this sum is " + result);

        // Thằng then này dĩ nhiên có thể return hoặc throw như thằng trước
        // Nhưng lần này mình thử throw xem sao

        message = "Sorry, this ended !";
        throw message;
    })
    .catch(message => console.log(message));

```

Mình có thể `then` nhiều lần, `catch` một hay nhiều lần, viết thẳng hàng như trên. Cơ chế giống `callback` như cú pháp nhìn tuần tự mà không bị lồng nhau, dùng để thay thế được cho `callback`.

Thông thường khi thực hành, ở những đoạn `throw` người ta sẽ ném ra một `Error object`, và ở phần `catch` người ta sẽ in ra hoặc xử lý `Error object` đấy. Do tất cả các `thow` của mình đều là 1 `Error object` nên mình có thể dùng 1 thằng `catch` duy nhất để `catch` tất cả các TH không hợp lệ.

### Tổng hợp
Tổng hợp lại ta có đoạn code ở dưới.

Thử thay đổi giá trị của `a` và `b` để tổng nó ra các kết quả khác nhau (lớn hoặc nhỏ hơn 10) để xem các hàm thực hiện như nào.

Ngồi tự dò lại luồng của đống `Promise` này.
```js

const a = 10,
  b = 12;

const sumIsMoreThanTen = (resolve, reject) => {
  const sum = a + b;

  // TH tốt, thỏa mãn:
  if (sum > 10) resolve(sum);

  // TH xấu, không thỏa mãn
  if (sum <= 10) reject(
    new Error("Nah man!, this sum cannot even reach 10. Sum is " + sum)
  );
};

const firstPromise = new Promise(sumIsMoreThanTen);

firstPromise
    .then((sum) => {
        // code when resolve
        console.log("Ok, this sum is bigger than 10. Sum is " + sum);

        // lấy bình phương của sum
        const result = sum * sum;

        // return để truyền result cho thằng then tiếp theo
        return result;
    })
   
    .then(result => {
        console.log("The square of this sum is " + result);

        // Thằng then này dĩ nhiên có thể return hoặc throw như thằng trước
        // Nhưng lần này mình thử throw xem sao

        message = "Sorry, this ended !";
        throw new Error(message);
    })
    .catch(error => console.log(error.message)); // Một `catch` cho tất cả các error.
```

## Các nguồn tham khảo:

["Promise" by MDN doc ](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Promise)

["Promise" by W3 Tutorial](https://www.w3schools.com/js/js_promise.asp)

Về tài liệu chuẩn thì có 2 cái là [MDN](https://developer.mozilla.org/en-US/) và [W3School](https://developer.mozilla.org/en-US/). Hai tài liệu này khi viết về web thì đều là kiến thức đúng, là tiêu chuẩn.

- **MDN** cho kiến thức chuẩn tuyệt đối nhất, là đầy đủ, reference cho tất cả các bên khác.

- **W3** viết ngắn gọn và có ví dụ theo kiểu dễ hiểu hơn, hay được dùng làm tutorial.

- Ngoài ra có thể đọc các blog về `Promise`
---

🧑‍💻🧑‍💻🧑‍💻 Happy coding !!! 🧑‍💻🧑‍💻🧑‍💻

| [Trước: JS Callback Hell](part3.md) |     |
| ----------------------- | --- |

