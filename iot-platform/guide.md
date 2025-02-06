
# Hướng dẫn nhanh cho Dũng

## Công nghệ cần tìm hiểu

Typescript và NextJS.

Ông không cần sâu hay là thực hành được 2 cái này (vì đơn giản là không kịp :v ). Ông chỉ cần hiểu 2 cái này là gì,
tại sao tôi dùng 2 cái này, và khi tôi code ông biết tôi đang code cái gì là được.

Về cơ bản, này là 2 công nghệ hiện đại để làm phần mềm.

## Typescript (TS/ts)

Typescript là ngôn ngữ lập trình.

Tôi dùng nó để viết Backend và giao diện cho bộ lập lịch.

Typescript (TS/ts) vốn được xây dựng dựa trên JavaScript. Cú pháp cũng dựa trên JavaScript nhưng được "nâng cấp hơn".

```ts
console.log("Hello world!"); // "hello world" in typescript (same as in javascript)
```

Bình thường sau khi code bằng ts, trình biên dịch cũng sẽ biên dịch ts thành JavaScript. Sau đó NodeJS hoặc Browser (Google chrome các kiểu) sẽ chạy đống Javascript đó như bình thường.

### Tại sao ts thay vì Javascript (js)

* js không có kiểu dữ liệu cố định, các biến, các tham số của function không cần khai báo kiểu dữ liệu.

```js

const funcExample = (a, b) => {
    // function logic
}

```

`a` và `b` đều không có kiểu dữ liệu. Lúc gọi hàm truyền vào cái gì cũng được (`number`, `string`, `object`, `array`, ...)

* js ít hỗ trợ hướng đối tượng, có mỗi khái niệm `class`, không có các khái niệm khác của hướng đối tượng như kiểu `Interface`, ...

=> **ts chính là js nhưng mà bắt tên các biến và tham số phải có kiểu dữ liệu rõ ràng**.

```ts
 // code sử dụng ts
const funcExample : (a: number, b: number) => number = (a, b) => {

    let msg: string = "Hello world!"

    console.log(msg)

    return a + b
}

```

Chỗ này dùng ts thì nó sẽ chỉ rõ được là funcExample là một hàm có 2 tham số phải là number, đầu ra phải là number nốt.
còn biến thì nó cũng bắt `msg` phải là `string`.

Dùng ts để kiểu dữ liệu của các biến, hàm, object được tường minh, không bị lần lộn và gặp lỗi khi truyền sai
kiểu dữ liệu, dùng được hướng đối tượng, design patterns, v.v..

Phần server cho bộ lập lịch tôi viết bằng ts, được dịch ra js và đặt trong folder build.

### Các phần quan trọng cần tìm hiểu 

