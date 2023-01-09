#include <vector>
#include <cstdio>
#include <iostream>
#include <string.h>
using namespace std;
int main(){
    vector<int> vec = {1};
    cout << "vec.size() = " << vec.size() << endl;
    for (auto i : vec){
        cout << i << endl;
    }
    char ch[] = "123";
    int su = atoi(ch);
    cout << "su * 2 = " << su * 2 << endl;
    char cha[10] = {0};
    snprintf(cha, sizeof(cha), "%d", su);
    cout << "cha = " << cha <<endl;
    strcat(ch, cha);
    cout << "ch = " << ch << endl;
}