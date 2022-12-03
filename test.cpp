#include <bits/stdc++.h>
#include "pbl2.cpp"
using namespace std;

class base{
    public:
        virtual void foo(){
            cout<<"base nothing";
        }
        virtual void foo(int x=0){
            cout<<"base int";
        }
};

class derive: public base{
    public:
        virtual void foo(){
            cout<<"derive nothing";
        }
        virtual void foo(int x=0){
            cout<<"derive int";
        }
};

int main(){
    base* ptr;
    derive obj;
    ptr = &obj;
    ptr->foo();
    ptr->foo(5);
    obj.foo(5);
}
