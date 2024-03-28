#include <iostream>
#include <stack>
#include <queue>
using namespace std;

void hello () {
    std::cout<<"hello world in recursion !\n";
    hello();

}

int main() {
    hello();
}