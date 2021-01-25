// 깊이 우선 탐색(Depth First Search) 재귀 함수로 구현
#include <iostream>
#include <vector>
using namespace std;

const int NODE_CNT = 9;

vector<int> graph[NODE_CNT];
bool visited[NODE_CNT] = {false, };

void dfs(int node);
void setGraph(vector<int> graph[NODE_CNT]);

int main()
{
    setGraph(graph);
    int start = 1;
    dfs(start);
}

void dfs(int node)
{
    // 2. 현재 노드 방문 처리
    visited[node] = true;
    cout << node << "-> "; // 탐색 순서에 현재 노드 추가 출력

    // 3. 현재 노드의 인접 노드 중 방문하지 않은 노드 선택
    int adjSize = graph[node].size();
    for (int i=0; i<adjSize; i++) 
    {
        int nextNode = graph[node][i];
        if (!visited[nextNode])
        {
            // 4. 방문하지 않은 인접 노드 발견시
            //    해당 노드를 시작 노드로 하여 재귀 호출
            dfs(nextNode);
        }
        // 인접 리스트를 순차적으로 탐색하게 됨
    }
}

void setGraph(vector<int> graph[NODE_CNT]) 
{
    // node 1
    graph[1].push_back(2);
    graph[1].push_back(3);
    graph[1].push_back(8);
    // node 2
    graph[2].push_back(1);
    graph[2].push_back(7);
    // node 3
    graph[3].push_back(1);
    graph[3].push_back(4);
    graph[3].push_back(5);
    // node 4
    graph[4].push_back(3);
    graph[4].push_back(5);
    // node 5
    graph[5].push_back(3);
    graph[5].push_back(4);
    // node 6
    graph[6].push_back(7);
    // node 7
    graph[7].push_back(2);
    graph[7].push_back(6);
    graph[7].push_back(8);
    // node 8
    graph[8].push_back(1);
    graph[8].push_back(7);
}