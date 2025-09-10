# Easy-WiFi for IoT Device

## Mục tiêu chức năng

Trong hầu hết các project IoT, một vi điều khiển (ESP32, ESP8684, ...), thường đều có một chức năng chung là kết nối mạng, kết nối tới server và đẩy dữ liệu do vi điều khiển thu thập được lên server đó. Tùy vào từng project khác nhau mà loại dữ liệu thu thập, giao thức sử dụng cũng như cách thức xử lý dữ liệu thô trước khi gửi là khác nhau, nhưng nhu cầu kết nối WiFi và server thì luôn có.

Do đó, ý tưởng của project này là xây dựng 1 **thư viện** chung cho **ESP32** có chức năng **tự động kết nối** tới WiFi và server, từ đó có thể sử dụng thư viện này vào nhiều IoT Project khác. Với thư viện này, ESP32:

1. Khi khởi động có thể tự dò và kết nối với các WiFi có sẵn trong danh sách, chọn WiFi tốt nhất dò được để kết nối

2. Tự động tìm và tạo kết nối tới 1 HTTP(S)/MQTT(S) Server.

3. Khi mất kết nối tới WiFi hoặc Server, vi điều khiển tự cố gắng kết nối lại.

4. Trong trường hợp vi điều khiển chưa hoặc không kết nối tới WiFi hoặc Server, có thể chọn và điều chỉnh WiFi hoặc Server cần kết nối thông qua ứng dụng trên điện thoại.

Ý tưởng của project là đưa ra giải pháp chung cho kết nối mạng và gửi dữ liệu server, có thể ứng dụng vào các project khác sau này. Các project khác về sau sẽ chỉ cần lo công việc đọc dữ liệu cảm biến và xử lý, không phải lo vấn đề về mạng và gửi dữ liệu.

## Giới hạn project

Giới hạn cụ thể bao gồm:

- Xây dựng thư viện cho ESP32.

