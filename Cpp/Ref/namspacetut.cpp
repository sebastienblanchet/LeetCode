#include <iostream>

// similar to imported modules
using namespace std::cout;
using namespace std::endl;


namespace Cont1 {
    int a = 10;
}

namespace Cont2 {
    int a = 0;
}

int main(int argc, char const *argv[]) {
    int a = 20;
    cout << Cont1::a << endl;
    cout << Cont2::a << endl;
    cout << a << endl;
    return 0;
}
