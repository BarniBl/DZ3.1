#pragma once
#include "IGraph.h"
class CMatrixGraph :public IGraph{
public:
	CMatrixGraph(int count);
	CMatrixGraph(const IGraph& graph);
	~CMatrixGraph();

	virtual void AddEdge(int from, int to) override;
	virtual int VerticesCount() const override;

	virtual std::vector<int> GetNextVertices(int vertex) const override;
	virtual std::vector<int> GetPrevVertices(int vertex) const override;

private:
	std::vector<std::vector<int>> adjacencyMatrix;
};

