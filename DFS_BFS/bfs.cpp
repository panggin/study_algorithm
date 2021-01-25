// 너비 우선 탐색(Breadth First Search) 구현
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int NODE_CNT = 9; // 0 ~ 8

vector<int> graph[NODE_CNT];
queue<int> nodes;
bool visited[NODE_CNT] = {false, };

void setGraph(vector<int> graph[NODE_CNT]);
void bfs();

int main()
{
    setGraph(graph);
    bfs();
}

// 큐에서 노드 삭제시 현재 노드를 출력하여 탐색 순서 완성
void bfs()
{
    // 1. 시작 노드 큐에 삽입 후 방문 처리
    int start = 1;
    nodes.push(start);
    visited[start] = true;

    // 큐에 값이 남아있지 않을 때까지 반복
    while (!nodes.empty())
    {
        // 2. 큐의 가장 앞쪽 노드를 가져온 후 삭제
        int node = nodes.front();
        nodes.pop();
        cout << node << "-> "; // 출력

        // 3. 가져온 노드의 인접 노드 중 
        //    방문하지 않은 노드를 모두 큐에 삽입 후 방문 처리
        int adjSize = graph[node].size();
        for(int i=0; i<adjSize; i++)
        {
            int adjNode = graph[node][i];
            if (!visited[adjNode])
            {
                nodes.push(adjNode);
                visited[adjNode] = true;
            }
        }
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