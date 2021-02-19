#include <iostream>
#include <algorithm>
using namespace std;

int x, y, w, h;

int main()
{
    cin >> x >> y >> w >> h;
    int dx = min(x, w-x);
    int dy = min(y, h-y);
    int result = min(dx, dy);
    cout << result << "\n";
}