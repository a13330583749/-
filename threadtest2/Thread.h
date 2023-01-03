#include <pthread.h>
#include <iostream>
#include <functional>
using ThreadFunc = std::function<void()>;
class Thread{
public:
    explicit Thread(const ThreadFunc& f);
    ~Thread();
    void start();
    void join();
    static void* ThreadRountine(void* arg);

private:
    ThreadFunc f_;
    pthread_t t;
};