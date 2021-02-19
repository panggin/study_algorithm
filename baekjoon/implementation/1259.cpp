#include <iostream>
#include <string>
#include <vector>
using namespace std;

string word = "";

// 입력 숫자가 팰린드롬수인지 확인하여 출력하는 함수
void checkWord()
{
    int i = 0;
    int j = word.length() - 1;
    while (i < j) {
        if (word[i] != word[j]) {
            cout << "no\n";
            return;
        }
        i++;
        j--;
    }
    cout << "yes\n";
}

int main()
{
    while (true) {
        // 입력 처리
        cin >> word;
        if (word == "0")
            return 0;

        // 팰린드롬수 확인
        checkWord();
    }
}