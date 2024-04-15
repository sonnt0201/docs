// wait in `time` seconds then log the sum of `a` and `b`
const waitThenCalculateSum = (time, a, b) => {
    
  return new Promise((resolve, reject) => {

    console.log("Waiting for " + time + " seconds...")

      setTimeout(() => {
          const sum = a + b;
          resolve("Sum is: " + sum);
      }, time * 1000)
  })
} 

// call the function.
// đợi 4 giây rồi trả về tổng của 10 và 20
waitThenCalculateSum(4, 10, 20)
    .then(sum => { // biến `sum` để hứng giá trị `sum` từ tiến trình trước
        console.log(sum) // in ra tổng đã tính.
    })
    .catch(error => console.log(error.message)) // catch any error if it has.