- Công nghệ sử dụng là [ESP-IDF](https://docs.espressif.com/projects/esp-idf/en/stable/esp32/get-started/index.html) (ngôn ngữ C)

- Server để kết nối và đẩy dữ liệu lên là 1 server [Thingsboard](https://thingsboard.io/).

## Gợi ý roadmap

1. Tìm hiểu ngôn ngữ C (1 tháng): các kiểu dữ liệu, con trỏ, bộ nhớ, các thuật toán cơ bản. Demo được một chương trình cơ bản

2. Tìm hiểu ESP-IDF, viết code nháy led và kết nối tới 1 WiFi sử dụng ESP-IDF (1 tháng)

3. Triển khai dò tìm và kết nối tới 1 WiFi tốt nhất trong danh sách Wifi có sẵn, tự dò và kết nối lại nếu mất kết nối. (2 tuần)

4. Tìm hiểu [Thingsboard](https://thingsboard.io/) (2 tuần). Demo tạo 1 project và đẩy dữ liệu lên Thingsboard.

5. Kết nối ESP32 tới server Thingsboard thông qua MQTT, thông báo lỗi và cố gắng kết nối lại nếu mất kết nối. (1 tháng).

## Sản phẩm đầu ra

Yêu cầu sản phẩm đầu ra có ít nhất 3/4 chức năng đã nêu ra ở [Mục tiêu chức năng](#mục-tiêu-chức-năng)

Yêu cầu source code sạch sẽ, có comment, có kiến trúc, phân chia file và thư mục rõ ràng, không code bừa phứa nhét hết code vào 1 file.

***

September 2025 by Thai-Son Nguyen

🧑‍💻🧑‍💻🧑‍💻 Happy coding !!! 🧑‍💻🧑‍💻🧑‍💻

```
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⣤⣀⣀⣀⣀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⠀⠀⠀⢀⣀⣀⣀⡀⠀⠀⠀⠀⠀⠀⠀⡇⠉⠓⠦⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⣿⣿⣿⣿⣿⣿⣷⣶⣦⣤⣠⣴⣶⣿⣿⣿⣿⣿⣿⣿⣿⣿⣛⠿⣿⣶⣦⣄⡀⠀⠀⠇⠀⠀⠀⠀⠑⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⣿⠙⠿⣿⣿⣿⣿⣿⡿⣯⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣌⠻⣿⣿⣿⣦⣰⠀⠀⠀⠀⠀⡜⢁⣀⣀⣀⣀⣀⣤⣤⣤⡄⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢾⡀⠀⠺⣿⣿⣿⢯⣾⣿⣿⣿⣿⣿⢿⣛⣛⣛⣛⣛⣛⣛⡿⢿⣿⣿⣷⡜⣿⣿⣿⡿⠀⠀⠀⢀⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⢿⠇⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⣇⠀⠀⠹⣿⡟⣾⣿⣿⣿⣿⡿⢾⣿⡿⠿⠿⣿⣿⣿⣿⣿⣷⣮⣝⢿⣷⢹⣿⣿⠗⠁⠀⣠⣿⣿⣿⣿⣿⣿⢿⣿⣿⡿⢫⡎⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⢆⠀⠀⢈⣿⣿⠿⠛⠋⠁⠀⠁⠀⠀⠀⠀⠀⠙⠉⠛⠛⠛⠻⢿⣿⣿⣾⣟⣁⠠⠴⢾⣿⣿⡿⠿⠟⠛⠁⢸⣿⠏⠀⣼⠁⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⢧⣴⣿⡿⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⣏⠀⠈⡆⠀⠀⠀⠀⠀⠀⠀⠀⠀⡞⠁⠀⣸⠃⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣸⣿⡟⠀⡠⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠠⠀⠀⠀⠀⠙⣶⣾⣷⣦⣄⣀⣀⠀⠀⠀⢀⡜⠀⢀⡼⠃⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⡿⠀⠈⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠁⠀⠀⠀⣾⣿⢿⣿⣯⢻⣿⣿⣿⣯⠉⠀⢠⡞⠁⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⠁⠐⢀⠀⢀⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⣼⣿⣿⡎⣿⡿⣿⣧⢀⡴⠋⠀⠀⠀⠀⠀⠀⠀
⠈⠉⠐⠤⡀⠀⠀⠀⠀⠀⠀⠀⢸⣿⣠⣴⠿⠛⠛⠛⠛⠲⣄⠀⠀⠀⠀⠀⠀⢐⣶⠶⣶⣶⣤⡀⡀⠂⠀⣿⣿⣿⣿⣿⣷⢿⣿⡹⣿⣿⣇⠀⠀⠀⠀⠀⠀⠀⠀
⢀⠀⠀⠀⠈⢢⡀⠀⠀⠀⠉⠓⢩⣽⡝⠁⣀⠄⠀⠒⠒⢀⠈⠃⠀⠀⠀⠀⠈⠁⡀⠀⠠⢀⡈⠉⠳⣄⠀⣿⣿⣿⣿⣿⣿⢸⣿⣷⢻⣿⣿⡀⠀⠀⠀⠀⠀⠀⠀
⠺⡖⡂⠀⠀⠀⠱⡀⠀⠀⠀⠀⢸⣿⠀⢸⠁⡠⠀⠂⠀⠀⠂⠀⠀⠀⠀⠀⣠⠊⡀⠀⠄⠀⠀⠑⡄⠈⢷⣿⡟⠘⢛⣛⣿⡼⣿⣿⣏⣿⣿⣧⠀⠀⠀⠀⠀⠀⠀
⠀⠶⣧⡄⠀⠀⠀⠇⠀⠀⠀⠀⢸⣿⡇⠸⡀⠁⠒⣇⠀⠀⢸⠀⠀⠀⠀⠀⠇⠀⠣⢤⡂⠀⠀⠀⢰⠀⠀⣿⣿⢸⣿⣿⣿⡇⣿⣿⣿⢹⣿⣿⡆⠀⠀⠀⠀⠀⠀
⠀⠀⠁⠀⠀⠀⠀⡄⠀⠀⠀⠀⢸⣿⠇⣠⡀⠀⠀⢀⣀⠤⠂⠀⠀⠀⠀⠀⠐⠀⠀⠀⠁⠀⠀⠀⠸⠀⠀⣿⡏⣿⣿⣿⣿⡇⣿⣿⣿⡏⣿⣿⣷⣀⠀⠀⠀⠀⠀
⠀⠭⢤⠀⠀⠀⣠⠃⠀⠀⣠⠎⢉⠙⢳⠒⠒⠤⢤⣈⣀⣀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠠⠤⢐⡡⠀⠀⣿⢇⣿⣿⣿⣿⡇⣿⣿⣿⣇⣿⣿⣿⣿⣿⣦⡀⠀⠀
⠀⠀⠚⢀⣠⠆⠉⠁⠀⢠⠃⢠⠂⢀⠇⠀⡀⠀⠀⠀⠀⠀⠀⠈⠉⠉⠉⠀⡐⠉⠑⠒⠉⢀⠝⣿⣀⠀⢀⣿⢸⣿⣿⣿⣿⡇⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⡀
⠶⠶⠚⠋⠁⠀⠀⠀⠀⢸⠀⢸⣀⢸⠀⠀⡧⠤⠄⠀⠀⣀⡀⠀⠀⠀⠀⠸⠀⢰⠰⠀⠀⣼⡋⣫⠦⢠⣼⣏⣿⣿⣿⣿⣿⢗⣿⣿⢹⣿⣿⠙⢿⣿⣿⣿⣿⣿⣿
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⢦⣀⠓⣤⣦⣀⣨⣦⣒⣈⣉⠁⠀⠀⠀⠀⠒⢇⠀⠸⡆⠀⠀⠙⠸⣏⣠⠟⣹⣿⣿⣿⣿⡿⣫⣿⣿⣿⢸⣿⣿⣧⠀⠙⢿⣿⣿⣿⣿
⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⣿⣿⡿⣿⣿⣿⣿⣿⣿⢿⣿⠟⠉⠉⠙⢷⡆⠚⠦⠤⠜⢄⡀⠀⣠⠏⢀⣼⣿⣿⣿⣿⢻⢪⣿⣿⣿⣿⢸⣿⣿⣿⣧⡀⠈⠻⣿⣿⣿
⠀⠀⠀⠀⠀⠀⠀⠀⣠⣿⠟⣫⣾⣿⢫⣿⣿⡿⣻⠿⡅⠀⠀⠀⠀⠀⠑⠄⣠⠔⠊⠁⠈⠉⢁⣴⣿⣿⣿⣿⢟⣵⡟⣾⣿⣿⣿⣿⣼⣿⣿⣿⣿⣿⣄⠀⠹⣿⣿
⠀⠀⠀⠀⠀⠀⠀⢰⣿⣵⣾⣿⡟⣵⣿⣿⢟⣾⡟⠀⠱⡀⠀⠀⠀⠀⠠⠚⠁⠀⠀⠀⢀⣴⣿⣿⣿⣿⡿⣳⣿⣿⣸⣿⣿⣿⣿⡇⢿⣿⣿⣿⣿⣿⣿⣧⠀⢹⣿
⠀⠀⠀⣀⣤⣶⣾⣿⣿⣿⡿⣫⣾⣿⣿⢫⣾⢟⠅⡀⡴⡘⢆⠀⠀⠀⠀⠀⠀⠀⣠⣴⣿⣿⣿⣿⣿⢏⣾⣿⣿⣇⣿⣿⣿⣿⣿⡇⣷⡻⣿⣿⣿⣿⣿⣿⣇⠈⣿
⠀⣤⣾⣿⣿⣿⣿⣿⡿⣿⣾⣿⣿⣿⢏⣿⡇⠡⠊⡜⠀⠈⢆⠑⢦⡀⢀⡠⠒⢉⣾⣿⣿⣿⣿⣿⢫⣾⣿⣿⣿⢹⣿⣿⣿⣿⣿⣇⣿⣷⡹⣿⣿⣿⣿⣿⣿⣤⣿
⢸⣿⣿⣿⣿⣿⠟⠁⣼⣿⣿⣿⡟⣵⣿⣿⣿⡀⡜⠀⠀⡀⠀⠃⠠⢋⠅⠈⠀⣾⣿⣿⣿⣿⣿⢳⢻⣿⣿⣿⣿⢸⣿⣿⣿⣿⣿⣿⡸⣿⣷⠹⣛⣛⣭⣭⣭⣽⣿
⢸⣿⣿⣿⣿⡇⠀⢸⣿⣿⣿⣿⣷⣿⣿⣿⣿⣿⣾⣄⠀⠇⠐⠀⠀⠀⠪⠢⡘⣿⣿⣿⣿⣿⢣⣿⣮⢿⣿⣿⣿⣼⣿⣿⣿⣿⣿⣿⣿⡻⢿⣧⢻⣿⣿⣿⣿⣿⣿
⢸⣿⣿⣿⣿⣧⠀⣿⣿⣿⣿⣿⡏⣿⣿⣿⣿⣿⣿⣌⠙⠚⠒⠦⣄⠤⠒⠒⢲⣽⣿⣿⣿⣿⢸⣿⣿⣿⣮⡻⣿⣷⡻⣿⣿⣿⣿⣿⣿⣿⣷⣮⣙⠿⣿⣿⣿⣿⣿
```
