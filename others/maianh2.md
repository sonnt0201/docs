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

- Gợi ý về mối quan hệ với an ninh quốc gia

- bla bla (vừa viết vừa nghĩ)

## Khái niệm chip bán dẫn

Cái từ `Chip bán dẫn` trong đề nó có vẻ là từ nghĩa rộng, vừa đề cập đến các mạch điện tử đơn giản, mạch logic, vừa đề cập đến những con chip phức tạp hơn như vi xử lý (microprocessor), vi điều khiển (microcontroller), CPU, ...




### Nguồn chuẩn

Chip bán dẫn (chip vi mạch, IC) là các mạch điện tử số được sản xuất dưới dạng mạch tích hợp (Integrated circuit -> IC) hay còn gọi là vi mạch ... [[1]](#ref1)


A monolithic integrated circuit (IC) is an electronic circuit that is constructed entirely on a single small chip of silicon. All the components that make up the circuit—transistors, diodes, resistors, and capacitors—are an integral part of that single chip. Fixed-function logic and programmable logic are two broad categories of digital ICs. In fixed-function logic devices, the logic functions are set by the manufacturer and cannot be altered. [[2]](#ref2)

## Các loại chip và chức năng

Giải thích đơn giản, mỗi con chip nó giống như một hàm ấy, có các đầu vào và các đầu ra. Đầu vào và đầu ra đều là các giá trị số (0 hoặc 1) biểu diễn bằng mức điện áp: [[12]](#ref12)

- Mức cao, 3.3V hoặc 5V hoặc 12V tùy từng loại thiết bị, dùng để biển diễn giá trị logic 1

- Mức thấp, trên 0V đến tầm 2V hoặc hơn tùy từng loại thiết bị, để biếu diễn giá trị logic 0

Và một hệ thống của em hiểu đơn giản là (rất) nhiều hàm như thế ghép lại với nhau, đầu ra của hàm này là đầu vào của hàm kia, các IC (tượng trưng cho hàm) giao tiếp trao đổi dữ liệu với nhau theo cách đó.

**Về phân loại IC:**

- Những chip đơn giản - vi mạch có độ tích hợp nhỏ, mỗi chip gồm khoảng vài chục bóng bán dẫn, tạo thành vìa cổng logic. VD chip mạch AND OR XOR NOT

- Vi mạch có độ tích hợp trung bình, gồm vài chục đến trăm cổng logic, tạo thành mạch có chức năng giải mã, chọn kênh, đếm, ...

- Vi mạch có độ tích hợp lớn ... [[4]](#ref4)

- Vi mạch có độ tích hợp rất lớn ... [[4]](#ref4)

- Vi mạch khả trình ... [[4]](#ref4)

- Xịn hơn nữa, ta có SoC (System on Chip). Hiểu đơn giản, con này rất lớn (chính là ram, rom , cpu của mình), tích hợp rất nhiều mạch logic, lập trình hoặc điều khiển (hoặc cả 2) được, cung cấp nhiều chức năng và khả năng tùy biến, ứng dụng để làm nhúng, vi điều khiển hoặc máy tính điện thoại hiện đại.

## Ứng dụng

Anh sẽ nói ứng dụng từ các chip cỡ nhỏ -> cỡ lớn, từ lĩnh vực điện tử tương tự -> điện tử số -> vi mạch, nhúng, cảm biến -> phần mềm -> AI, Cloud... 

**Điện tử tương tự**, ứng dụng vào các mạch điện tử tương tự trong đời sống hàng ngày:

- Mạch khuếch đại, lọc tín hiệu, mạch thuật toán tương tự, ... để xử lý tín hiệu như âm thanh (khuếch đại trong loa, đài), lọc nhiễu với mạch lọc tích cực [[5]](#ref5). Khuếch đại tín hiệu cảm biến để dễ dàng đưa vào bộ ADC (chuyển đổi tương tự - số).

- Mạch chỉnh lưu, nghịch lưu ứng dụng vào điện tử công suất (chế tạo bộ nguồn, điều áp, sạc, v.v..) [[6]](#ref6).

- Điều chế tín hiệu

**Điện tử số**, cũng là ứng dụng vào đời sống hàng ngày: mạch đồng hồ, mạch đèn giao thông, mạch chuyển đổi tương tự số, thanh ghi, bộ nhớ bán dẫn như RAM, ROM, ... [[7]](#ref7)


**Vi mạch và hệ thống nhúng, IoT**
- Phát triển trên nền tảng điện tử tương tự và số, các **vi xử lý** và vi điều khiển xuất hiện, là các SoC (System on Chip):

    - Tích hợp sẵn các mạch tính toán và module giao tiếp (giao tiếp bằng các chuẩn giao thức khác nhau như UART, SPI, I2C, thậm chi là Wifi, Bluetooth) và bộ nhớ riêng.

    - Lập trình được, linh hoạt, bằng ngôn ngữ Assembly, C, C++

    - Có cộng đồng phát triển mạnh mẽ

    - Ứng dụng vào: hệ thống điều khiển công nghiệp (PLC), đo và truyền tin công nghiệp [[8]](#ref8), kĩ thuật cảm biến, radar, ...

- Cảm biến: chế tạo các mạch khuếch đại và lọc cho cảm biến. Chế tạo các RF (antenna) tiêu thụ năng lượng thấp để truyền tin. [[9]](#ref9). Xem bài báo về 1 ứng dụng của lab anh [tại đây](https://www.facebook.com/sensor.lab.hust/posts/pfbid02WGfUqyfbTajmVqCLufkaCdq8X8d9dUHhw9KbKrV6AToCTcEGxnAkNBzfeQhBRcXsl)

**Điện thoại máy tính hiện đại**

- Quá đơn giản, lấy luôn các ứng dụng của x86 anh viết hôm trước để cho vào, thêm vào đó là ứng dụng cho thiết bị di động

## Chế tạo

Xem cách người ta chế tạo chip [tại đây](https://www.youtube.com/watch?v=g8Qav3vIv9s&t=138s) (video).

Về nguồn chuẩn, đọc tại đây [[3]](#3-gary-s-may-phd-costas-j-spanos-phd-fundamentals-of-semiconductor-manufacturing-and-process-control-page-8)


## Đối với an ninh quốc gia

Cái này anh chịu :))) vì không trong ngành, nhưng cũng có một vài gợi ý cơ bản sau

- Em chia làm 2 ý chính là **an ninh trong nước** và **quốc phòng**

- Báo đài (chính thống của nhà nước) sẽ có đầy, nhất là khi dạo này có "trend bán dẫn" (anh không thích cách người ta rêu rao cái trend này lắm), báo đài Tiếng Việt thì các em cứ search Tiếng Việt và khả năng cao sẽ tìm được thôi. Ví dụ [[10]](#ref10)

- Nguy cơ với quốc gia có thể đến từ 

    - Các đối tượng xấu, tội phạm công nghệ cao can thiệp vào mạng, vào chip hay phá sóng để ăn cắp thông tin hoặc thực hiện hành vi xấu (**an ninh trong nước**)

    - Phụ thuộc vào công nghệ (phần cứng hoặc phần mềm) nước ngoài (do VN chưa tự sản xuất được chip), để chế tạo các thiết bị an ninh quốc phòng, từ đó rủi ro xảy ra khi có khủng hoảng kinh tế, mâu thuẫn chính trị, chiến tranh các nước khiến giá chip bị đẩy lên, gây khó khăn cho sự phát triển khoa học kĩ thuật => Phải tự chủ công nghệ, nâng cao trình độ và ưu tiên phát triển khoa học cơ bản, ...

    - Một case study: [[11]](#ref11) 

## Trích dẫn

<a id='ref1'></a>
#### [1] Lương Ngọc Hải, Lê Hải Sâm, Nguyễn Trinh Đường, Nguyễn Quốc Cường, Trần Văn Tuấn. Điện tử số. Trang 34

<a id='ref2'></a>
#### [2] [Thomas L. Floyd. Digital Fundamentals](https://bpcbirgunj.edu.np/wp-content/uploads/2019/10/DIGITAL_ELECTRONICS-by-Flyod.pdf). Page 41

<a id='ref3'></a>
#### [3] [Gary S. May, Ph.D. Costas J. Spanos, Ph.D. FUNDAMENTALS OF SEMICONDUCTOR MANUFACTURING AND PROCESS CONTROL](https://www.gacbe.ac.in/images/E%20books/Fundamentals%20of%20Semiconductor%20Manufacturing%20and%20Process%20Control%20G.%20May%20C.%20Spanos.pdf). Page 8

<a id='ref4'></a>
#### [4] Lương Ngọc Hải, Lê Hải Sâm, Nguyễn Trinh Đường, Nguyễn Quốc Cường, Trần Văn Tuấn. Điện tử số. Trang 35

<a id='ref5'></a>
#### [5] Nguyễn Trinh Đường, Lê Hải Sâm, Lương Ngọc Hải, Nguyễn Quốc Cường, Trần Văn Tuấn. Điện Tử Tương Tự. Trang 114

<a id='ref6'></a>
#### [6] Nguyễn Trinh Đường, Lê Hải Sâm, Lương Ngọc Hải, Nguyễn Quốc Cường, Trần Văn Tuấn. Điện Tử Tương Tự. Trang 193

<a id='ref7'></a>
#### [7] Nguyễn Lương Ngọc Hải, Lê Hải Sâm, Nguyễn Trinh Đường, Nguyễn Quốc Cường, Trần Văn Tuấn. Điện tử số. Trang 162

<a id='ref8'></a>
#### [8] Hoàng Minh Sơn. MẠNG TRUYỀN THÔNG CÔNG NGHIỆP

<a id='ref9'></a>
#### [9] [T. N. Thanh et al., "A Novel Energy-efficient Health Monitoring System with Electromagnetic-reducing Dual-band Antenna," in IEEE Sensors Journal, doi: 10.1109/JSEN.2025.3553929.](https://ieeexplore.ieee.org/abstract/document/10945538?fbclid=IwY2xjawJdh4dleHRuA2FlbQIxMAABHsyNAHVMmNkGpUcFnw9IWpOJT7bXxGsDRCTuiR2rttD5s8hzMtMdjW9Q3tUz_aem_WvWLUVc8OW5SZHU48C0jqg)

<a id='ref10'></a>
#### [10] [Tạp Chí Cộng Sản. Tường Linh. Vai trò của công nghệ bán dẫn trong lĩnh vực quốc phòng - an ninh](https://hssk.tapchicongsan.org.vn/bai-viet/chuyen-sau/vai-tro-cua-cong-nghe-ban-dan-trong-linh-vuc-quoc-phong-an-ninh-post1017.html)

<a id='ref11'></a>
#### [11] [REUTERS. U.S. actions against China's Huawei](https://www.reuters.com/graphics/USA-CHINA/HUAWEI-TIMELINE/zgvomxwlgvd/?utm_source=chatgpt.com)

<a id='ref12'></a>
#### [12] [Thomas L. Floyd. Digital Fundamentals](https://bpcbirgunj.edu.np/wp-content/uploads/2019/10/DIGITAL_ELECTRONICS-by-Flyod.pdf). Page 855