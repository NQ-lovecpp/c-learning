//#include <iostream>
//#include <list>
//#include <queue>
//#include <stack>
//#include <vector>
//
//using namespace std;
//
//class Graph {
//private:
//    int V; // 顶点数
//    list<int>* adj; // 邻接表
//
//    void DFSUtil(int v, vector<bool>& visited) {
//        visited[v] = true;
//        cout << v << " ";
//
//        for (auto i = adj[v].begin(); i != adj[v].end(); ++i)
//            if (!visited[*i])
//                DFSUtil(*i, visited);
//    }
//
//public:
//    Graph(int V) {
//        this->V = V;
//        adj = new list<int>[V];
//    }
//
//    ~Graph() {
//        delete[] adj;
//    }
//
//    void addEdge(int v, int w) {
//        adj[v].push_back(w); // 添加边到无向图
//        adj[w].push_back(v); // 因为是无向图
//    }
//
//    void BFS(int s) {
//        vector<bool> visited(V, false);
//        queue<int> queue;
//
//        visited[s] = true;
//        queue.push(s);
//
//        while (!queue.empty()) {
//            s = queue.front();
//            cout << s << " ";
//            queue.pop();
//
//            for (auto i = adj[s].begin(); i != adj[s].end(); ++i) {
//                if (!visited[*i]) {
//                    visited[*i] = true;
//                    queue.push(*i);
//                }
//            }
//        }
//    }
//
//    void DFS(int v) {
//        vector<bool> visited(V, false);
//        DFSUtil(v, visited);
//    }
//
//    // 其他方法（如拓扑排序、最小生成树等）可以在此基础上继续添加
//};
//
//int main() {
//    Graph g(4);
//    g.addEdge(0, 1);
//    g.addEdge(0, 2);
//    g.addEdge(1, 2);
//    g.addEdge(2, 3);
//
//    cout << "BFS (starting from vertex 2): ";
//    g.BFS(2);
//
//    cout << "\nDFS (starting from vertex 2): ";
//    g.DFS(2);
//
//    return 0;
//}


#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <climits>
#include <set>

using namespace std;

class Graph 
{
private:
    int V;
    list<pair<int, int>>* adj; // 存储边和权重

    void DFSUtil(int v, vector<bool>& visited, stack<int>& Stack) 
    {
        visited[v] = true;

        for (auto i = adj[v].begin(); i != adj[v].end(); ++i)
            if (!visited[i->first])
                DFSUtil(i->first, visited, Stack);

        Stack.push(v);
    }

public:
    Graph(int V) 
    {
        this->V = V;
        adj = new list<pair<int, int>>[V];
    }

    ~Graph() 
    {
        delete[] adj;
    }

    void addEdge(int v, int w, int weight = 0) 
    {
        adj[v].push_back(make_pair(w, weight));
    }

    // 拓扑排序
    void topologicalSort() 
    {
        stack<int> Stack;
        vector<bool> visited(V, false);

        for (int i = 0; i < V; i++)
            if (visited[i] == false)
                DFSUtil(i, visited, Stack);

        while (!Stack.empty()) 
        {
            cout << Stack.top() << " ";
            Stack.pop();
        }
    }

    // 最小生成树 - Prim算法
    void primMST() 
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        int src = 0; // 从顶点0开始
        vector<int> key(V, INT_MAX);
        vector<int> parent(V, -1);
        vector<bool> inMST(V, false);

        pq.push(make_pair(0, src));
        key[src] = 0;

        while (!pq.empty()) 
        {
            int u = pq.top().second;
            pq.pop();

            inMST[u] = true;

            for (auto i = adj[u].begin(); i != adj[u].end(); ++i) \
            {
                int v = (*i).first;
                int weight = (*i).second;

                if (inMST[v] == false && key[v] > weight) 
                {
                    key[v] = weight;
                    pq.push(make_pair(key[v], v));
                    parent[v] = u;
                }
            }
        }

        for (int i = 1; i < V; ++i)
            cout << parent[i] << " - " << i << endl;
    }

    
};

int main() {
    // 示例用图
    Graph g(6);
    g.addEdge(0, 1, 5);
    g.addEdge(0, 2, 3);
    g.addEdge(1, 3, 6);
    g.addEdge(1, 2, 2);
    g.addEdge(2, 4, 4);
    g.addEdge(2, 5, 2);
    g.addEdge(2, 3, 7);
    g.addEdge(3, 4, -1);
    g.addEdge(4, 5, -2);

    cout << "拓扑排序: ";
    g.topologicalSort();

    cout << "\n最小生成树（Prim算法）: \n";
    g.primMST();

    return 0;
}
