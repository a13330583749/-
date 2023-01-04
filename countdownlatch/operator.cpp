//#include<iostream>
#include <unistd.h>
//#include <pthread.h>
#include <thread>
#include "../threadtest2/Thread.h"

class A{
public:
    void operator()(){
        while(count_--){
            std::cout << "Thread " << ::getpid() << " ..." << std::endl;
            sleep(2);
        }
    }
    A(int &&a = 10 ):count_(a) {std::cout << "A() ...\n";}
    int count_;
};

int main(){
    A a;
    std::thread t(a);
    t.join();

}