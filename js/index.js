function printSquare(x) {
    const square = x + x
    console.log("Bình phương của tổng là" + square)
}

function printSum(a, b, callback) {
    const s = a + b;
    console.log(s);

    // callback
    callback(s);
}

// main: call the function 
const a = 2, b = 3

printSum(a, b, printSquare)
