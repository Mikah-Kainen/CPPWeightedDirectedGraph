#pragma once
#include <vector>
#include <memory>

template<typename T>
class Vertex;

template <typename T>
class Edge
{
private:
public:
	int Weight;
	std::shared_ptr<Vertex<T>> EndVertex;

	Edge(int weight, std::shared_ptr<Vertex<T>> vertex)
		:Weight{weight}, EndVertex{vertex}
	{
	}

	~Edge()
	{
		EndVertex = nullptr;
	}
};

template <typename T>
class Vertex
{
private:
public:
	std::vector<std::shared_ptr<Edge<T>>> Connections;
	T Value;
	int Distance;
	bool WasVisited;
	std::shared_ptr<Vertex<T>> Founder;

	Vertex(T value)
		:Value{ value }, Distance{ INT32_MAX }, WasVisited{ false }, Founder{ nullptr }
	{

	}

	~Vertex()
	{
		Connections = std::vector<std::shared_ptr<Edge<T>>>();
	}

	bool AddEdge(int weight, std::shared_ptr<Vertex<T>> endVertex)
	{
		if (!ContainsEdge(endVertex))
		{
			Connections.push_back(std::make_shared<Edge<T>>(weight, endVertex));
			return true;
		}
		return false;
	}


	bool ContainsEdge(std::shared_ptr<Vertex<T>> endVertex)
	{
		for (int i = 0; i < Connections.size(); i ++)
		{
			if (Connections[i]->EndVertex == endVertex)
			{
				return true;
			}
		}
		return false;
	}
};