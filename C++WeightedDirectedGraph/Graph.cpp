
#include "Vertex.cpp"
#include "PriorityQueue.cpp"
#include <deque>
#include <vector>

template <typename T>
bool shouldSwapDijkstra(T a, T b)
{
	return a->Distance < b->Distance;
}

template <typename T>
bool shouldSwapAStar(T a, T b)
{
	return a->FinalDistance < b->FinalDistance;
}

template <typename T>
class Graph
{
private:
	int Heuristic(std::shared_ptr<Vertex<T>> startVertex, std::shared_ptr<Vertex<T>> endVertex)
	{
		return sqrt((endVertex->X - startVertex->X) * (endVertex->X - startVertex->X) + (endVertex->Y - startVertex->Y) * (endVertex->Y - startVertex->Y));
	}

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
		if (!targetVertex)
		{
			return false;
		}
		bool wasContained = false;
		for (int i = 0; i < Vertices.size(); i++)
		{
			if (Vertices[i] != targetVertex)
			{
				for (int x = 0; x < Vertices[i]->Connections.size(); x++)
				{
					if (Vertices[i]->Connections[x]->EndVertex == targetVertex)
					{
						Vertices[i]->Connections.erase(Vertices[i]->Connections.begin() + x/*--*/);
						//Vertices[i]->Connections[x]->EndVertex = nullptr;
						x--;
					}
				}
			}
			else
			{
				Vertices[i]->CleanUp();
				wasContained = true;
				Vertices.erase(Vertices.begin() + i--);
			}
		}
		return wasContained;
	}

	bool RemoveEdge(std::shared_ptr<Vertex<T>> startVertex, int weight, std::shared_ptr<Vertex<T>> endVertex)
	{
		if (!startVertex ||
			!endVertex ||
			!startVertex->ContainsEdge(endVertex))
		{
			return false;
		}
		for (int i = 0; i < startVertex->Connections.size(); i++)
		{
			if (startVertex->Connections[i]->EndVertex == endVertex)
			{
				//startVertex->Connections[i]->EndVertex = nullptr;
				startVertex->Connections.erase(startVertex->Connections.begin() + i);
				//std::vector<int> test = std::vector<int>();
				//test.erase(test.begin() + 0);
				//new std::vector<int>::const_iterator(,);
				return true;
			}
		}
		return false;
	}


