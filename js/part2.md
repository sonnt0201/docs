# JS Asynchronous (Bất đồng bộ)

> "I will finish later !".
> Cứ chạy tiếp đi, tôi sẽ hoàn thành việc này sau.

## Tổng quan

Một hàm bất đồng bộ (`asynchronous function` | `async func`) là hàm mà khi được gọi ra sẽ được ném cho một luồng khác để xử lý.

Trong khi đó, luồng chính vừa gọi hàm sẽ tiếp tục chạy dòng lệnh tiếp theo mà không thèm đợi `async func` kia thực hiện xong.

## Chức năng

Với tính chất trên, có thể thấy rõ chức năng của `async func` là để chương trình có thể chạy được nhiều task cùng một lúc.

Những tác vụ dài, mất tương đối nhiều thời gian, hoặc những tác vụ mà không biết trước khi nào mới xong (như chờ kết nối, gửi 1 request tới server, lưu hoặc đọc dữ liệu từ database hay là bấm giờ đếm giờ), thì sẽ dùng `async func` để vẫn có thể chạy hàm đó mà không bị gián đoạn chương trình chính.

> "Anh cứ chạy câu lệnh tiếp theo đi, tôi sẽ hoàn thành cái này sau."

Hoặc `async func` được dùng trong lập trình hướng sự kiện: `event-driven programming (EDP)`. Thay vì chạy tuần tự các câu lệnh theo 1 luồng định sẵn, tôi sẽ ngồi "trực" cho 1 sự kiện xảy ra: click 1 nút, nhập 1 phím, hay nhận 1 message từ chương trình khác, hay khi 1 file đã được tải xong, v.v..

Tôi sẽ có 1 đống `async func` trực những sự kiện như thế, và khi sự kiện đó xảy ra, tôi sẽ gọi 1 `callback` tương ứng.

## Callback

Việc ném 1 tác vụ dài sang luồng mới, không đợi tác vụ đó hoàn thành mà nhảy luôn sang câu lệnh tiếp theo thì khá là tiện. Tuy nhiên câu hỏi đặt ra là

> Vậy khi nào `async func` kia mới chạy xong. Khi nó chạy xong tôi muốn lấy kết quả của hàm đó, hay muốn thực hiện 1 lệnh tiếp theo`async func` kia thì làm kiểu gì?

`Callback` được dùng để giải quyết vấn đề đó. Thường nó sẽ được đưa vào như là 1 tham số của `async func`, và `callback` được gọi ra sau khi `async func` kia hoàn thành.

Nếu thằng `callback` cũng là 1 `async func` và ta lại muốn gọi một hàm khác sau khi thằng `callback` kia kết thúc, thì ta sẽ lại truyền một `callback` mới vào `callback` => `callback` lồng nhau.

## Một ví dụ điển hình: Hàm `setTimeout`

Hàm `setTimeout` cho phép chương trình đợi trong 1 khoảng thời gian rồi sau đó mới thực hiện các câu lệnh được yêu cầu.

Cú pháp:

```js
setTimeout(callback, time);
```

gồm 2 tham số với tham số thứ nhất là `callback`, tham số thứ 2 `time` là thời gian (tính theo milli giây) mà hàm sẽ đợi.

**Sau khoảng thời gian là `time`, hàm `callback` sẽ được gọi**

VD:

```js
//index.js
setTimeout(() => {
  console.log("I have been waiting for you for 3 seconds");
}, 3000);
```

Chạy dòng lệnh trên, sẽ thấy chương trình ngưng 3 giây rồi mới `log` ra đoạn text.

Thử thêm 1 dòng lệnh tiếp theo sau `setTimeout`

```js
//index.js
setTimeout(() => {
  console.log("I have been waiting for you for 3 seconds");
}, 3000);

console.log("I don't need to wait");
```

Nếu theo đúng tuần tự câu lệnh mà ta code thì nó phải đợi 3 giây để in ra `"I have been waiting for you for 3 seconds"` rồi mới `log` ra `"I don't need to wait"`.

Tuy nhiên dòng `log` thứ 2 lại xuất hiện trước:

```shell
log:
>> I don't need to wait
>> I have been waiting for you for 3 seconds
```

Lý do là vì `setTimeout` là 1 `async func`, khi được gọi ra, nó sẽ được chương trình ném cho một luồng khác để làm

Sau đó chương trình không đợi `setTimeout` chạy xong mà nhảy tới câu lệnh tiếp theo luôn.

Thứ gọi 2 hàm `setTimeout` như thế.

```js
//index.js

// first timeout
setTimeout(() => {
  console.log("I have been waiting for you for 3 seconds");
}, 3000);

// second timeout
setTimeout(() => {
  console.log("And so does my friend");
}, 3000);
```

