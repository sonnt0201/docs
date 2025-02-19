# Note cho Mai Anh: Vi xử lý và x86-64 

## Processor (bộ xử lý)

Máy tính (để bàn, laptop,...) mà em đang dùng ấy, nó có con CPU là bộ xử lý (processor) trung tâm, chịu trách nhiệm 
thực hiện các lệnh tính toán, đọc ghi bộ nhớ, kết nối và điều khiển các phần khác, v.v..

Nó như là đầu não của máy tính luôn.



## Bus

Bus (nó chính là "buýt" trong xe buýt mình hay gặp ấy), nó là kiến trúc để dựng lên máy tính hiện đại mà mình dùng.

Máy tính của mình thường bao gồm:

- CPU: đầu não, xử lý trung tâm, thực hiện các phép toán

- RAM: bộ nhớ tạm thời

- ROM

- Ổ cứng (storage): để lưu dữ liệu

- Ngoại vi: chuột, bàn phím, máy in, ...

- Và mấy thành phần khác.

Các phần này sẽ giao tiếp với nhau thông qua một đường Bus.

Cái cơ thế này nó giống hệt cơ chế xe buýt để vận chuyển người và hàng trong thực tế. 
Các phần ở phía trên (CPU, RAM, phần cứng các kiểu) giống như các tòa nhà (đơn vị hành chính hoặc dân cư) 
trong thành phố. Sẽ có một tuyến xe buýt kết nối với tất cả các toàn nhà đó, người dân (ứng với data trong máy tính) 
di chuyển qua lại giữa các tòa nhà thông qua việc lên cái xe buýt đó.


"Người dân" ở đây có thế mang theo dữ liệu, hoặc câu lệnh (instruction) cần thực thi.

Còn CPU ví nó như tòa nhà chính phủ đi, là người điều khiển chính của thành phố,
 cử những người mang mệnh lệnh hoặc dữ liệu lên tuyến xe buýt và gửi tới các tòa 
nhà khác (dân cư, đơn vị, ...), cũng thông qua tuyến bus này.

### Thế xe buýt chở được bao nhiêu "người"

Ngày xưa ban đầu xe buýt còn yếu, công nghệ thấp thì chỉ được 8 "người" (**8-bit data bus**).
Sau công nghệ phát triển lên thì chở được được hẳn 16 "người": **16-bit data bus**. Xịn nữa thì 
**32-bit data bus**.

Hiện đại thì là **64-bit data bus**.

### Địa chỉ (Memory Addressing)

Như một thành phố thực tế, từ cơ quan tới các đơn vị, nhà dân, đều phải đánh số nhà (0, 1, 2, ...),
để gói tin được gửi đi qua đường bus biết địa chỉ đích đến của nó.

Gói tin được gửi lên bus, ngoài nội dung được gửi (payload), cũng cần ghi kèm địa chỉ đích và
cả địa chỉ nguồn nếu cần.

Ngày xưa thành phố còn nhỏ, xây dựng được ít toà nhà hơn, chỉ cần 2^16 giá trị là đủ để đánh
địa chỉ tòa nhà rồi (64kB Address), về sau lượng tòa nhà - **số lượng ô nhớ** mở rộng, cần nhiều giá trị hơn
để đánh số địa chỉ => **2^32** giá trị địa chỉ hoặc **2^64** giá trị địa chỉ với máy tính hiện 
đại của mình.



## Lệnh (Instruction) và tập lệnh (instruction set)

Lệnh là các chỉ dẫn, những phép toán cơ bản nhất mà con processor thực hiện được, ví dụ:

- Đọc, ghi, xóa một bit hoặc byte hoặc một thanh ghi.

- công trừ nhân chia.

- Các phép logic: and, or, xor, not, ...

- Nhảy tới một địa chỉ khác.

...

Ví dụ một câu lệnh trong code `C/C++` hay `Java` mà em dùng ấy, sẽ được biên dịch thành mã máy gồm nhiều lệnh (instruction) mà con processor thực hiện được.

ví dụ về 1 instruction (bằng ngôn ngữ assembly - hợp ngữ)

```assembly
MOV 0xE0, #0x24
```

Là đặt giá trị 24 theo hệ 16 (36 theo hệ 10) vào thanh ghi 
có địa chỉ E0 theo hệ 16 (địa chỉ 224 theo hệ 10)

## Register (Thanh ghi)

Thanh ghi là một phần của Processor.

Thanh ghi thì đúng như tên của nó, để ghi các giá trị :v.

