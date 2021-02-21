#include <iostream>
#include <stack>
using namespace std;

int n;
stack<int> myStack;

int main()
{
    cin >> n;
    string cmd;
    int num;
    for (int i=0; i<n; i++) {
        cin >> cmd;
        // push
        if (cmd == "push") {
            cin >> num;
            myStack.push(num);
        } 
        // size
        else if (cmd == "size") {
            cout << myStack.size() << "\n";
        }
        else if (myStack.empty()) {
            // 스택이 비어있는 경우
            if (cmd == "empty")
                cout << "1\n";
            else
                cout << "-1\n";
        }
        else if (!myStack.empty()) {
            if (cmd == "empty")
                cout << "0\n";
            else if (cmd == "pop") {
                cout << myStack.top() << "\n";
                myStack.pop();
            }
            else if (cmd == "top") {
                cout << myStack.top() << "\n";
            }
        }
    }
    return 0;
}