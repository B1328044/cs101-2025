#include <iostream>
#include <string>
using namespace std;

class node {
public:
    int m_Date;
    string m_Mystr;

    node(int n, string s) {
        m_Date = n;
        m_Mystr = s;
        cout << "init node" << endl;
    }

    ~node() {
        cout << "delete node" << endl;
    }
};

int main() {
    node* pN = new node(5, "IU");
    cout << pN->m_Date << endl;
    cout << pN->m_Mystr << endl;
    delete pN;
    return 0;
}
