// DZ3.1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include "pch.h"
#include "CArcGraph.h"
#include "CListGraph.h"
#include "CMatrixGraph.h"
#include "CSetGraph.h"

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

int main() {
	CListGraph LGraph(5);
	LGraph.AddEdge(0, 1);
	LGraph.AddEdge(0, 2);
	LGraph.AddEdge(0, 3);
	LGraph.AddEdge(1, 4);
	LGraph.AddEdge(2, 1);
	LGraph.AddEdge(2, 3);
	LGraph.AddEdge(2, 4);
	LGraph.AddEdge(4, 3);
	BFS(LGraph, 0, [](int vertex) { std::cout << vertex << " "; });
	std::cout << std::endl;
	CMatrixGraph MGraph(5);
	MGraph.AddEdge(0, 1);
	MGraph.AddEdge(0, 2);
	MGraph.AddEdge(0, 3);
	MGraph.AddEdge(1, 4);
	MGraph.AddEdge(2, 1);
	MGraph.AddEdge(2, 3);
	MGraph.AddEdge(2, 4);
	MGraph.AddEdge(4, 3);
	BFS(MGraph, 0, [](int vertex) { std::cout << vertex << " "; });
	std::cout << std::endl;
	CArcGraph AGraph(5);
	AGraph.AddEdge(0, 1);
	AGraph.AddEdge(0, 2);
	AGraph.AddEdge(0, 3);
	AGraph.AddEdge(1, 4);
	AGraph.AddEdge(2, 1);
	AGraph.AddEdge(2, 3);
	AGraph.AddEdge(2, 4);
	AGraph.AddEdge(4, 3);
	BFS(AGraph, 0, [](int vertex) { std::cout << vertex << " "; });
	std::cout << std::endl;
	CSetGraph SGraph(5);
	SGraph.AddEdge(0, 1);
	SGraph.AddEdge(0, 2);
	SGraph.AddEdge(0, 3);
	SGraph.AddEdge(1, 4);
	SGraph.AddEdge(2, 1);
	SGraph.AddEdge(2, 3);
	SGraph.AddEdge(2, 4);
	SGraph.AddEdge(4, 3);
	BFS(SGraph, 0, [](int vertex) { std::cout << vertex << " "; });
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
