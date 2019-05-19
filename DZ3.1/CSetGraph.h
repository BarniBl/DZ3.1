#pragma once
//#include "HashTable.h"
#include "IGraph.h"
#include <unordered_set>

class CSetGraph :public IGraph{
public:
	CSetGraph(int count);
	CSetGraph(const IGraph& graph);

	~CSetGraph();
	virtual void AddEdge(int from, int to) override;
	virtual int VerticesCount() const override;

	virtual std::vector<int> GetNextVertices(int vertex) const override;
	virtual std::vector<int> GetPrevVertices(int vertex) const override;

private:
	std::vector<std::unordered_set<int>> adjacencyHashTables;
};


