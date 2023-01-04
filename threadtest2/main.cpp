#include "Thread.h"
#include <unistd.h>
#include <mutex>
#include <memory>
//基于对象的方法
using std::placeholders::_1;
class deThread
{
public:
    deThread(int&& count):count_(count) {std::cout << "deThread  ...\n";};
    ~deThread(){std::cout << "~deThread  ...\n";};
    void run(){
        std::unique_lock<std::mutex> lock(muted);
        while(count_--){
            std::cout <<"count_ = " <<count_ << ",   this is a run ...\n";
            sleep(1);
        }
    }
    void run2(int x){
        std::unique_lock<std::mutex> lock(muted);
        while(x--){
            std::cout << "count_ = " << count_ << ",   this is a run2 ...\n";
            sleep(1);
        }
    }
    int count_;
    std::mutex muted;
};

void ThreadFunction1(){
    std::cout << "ThreadFunction1  ..." << std::endl;
    sleep(1);
}

void ThreadFunction2(int& count){
    while(count--){
        std::cout << "ThreadFunction2  ..." << std::endl;
        sleep(1);
    }
}

int main(){
    deThread a(5);
    Thread t1(std::bind(ThreadFunction1));
    Thread t2(std::bind(ThreadFunction2, 5));
    Thread t3(std::bind(deThread::run, std::ref(a)));
    Thread t4(std::bind(deThread::run2, std::ref(a), 10));
    t4.start();
    t3.start();
    t1.start();
    t2.start();
    
    t1.join();
    t2.join();
    t3.join();
    t4.join();
}