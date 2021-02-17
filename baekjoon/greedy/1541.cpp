#include <iostream>
#include <string>
#include <vector>
using namespace std;

long long int result;
string inp;
vector<string> number; // 숫자와 - 저장
vector<long long int> sum; // - 를 기준으로 나누어 합 계산

// 숫자와 - 정보를 벡터에 저장하는 함수
void split()
{
    string tmp = "";
    for (auto i : inp) {
        if (i >= '0' && i <= '9') {
            tmp += i;
        } else if (i == '+') {
            number.push_back(tmp);
            tmp = "";
        } else if (i == '-') {
            number.push_back(tmp);
            number.push_back("-");
            tmp = "";
        }
    }
    number.push_back(tmp);
}

int main()
{
    // 입력 처리
    cin >> inp;

    // 숫자, +, - 분리
    split();

    // - 를 기준으로 나누어 숫자의 합 계산
    result = 0;
    for (auto num : number) {
        if (num == "-") {
            sum.push_back(result);
            result = 0;
        } else {
            result += stoll(num);
        }
    }
    sum.push_back(result);

    // 최솟값 계산
    result = sum[0];
    for (int i=1; i<sum.size(); i++) {
        result -= sum[i];
    }

    cout << result << "\n";
}