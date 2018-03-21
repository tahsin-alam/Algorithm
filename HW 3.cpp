//Tahsin Alam
//CS 220
//HW 3

#include <iostream>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <queue>
#include <stdio.h>
using namespace std;

// look for path from start vertex s to target vertex t. returns true
//if there is any.
bool search( int n, int s, int t, int res_graph[], int parent[] ) {
    // a visited array to mark vertices not visited.
    bool mark_visit[n];
    memset(mark_visit, 0, sizeof(mark_visit));
    // queue to mark start vertex visited. BFS method used for search.
    queue<int> q;
    q.push(s);
    mark_visit[s] =1;
    parent[s] = -1;

    //loop for BFS
    while (!q.empty()) {
        int k = q.front();
        q.pop();
        for (int j = 0; j < n; j++) {
            if (mark_visit[j] == 0 && res_graph[k * n + j] > 0) {
                q.push(j);
                parent[j] = k;
                mark_visit[j] = 1;


            }
        }
    }
return mark_visit[t];

}
// Ford-Fulkerson Algorithm flow
void maximum_flow(int n, int s, int t, int *capacity, int *flow){
    int i,j;
    int res_graph[n][n];
    int parent[n];// array to store path.
    // making residual capacity equal to the capapcity we have.
    for(i=0;i<n;i++)
        for(j=0;j<n;j++) {
            res_graph[i][j] = *(capacity + i * n + j);
            *(flow + i * n + j) = 0; // initial flow is 0.
        }
    int flow_max=0;
    // find exisiting path.
    while(search(n,s,t,&(res_graph[0][0]),&(parent[0]))==1){
        int flow_path=INT_MAX;
        for(j=t; j!=s; j=parent[j]) {
            i = parent[j];
            flow_path=min(flow_path, res_graph[i][j]);
        }
        //updating res capacity.
        for(j=t; j!=s; j=parent[j]) {
            i = parent[j];
            res_graph[i][j] -= flow_path;
            res_graph[j][i] += flow_path;
            *(flow + i * n + j)+=flow_path;
        }
        flow_max+=flow_path;

    }
}
