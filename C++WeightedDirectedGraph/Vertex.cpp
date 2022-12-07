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
	std::weak_ptr<Vertex<T>> EndVertex;

	Edge(int weight, std::shared_ptr<Vertex<T>> vertex)
		:Weight{weight}, EndVertex{std::weak_ptr<Vertex<T>>(vertex)}
	{
	}

	~Edge()
	{
		//EndVertex = nullptr;
	}
};

template <typename T>
class Vertex
{
private:
public:
	std::vector<std::shared_ptr<Edge<T>>> Connections;
	T Value;
	int X;
	int Y;
	float Distance;
	float FinalDistance;
	bool WasVisited;
	std::weak_ptr<Vertex<T>> Founder;

	Vertex(T value, int x, int y)
		:Value{ value }, X{ x }, Y{ y }, Distance{ FLT_MAX }, FinalDistance{ FLT_MAX }, WasVisited { false }, Founder{}
	{
	}

	~Vertex()
	{
	}

	void CleanUp()
	{
		while (Connections.size() > 0)
		{
			Connections.pop_back();
		}
		//Founder = nullptr;
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
			if (Connections[i]->EndVertex.lock() == endVertex)
			{
				return true;
			}
		}
		return false;
	}
};