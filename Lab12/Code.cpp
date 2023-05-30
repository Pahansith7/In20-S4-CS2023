#include <iostream>
#include <vector>
using namespace std;

const int INF = 9999;
const int n = 6;

vector<vector<int>> g;

vector<int> SSSP(int start) {
    vector<int> d(n, INF);
    vector<bool> visited(n, false);

    d[start] = 0;

    for (int i = 0; i < n - 1; i++) {
        int minimum_distance = INF;
        int minimum_node = -1;

        for (int j = 0; j < n; j++) {
            if (!visited[j] && d[j] < minimum_distance) {
                minimum_distance = d[j];
                minimum_node = j;
            }
        }

        visited[minimum_node] = true;

        for (int j = 0; j < n; j++) {
            if (!visited[j] && g[minimum_node][j] != INF) {
                int new_distance = d[minimum_node] + g[minimum_node][j];
                if (new_distance < d[j]) {
                    d[j] = new_distance;
                }
            }
        }
    }

    return d;
}

int main() {
    g.resize(n, vector<int>(n, INF));

    g[0][1] = 10;
    g[1][0] = 10;
    g[0][4] = 15;
    g[4][0] = 15;
    g[0][5] = 5;
    g[5][0] = 5;
    g[1][2] = 10;
    g[2][1] = 10;
    g[2][3] = 12;
    g[3][2] = 12;
    g[2][4] = 5;
    g[4][2] = 5;
    g[1][3] = 30;
    g[3][1] = 30;
    g[3][5] = 20;
    g[5][3] = 20;

    cout << "Enter the starting node: ";
    int start; 
    cin >> start;

    vector<int> distances = SSSP(start);

    for (int i = 0; i < n; i++) {
        cout << "Distance from " << start << " to " << i << " : ";
        if (distances[i] == INF)
            cout << "can't be reached" << endl;
        else
            cout << distances[i] << endl;
    }

    return 0;
}
