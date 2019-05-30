// DZ3.1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include "pch.h"
//#include "CArcGraph.h"
//#include "CListGraph.h"
#include "CMatrixGraph.h"
//#include "CSetGraph.h"
#include <queue>

class BFS_Finder {
public:
	BFS_Finder(int n);
	std::vector<int> GetR();
	std::vector<int> r, pi;
	void bfs(int s, const IGraph& graph);
};

BFS_Finder::BFS_Finder(int n) {
	r.resize(n);
	pi.resize(n);
}

void BFS_Finder::bfs(int s, const IGraph& graph) {
	r.assign(r.size(), INT_MAX);
	std::queue<int> q;
	q.push(s); r[s] = 0; pi[s] = -1;
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		for (int i = 0; i < graph.GetNextVertices(v).size(); i++) { //(w : (v, w) ∈ E)
			int w = graph.GetWeight(v, graph.GetNextVertices(v)[i]);
			if (r[w] > r[v] + 1) {
				r[w] = r[v] + 1;
				pi[w] = v;
				q.push(w);
			}
		}

	}
}

std::vector<int> BFS_Finder::GetR() {
	return r;
}
// visit (номер вершины)
void BFS(const IGraph& graph, int vertex, void(*visit)(int)) {
	std::vector<bool> visited(graph.VerticesCount(), false);
	// Тут храним текуший фронт - ?
	std::queue<int> qu;
	// Кладем вершину, с которой наиснаем обход
	qu.push(vertex);
	visited[vertex] = true;

	while (qu.size() != 0) {
		int current = qu.front();
		qu.pop();
		visit(current);
		std::vector<int> adjacentVertices = graph.GetNextVertices(current);
		for (int i = 0; i < adjacentVertices.size(); ++i) {
			if (!visited[adjacentVertices[i]]) {
				qu.push(adjacentVertices[i]);
				visited[adjacentVertices[i]] = true;
			}
		}
	}
}

class FindRoute {
public:
	FindRoute(const IGraph& graph);
	~FindRoute();
	void Dijkstra(int start);
	int NumberMinLenght(int end);
private:
	bool Relax(int first, int second);
	int V;
	int Start;
	std::vector<int> pi;
	std::vector<int> distance;
	const IGraph* Graph;
};

bool FindRoute::Relax(int first, int second) {
	if (distance[second] > distance[first] + Graph->GetWeight(first, second)) {
		distance[second] = distance[first] + Graph->GetWeight(first, second);
		pi[second] = first;
		return true;
	}
	return false;
}

FindRoute::FindRoute(const IGraph& graph) {
	V = graph.VerticesCount();
	pi.resize(V, -1);
	distance.resize(V, INT_MAX);
	Graph = &graph;
}

FindRoute::~FindRoute() {}

void FindRoute::Dijkstra(int start) {
	Start = start;
	distance[start] = 0;
	std::priority_queue<int> queue;
	queue.push(start);
	while (!queue.empty()) {
		int u = queue.top();
		queue.pop();
		for (int i = 0; i < Graph->GetNextVertices(u).size(); i++) {//( (u, v) : ребра из u) {
			if (distance[Graph->GetNextVertices(u)[i]] == INT_MAX) {
				distance[Graph->GetNextVertices(u)[i]] = distance[u] + Graph->GetWeight(u, Graph->GetNextVertices(u)[u]);
				pi[Graph->GetNextVertices(u)[i]] = u;
				queue.push(Graph->GetNextVertices(u)[i]);
			}
			else if (Relax(u, Graph->GetNextVertices(u)[i])) {
				queue.push(Graph->GetNextVertices(u)[i]);//, distance[Graph.GetNextVertices(u)[i]]);
			}
		}
	}
}

int FindRoute::NumberMinLenght(int end) {
	int count = 0;
	if (distance[end] != INT_MAX) {
		while (end != Start) {
			for (int i = 0; i < distance.size(); i++) {
				if (Graph->GetWeight(i, end) != 0) {
					if (distance[end] - Graph->GetWeight(i, end) == distance[i]) {
						end = i;
					}
				}
			}
		}
	}
	return 1;
}

int main() {
	int VNumber;
	std::cin >> VNumber;
	CMatrixGraph MGraph(VNumber);
	int Ver, first, second;
	std::cin >> Ver;
	for (int i = 0; i < Ver; i++) {
		std::cin >> first >> second;
		MGraph.AddEdge(first, second);
	}
	int start, end;
	std::cin >> start >> end;
	BFS_Finder BFS(Ver);
	BFS.bfs(0, MGraph);
	std::vector<int> NewV = BFS.GetR();
	//BFS(MGraph, 0, [](int vertex) { std::cout << vertex << " "; });
	//std::cout << std::endl;
	//FindRoute Find(MGraph);
	//Find.Dijkstra()
	return 0;
}
// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
