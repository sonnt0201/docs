# Dự tính cho hệ thống WSN

## Tổng quan

Tôi viết một vài dự tính về hệ thống, ae xem thử xong nom chỉnh sửa các thứ như thế nào.
Mục tiêu tôi muốn là mình làm **nhanh, sớm ra được hệ thống cơ bản** để:
 
 - Phòng TH lỗi (bug) hay có sự cố hệ thống, hoặc công nghệ không phù hợp hay có khó khăn thì mình cx chủ động khắc phục sớm được.

 - Có thời gian cho ae làm các đồ án hoặc project môn khác.

 - Nếu sớm được thì mình có thể xoay sở xem có làm thêm được các chức năng nâng cao không, cho dễ lấy điểm.

Do ae cũng đều làm lab các dự án liên quan tới nhúng rồi nên tôi nghĩ mình có thể triển khai sớm được :v

## Mô hình hệ thống

- Mạng cảm biến **hình sao**, 1 máy tính đặt ở trung tâm, các cảm biến - vi điều khiển là các node kết nối và truyền trực tiếp dữ liệu tới máy tính đấy.

- Máy tính đảm nhiệm cả làm **gateway** lẫn server - database - giao diện.

- Các node cảm biến truyền trực tiếp dữ liệu tới máy theo chu kì yêu cầu.

## Công nghệ

### Giao thức

- Các node đóng gói và gửi dữ liệu tới **gateway** thông qua `lora`.

- Gateway giải mã `lora` và đóng gói thành `TCP` message, gửi tới **server**.

- **Server** là `TCP & HTTP server`, nhận gói tin, phân tích nếu cần, lưu trữ vào **database** và hiển thị lên giao diện.

### Phần cứng và firmware

- Module nhiệt độ và độ ẩm: Tâm chọn, tôi chưa biết :3

- Module `Lora`: Tâm chọn nốt :3

- Vi điều khiển: `STM32` 

### Gateway và server

Về **server** và **giao diện**, liệt kê cho ae biết thôi chứ tôi sẽ ôm hết phần này, ae không cần tìm hiểu làm gì.

- **Server** và **giao diện** đều đặt trên 1 máy tính.

- Môi trường `NodeJS`

- Database: `Sqlite`

Các công nghệ này đều đảm bảo nhu cầu mình làm về hệ thống nhúng (tải, tốc độ xử lí, chức năng, v.v..).

Về **gateway** tôi đang cân nhắc, tôi sẽ viết chi tiết phía dưới.


## Phân chia công việc (tạm thời)

- **Tâm:** mạch cứng, cảm biến.
- **Đức:** code cho `STM32`, đọc data từ sensor, tạo và gửi `lora`.
- **Sơn:** code cho gateway, server và giao diện.

## Tiến độ

- Ae thử cố gắng trong 4 hay 5 tuần đầu, mình ra được **Sản phẩm tối thiểu chạy được (MVP)** để mình nhanh có cái nhìn hoàn chỉnh về hệ thống và có thời gian chỉnh sửa, nâng cấp.

## Các vấn đề cần cân nhắc

Tôi không quá đặt nặng là phải theo giải pháp nào hay thế nọ thế kia, miên sao giải pháp mình biết triển khai là được. Tuy nhiên trong TH có nhiều lựa chọn, ae mình lựa chọn giải pháp nào thì phải đưa ra lý do chi tiết cho giải pháp đó, để phòng TH thầy Thịnh vặn (theo tôi được bt là thầy hay vặn) thì mình có lý do hợp lý để giải thích.

Giải pháp nào cũng được, lý do nào cx đc, miễn là phải có và hợp lý :v

### Gateway.

Cái gateway khá to và cần một lượng thời gian nhất định để lập trình, nên tôi đang muốn bàn riêng.

Về cơ bản đang có 2 cách triển khai:

- Tôi đang muốn tích hợp Gateway vào PC. PC sẽ vừa có gateway, vừa có server giao diện

- Tâm đang muốn tách ra gateway riêng. Cho 1 ESP32 làm gateway, decode lora và chuyển tiếp lên server sử dụng wifi.

Trong TH tích hợp gateway vào PC, tôi sẽ đảm nhiệm làm gateway. Mình cũng sẽ cần kiếm 1 lora module cắm được và máy tính để nhận gói tin lora.

Trong TH tách thành esp32, Đức sẽ làm gateway.

**Về việc tích hợp gateway vào máy tính:**

- Máy tính thừa khỏe để đảm nhiệm cả gateway lẫn server.

- Tiết kiệm được 1 vi điều khiển, cả chi phí lẫn năng lượng

