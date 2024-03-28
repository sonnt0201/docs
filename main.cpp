#include <iostream>
#include <stack>
#include <queue>
using namespace std;
// n không âm

int f(int n) {

    if (n == 1) return 1; // giai thừa của 1 


    // nếu n lớn hơn 1
    return (f(n - 1) * n); // giai thừa của (n - 1) rồi nhân n.
};

int main() {
    int n = 3;
    cout<<f(n)<<endl;

}