#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, result = 0;
vector<int> people;

int main()
{
    cin >> n;
    for (int i=0; i<n; i++) {
        int p;
        cin >> p;
        people.push_back(p);
    }

    sort(people.begin(), people.end(), less<int>());
    
    int time = 0;
    for (auto t : people) {
        time += t;
        result += time;
    }
    
    cout << result << "\n";
}