#include <iostream>

using namespace std;

void fizzbuzz(int max){
    for(int i =0; i < max; ++i){
      if(i % 3 ==0 && i %5 ==0){cout <<"fizzbuzz" <<endl;}
      else if(i % 3 ==0){cout <<"fizz" <<endl;}
      else if(i % 5 ==0){cout <<"buzz" <<endl;}
      else{cout << i << endl;}
    }

}
// Driver
int main(void) {
    fizzbuzz(100);
    return 0;
}
