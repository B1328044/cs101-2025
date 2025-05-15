#include <iostream>
using namespace std;

class MyClass {
public:
    MyClass() {
        cout << "Constructor called!" << endl;
    }

    ~MyClass() {
        cout << "Destructor called!" << endl;
    }

    void doSomething() {
        cout << "Doing something!" << endl;
    }
};

int main() {
    MyClass* obj = new MyClass();  // 動態建立物件
    obj->doSomething();            // 呼叫成員函式
    delete obj;                    // 釋放記憶體
    return 0;
}
