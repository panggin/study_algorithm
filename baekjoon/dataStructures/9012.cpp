#include <iostream>
#include <stack>
using namespace std;

// 올바른 입력인지 확인하는 함수
bool isRightPS(string inp)
{
    stack<char> PS;
    for (auto w : inp) {
        if (w == '(')
            PS.push(w);
        else { // w == ')'
            if ( PS.empty() )
                return false;
            else
                PS.pop(); 
        }
    }
    if (PS.empty())
        return true;
    else // '('가 남아있는 경우
        return false;
}

int main()
{
    int n;  // 테스트 개수 입력
    cin >> n;
    getchar();

    for (int i=0; i<n; i++) {
        string inp; // 문자열 입력
        getline(cin, inp);

        // 올바른 괄호 입력인지 판단
        if (isRightPS(inp))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}