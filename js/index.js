const a = 10,
  b = 12;

const sumIsMoreThanTen = (resolve, reject) => {
  const sum = a + b;

  // TH tốt, thỏa mãn:
  if (sum > 10) resolve(sum);

  // TH xấu, không thỏa mãn
  if (sum <= 10) reject(
    new Error("Nah man!, this sum cannot even reach 10. Sum is " + sum)
  );
};

const firstPromise = new Promise(sumIsMoreThanTen);

firstPromise
    .then((sum) => {
        // code when resolve
        console.log("Ok, this sum is bigger than 10. Sum is " + sum);

        // lấy bình phương của sum
        const result = sum * sum;

        // return để truyền result cho thằng then tiếp theo
        return result;
    })
   
    .then(result => {
        console.log("The square of this sum is " + result);

        // Thằng then này dĩ nhiên có thể return hoặc throw như thằng trước
        // Nhưng lần này mình thử throw xem sao

        message = "Sorry, this ended !";
        throw new Error(message);
    })
    .catch(error => console.log(error.message));