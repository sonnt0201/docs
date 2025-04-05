# Một vài gợi ý khi thuyết trình về chip bán dẫn

## Vấn đề với bài viết này

Để có kiến thức cơ sở ngành về chip bán dẫn, cơ bản là em sẽ cần học Điện tử tương tự, Điện tử số, Vi xử lý và Hệ thống nhúng, ...,
Thực chất là giáo trình điện tử của bọn anh. Đơn giản nhất nếu em bắt đầu học về chip, anh ném đống này.

Nhưng vấn đề là đây không phải môn học của em, này chỉ là bài thuyết trình nói theo "chủ đề rộng" về ngành chip,
tổng hợp kiến thức và ảnh hưởng của ngành chip bán dẫn trong kinh tế chính trị xã hội (theo kiểu chém gió :)))

Anh không có hẳn tài liệu tổng hợp nào để làm cái này :D

**Vậy**

Anh sẽ đưa cho em vài gợi ý để em có hướng đọc và triển khai các ý tưởng, kèm các nguồn tài liệu. Sau đó, việc đọc tài liệu và chọn ý để triển khai là do em :v

## Bài viết có gì

Chip bán dẫn dưới góc nhìn của *anh* - anh không làm thiết kế hay chế tạo chip, mà là người **sử dụng** chip, đưa vào triển khai trong các ứng dụng nhúng, IoT và mạng cảm biến không dây. Cũng sẽ là góc nhìn nói chung về chip của kĩ sư phần mềm, nhúng và IoT:

- Chip bán dẫn bản chất là gì, chế tạo thế nào

- Các chức năng của chip

- Microchip, microprocessor & microcontroller 

- bla bla (vừa viết vừa nghĩ)

## Khái niệm chip bán dẫn

Cái từ `Chip bán dẫn` trong đề nó có vẻ là từ nghĩa rộng, vừa đề cập đến các mạch điện tử đơn giản, mạch logic, vừa đề cập đến những con chip phức tạp hơn như vi xử lý (microprocessor), vi điều khiển (microcontroller), CPU, ...




### Nguồn chuẩn

