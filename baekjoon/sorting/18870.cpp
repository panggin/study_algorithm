#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int n, inp, idx = 0;
vector<int> inputNum;
map<int,int> newNum;

int main()
{
    ios::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    cin >> n;
    while (n--) {
        cin >> inp;
        inputNum.push_back(inp);
        newNum[inp] = 0;
    }
    for (auto iter = newNum.begin(); iter != newNum.end(); iter++) {
        iter->second = idx;
        idx += 1;
    }
    for (auto num : inputNum) {
        cout << newNum[num] << " ";
    }
    cout << "\n";
}