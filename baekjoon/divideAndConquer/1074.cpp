#include <iostream>
using namespace std;

int n, r, c;
int length, section = 0;
int result = 0;

int main()
{
    ios::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    cin >> n >> r >> c;
    length = 1 << n; // map size

    while ((length /= 2) > 0) {
        if (r < length && c < length) {         // section 0
            section = 0;
        } else if (r < length && c >= length) { // section 1
            section = 1;
            c = c - length;
        } else if (r >= length && c < length) { // section 2
            section = 2;
            r = r - length;
        } else {                                // section 3
            section = 3;
            r = r - length;
            c = c - length;
        }
        result += section * length * length;
    }

    cout << result << "\n";
}