Playground để nghịch ts: [playground](https://www.typescriptlang.org/play/)

Ông sẽ tìm hiểu: cách định nghĩa kiểu dữ liệu cho 1 biến/ hàm. Khai báo `class` và khởi tạo đối tượng thuộc `class` đó.
`Type` và `Interface` và tạo đối tượng thuộc Type và Interface đó.

- [Bắt đầu ts cho người đã quen với js](https://www.typescriptlang.org/docs/handbook/typescript-in-5-minutes.html)

- [Cơ bản](https://www.typescriptlang.org/docs/handbook/2/basic-types.html)

- [Kiểu dữ liệu (Type)](https://www.typescriptlang.org/docs/handbook/2/everyday-types.html)

- [Function](https://www.typescriptlang.org/docs/handbook/2/functions.html)

- [Object](https://www.typescriptlang.org/docs/handbook/2/objects.html)

- [Class](https://www.typescriptlang.org/docs/handbook/2/classes.html)

- [Interface và Type](https://www.typescriptlang.org/docs/handbook/2/objects.html).

## NextJS

Còn `Next` là công nghệ chủ yếu để làm giao diện. Tôi dùng cái này để làm phần giao diện.

Nó được xây dụng dựa trên React và ông có thể dùng Typescript để tạo component và code phần logic.

### Tại sao

Nếu ông chỉ dùng React chay để làm như hồi làm BLE với Đức, mỗi khi truy cập sử dụng Google Chrome, thằng Chrome nó sẽ nhận về nguyên một cục giao diện to đùng gồm cả html css và các nhiều js, Chrome mất nhiều thời gian xử lí hơn trước khi ra được giao diện cần hiển thị.

`Next` sẽ giúp ông tính toán trước và xuất ra html, sau đó html đấy mới được gửi tới Chrome => Chrome ít phải xử lý hơn, nhanh hơn.

=> Tóm lại là Next nhanh hơn React thông thường.

Next có `file based routing`, cái này phải call thì tôi sẽ minh họa. Hoặc đọc trước [tại đây](https://www.geeksforgeeks.org/next-js-routing/).

## Tóm lại

Hiểu các khái niệm cơ bản của ts, múa được mấy dòng code như js.
Còn NextJS hiểu nó là gì và tại sao dùng nó, sau đó call tôi sẽ minh họa sau. Vậy là Oke.

***

🧑‍💻🧑‍💻🧑‍💻 Happy coding !!! 🧑‍💻🧑‍💻🧑‍💻


``` brainfuck
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡞⠀⠀⢀⡞⠀⠀⠀⠀⣠⡴⠚⠉⠁⠀⢻⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣠⣴⣶⣶⣿⣿⣿⣶⣶⣤⣤⢤⡤⢤⣤⣀⣼⠁⠀⢀⡜⠀⢀⣠⠖⡋⠁⠀⠀⠀⢀⣤⠟⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣴⣾⣿⣿⡿⢟⣩⣽⣾⣿⣿⣿⣿⣿⣿⣿⣿⣮⣽⣇⡀⣠⣮⠴⣚⠽⠂⠈⠀⣀⣀⠤⠖⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠻⡄⠀⠀⠀⠀⠀⠀⠀⠀⣠⣾⣿⣿⣿⢟⣵⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠁⢈⣏⣠⣴⣶⣶⣶⣛⡉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠈⠂⠀⠀⠀⠀⠀⠀⣼⣿⣿⣿⡿⣧⣿⣿⣿⣿⣻⣭⣷⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣶⣿⣿⣿⣿⣿⣿⣿⣿⣿⣶⣤⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⢀⣼⣿⣿⣿⣿⣱⣿⡟⣯⣾⣿⣿⣿⣿⣿⣿⣿⣿⠵⣻⣿⣿⣿⣿⣿⣿⣿⣟⢿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⢸⠀⠀⢠⣿⣿⣿⣿⣿⣇⣿⣿⣿⣿⢿⡿⠛⠛⠉⠉⠁⠀⠀⠈⠉⠀⠀⠀⠉⢿⣿⣿⣿⣷⣝⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣶⣦⣄⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⢸⠀⠀⣸⣿⣿⣿⣿⣿⣿⠏⠉⠈⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠻⣿⣿⣿⣿⣧⡻⣿⣿⣿⣿⣿⣿⣿⣍⡻⣿⣿⣿⣿⣷⣶⣦⣄⣀⡀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⢸⠀⢠⣟⣿⣿⡿⠻⠇⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠻⣿⣿⣿⣷⣜⣿⣿⣿⣿⣿⣿⣿⣿⣮⡙⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣤
⠀⠀⠀⢸⢠⣿⣿⣷⡟⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣀⣀⣠⣤⣄⣀⣀⣀⡀⠀⠀⠙⢿⣿⣿⣿⣮⣿⣿⣿⣿⣿⣿⣿⣿⣿⣶⡿⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
⠀⠀⠀⠘⣾⣿⣿⣿⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠒⠋⠉⠁⠀⠀⠀⠀⠀⠀⠉⠉⠉⠑⠒⠚⢿⣿⣿⣿⣯⠻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣶⣄⠉⠙⠛⠛⠿⠿⣿⣿⣿⣿
⠀⠀⠀⢸⣿⣿⣿⠇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣻⣿⢿⣿⣧⢿⡿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣄⠀⠀⠀⠀⠀⠈⠙⠿
⠀⠀⠀⢸⣿⣿⡟⠀⠀⠀⠀⠀⢀⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡉⢿⣇⢿⣿⡎⢿⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⡀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⢸⣿⣿⡇⠀⠀⠀⣠⠜⠋⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠒⠒⠀⠀⠀⣤⠴⠋⠀⠀⠹⣼⣿⣿⣞⠛⠛⠿⣟⢿⣿⣿⣿⣿⣿⣿⣿⣿⣦⡀⠀⠀⠀⠀
⠀⠀⠀⣾⣿⣿⡇⠀⠀⡰⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣤⣶⣾⣿⣷⣶⣾⡻⠦⠀⠀⠀⠀⠙⣿⣿⣿⣜⠑⠀⠈⢿⣽⣿⣿⣿⣿⣿⣿⣿⣿⣿⣄⠀⠀⠀
⠀⠀⢠⣿⣿⣿⡇⠀⣸⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣨⣾⡿⠛⠁⠀⠈⠉⠈⠉⠃⠀⠀⠀⠀⠀⠘⣿⣿⣿⡉⢳⠀⠀⣿⣿⣾⣿⣿⣿⣿⣿⣿⣿⣿⣷⣄⠀
⠀⢀⣼⣿⣿⣿⣿⣴⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢹⣿⣿⣧⡀⠀⣰⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷
⠀⣼⢹⣿⣿⣿⣿⣧⠀⠀⠀⠀⠀⠀⠀⣀⣀⣄⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢻⣿⣿⣆⢀⣿⣷⣝⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
⡼⠁⢸⣿⣿⣿⣿⣿⣇⠀⠠⢎⣤⡶⣿⣿⠿⠛⠛⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⣿⣿⣿⡿⣿⣿⣿⣿⣯⡻⢿⣿⣿⣿⣿⣿⣽⣟⣻
⠁⠀⢰⣿⣿⣿⣿⣿⣿⣦⠀⢉⣿⣿⠟⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣄⣠⣽⣿⣿⣷⣝⢿⣿⣿⣿⣿⣦⡙⠻⢿⣿⣿⣿⣿⣿
⠀⠀⣼⣿⡏⣿⣉⣉⣹⣿⣟⠛⡿⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢰⣿⣿⣷⡹⣿⣿⣿⣮⡻⣿⣿⣿⣿⣿⣆⠀⠈⠉⠛⠻⠿
⠀⢸⣿⣿⡇⢿⣿⣿⣿⡿⢿⣦⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⡠⠶⠚⠉⠉⠁⠀⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⣿⣿⣷⣽⣿⣿⣿⣿⣮⣝⢿⣿⣿⣿⣷⣄⠀⠀⠀⠀
⠀⣾⣿⣿⠃⢸⣿⣿⡟⠀⢘⣿⣧⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡴⠛⠁⠀⢀⣀⣤⣴⣶⠿⡋⠀⠀⠀⠀⠀⠀⠀⠀⢠⣿⣾⡻⣿⣿⣿⣞⢿⣿⣿⣿⣿⣷⣝⡻⣿⣿⣿⣦⡀⠀⠀
⢠⣿⣿⡿⠀⠀⣿⣿⣧⠀⠈⢻⣿⣇⠀⠀⠀⠀⠀⠀⠀⢰⡏⠀⣀⣤⣾⠟⠋⢉⡴⣧⠛⠀⠀⠀⠀⠀⠀⠀⠀⢀⠟⣿⣿⣿⣿⡻⣿⣿⣷⣝⢿⣿⣿⣿⣿⣿⣾⣽⡻⢿⣿⣷⣄
⣸⣿⣿⠁⠀⠀⢻⣿⣿⣆⠀⠈⣿⣿⣷⡀⠀⠀⠀⠀⠀⠀⠙⠛⠿⣿⣟⠒⠚⣩⠖⠁⠀⠀⠀⠀⠀⠀⠀⠀⣠⠂⠀⠹⣿⠿⣿⢿⣾⣽⣿⣿⣷⣽⣿⣿⣿⣿⣿⣿⣿⣷⣯⣿⣿
⠹⣿⣿⡀⠀⠀⠈⢿⣿⣿⣦⡀⠘⣿⣿⣷⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠉⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⠞⠁⠀⠀⠀⢉⡾⠁⠀⣸⠉⠉⠙⣿⣷⣶⣿⣝⠿⣿⣿⣿⣿⣿⣿⣿
⠀⣸⣿⣷⡀⠀⠀⠈⣿⣿⣿⣿⣶⢻⣿⣿⣿⡳⣦⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⠞⠁⠀⠀⠀⠀⢀⡞⠁⠀⢀⣿⠶⠶⠤⣿⣿⣿⣿⣿⣿⣷⣯⣝⣻⠿⢿⣿
⡄⠻⣿⣿⣿⣦⣀⠀⢸⣿⣿⣿⣿⣏⣿⣿⣿⣷⡽⣿⣿⣦⣤⣀⡀⠀⠀⠀⠀⠀⠀⠀⠀⣀⡤⠛⠁⠀⠀⠀⠀⠀⢠⠞⠀⠀⠀⣸⠁⢀⡴⠚⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣾
⠳⣀⡞⣿⣿⣿⣿⣷⣄⣿⣿⣿⣿⣿⣜⣿⣿⣿⣿⡹⣿⣿⣿⣿⣿⣷⣶⣖⠶⢤⣤⠶⠚⠉⠀⠀⠀⠀⠀⠀⠀⢀⠎⠀⠀⠀⢰⣧⠔⠋⠀⠀⢸⡽⣽⡿⡿⢿⠿⣿⣿⣿⣿⣿⣿
⠀⡿⠀⠘⡏⠻⢿⣿⣿⣸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⡈⠻⣿⣿⣿⣿⣿⣿⣧⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⠟⠀⠀⠀⠀⡼⠓⠤⣤⣀⣀⠴⠁⠀⠀⠀⠀⠀⠁⠊⢉⠛⠛⠋
⢶⠁⠀⠀⡇⠀⠀⠈⠻⣇⣿⣿⣿⣿⣿⣿⢿⣿⣿⣿⣷⡀⠈⠛⢿⣿⣿⣿⣿⡟⢦⡀⠀⠀⠀⠀⠀⠀⠀⢀⡎⠀⠀⠀⠀⢠⠷⡄⠀⠀⢀⣡⠶⠚⠋⠉⠉⠉⠙⣶⡦⣤⣀⣀⣀
⠈⠀⠀⣰⠇⠀⠀⠀⠀⠈⢿⣿⠹⣿⣿⣿⣮⣻⣿⣿⣿⠻⣄⠀⠀⠙⢿⣿⡿⢇⠀⠙⢦⡀⠀⠀⠀⠀⠀⡞⠀⠀⠀⠀⠀⡼⠀⠹⣄⡴⠋⠀⠀⠀⠀⠀⢀⡴⠋⠁⠀⠀⠀⠈⠿
⠀⢀⡰⠃⡀⣀⡀⠀⢠⠤⢼⣿⠧⠙⣿⣿⣿⣿⣿⣻⣴⠘⠘⠳⡄⠀⠀⢹⠁⢸⠀⠀⠀⢻⡳⠄⠀⢀⡼⠁⠀⠀⠀⠀⢰⢧⠀⣠⠏⠀⠀⠀⠀⠀⢀⣤⠏⠀⠀⠀⢀⡀⣀⢀⠀
```