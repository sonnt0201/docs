const printSum = (a, b, callback) => {
    const s = a + b;
    console.log("Tổng là: " + s);
    callback(s);
  };
  
  // gọi hàm
  const a = 2,
    b = 3;
  
  printSum(a, b, (s) => console.log("Bình phương là: " + s*s));