Chip bán dẫn (chip vi mạch, IC) là các mạch điện tử số được sản xuất dưới dạng mạch tích hợp (Integrated circuit -> IC) hay còn gọi là vi mạch ... [[1]](#1-nguyễn-lương-ngọc-hải-lê-hải-sâm-nguyễn-trinh-đường-nguyễn-quốc-cường-trần-văn-tuấn-điện-tử-số-trang-34)


A monolithic integrated circuit (IC) is an electronic circuit that is constructed entirely on a single small chip of silicon. All the components that make up the circuit—transistors, diodes, resistors, and capacitors—are an integral part of that single chip. Fixed-function logic and programmable logic are two broad categories of digital ICs. In fixed-function logic devices, the logic functions are set by the manufacturer and cannot be altered. [[2]](#2-thomas-l-floyd-digital-fundamentals-page-41)

## Các loại chip và chức năng

Giải thích đơn giản, mỗi con chip nó giống như một hàm ấy, có các đầu vào và các đầu ra. Đầu vào và đầu ra đều là các giá trị số (0 hoặc 1) biểu diễn bằng mức điện áp:

- Mức cao, 3.3V hoặc 5V hoặc 12V tùy từng loại thiết bị, dùng để biển diễn giá trị logic 1

- Mức thấp, trên 0V đến tầm 2V hoặc hơn tùy từng loại thiết bị, để biếu diễn giá trị logic 0

Và một hệ thống của em hiểu đơn giản là (rất) nhiều hàm như thế ghép lại với nhau, đầu ra của hàm này là đầu vào của hàm kia, các IC (tượng trưng cho hàm) giao tiếp trao đổi dữ liệu với nhau theo cách đó.

**Về phân loại IC:**

- Những chip đơn giản - vi mạch có độ tích hợp nhỏ, mỗi chip gồm khoảng vài chục bóng bán dẫn, tạo thành vìa cổng logic. VD chip mạch AND OR XOR NOT

- Vi mạch có độ tích hợp trung bình, gồm vài chục đến trăm cổng logic, tạo thành mạch có chức năng giải mã, chọn kênh, đếm, ...

- Vi mạch có độ tích hợp lớn ... [[4]](#4-lương-ngọc-hải-lê-hải-sâm-nguyễn-trinh-đường-nguyễn-quốc-cường-trần-văn-tuấn-điện-tử-số-trang-35)

- Vi mạch có độ tích hợp rất lớn ... [[4]](#4-lương-ngọc-hải-lê-hải-sâm-nguyễn-trinh-đường-nguyễn-quốc-cường-trần-văn-tuấn-điện-tử-số-trang-35)

- Vi mạch khả trình ... [[4]](#4-lương-ngọc-hải-lê-hải-sâm-nguyễn-trinh-đường-nguyễn-quốc-cường-trần-văn-tuấn-điện-tử-số-trang-35)

- Xịn hơn nữa, ta có SoC (System on Chip). Hiểu đơn giản, con này rất lớn (chính là ram, rom , cpu của mình), tích hợp rất nhiều mạch logic, lập trình hoặc điều khiển (hoặc cả 2) được, cung cấp nhiều chức năng và khả năng tùy biến, ứng dụng để làm nhúng, vi điều khiển hoặc máy tính điện thoại hiện đại.

## Ứng dụng

Anh sẽ nói ứng dụng từ các chip cỡ nhỏ -> cỡ lớn, từ lĩnh vực điện tử tương tự -> điện tử số -> vi mạch, nhúng, cảm biến -> phần mềm -> AI, Cloud... 

Điện tử tương tự, ứng dụng vào các mạch điện tử tương tự trong đời sống hàng ngày:

- Mạch khuếch đại, lọc tín hiệu, mạch thuật toán tương tự, ... để xử lý tín hiệu như âm thanh (khuếch đại trong loa, đài), lọc nhiễu với mạch lọc tích cực [[5]]

- Mạch chỉnh lưu, nghịch lưu ứng dụng vào điện tử công suất (chế tạo bộ nguồn, điều áp, sạc, v.v..) [[6]](#ref6)


## Chế tạo

Xem cách người ta chế tạo chip [tại đây](https://www.youtube.com/watch?v=g8Qav3vIv9s&t=138s) (video).

Về nguồn chuẩn, đọc tại đây [[3]](#3-gary-s-may-phd-costas-j-spanos-phd-fundamentals-of-semiconductor-manufacturing-and-process-control-page-8)


## Chức năng



## Trích dẫn

#### [1] Nguyễn Lương Ngọc Hải, Lê Hải Sâm, Nguyễn Trinh Đường, Nguyễn Quốc Cường, Trần Văn Tuấn. Điện tử số. Trang 34

#### [2] Thomas L. Floyd. Digital Fundamentals. Page 41

#### [3] Gary S. May, Ph.D. Costas J. Spanos, Ph.D. FUNDAMENTALS OF SEMICONDUCTOR MANUFACTURING AND PROCESS CONTROL. Page 8

#### [4] Lương Ngọc Hải, Lê Hải Sâm, Nguyễn Trinh Đường, Nguyễn Quốc Cường, Trần Văn Tuấn. Điện tử số. Trang 35

#### [5] Nguyễn Trinh Đường, Lê Hải Sâm, Lương Ngọc Hải, Nguyễn Quốc Cường, Trần Văn Tuấn. Điện Tử Tương Tự. Trang 114

#### [6] Nguyễn Trinh Đường, Lê Hải Sâm, Lương Ngọc Hải, Nguyễn Quốc Cường, Trần Văn Tuấn. Điện Tử Tương Tự. Trang 193 {#ref6}


