// 그래프 표현 방식 예제
#include <iostream>
#include <vector>
#include <utility>
#define INF 999999999
using namespace std;


// 그래프 연결 관계
//    0  1   2
// 0  0  7   5
// 1  7  0  무한
// 2  5 무한 0

// 2차원 배열을 이용한 인접 행렬(Adjacency Matrix) 표현
int adjMatrix[3][3] = {
    {0, 7, 5},
    {7, 0, INF},
    {5, INF, 0}
};
// 2차원 배열을 이용한 인접 리스트(Adjacency List) 표현
vector<pair<int,int>> adjList[3];

int main()
{
    // set adjList
    adjList[0].push_back({1,7}); // make_pair(1,7) = {1,7}
    adjList[0].push_back({2,5});

    adjList[1].push_back({0,7});
    
    adjList[2].push_back({2,5});

    // 인접 행렬 그래프 출력
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            cout << adjMatrix[i][j] << " ";
        }
        cout << "\n";
    }
    // 인접 리스트 그래프 출력

    for (int i=0; i<3; i++) {
        for (int j=0; j<adjList[i].size(); j++) {
            cout << "(" << adjList[i][j].first << "," << adjList[i][j].second << ") ";
        }
        cout << "\n";
    }
}