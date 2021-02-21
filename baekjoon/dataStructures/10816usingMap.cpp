#include <iostream>
#include <map>
#include <utility>
using namespace std;

int n, num;
map<int,int> numbers;

int main()
{
    // cin 속도를 높이기 위함
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    // 입력
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> num;
        if ( numbers.find(num) == numbers.end() ) {
            numbers.insert({num,1});
        } else {
            numbers[num] += 1;
        }

        // // for debugging
        // for (auto n : numbers) {
        //     cout << "(" << n.first << "," << n.second << ") ";
        // }
        // cout << "\n";
    }
    // 조회
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> num;
        if ( numbers.find(num) != numbers.end() ) {
            cout << numbers.find(num)->second << " ";
        } else {
            cout << "0 ";
        }
    }
}