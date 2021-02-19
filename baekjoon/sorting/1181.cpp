#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
vector<string> words;

bool compare (string a, string b)
{
    if (a.length() == b.length()) // 길이 같을 경우 사전순
        return a < b;
    else // 길이 기준 내림차순 정렬
        return a.length() < b.length();
}

int main()
{
    // 입력 처리
    cin >> n;
    for (int i=0; i<n; i++) {
        string w;
        cin >> w;
        if ( find(words.begin(), words.end(), w) == words.end() )
            words.push_back(w);
    }
    // 문자열 정렬
    sort(words.begin(), words.end(), compare);
    // 결과 출력
    for (auto word : words) {
        cout << word << "\n";
    }
}