#pragma once
#include "IGraph.h"

struct Edge {
	int From;
	int To;
};

class CArcGraph :public IGraph{
public:
	CArcGraph(int count);
	CArcGraph(const IGraph& graph);
	~CArcGraph();

	virtual void AddEdge(int from, int to) override;
	virtual int VerticesCount() const override;

	virtual std::vector<int> GetNextVertices(int vertex) const override;
	virtual std::vector<int> GetPrevVertices(int vertex) const override;

private:
	std::vector<Edge> adjacencyEdge;
	int VertCount;
};

