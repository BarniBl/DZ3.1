#include "pch.h"
#include "CArcGraph.h"

CArcGraph::CArcGraph(int count) {
	VertCount = count;
	adjacencyEdge.resize(0);
}

CArcGraph::CArcGraph(const IGraph& graph) {
	Edge TempEdge;
	for (int i = 0; i < graph.VerticesCount(); ++i) {
		TempEdge.From = i;
		for (int j = 0; j < graph.GetNextVertices(i).size(); j++) {
			TempEdge.To = graph.GetNextVertices(i)[j];
			adjacencyEdge.push_back(TempEdge);
		}
	}
	VertCount = graph.VerticesCount();
}

CArcGraph::~CArcGraph() {}

void CArcGraph::AddEdge(int from, int to) {
	Edge TempEdge;
	TempEdge.From = from;
	TempEdge.To = to;
	adjacencyEdge.push_back(TempEdge);
	//VertCount++;
}

int CArcGraph::VerticesCount() const {
	return VertCount;
}

std::vector<int> CArcGraph::GetNextVertices(int vertex) const {
	std::vector<int> next;
	for (int i = 0; i < adjacencyEdge.size(); ++i) {
		if (adjacencyEdge[i].From == vertex)
			next.push_back(adjacencyEdge[i].To);
	}
	return next;
}

std::vector<int> CArcGraph::GetPrevVertices(int vertex) const {
	std::vector<int> prev;
	for (int i = 0; i < adjacencyEdge.size(); ++i) {
		if (adjacencyEdge[i].To == vertex)
			prev.push_back(adjacencyEdge[i].From);
	}
	return prev;
}
