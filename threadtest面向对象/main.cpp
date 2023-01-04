#include "Thread.h"
#include <unistd.h>

class deThread: public Thread
{
public:
    deThread(int&& count):count_(count) {std::cout << "deThread  ...\n";};
    ~deThread(){std::cout << "~deThread  ...\n";};
    void run(){
        while(count_--){
            std::cout << "this is a test ...\n";
            sleep(1);
        }
    }
    int count_;
};


int main(){
    deThread t11(5);
    t11.start();
    t11.join();
}