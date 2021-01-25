// 스택 구현 예제
#include <iostream>
#include <stack>
using namespace std;

int main()
{
    stack<int> myStack;

    // 삽입(5) - 삽입(2) - 삽입(3) - 삽입(7) - 삭제() - 삽입(1) - 삽입(4) - 삭제()
    myStack.push(5);
    myStack.push(2);
    myStack.push(3);
    myStack.push(7);
    myStack.pop();
    myStack.push(1);
    myStack.push(4);
    myStack.pop();

    // 스택 최상단 원소부터 출력 (1 3 2 5)
    while (!myStack.empty()) {
        cout << myStack.top() << " ";
        myStack.pop();
    }
}