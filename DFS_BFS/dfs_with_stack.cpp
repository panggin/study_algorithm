// 깊이 우선 탐색(Depth First Search) 스택 활용하여 구현
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

const int NODE_CNT = 9;

vector<int> graph[NODE_CNT];
stack<int> nodes;
bool visited[NODE_CNT] = {false, };

void dfs();
void setGraph(vector<int> graph[NODE_CNT]);

int main()
{
    setGraph(graph);
    dfs();
}

// 스택에 노드 삽입시 현재 노드를 출력하여 탐색 순서 완성
void dfs()
{
    // 1. 시작 노드 스택에 삽입
    int start = 1;
    nodes.push(start);
    cout << start << "-> "; // 출력

    // 스택에 값이 남아있지 않을 때까지 반복
    while (!nodes.empty()) 
    {
        // 2. 스택 최상단 노드 방문 처리
        int node = nodes.top();
        visited[node] = true;

        // 3. 최상단 노드의 인접 노드 중 방문하지 않은 노드 선택
        int adjSize = graph[node].size();
        int checker = 0;
        while (checker < adjSize) 
        {
            int nextNode = graph[node][checker];
            if (!visited[nextNode]) 
            {
                // 4-1. 방문하지 않은 노드 존재시 스택에 삽입
                nodes.push(nextNode);
                cout << nextNode << "-> "; // 출력
                break;
            }
            checker++;
        }
        // 4-2. 모든 인접 노드를 방문했을 경우 현재 노드 스택에서 삭제
        if (checker == adjSize)
            nodes.pop();
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