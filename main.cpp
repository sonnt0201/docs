#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

void doicho(int arr[2]) // arr là array - mảng được truyền vào hàm
{
    int temp = arr[0];
    arr[0] = arr[1];
    arr[1] = temp;
}

int main() {
    int a[2] = {5, 10}; // mảng với 2 giá trị là 5 và 10

    doicho(a);

    cout<<"i = 0: "<<a[0]<<endl;
    cout<<"i = 1: "<<a[1]<<endl;
}


// callback