- Code trên PC dễ hơn so với vi điều khiển (có sẵn công nghệ, thư viện,...). Dễ triển khai, sửa code, nâng cấp.

Nhược: 

- Cần kiếm lora module cắm thẳng được vào máy tính, tôi chưa kiếm được hoặc hình dung được mình làm kiểu gì. Do bình thường mình toàn cắm lora module vào vi điều khiển thay vì máy tính.

- Không tách gateway, nếu máy tính ở xa, năng lượng truyền từ sensor node tới gateway lớn hơn.

**Về việc để gateway riêng:**

- Phạm vi truyền từ **sensor node** tới **gateway** nhỏ hơn do mình thường đặt gateway tại vị trí ở giữa **sensor** và **pc server**. Do đó, nếu như mình có thể **tự ý điều chỉnh được công suất phát** của con `lora`, mình có thể tiết kiệm được năng lượng.

- Truyền được xa hơn khi có nhu cầu. Khi mình cần đặt **sensor** giữa cánh đồng chẳng hạn. Thì khoảng cách truyền từ **sensor** tới **server** = khoảng cách truyền từ **sensor** tới **gateway** (`lora`) + **gateway** tới máy tính/**server** (`wifi - internet`). => Xa hơn so với việc chỉ truyền từ **sensor** tới thẳng máy tính.

- (Tôi đoán) Các module điện tử như `lora` cũng thường hỗ trợ để giao tiếp với vi điều khiển nhiều hơn là máy tính PC.

Nhược:

- Thêm 1 vi điều khiển, nếu ae dùng **esp** thì mình cắm thêm 1 module `lora` vào **esp32** trong khi nó có sẵn `ble`, `wifi` rồi => tốn kém hơn về chi phí và năng lượng.

- Code bằng `C`, tốn thời gian hơn và khó bảo trì, nâng cấp hơn.

## Kết luận

Ae cân nhắc các giải pháp trên như nào để mình dễ triển khai đồng thời giải thích tốt được cho thầy. Tôi viết dài dòng vậy thôi chứ thực chất nd cũng khá đơn giản. Nếu được thì trong tuần này hoặc tuần sau ae mua đồ về setup thử luôn xem sao :v.

***

**9/2024 by Thai-Son Nguyen**

🧑‍💻🧑‍💻🧑‍💻 Happy coding !!! 🧑‍💻🧑‍💻🧑‍💻



```brainfuck
⣏⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⣩⣭⣽⣿⣿⣿⣿⣿⣿⣯⣭⣭⣭⣭⣭⣭⣉⠉⠉⠉⠉⠉⠉⠉⢹⡟⠛⠻⣭⣍⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⣩
⠈⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣤⣶⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣶⣝⢿⣿⣷⣤⣄⠀⠀⠀⣸⠃⠀⠀⠀⠈⠛⡆⠀⠀⠀⠀⠀⠀⣠⠞⠁
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣴⣿⣿⣿⣿⣿⡿⢿⣻⣉⣩⣭⣍⣙⣛⡿⢿⣿⣿⣿⣿⣷⣝⢿⣿⣿⣷⣄⠀⡿⠀⠀⠀⠀⢀⡼⠃⠀⠀⠀⠀⡠⠞⠁⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣰⣿⣿⣿⣿⡿⣛⣥⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣮⣟⡿⣿⣿⣿⣎⢿⣿⣿⣿⣿⢁⡀⠀⠀⣠⠟⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⣾⣿⣿⣿⣿⡿⣵⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣮⣿⣿⣿⡜⣿⣿⣿⠟⠋⠀⣠⡞⠁⠀⠀⠀⠀⠀⣀⣀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⣿⣿⣿⢸⣿⣿⣿⡿⠟⢻⠽⠛⠛⠉⠉⠉⠉⠉⠉⠙⠿⣿⣿⣿⣿⣿⣿⣿⣿⡿⣿⣟⠁⢀⣤⣾⣿⣷⠀⠀⣠⡤⠖⠛⢉⡏⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣼⣿⣿⣿⣿⣿⡿⠟⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠉⠻⠿⣿⣿⣤⠇⢈⡏⠉⠀⠉⠉⠛⠛⠉⠁⠀⠀⠀⢸⠇⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣼⣿⣿⣿⣿⡿⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⢿⣿⣿⣶⣄⡀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣾⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣼⣿⣿⣿⣿⠏⠀⢳⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⠀⠀⠀⠀⢽⣿⣿⣿⢿⣷⣦⣤⣤⣀⣀⣀⣤⠼⠃⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⢰⣿⣿⣿⣿⠃⠀⠀⠀⢳⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⠞⠁⠀⠀⠀⠀⠈⢿⣿⣿⣏⣿⣿⣿⣿⣿⣿⣇⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⢠⣿⣿⣟⣿⡇⠀⠀⠀⠀⠀⠙⢦⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⠖⠁⠀⠀⠀⠀⠀⠀⠀⢸⣿⣿⣿⢸⣿⣿⣿⣽⣿⣿⡆⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⣸⣿⡿⣽⣿⠀⠀⢀⣀⠤⠠⠤⢤⣙⡶⣄⠀⠀⡀⠀⡀⠀⠀⢀⣠⣴⡟⠁⠠⠦⢤⣀⡀⠀⠀⠀⠀⢸⣿⣿⣿⡇⣿⣿⣿⣧⢻⣿⣇⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⢷⣿⠇⠀⠀⢉⣀⣤⣶⣶⣦⣄⣉⠀⠀⠀⠁⠀⠀⠀⠀⢘⣻⣷⣶⢶⣾⣶⣤⣀⣉⠳⢤⡀⠀⢸⣿⣿⣿⡇⣿⣿⣿⣿⡟⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⢠⣿⡟⣾⣿⠀⢠⣾⠿⠛⠉⣀⢠⣄⡉⠛⠳⢄⠀⠀⠀⠀⠀⠠⠞⠉⢀⣠⠄⠠⢤⣉⠛⠿⣿⣦⡀⠀⢸⣿⣿⣿⢷⣿⣿⣿⣿⣷⢻⣿⡀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⢸⣿⢯⣟⣻⠲⡿⠁⣠⡶⠊⠉⣀⠈⠙⢦⡀⠀⠀⠀⠀⠀⠀⠀⢠⡶⢋⡥⠠⣤⠀⠈⠳⣄⠈⢻⣿⠒⢾⣯⣽⣶⣿⢿⣿⣿⣿⣿⡼⣿⡇⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⢸⣏⣾⣿⣿⣼⠁⢠⡏⠀⣎⠁⢸⠃⠀⠈⢳⠀⠀⠀⠀⠀⠀⠀⣾⠁⢸⣄⣤⣼⠀⠀⠀⢸⡆⠀⢹⡇⢸⣿⣿⣿⣿⡀⠘⣿⣿⣿⣇⢻⡇⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⢸⢿⣿⣿⣿⣷⠀⢻⣇⠀⠈⠹⣿⠇⠀⠀⣾⠀⠀⠀⠀⠀⠀⠀⢻⠀⠀⠈⠙⠛⠁⠀⠀⣼⠃⠀⠀⠀⢸⣿⣿⣿⣿⡙⠆⠘⣿⣿⣿⡼⣧⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⢸⣾⣿⣿⣿⣿⡄⢤⣻⣆⠀⠀⠀⠀⠀⢰⠏⠀⠀⠀⠀⠀⠀⠀⠘⣆⡀⠀⠀⠀⠀⠀⣠⠏⠀⠀⠀⠀⢸⣿⣿⣿⣿⠛⠁⠀⣿⣿⣿⣇⣿⡀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⢸⣿⣿⣿⣿⣿⡇⢮⣧⣌⡁⠀⠤⠤⠾⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠉⠐⠦⠤⠴⢚⣥⡾⠃⠀⠀⠀⣸⣿⣿⣿⣿⠀⠀⣼⣿⣿⣿⣿⢸⡇⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⣼⣿⣿⠋⠉⣽⢧⡾⠛⠻⣅⣀⣀⣀⣀⣀⣀⣀⣀⣀⠀⠀⠀⠀⠀⠀⠀⢀⣤⣤⣿⣉⣭⠤⠤⣤⠀⠀⣿⣿⣿⣿⡿⠀⣰⣿⣿⣿⣿⣿⡿⡇⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⢰⣿⣿⠃⠀⣸⠁⢸⠁⠀⡼⠁⠀⠀⠀⠀⠀⠀⠀⠀⠈⠉⠉⠉⠉⠉⠉⢉⡟⠁⢠⠟⢸⠃⠀⡶⠘⡇⢸⣿⣿⣿⣿⣷⣶⣿⣿⣿⣿⣿⣿⣿⡁⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⣾⣿⡇⠀⢰⡇⠀⡏⠀⢠⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡾⠀⢀⡎⠀⡏⠀⢰⣷⣾⣿⣿⣿⣿⣿⣿⡏⣿⣿⣿⣿⣿⣿⣿⣿⡇⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⢀⣿⣿⡇⠀⠸⣇⣀⣳⠀⠸⡇⠀⠀⠀⠀⠀⡀⠀⠀⠀⠀⠀⠀⢀⣀⣀⢸⡇⠀⢸⡇⢸⡇⠀⢸⣿⣝⣭⣾⣿⣿⣿⣿⣇⣿⣿⣿⣿⣿⣿⣿⣿⣿⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⣼⣿⣿⣿⣦⣀⠙⢿⣫⣧⣀⣹⣿⣿⣿⣒⣒⣒⣀⣀⣈⣉⣀⣀⣀⣀⠀⠘⣇⠀⠸⣿⣿⣷⠀⠸⡛⣻⣿⣹⣟⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠿⢛⣿⣿⣿⣿⠉⠙⠻⣿⠛⠉⠉⠙⠛⠛⠛⠛⢙⣶⠤⠟⠚⠚⣷⣤⣿⣿⣏⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡽⣿⣿⣿⣿⡄⠀⠀⠀⠀
⠀⠀⠀⠀⢸⣿⣿⣿⣿⣿⣯⣿⣿⣋⣷⣻⣿⣿⣿⣿⠃⠀⠀⠀⠈⢷⡀⠀⠀⠀⠀⣀⠴⠋⠀⠀⠀⠀⣰⢿⣿⣿⣿⣹⣿⣿⢸⣿⡿⣿⣮⢻⣿⣿⣿⣇⢹⣿⣿⣿⣿⣄⠀⠀⠀
⠀⠀⠀⠀⣼⣿⣿⣿⣿⣿⡾⣫⣾⢟⣶⣿⣿⣿⠟⢹⡀⠀⠀⠀⠀⠀⠹⣆⢀⣠⠞⠁⠀⠀⠀⠀⣠⠞⠋⠀⣿⣿⡇⣿⣿⣿⣿⣿⢳⣿⣿⣷⣝⢿⣿⣿⡄⢿⣿⣿⣿⣿⣆⠀⠀
⠀⠀⠀⢠⣿⣿⣿⣿⣟⣠⣾⣿⣋⣿⣿⣿⡿⠃⡠⠈⢧⠀⠀⠀⠀⠀⢀⡠⠛⠁⠀⠀⠀⠀⢀⠜⠁⢀⡠⠞⢻⣿⢻⣿⣿⣿⡏⣿⣸⣿⣿⣿⣿⣧⡹⣿⡇⠘⣿⣿⣿⣿⣿⣧⠀
⠀⠀⣴⣿⣿⣿⣿⣟⣽⣿⣿⣳⣿⣿⣿⡏⣠⠎⠀⣠⢼⣧⠀⠀⣀⡴⠋⠀⠀⠀⠀⠀⢀⡴⠃⣠⠔⠋⠀⠀⣿⣿⢸⣿⣿⣿⣿⣸⣿⣿⣿⣿⣿⣿⣷⣽⡇⠀⢹⣿⣿⣿⣿⣿⡆
⣠⣾⣿⣿⣿⣿⢫⣾⣿⣿⣿⣿⣿⣿⣷⡷⢃⡴⠋⡵⢹⠘⣧⠖⠁⠀⠀⠀⠀⠀⢀⣴⠋⠉⠉⠹⡄⠀⠀⢠⠻⣿⣸⣿⣿⣿⣿⣿⢿⣿⣿⣿⣿⣿⣿⣿⣿⡄⠈⣿⣿⣿⣿⣿⣿
⣿⣿⣿⣿⡿⣳⣿⣿⣿⣿⣿⣿⣿⣿⣟⡴⠋⢀⡼⠁⢸⠀⠈⢦⡀⠀⠀⠀⣠⡶⡻⡌⢳⡀⠀⠀⢳⠀⠀⣼⠀⣿⣇⢿⣿⣿⣿⣿⣦⢻⣿⣿⣿⣿⣿⣿⣿⣷⡄⢹⣿⣿⣿⣿⣿
⣿⣿⣿⠟⣼⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇⠀⢠⠏⠀⠀⢸⠀⠀⠀⠳⣀⡴⢻⠏⠀⡇⠹⣄⠙⣦⠀⠈⡆⠀⡟⠀⣿⣿⡞⣿⣿⣿⣿⣿⣇⢿⣿⣿⣿⣿⣿⣿⣿⣷⣤⣿⣿⣿⣿⣿
⣿⣿⢫⣿⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡧⠴⣇⠀⠀⠀⡞⠀⣀⣴⢟⢁⣰⠃⠀⢸⠀⠀⠈⢧⡈⢳⡄⢳⢀⠃⠀⣿⣿⣿⡜⣿⣿⣿⣿⣿⣆⣿⣿⣿⣿⣿⣿⣿⣿⣿⡝⣿⣿⣿⣿
```






