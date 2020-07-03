#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void bfs(vector<vector<int> >graph, int v) {
    queue<int> q；
    vector<bool> visited(v, false);
    for (int i = 0; i < v; i++) {
        if (visited[i] == false && graph[i][i] != 0) {
            visited[i] = true;
            q.push(i);
            while (!q.empty()) {
                int node = q.front();
                q.pop();
                cout << node + 1 << " ";
                for (int j = 0; j < v; j++) {
                    if (graph[node][j]==1 && visited[j] == false) {
                        q.push(j);
                        visited[j] = true;
                    }
                }
            }
        }
    }
}

int main(int argc, char *argv[]) {
    int v, e;
    cin >> v >> e;
    int from, to;
    vector<vector<int> > graph(v, vector<int>(v, 0));
    for (int i = 0; i < e; i++) {
        cin >> from >> to;
        graph[from-1][to-1] = graph[to-1][from-1] = 1;
        graph[from-1][from-1] = graph[to-1][to-1] = 1;
    }
    bfs(graph, v);
    return 0;
}