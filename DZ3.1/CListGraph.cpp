#include "pch.h"
#include "CListGraph.h"


CListGraph::CListGraph(int count) {
	adjacencyLists.resize(count);
}

CListGraph::CListGraph(const IGraph& graph) {
	for (int i = 0; i < graph.VerticesCount(); ++i) {
		adjacencyLists.push_back(graph.GetNextVertices(i));
	}
}

CListGraph::~CListGraph() {}

void CListGraph::AddEdge(int from, int to) {
	adjacencyLists[from].push_back(to);
}

int CListGraph::VerticesCount() const {
	return adjacencyLists.size();
}

std::vector<int> CListGraph::GetNextVertices(int vertex) const {
	std::vector<int> next;
	for (int i = 0; i < adjacencyLists[vertex].size(); ++i) {
		next.push_back(adjacencyLists[vertex][i]);
	}
	return next;
}

std::vector<int> CListGraph::GetPrevVertices(int vertex) const {
	std::vector<int> prev;
	for (int i = 0; i < adjacencyLists.size(); ++i) {
		for (int j = 0; j < adjacencyLists[i].size(); ++j) {
			if (adjacencyLists[i][j] == vertex) {
				prev.push_back(i);
			}
		}
	}
	return prev;
}
