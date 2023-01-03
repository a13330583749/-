#include <pthread.h>
#include <iostream>
class Thread{
public:
    Thread();
    virtual ~Thread();
    void start();
    void join();
    static void * foo( void *);

private:
    virtual void run() = 0;
    pthread_t t;
};