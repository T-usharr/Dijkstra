
#include <bits/stdc++.h>//this is enough use it
using namespace std;

vector<int> dijkstras(vector<vector<pair<int,int>>> graph,int start){
    vector<int> dist(graph.size(),INT_MAX);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;


    pq.push({0,start}); //the pair is made of 0 and start that is how pair made
    //pq.push(make_pair(0,start)); //pair can also be made like this
    dist[start]=0;
    while(!pq.empty()){
        int u=pq.top().second; //previous node
        pq.pop();
        for(int i=0;i<graph[u].size();i++){
            int v = graph[u][i].first;//current node
            int weight = graph[u][i].second;//current weight
            if(dist[v]>dist[u]+weight){
                dist[v]=dist[u]+weight;
                pq.push(make_pair(dist[v],v));
            }

        }
    }
    return dist;
}
void addEdge(vector<vector<pair<int,int>>>& graph, int u, int v, int w)
{
    graph[u].push_back(make_pair(v, w));
    graph[v].push_back(make_pair(u, w));
}
int main()
{
    // pair of node, weight
    vector<vector<pair<int,int>>> graph(5, vector<pair<int,int>>(5));

    addEdge(graph, 0, 1, 2);
    addEdge(graph, 0, 4, 6);
    addEdge(graph, 1, 2, 3);
    addEdge(graph, 2, 3, 4);
    addEdge(graph, 4, 3, 5);
    // addEdge(graph, 4, 1, -5);
    // addEdge(graph, 2, 8, 2);
    // addEdge(graph, 2, 5, 4);
    // addEdge(graph, 3, 4, 9);
    // addEdge(graph, 3, 5, 14);
    // addEdge(graph, 4, 5, 10);
    // addEdge(graph, 5, 6, 2);
    // addEdge(graph, 6, 7, 1);
    // addEdge(graph, 6, 8, 6);
    // addEdge(graph, 7, 8, 7);

    vector<int> dist = dijkstras(graph, 0);
    // Print shortest distances stored in dist[]
    cout << "Vertex      Distance from Source" << endl;
    for (int i = 0; i < 5; ++i)
        cout << i << "\t" << dist[i] << endl;
  
    return 0;
}
