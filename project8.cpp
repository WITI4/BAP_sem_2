#include <iostream>
#include <vector>

class Graph {
private:
    int V;
    std::vector<std::vector<int>> adj;

public:
    Graph(int vertices) : V(vertices), adj(vertices, std::vector<int>(vertices, 0)) {}
    void addEdge(int u, int v) {
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    void printAdjMatrix() {
        std::cout << "Матрица смежности:\n";
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                std::cout << adj[i][j] << " ";
            }
            std::cout << "\n";
        }
    }

    void removeVertex(int v) {
        if (v < 0 || v >= V) {
            std::cout << "Ошибка: вершина " << v << " не существует.\n";
            return;
        }

        adj.erase(adj.begin() + v);
        for (auto& row : adj) {
            row.erase(row.begin() + v);
        }
        V--;
    }

        std::vector<int> shortestPath(int start, int end) {
        std::vector<bool> visited(V, false);
        std::vector<int> parent(V, -1);
        std::vector<int> currentLevel;
        std::vector<int> nextLevel;

        currentLevel.push_back(start);
        visited[start] = true;

        bool found = false;
        while (!currentLevel.empty() && !found) {
            for (int u : currentLevel) {
                if (u == end) {
                    found = true;
                    break;
                }

                for (int v = 0; v < V; v++) {
                    if (adj[u][v] && !visited[v]) {
                        visited[v] = true;
                        parent[v] = u;
                        nextLevel.push_back(v);
                    }
                }
            }

            if (!found) {
                currentLevel = nextLevel;
                nextLevel.clear();
            }
        }

        std::vector<int> path;
        if (!visited[end]) {
            std::cout << "Путь не найден!\n";
            return path;
        }

        for (int v = end; v != -1; v = parent[v]) {
            path.push_back(v);
        }

        for (int i = 0; i < path.size() / 2; i++) {
            std::swap(path[i], path[path.size() - 1 - i]);
        }

        return path;
    }

    void printGraph() {
        std::cout << "Граф (список рёбер):\n";
        for (int i = 0; i < V; i++) {
            for (int j = i + 1; j < V; j++) {
                if (adj[i][j]) {
                    std::cout << i + 1 << " - " << j + 1 << "\n";
                }
            }
        }
    }
};
