#include <iostream>
#include <string>
using namespace std;

struct Student {
    int id;
    string name;
};

int main() {
    Student* p1 = new Student;                         // 預設建構，值為未初始化
    Student* p2 = new Student();                       // 預設建構，值為零初始化
    Student* p3 = new Student{10, "IU"};               // 使用初始化列表初始化

    cout << "p1 = " << p1->id << ", " << p1->name << endl;
    cout << "p2 = " << p2->id << ", " << p2->name << endl;
    cout << "p3 = " << p3->id << ", " << p3->name << endl;

    delete p1;
    delete p2;
    delete p3;
    return 0;
}
