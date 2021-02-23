#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
set<string> name;
vector<string> selectedName;

int main()
{
    // cin 속도 up
    ios::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    // 입력 처리
    cin >> n >> m;
    string inp;
    for (int i=0; i<n; i++) {
        cin >> inp;
        name.insert(inp);
    }
    for (int i=0; i<m; i++) {
        cin >> inp;
        if (name.count(inp) == 1) {
            selectedName.push_back(inp);
        }
    }
    
    // 정렬
    sort(selectedName.begin(), selectedName.end(), less<string>());

    // 출력
    cout << selectedName.size() << "\n";
    for (auto sName : selectedName) {
        cout << sName << "\n";
    }
}