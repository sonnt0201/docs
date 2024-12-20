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
   "ts": number,
    "values": {
        "key1": number | number[],
        "key2": number | number[],
        ...
    }
}
```
`ts` là timestamp theo millisecond.

`values` là các giá trị theo thời gian thực được gửi lên.
Gồm các nhãn `key1`, `key2`, ... là tên các loại giá trị (ví dụ: "I", "U", "P", "wearform", ...) 

Giá trị của các khóa (`key`) có thể là một số (`number`) hoặc một mảng các số (`number[]`, ví dụ:  `[10, 8, 7, 5, 4, 2, -2, -4]`). Quy ước:

- Nếu giá trị là một số thì timestamp (`ts`) gửi kèm là thời điểm trích mẫu của giá trị đó.

- Nếu giá trị là một mảng thì timestamp gửi kèm là thời điểm trích mẫu của **giá trị đầu tiên** trong mảng đó.



**VD:** Gửi 1 loại giá trị (I), dạng mảng
```JSON

{
   "ts": 1733108907577,
    "values": {
        "I": [10, 8, 7, 5, 4, 2, -2, -4]
    }
}

Khi đó `ts` là thời gian trích mẫu (timestamp theo millisec) của giá trị đầu tiên (`I = 10`)

```
**VD:** Gửi nhiều loại giá trị
 
```JSON

{
   "ts": 1733108907577,
    "values": {
        "I": [10, 8, 7, 5, 4, 2, -2, -4],
        "P": 100,
        "Q" : 10
    }
}
```

**Lưu ý:** Trong device của Thingsboard cũng có 1 `shared attribute` tên là `sampleTime`. 
`sampleTime` là chu kì lấy mẫu thiết bị, được cố định để về sau phục vụ việc tách các giá trị trong `values array`, tính toán timestamp của từng giá trị trong array dựa trên `timestamp` của giá trị đầu cũng như `sample time` của thiết bị.

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