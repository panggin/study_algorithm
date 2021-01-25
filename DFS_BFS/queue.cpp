// 큐 예제 구현
#include <iostream>
#include <queue>
using namespace std;

int main()
{
    queue<int> myQueue;

    // 삽입(5) - 삽입(2) - 삽입(3) - 삽입(7) - 삭제() - 삽입(1) - 삽입(4) - 삭제()
    myQueue.push(5);
    myQueue.push(2);
    myQueue.push(3);
    myQueue.push(7);
    myQueue.pop();
    myQueue.push(1);
    myQueue.push(4);
    myQueue.pop();

    // 큐 먼저 들어온 순서대로 출력 (3 7 1 4)
    while (!myQueue.empty()) {
        cout << myQueue.front() << " ";
        myQueue.pop();
    }
}