#include <iostream>
#include <vector>
#include<queue>
//Поиск в ширину
using namespace std;
vector<vector<int> > graph;
int length[30000];
int vis[30000];

int main() {
    freopen("pathbge1.in", "r", stdin);
    freopen("pathbge1.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    graph.resize(n);
    int from, to;
    // cout <<graph.size() << endl;
    for (int i = 0; i < m; i++) {
        cin >> from >> to;
        graph[from - 1].push_back(to - 1);
        graph[to - 1].push_back(from - 1);
    }

    for (int i = 1; i < n; i++) {
        length[i] = -1;
        vis[i] = 0;
    }

    queue<int> path;
    path.push(0);
    vis[0] = 1;
    length[0] = 0;
    while (path.size() != 0) {
        int now = path.front();
        path.pop();
        for (int i = 0; i < graph[now].size(); i++) {
            int to = graph[now][i];
            if (vis[to] == 0) {
                vis[to] = 1;
                path.push(to);
                length[to] = length[now] + 1;

            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << length[i] << " ";
    }
    cout << endl;
    /*for(int i = 0; i < n; i++){
        int min= length[0];
        int index = 0;
        for(int j = 0; j < n; j++){
            if(min > length[j] && length[j] != -1){
                index = j;
                min = length[j];
            }
        }
        for(int j = 0; j < graph[index].size(); j++){
            if(length[graph[index][j]] == -1){
                length[graph[index][j]] = 1;
            }
            else{

            }

        }
    }*/

    return 0;
}