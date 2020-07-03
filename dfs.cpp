#include <iostream>

using namespace std;

void dfs(int s, int g[5][5], int v, bool *visited) {
    for (int i = 0; i < v; i++) {
        if (g[s][i] && visited[i] == false) {
            visited[i] = true;
            cout << i;
            dfs(i, g, v, visited);
        }
    }
}

int main(int argc, char *argv[]) {
    int g[5][5] = {0};
    
    g[0][1] = g[1][0] = g[1][2] = g[2][1] = g[2][4] = g[4][2] = 1;
    bool visited[100] = {false};
    int v = 5;
    
    for (int i = 0; i < v; i++) {
        if (visited[i] == false) {
            dfs(i, g, v, visited);
            cout << " ";
        }
        // visited[i] = true;
    }
    
    return 0;
}