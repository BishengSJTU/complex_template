#include <iostream>
#include "Complex.h"
using namespace std;

int main() {
    Complex<int> a(1, 2);
    Complex<int> b(2, 3);
    a += b += b;
    Complex<int> c = a + b;
    cout << a << b << c;
    return 0;
}
