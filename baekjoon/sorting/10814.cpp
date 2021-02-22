#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Member {
    int age;     // 나이
    string name; // 이름
    int index;   // 가입한 순서
};


int n;
vector<Member> members;

bool compare(Member a, Member b)
{
    if (a.age == b.age) {
        return a.index < b.index;
    }
    return a.age < b.age;
}

int main()
{
    // cin 속도 up
    ios::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    // 입력 처리
    cin >> n;
    for (int i=0; i<n; i++) {
        int age; string name;
        cin >> age >> name;
        members.push_back({age, name, i});
    }

    // 정렬
    sort(members.begin(), members.end(), compare);

    // 출력
    for (auto mem : members) {
        cout << mem.age << " " << mem.name  << "\n";
    }
}