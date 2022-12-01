// C++WeightedDirectedGraph.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Graph.cpp"
#include "Vertex.cpp"
#include "PriorityQueue.cpp"
#include <string>

//static bool shouldSwap(std::shared_ptr<Vertex<int>> a, std::shared_ptr<Vertex<int>> b)
//{
//	return a->Value < b->Value;
//}

int main()
{
	std::string input;
	while (true)
	{
		//std::cin >> input;
		Graph<int> graph = Graph<int>();


		//for (int i = 0; i < 36; i ++)
		//{
		//	graph.AddVertex(i);
		//}
		//for (int a = 1; a < 10; a++)
		//{
		//	graph.AddEdge(0, a, a);
		//	for (int b = 10; b < 20; b ++)
		//	{
		//		graph.AddEdge(a, b, b);
		//		for (int c = 20; c < 30; c ++)
		//		{
		//			graph.AddEdge(b, c, c);
		//			graph.AddEdge(c, 1, 35);
		//		}
		//	}
		//}
		std::vector<std::shared_ptr<Vertex<int>>> path = graph.AStar(0, 35);
	}
}

		//PriorityQueue<std::shared_ptr<Vertex<int>>> queue = PriorityQueue<std::shared_ptr<Vertex<int>>>(shouldSwap);
		//for (int i = -10; i <= 0; i ++)
		//{
		//	queue.Enqueue(std::make_shared<Vertex<int>>(i));
		//}
		//for (int i = 100; i > 0; i -= 2)
		//{
		//	queue.Enqueue(std::make_shared<Vertex<int>>(i));
		//}
		//for (int i = 99; i > 0; i -= 2)
		//{
		//	queue.Enqueue(std::make_shared<Vertex<int>>(i));
		//}
		//int QueueCount = queue.GetCount();
		//std::cout << std::endl;
		//for (int i = 0; i < QueueCount; i ++)
		//{
		//	std::cout << queue.Dequeue()->Value << std::endl;
		//}
		//std::cin >> input;