Nhưng mà là giá trị gì cơ. Thì trong quá trình thực hiện 1 lệnh (instruction),
nó sẽ có:

- Mã câu lệnh ( mã của instruction được đánh số bằng hệ 16).

- Địa chỉ câu lệnh.

- Giá trị đầu vào, các giá trị trung gian và giá trị đầu ra.

Đấy thanh ghi nó cần lưu nhưng cái như thế.

VD lệnh cộng 2 số đi:

```asm
ADD A, #0x24
```

Processor cần thanh ghi để lưu mã của lệnh `ADD`, 2 giá trị đầu vào và giá trị đầu ra, 
 nó dùng các thanh ghi nội để lưu những giá trị như thế.

### Số bit của thanh ghi

Giả sử thanh ghi của processor có 8 bíts, đồng nghĩa với việc 1 phép toán của lệnh
 có thể thao tác với 8 bit cùng 1 lúc. => `Registers: 8-bit`

Thanh ghi và ALU xịn hơn, 16 bits đi chẳng hạn, đồng nghĩa với việc 1 phép toán thao tác được
với hẳn 16 bits, xử lý được nhiều bit hơn trong 1 khoảng thời gian => tốc độ nhanh hơn.

Tương tự với processor có thanh ghi 32 và 64 bit: 
- `Registers: 32-bit`: processor có thanh ghi 32 bit
- `Registers: 64-bit`: processor có thanh ghi 64 bit

## Họ x86

Cái số `86` xuất phát từ con `8086 microprocessor` (vi xử lý 8086) của Intel từ hồi năm 1978.
Con vi xử lý này có kiến trúc 16-bit bao gồm :

- `16-bit` Register (thanh ghi)

- `20-bit` Address bus -> có thể đánh số lên đến 1MB địa chỉ với cơ chế `Memory segmentation`

- `16-bit` Data bus.

Đây là con đầu tiên của dòng x86.

x86 đề cập đến dòng vi xử lý là mở rộng của con 8086 này. Những con vi xử lý đời sau (chính là 
máy tính hiện đại của mình) "nhanh hơn, mạnh hơn" là vì có kiến trúc bit cao hơn:

### x86-32

Tức là thuộc dòng x86 có kiến trúc 32-bit:

- **Registers**: 32-bit (e.g., EAX, EBX, ECX, etc.).
- **Memory Addressing**: Đánh số địa chỉ lên đến 4 GB (2³² bytes).
- **Data Bus Width**: 32-bit processing.

Example OS: Windows 95, Windows XP (32-bit), Linux (i386).

### x86-64 (AMD64, Intel 64)

Tương tự, dòng này có:

- **Registers**: 64-bit (e.g., RAX, RBX, RCX, etc.).
- **Memory Addressing**: Trên lý thuyết thì nó có thể đánh số được 16 exabytes (2⁶⁴ bytes) địa chỉ, 
Nhưng số địa chỉ thật sự cần cần cho CPU hiện tại thì ít hơn (e.g., 256 TB in AMD64). 
Nghĩa là mình "giàu", có tận 16 exabytes để đánh địa chỉ nhưng gần như không bao giờ dùng hết 
- **Data Bus Width**: 64-bit data operations.
- **Example OS**: Windows 10/11 (64-bit), Linux (x86_64).

Lợi ích chính của các dòng bit cao hơn:

- Truy cập được vào nhiều ô nhớ/địa chỉ hơn.

- Tính nhanh hơn do 1 thanh ghi lưu được số lớn.

- Từ đó triển khai được nhiều tính năng hơn.

### Tương thích ngược

Để ý các máy tính 64-bit của em vẫn có thể chạy được các app cũ thuộc kiến trúc 32-bit, 
này là do khả năng tương thích ngược của dòng x86 mới có thể giúp nó chạy các app thuộc dòng
cũ, cái này có thể tự đọc thêm trong giáo trình.

## Tài liệu tham khảo

- Giáo trình của em 

- Nguyễn Tăng Cường, Phan Quốc Thắng • Cấu trúc và lập trình họ vi điều khiển 8051 
(thực ra này là giáo trình của anh ^^, liệt kê v chứ ko mua cx đc)

- [Kiến trúc của 8086](https://www.geeksforgeeks.org/architecture-of-8086/) (Blog)

- [AMD64 Manual](https://www.amd.com/content/dam/amd/en/documents/processor-tech-docs/programmer-references/40332.pdf): Tài liệu chuẩn của hãng

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