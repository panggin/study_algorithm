#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int n, m;
map<string, int> name; // key: 포켓몬 이름
map<int, string> number; // key: 도감 순서

int main()
{
    // cin 속도 up
    ios::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    // 입력 처리
    cin >> n >> m;
    string p;
    for (int i=1; i<=n; i++) {
        cin >> p;
        name.insert({p,i});
        number.insert({i,p});
    }

    // 출력
    for (int i=0; i<m; i++) {
        cin >> p;
        try {
            int idx = stoi(p);
            cout << number[idx] << "\n";

        } catch(exception e) {
            cout << name[p] << "\n";
        }
    }
}