Cả hai câu lệnh `setTimeout` đều là `async func` nên chương trình sẽ ném cả 2 ra luồng mới (2 luồng mới khác nhau).

Kết quả: sau 3s, 2 đoạn text trên đồng thời được `log` ra màn hình.

Nếu muốn thực sự gọi 2 thằng `setTimeout` kia tuần tự: đợi 3s rồi `log` ra
`"I have been waiting for you for 3 seconds"`, 3s tiếp theo để `log` `"And so does my friend"` (tổng cộng 6s, ta phải lồng `callback` vào nhau).

```js
//index.js

// first timeout
setTimeout(() => {
  console.log("I have been waiting for you for 3 seconds");

    
  setTimeout(() => {
    console.log("And so does my friend");
  }, 3000);

}, 3000);

// second timeout
```

## Các nguồn tham khảo:

[W3 School Doc - JS Asynchronous](https://www.w3schools.com/js/js_asynchronous.asp)

[Event-driven programming](<https://quix.io/blog/what-why-how-of-event-driven-programming#:~:text=Event%2Ddriven%20programming%20(EDP),programs%2C%20sensor%20outputs%2C%20etc.>)

---

🧑‍💻🧑‍💻🧑‍💻 Happy coding !!! 🧑‍💻🧑‍💻🧑‍💻

| [Trước: JS Callback](part1.md) | [Tiếp: Callback Hell](part3.md)    |
| ----------------------- | --- |

```

⠋⠉⠉⠉⠉⠉⠉⠉⠉⢉⣭⣿⣿⣿⣿⣿⣿⣿⣿⣭⣉⠉⡹⠉⠛⠍⠉⠉⢉⠝
⠀⠀⠀⠀⠀⠀⠀⢀⣴⣿⣿⣯⣿⣶⣶⣾⣿⣿⣿⣟⣿⣷⡃⠀⡐⠁⠀⠀⠁⠀
⠀⠀⠀⠀⠀⢀⣴⣿⣿⡿⠻⠟⠛⠋⠉⠛⠿⢿⣿⣿⡿⡋⠤⢾⡀⠤⠒⡆⠀⠀
⠀⠀⠀⠀⢀⣾⣿⠟⡁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⢷⣧⣄⣀⠀⠀⣠⠁⠀⠀
⠀⠀⠀⠀⣼⣿⠏⠀⠐⠀⠀⠀⠀⠀⠀⠀⢀⠔⠀⠀⠈⣿⣿⣿⣿⣯⠀⠀⠀⠀
⠀⠀⠀⢠⣿⡟⠀⣐⣠⣔⡓⠀⠀⠀⢰⣾⢤⣄⣂⢄⠀⣿⣿⣿⣷⢿⡄⠀⠀⠀
⠀⠀⠀⢸⣿⡧⠞⡥⡒⡐⢌⠀⠀⠀⢩⢔⠠⠐⢉⠳⡤⣿⣿⢿⣿⣿⡇⠀⠀⠀
⠀⠀⠀⢸⣿⣿⠸⡄⠰⠇⢰⠀⠀⠀⢨⠈⠛⠀⢸⠀⠁⣿⣿⡂⢻⣷⣧⠀⠀⠀
⠀⠀⠀⣸⣿⢿⣸⢯⠀⠐⠂⠀⠀⠀⠀⠁⢒⡢⣕⡀⠀⣿⣿⠀⣾⣿⣿⠀⠀⠀
⠀⠀⠀⣿⠁⠎⡆⡘⠀⠀⠀⠀⠉⠉⠉⡹⢡⢻⢁⣮⣼⣿⣿⣾⣿⣿⣿⠀⠀⠀
⠀⠀⢸⣿⣄⣲⣃⣡⣤⣤⣤⣀⣀⣐⡂⡇⢠⣼⠸⣿⣾⣿⣿⣿⣿⣿⣿⡆⠀⠀
⠀⠀⣾⣿⣿⡿⣻⣿⣿⠇⠈⠩⡀⠉⡩⠜⠉⢩⢷⣿⣿⣽⣿⣿⣿⣟⣿⣿⡄⠀
⠀⣠⣿⣿⣽⣾⣾⡟⠁⢃⠀⠀⠠⠊⠀⢀⠔⡡⢺⣷⣿⣿⣿⣿⣯⣿⠘⣿⣿⡄
⣴⣿⣟⣿⣿⣿⣿⡪⠪⠻⢒⠁⠀⢀⡴⡁⠡⠀⡜⣿⣿⣿⣻⣿⣿⣿⣆⢻⣿⣿
⣿⣯⣿⣿⣿⣿⣏⡔⠁⡀⢀⠵⡺⢡⠑⢔⢄⠆⠁⣿⣽⣿⣷⣻⣿⣿⣿⣾⣿⣿
```