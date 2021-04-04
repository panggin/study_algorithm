#include <iostream>
#include <queue>
#include <utility>
using namespace std;

const int MAX_SIZE = 50;

int t, m, n, k;
int graph[MAX_SIZE][MAX_SIZE] = {0,};
int x, y, result;

void dfs(int currX, int currY)
{
    graph[currX][currY] = 0;
    if (currX - 1 >= 0 && graph[currX-1][currY] == 1)
        dfs(currX-1, currY); // up
    if (currX + 1 < m && graph[currX+1][currY] == 1)
        dfs(currX+1, currY); // down
    if (currY - 1 >= 0 && graph[currX][currY-1] == 1)
        dfs(currX, currY-1); // left
    if (currY + 1 < n && graph[currX][currY+1] == 1)
        dfs(currX, currY+1); // right
}

int main()
{
    ios::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    cin >> t;
    while(t--) {
        cin >> m >> n >> k;
        // init graph, result
        for (int x=0; x<m; x++) {
            for (int y=0; y<n; y++) {
                graph[x][y] = 0;
            }
        }
        result = 0;
        // set graph
        while(k--) {
            cin >> x >> y;
            graph[x][y] = 1;
        }

        for (int x=0; x<m; x++) {
            for (int y=0; y<n; y++) {
                if (graph[x][y] == 1) {
                    result += 1;
                    dfs(x,y);
                }
            }
        }

        cout << result << "\n"; // 결과 출력

    }
    return 0;
}