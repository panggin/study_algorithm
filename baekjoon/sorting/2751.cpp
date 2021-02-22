#include <iostream>
#include <set>
using namespace std;

int n;
set<int> numbers;

int main()
{
    // cin 속도를 높이기 위함
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    // 입력 처리
    cin >> n;
    for (int i=0; i<n; i++) {
        int num;
        cin >> num;
        numbers.insert(num);
    }
    // 출력
    for (auto num : numbers) {
        cout << num << "\n";
    }
}