public:
	std::vector<std::shared_ptr<Vertex<T>>> Vertices;

	Graph()
		:Vertices{ std::vector<std::shared_ptr<Vertex<T>>>() }
	{

	}

	~Graph()
	{
		while (Vertices.size() > 0)
		{
			//std::shared_ptr<Vertex<T>> current = Vertices.back();
			//while (current->Connections.size() > 0)
			//{
			// 	current->Connections.pop_back();
			//}
			Vertices.back()->Founder = nullptr;
			Vertices.pop_back();
		}
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

	void AddVertex(T Value, int x, int y)
	{
		Vertices.push_back(std::make_shared<Vertex<T>>(Value, x, y));
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

	std::vector<std::shared_ptr<Vertex<T>>> Dijkstras(T startValue, T targetValue)
	{
		std::vector<std::shared_ptr<Vertex<T>>> path = std::vector<std::shared_ptr<Vertex<T>>>();
		std::shared_ptr<Vertex<T>> startVertex = GetVertex(startValue);
		std::shared_ptr<Vertex<T>> targetVertex = GetVertex(targetValue);
		if (!startVertex || !targetVertex)
		{
			return path;
		}
		if (startValue == targetValue)
		{
			path.push_back(startVertex);
			path.push_back(targetVertex);
			return path;
		}

		PriorityQueue<std::shared_ptr<Vertex<T>>> backingQueue(&shouldSwapDijkstra<std::shared_ptr<Vertex<T>>>);

		startVertex->Distance = 0;
		for (int i = 0; i < startVertex->Connections.size(); i++)
		{
			startVertex->Connections[i]->EndVertex->Founder = startVertex;
			startVertex->Connections[i]->EndVertex->Distance = startVertex->Connections[i]->Weight;
			backingQueue.Enqueue(startVertex->Connections[i]->EndVertex);
		}
		startVertex->WasVisited = true;
		std::shared_ptr<Vertex<T>> current;
		while (backingQueue.GetCount() > 0)
		{
			current = backingQueue.Dequeue();
			if (current == targetVertex)
			{
				break;
			}
			for (int i = 0; i < current->Connections.size(); i++)
			{
				if (current->Distance + current->Connections[i]->Weight < current->Connections[i]->EndVertex->Distance)
				{
					current->Connections[i]->EndVertex->Founder = current;
					current->Connections[i]->EndVertex->Distance = current->Connections[i]->Weight + current->Distance;
					current->Connections[i]->EndVertex->WasVisited = false;
					backingQueue.Enqueue(current->Connections[i]->EndVertex);
				}
			}
			current->WasVisited = true;
		}

		std::deque<std::shared_ptr<Vertex<T>>> supportDeque;
		while (current != startVertex)
		{
			supportDeque.push_back(current);
			current = current->Founder;
		}
		path.push_back(current);
		while (supportDeque.size() > 0)
		{
			path.push_back(supportDeque.back());
			supportDeque.pop_back();
		}

		return path;
	}

	std::vector<std::shared_ptr<Vertex<T>>> AStar(T startValue, T targetValue)
	{
		std::vector<std::shared_ptr<Vertex<T>>> path = std::vector<std::shared_ptr<Vertex<T>>>();
		std::shared_ptr<Vertex<T>> startVertex = GetVertex(startValue);
		std::shared_ptr<Vertex<T>> targetVertex = GetVertex(targetValue);
		if (!startVertex || !targetVertex)
		{
			return path;
		}
		if (startValue == targetValue)
		{
			path.push_back(startVertex);
			path.push_back(targetVertex);
			return path;
		}

		PriorityQueue<std::shared_ptr<Vertex<T>>> backingQueue(&shouldSwapAStar<std::shared_ptr<Vertex<T>>>);

		startVertex->Distance = 0;
		startVertex->FinalDistance = Heuristic(startVertex, targetVertex);
		for (int i = 0; i < startVertex->Connections.size(); i++)
		{
			startVertex->Connections[i]->EndVertex->Founder = startVertex;
			startVertex->Connections[i]->EndVertex->Distance = startVertex->Connections[i]->Weight;
			startVertex->Connections[i]->EndVertex->FinalDistance = startVertex->Connections[i]->Weight + Heuristic(startVertex->Connections[i]->EndVertex, targetVertex);
			backingQueue.Enqueue(startVertex->Connections[i]->EndVertex);
		}
		startVertex->WasVisited = true;
		std::shared_ptr<Vertex<T>> current;
		while (backingQueue.GetCount() > 0)
		{
			current = backingQueue.Dequeue();
			if (current == targetVertex)
			{
				break;
			}
			for (int i = 0; i < current->Connections.size(); i++)
			{
				if (current->Distance + current->Connections[i]->Weight < current->Connections[i]->EndVertex->Distance)
				{
					current->Connections[i]->EndVertex->Founder = current;
					current->Connections[i]->EndVertex->Distance = current->Connections[i]->Weight + current->Distance;
					current->Connections[i]->EndVertex->FinalDistance = current->Connections[i]->Weight + current->Distance + Heuristic(current->Connections[i]->EndVertex, targetVertex);
					current->Connections[i]->EndVertex->WasVisited = false;
					backingQueue.Enqueue(current->Connections[i]->EndVertex);
				}
			}
			current->WasVisited = true;
		}
		if (current != targetVertex)
		{
			return std::vector<std::shared_ptr<Vertex<T>>>();
		}

		std::deque<std::shared_ptr<Vertex<T>>> supportDeque;
		while (current != startVertex)
		{
			supportDeque.push_back(current);
			current = current->Founder;
		}
		path.push_back(current);
		while (supportDeque.size() > 0)
		{
			path.push_back(supportDeque.back());
			supportDeque.pop_back();
		}

		return path;
	}
};