# JS Promise (Tiếp)

## Promise trong các hàm `async`

`Promise` được dùng khi động tới các hàm `async` hay lập trình hướng sự kiện.

Các hàm `async` có sẵn trong JS hay trong các thư viện thường sẽ trả về một `Promise Object`.

Khi gọi một hàm như thế trong các thư viện, ta sẽ gọi tiếp `.then()`. Tham số trong `.then` sẽ được dùng để hứng giá trị trả về từ tiến trình trước đó.

Ví dụ 1 hàm gọi của `Axios`:

```js
axios
  .get("http://example.com/api/info")
  .then((response) => console.log(response.status))
  .catch((error) => console.log(error.message));
```

Hàm `axios.get(url)` sẽ trả về một `Promise` sau khi gọi `GET` tới server.

`Promise` đó xử lý việc gọi API sau đó ném ra một `response` làm tham số cho thằng `resolve` của nó.

Biến `response` trong thằng `then` kia dùng để hứng giá trị `response` có được sau khi gọi API.

## Function trả về `Promise`

Mình sẽ thử tự tạo một function nhận vào một hoặc một vài tham số và trả về 1 `Promise`.

Hàm cần tạo là hàm "đợi n giây sau đó tính và trả về tổng 2 số".

Mình sẽ sử dụng `setTimeout()`, do `setTimeout` của JS là hàm `async` nên hàm mình viết cũng sẽ trở thành hàm `async`.

```js
// wait in `time` seconds then log the sum of `a` and `b`
const waitThenCalculateSum = (time, a, b) => {
  return new Promise((resolve, reject) => {
    console.log("Waiting for " + time + " seconds...");

    setTimeout(() => {
      const sum = a + b;
      resolve("Sum is: " + sum);
    }, time * 1000);
  });
};
```

Hàm trên là `async`, trả về 1 `Promise`.

Khi gọi, nó sẽ đợi một khoảng thời gian rồi tính tổng 2 số, trả về tổng:

```js
// call the function.
// đợi 4 giây rồi trả về tổng của 10 và 20
waitThenCalculateSum(4, 10, 20)
  .then((sum) => {
    // biến `sum` để hứng giá trị `sum` từ tiến trình trước
    console.log(sum); // in ra tổng đã tính.
  })
  .catch((error) => console.log(error.message)); // catch any error if it has.
```

Màn hình log ra thông báo `Waiting for 4 seconds...` trước, rồi đợi 4s, sau đó in ra `Sum is: 30`.

🧑‍💻🧑‍💻🧑‍💻 Happy coding !!! 🧑‍💻🧑‍💻🧑‍💻

| [Trước: JS Promise](part4.md) |     |
| ----------------------------- | --- |
