#include "Thread.h"

Thread::Thread(){std::cout << "Thread  ...\n";}
Thread::~Thread(){std::cout << "~Thread  ...\n";}

void Thread::start(){
    pthread_create(&t, nullptr, foo, this);
}

void Thread::join(){
    pthread_join(t, nullptr);

}

void * Thread::foo( void* arg){
    Thread* threadptr = static_cast<Thread*>(arg);
    threadptr->run();
    return nullptr;
}
