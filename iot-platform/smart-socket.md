# Hướng dẫn cho nhóm Smart Socket (2/12 update)
 
## Tổng quan

Bài viết hướng dẫn cách về Thingsboard server của lab và cách đẩy dữ liệu và dạng dữ liệu đẩy lên server.

## Điều kiện tiên quyết

Các nhóm đã biết sử dụng cơ bản Thingsboard và biết đẩy dữ liệu đơn giản từ ESP32 lên Thingsboard.

## Thiết bị và tài khoản

Mỗi nhóm sẽ được tạo 1 Thingsboard device để lưu dữ liệu đẩy lên. Các nhóm đẩy dữ liệu của mình lên device đó qua đường HTTP hoặc MQTT.

Thành viên các nhóm sẽ được cấp tài khoản `Customer User`, có quyền truy cập vào device. Xem và config device.

Các device đã được fix cứng `device profile` và `rule chain`. Format dự liệu gửi lên phải tuân theo format trong tài liệu.

Về sau khi các nhóm đã đẩy được dữ liệu lên ổn định. Sẽ tạo dần các dashboard cho các thiết bị.

## Dạng dữ liệu

### JSON

```ts
{
   "label": string, 
    "timestamp": number, // timestamp in millisec
    "values": number[] // Array of number
}
```

`label` là tên nhãn - loại giá trị (**VD**: `U`, `I`, `P`, ...)

`values` là dãy các giá trị cần gửi lên với `timestamp` là thời gian đọc của giá trị đầu tiên trong dãy.

**VD:** Gửi I

```JSON
{
    "label": "I",
    "timestamp": 1733108907577,
    "values": [10, 8, 6, 2, ...]
}
```

Khi đó `1733108907577` sẽ là thời gian đọc giá trị đầu tiên (`I = 10`). 

Trong device của Thingsboard cũng có 1 `shared attribute` tên là `sampleTime`. `sampleTime` là chu kì lấy mẫu thiết bị, được cố định để về sau phục vụ việc tách các giá trị trong `values array`, tính toán timestamp của từng giá trị trong array dựa trên `timestamp` của giá trị đầu cũng như `sample time` của thiết bị.

***

12/2024 by Thai-Son Nguyen

 🧑‍💻🧑‍💻🧑‍💻 Happy coding !!! 🧑‍💻🧑‍💻🧑‍💻


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
⠀⠀⠀⣿⠁⠎⡆⡘⠉⠉⠉⠉⠉⠉⠉⡹⢡⢻⢁⣮⣼⣿⣿⣾⣿⣿⣿⠀⠀⠀
⠀⠀⢸⣿⣄⣲⣃⣡⣤⣤⣤⣀⣀⣐⡂⡇⢠⣼⠸⣿⣾⣿⣿⣿⣿⣿⣿⡆⠀⠀
⠀⠀⣾⣿⣿⡿⣻⣿⣿⠇⠈⠩⡀⠉⡩⠜⠉⢩⢷⣿⣿⣽⣿⣿⣿⣟⣿⣿⡄⠀
⠀⣠⣿⣿⣽⣾⣾⡟⠁⢃⠀⠀⠠⠊⠀⢀⠔⡡⢺⣷⣿⣿⣿⣿⣯⣿⠘⣿⣿⡄
⣴⣿⣟⣿⣿⣿⣿⡪⠪⠻⢒⠁⠀⢀⡴⡁⠡⠀⡜⣿⣿⣿⣻⣿⣿⣿⣆⢻⣿⣿
⣿⣯⣿⣿⣿⣿⣏⡔⠁⡀⢀⠵⡺⢡⠑⢔⢄⠆⠁⣿⣽⣿⣷⣻⣿⣿⣿⣾⣿⣿
```
