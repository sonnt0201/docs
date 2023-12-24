#include <iostream>
#include <set>
using namespace std;

int main() {
  int *pa;
 
  pa[2] = 10;

  cout<<pa<<endl;
  cout<<"size: "<<sizeof(pa)<<endl;
  for (int i = 0; i < 3; i++) {
    cout << pa[i] << endl;
  }
}

// callback