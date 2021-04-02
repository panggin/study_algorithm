#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

const int MAX_COMPUTERS = 101;

int computers, n, virusStart = 1, result = 0;
vector<int> network[MAX_COMPUTERS];
queue<int> searchQueue;

int main()
{
    ios::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    // 입력 처리
    cin >> computers;
    cin >> n;
    int a, b;
    while (n--) {
        cin >> a >> b;
        network[a].push_back(b);
        network[b].push_back(a);
    }

    vector<bool> hasVirus(computers+1, false); // 바이러스 감염 여부 확인
    hasVirus[virusStart] = true;

    // network BFS
    searchQueue.push(virusStart);
    while (!searchQueue.empty()) {
        int tmpPC = searchQueue.front();
        searchQueue.pop();
        for (auto linkedPC : network[tmpPC]) {
            if (!hasVirus[linkedPC]) { // 아직 감염되지 않은 PC
                hasVirus[linkedPC] = true;
                searchQueue.push(linkedPC);
            }
        }
    }

    // 감염된 PC 수 count
    for (auto virus : hasVirus) {
        if (virus) result += 1;
    }
    result -= 1; // 바이러스를 퍼뜨린 PC 제외
    cout << result << "\n";
    return 0;
}