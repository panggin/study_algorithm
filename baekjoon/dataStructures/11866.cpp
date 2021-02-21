#include <iostream>
#include <queue>
using namespace std;

queue<int> people;

int main()
{
    // 입력 처리
    int n, step, front;
    cin >> n;
    cin >> step;

    // 큐 만들기
    for (int i=step; i<=n; i++)
        people.push(i);
    for (int i=1; i<step; i++)
        people.push(i);
    
    // 요세푸스 순열 출력
    cout << "<";
    while (people.size() > 1) {
        cout << people.front() << ", ";
        people.pop();
        for (int i=1; i<step; i++) {
            people.push(people.front());
            people.pop();
        }
    }
    cout << people.front() << ">\n";
}