#include <iostream>
#include <functional>
using std::placeholders::_1;

class Foo{
public:
    explicit Foo(int&& a, int &&b, int &&c):x(a), y(b), z(c){std::cout << "Foo ...\n";};
    int members(int n, int m){
        std::cout << "x * n = " << x * n << std::endl;
        std::cout << "y * m = " << y * m  << std::endl;
        std::cout << "z * n * m = " << z * n * m<< std::endl;
        std::cout << "m = " <<  m<< std::endl;
        std::cout << "n = " <<  n<< std::endl;
        return x + y + z;
    };
    int x, y, z;
};

int main(){
    Foo foo(1, 10 ,100);
    std::function<int(int)> func = std::bind(&Foo::members, std::ref(foo),  _1, 2);
    std::cout << std ::endl << "func(2000) = " << func(2000) << std::endl;
    exit(0);
}