# Callback Hell

## `Async func` với `callback` (tiếp)

Do `async func` sẽ được ném sang luồng mới khi gọi và không biết được khi nào mới chạy xong. Thế nên muốn "đăng kí" trước một tác vụ mà sẽ được gọi ra sau khi `async func` chạy xong, hay nói cách khác tôi muốn chạy tuần tự: `async func` trước rồi sau đó là hàm của tôi (như kiểu code đơn luồng thông thường), thì khi đó tôi phải truyền hàm kia vào `callback`.

```js
// gọi 1 hàm async
asyncExample(
  param1,
  param2,
  callback1(cbParam) // callback's param
);
```

- `asyncExample` là 1 hàm async

- `asyncExample` sẽ được ném sang luồng mới khi gọi, sau khi nó chạy xong thì `callback1` sẽ được gọi ra.

## Callback Hell

- Khi code JS, hàm async được dùng rất rất nhiều, đúng theo kiểu "mở mắt ra là thấy `async func`".

- Vậy nên sẽ không lạ gì nếu như `callback1` ở phía trên cũng là 1 `async func`.

- Vậy nếu `callback1` cũng `async`, và tôi muốn làm tiếp một vài tác vụ khác sau khi `callback1` chạy xong thì tôi lại truyền tiếp 1 hàm `callback2` vào `callback1`.

- Và cứ như thế để cái luồng kia chạy tuần tự các hàm : `asyncExample` -> `callback1` -> `callback2`.

Và trông nó sẽ như sau:

```js
// gọi hàm
asyncExample(param1, param2, () => {
    oneMoreAsync(param1, () => {
        oneMoreAsync(param1, () => {
            oneMoreAsync(param1, () => {
                // ...
            }
        })
    })
})

```

Lấy luôn ví dụ với `setTimeout` của bài trước, nếu tôi có rất nhiều tác vụ cần đợi nhau để làm thì trông nó như này.

```js
setTimeout(() => {
  console.log("A waited in 3 sec");

  setTimeout(() => {
    console.log("B waited in 4 sec");
    setTimeout(() => {
      console.log("C waited in 5 sec");
      setTimeout(() => {
        console.log("D waited in 6 sec");
        // add more and more time out
      }, 6000);
    }, 5000);
  }, 4000);
}, 3000);
```

Code sẽ lồng nhau rất sâu. Về mặt logic thì chả sao nhưng mà trình bày thì trông rất tởm. (Hell là địa ngục).

![callback hell](https://images.viblo.asia/2b67c194-4ef8-4879-a44b-410c1b4bddee.png)

Nên không thể cứ giữ cái cú pháp dùng `callback` như thế với mọi hàm async, JS phải có cách khác thay thế nếu như có nhiều `async func` được gọi ra nhiều lần trong 1 luồng.

Đây là lý do vì sao cần `Promise` và `async-await`, viết trong bài sau.


## Các nguồn tham khảo:

[Callback hell trong JS](https://viblo.asia/p/callback-hell-trong-javascript-la-gi-va-cach-phong-trach-NbmvbaYKkYO)


---

🧑‍💻🧑‍💻🧑‍💻 Happy coding !!! 🧑‍💻🧑‍💻🧑‍💻

| [Trước: JS Asynchronous](part2.md) |  [Tiếp: JS Promise](part4.md)   |
| ----------------------- | --- |