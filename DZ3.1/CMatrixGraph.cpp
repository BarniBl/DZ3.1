#include "pch.h"
#include "CMatrixGraph.h"


CMatrixGraph::CMatrixGraph(int count) {
	adjacencyMatrix.resize(count);
	for (int i = 0; i < count; i++)
		adjacencyMatrix[i].resize(count, 0);
}

CMatrixGraph::CMatrixGraph(const IGraph& graph) {
	adjacencyMatrix.resize(graph.VerticesCount());
	for (int i = 0; i < graph.VerticesCount(); ++i) {
		adjacencyMatrix[i].resize(graph.VerticesCount(), 0);
		for (int j = 0; j < graph.GetNextVertices(i).size(); j++) {
			adjacencyMatrix[i][graph.GetNextVertices(i)[j]] = 1;
		}
	}
}

CMatrixGraph::~CMatrixGraph() {}

void CMatrixGraph::AddEdge(int from, int to) {
	adjacencyMatrix[from][to] = 1;
}

int CMatrixGraph::VerticesCount() const {
	return adjacencyMatrix.size();
}

std::vector<int> CMatrixGraph::GetNextVertices(int vertex) const {
	std::vector<int> next;
	for (int i = 0; i < adjacencyMatrix[vertex].size(); ++i) {
		if (adjacencyMatrix[vertex][i] != 0)
			next.push_back(i);
	}
	return next;
}

std::vector<int> CMatrixGraph::GetPrevVertices(int vertex) const {
	std::vector<int> prev;
	for (int i = 0; i < adjacencyMatrix[vertex].size(); ++i) {
		if (adjacencyMatrix[i][vertex] != 0)
			prev.push_back(i);
	}
	return prev;
}


int CMatrixGraph::GetWeight(int start, int end) const {
	if (start >= 0 && start < VerticesCount() && end >= start && end < VerticesCount())
		return adjacencyMatrix[start][end];
	else
		return -1;
}

