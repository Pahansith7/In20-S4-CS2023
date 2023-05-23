#include <iostream>
#include <vector>

using namespace std;


typedef vector<vector<int>> Graph;

vector<int> prims(const Graph& graph, int startNode) {
    int numNodes = graph.size();
    vector<bool> visited(numNodes, false);
    vector<int> MST(numNodes, -1);
    vector<int> distance(numNodes, 10);

    distance[startNode] = 0;

    for (int i = 0; i < numNodes - 1; ++i) {
        int u = -1;
        int minDistance = 10;

        for (int j = 0; j < numNodes; ++j) {
            if (!visited[j] && distance[j] < minDistance) {
                minDistance = distance[j];
                u = j;
            }
        }

        if (u == -1)
            break;

        visited[u] = true;

        for (int v = 0; v < numNodes; ++v) {
            if (!visited[v] && graph[u][v] != 0 && graph[u][v] < distance[v]) {
                MST[v] = u;
                distance[v] = graph[u][v];
            }
        }
    }

    return MST;
}

int main() {
        int numNodes=6;
        int numEdges=9;
        Graph graph(numNodes, vector<int>(numNodes, 0));
        graph[0][1] = 3;
        graph[1][0] = 3;
        graph[0][5] = 1;
        graph[5][0] = 1;
        graph[1][2] = 2;
        graph[2][1] = 2;
        graph[1][4] = 10;
        graph[4][1] = 10;
        graph[1][3] = 1;
        graph[3][1] = 1;
        graph[2][3] = 3;
        graph[3][2] = 3;
        graph[2][5] = 5;
        graph[5][2] = 5;
        graph[3][4] = 5;
        graph[4][3] = 5;
        graph[4][5] = 4;
        graph[5][4] = 4;
       
        
       

    vector<int> MST = prims(graph, 0);

    cout << "Minimum Spanning Tree Edges are :\n";
    for (int i = 1; i < numNodes; ++i) {
        cout << MST[i] << " --- " << i << endl;
    }

    return 0;
}
