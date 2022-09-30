
#include "Vertex.cpp"
#include <vector>

template <typename T>
class Graph
{
private:

	bool AddEdge(std::shared_ptr<Vertex<T>> startVertex, int weight, std::shared_ptr<Vertex<T>> endVertex)
	{
		if (!startVertex
			|| !endVertex)
		{
			return false;
		}

		return startVertex->AddEdge(weight, endVertex);
	}

	bool Contains(std::shared_ptr<Vertex<T>> targetVertex)
	{
		if (!targetVertex)
		{
			return false;
		}
		for (int i = 0; i < Vertices.size(); i++)
		{
			if (Vertices[i] == targetVertex)
			{
				return true;
			}
		}
		return false;
	}

	bool RemoveVertex(std::shared_ptr<Vertex<T>> targetVertex)
	{
		if (!Contains(targetVertex))
		{
			return false;
		}
		for (int i = 0; i < targetVertex->Edges.size(); i++)
		{
			targetVertex->Edges[i] = nullptr;
		}
		for (int i = 0; i < Vertices.size(); i++)
		{
			if (Vertices[i] == targetVertex)
			{
				Vertices[i] == nullptr;
			}
			for (int x = 0; x < Vertices[i]->Edges.size(); x++)
			{
				if (Vertices[i]->Edges[x]->EndVertex == targetVertex)
				{
					Vertices[i]->Edges[x]->EndVertex = nullptr;
				}
			}
		}
		return true;
	}

	bool RemoveEdge(std::shared_ptr<Vertex<T>> startVertex, std::shared_ptr<Vertex<T>> endVertex)
	{
		if (!startVertex ||
			!endVertex || 
			!startVertex->ContainsEdge(endVertex))
		{
			return false;
		}
		for (int i = 0; i < startVertex->Edges.size(); i++)
		{
			if (startVertex->Edges[i]->EndVertex == endVertex)
			{
				startVertex->Edges[i]->EndVertex = nullptr;
				return true;
			}
		}
		return false;
	}

public:
	std::vector<std::shared_ptr<Vertex<T>>> Vertices;

	Graph()
		:Vertices{std::vector<std::shared_ptr<Vertex<T>>>()}
	{

	}

	~Graph()
	{
		Vertices = std::vector<std::shared_ptr<Vertex<T>>>();
	}

	int GetCount()
	{
		return Vertices.size();
	}

	std::shared_ptr<Vertex<T>> GetVertex(T targetValue)
	{
		for (int i = 0; i < Vertices.size(); i++)
		{
			if (Vertices[i]->Value == targetValue)
			{
				return Vertices[i];
			}
		}
		return nullptr;
	}

	void AddVertex(T Value)
	{
		Vertices.push_back(std::make_shared<Vertex<T>>(Value));
	}

	bool AddEdge(T startVertexValue, int weight, T endVertexValue)
	{
		return AddEdge(GetVertex(startVertexValue), weight, GetVertex(endVertexValue));
	}

	bool RemoveVertex(T value)
	{
		return RemoveVertex(GetVertex(value));
	}

	bool RemoveEdge(T startVertexValue, int weight, T endVertexValue)
	{
		return RemoveEdge(GetVertex(startVertexValue), weight, GetVertex(endVertexValue));
	}
};