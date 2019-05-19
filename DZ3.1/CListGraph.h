#pragma once
#include "IGraph.h"

class CListGraph :public IGraph{
public:
	CListGraph(int count);
	CListGraph(const IGraph& graph);

	~CListGraph();
	virtual void AddEdge(int from, int to) override;
	virtual int VerticesCount() const override;

	virtual std::vector<int> GetNextVertices(int vertex) const override;
	virtual std::vector<int> GetPrevVertices(int vertex) const override;

private:
	std::vector<std::vector<int>> adjacencyLists;
	//    std::vector<std::vector<int>>
		// Можно пожертвовать памятью и хранить еще и входящие верщины?
};

