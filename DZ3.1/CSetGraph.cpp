#include "pch.h"
#include "CSetGraph.h"

CSetGraph::CSetGraph(int count) {
	adjacencyHashTables.resize(count);
}

CSetGraph::CSetGraph(const IGraph& graph) {
	for (int i = 0; i < graph.VerticesCount(); ++i) {
		for (int j = 0; j < graph.GetNextVertices(i).size(); i++) {
			adjacencyHashTables[i].insert(graph.GetNextVertices(i)[j]);
		}
	}
}

CSetGraph::~CSetGraph() {}

void CSetGraph::AddEdge(int from, int to) {
	adjacencyHashTables[from].insert(to);
}

int CSetGraph::VerticesCount() const {
	return adjacencyHashTables.size();
}

std::vector<int> CSetGraph::GetNextVertices(int vertex) const {
	std::vector<int> next;
	for (int i = 0; i < VerticesCount(); ++i) {
		if (adjacencyHashTables[vertex].find(i)!= adjacencyHashTables[vertex].end())
			next.push_back(i);
	}
	return next;
}

std::vector<int> CSetGraph::GetPrevVertices(int vertex) const {
	std::vector<int> prev;
	for (int i = 0; i < adjacencyHashTables.size(); ++i) {
		if (adjacencyHashTables[i].find(vertex)!= adjacencyHashTables[i].end())
			prev.push_back(i);
	}
	return prev;
}

/*
CSetGraph::CSetGraph(int count){
	adjacencyHashTables.resize(count);
}

CSetGraph::CSetGraph(const IGraph& graph) {
	for (int i = 0; i < graph.VerticesCount(); ++i) {
		for (int j = 0; j < graph.GetNextVertices(i).size(); i++) {
			adjacencyHashTables[i].Add(graph.GetNextVertices(i)[j]);
		}
	}
}

CSetGraph::~CSetGraph() {}

void CSetGraph::AddEdge(int from, int to) {
	adjacencyHashTables[from].Add(to);
}

int CSetGraph::VerticesCount() const {
	return adjacencyHashTables.size();
}

std::vector<int> CSetGraph::GetNextVertices(int vertex) const {
	std::vector<int> next;
	for (int i = 0; i < VerticesCount(); ++i) {
		if (adjacencyHashTables[vertex].Has(i))
			next.push_back(i);
	}
	return next;
}

std::vector<int> CSetGraph::GetPrevVertices(int vertex) const {
	std::vector<int> prev;
	for (int i = 0; i < adjacencyHashTables.size(); ++i) {
		if (adjacencyHashTables[i].Has(vertex))
			prev.push_back(i);
	}
	return prev;
}
*/