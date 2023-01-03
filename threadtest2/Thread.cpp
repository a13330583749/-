#include "Thread.h"
using ThreadFunc = std::function<void()>;
Thread::Thread(const ThreadFunc& f):f_(f){std::cout << "Thread  ...\n";}
Thread::~Thread(){std::cout << "~Thread  ...\n";}

void Thread::start(){
    pthread_create(&t, nullptr, ThreadRountine, this);
}

void Thread::join(){
    pthread_join(t, nullptr);
}

void* Thread::ThreadRountine(void* arg){
    Thread * ThreadPtr = static_cast<Thread*>(arg);
    ThreadPtr->f_();
    return nullptr;
}

