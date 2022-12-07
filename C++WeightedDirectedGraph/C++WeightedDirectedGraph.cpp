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

		graph.AddVertex(1, 0, 1);
		graph.AddVertex(2, 1, 2);
		graph.AddVertex(3, 2, 3);
		graph.AddVertex(4, 3, 0);
		graph.AddVertex(5, 5, 1);
		graph.AddVertex(6, 4, 1);
		graph.AddVertex(7, 3, 1);

		graph.AddEdge(1, 5, 2);
		graph.AddEdge(2, 2, 3);
		graph.AddEdge(3, 3, 7);
		graph.AddEdge(1, 5, 4);
		graph.AddEdge(4, 4, 5);
		graph.AddEdge(5, 1, 6);
		graph.AddEdge(6, 1, 7);

		//graph.RemoveEdge(1, 5, 2);
		//graph.RemoveEdge(4, 4, 5);
		//graph.RemoveVertex(3);

		auto path = graph.AStar(1, 7);
	}
}

#pragma region congaline

		//int height = 3;
		//int width = 3;
		//for (int y = 0; y < height; y++)
		//{
		//	for (int x = 0; x < width; x++)
		//	{
		//		graph.AddVertex(y * height + x, x, y);
		//	}
		//}
		//for (int y = 0; y < height; y++)
		//{
		//	for (int x = 0; x < width - 1; x++)
		//	{
		//		for (int y2 = 0; y2 < height; y2 ++)
		//		{
		//			graph.AddEdge(y * width + x, (y2 + 1) * (x + 1), y2 * width + x + 1);
		//		}
		//	}
		//}
		//graph.RemoveEdge(1, 6, 8);
		//auto path = graph.AStar(0, (height - 1) * height + width - 1);

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
//std::vector<std::shared_ptr<Vertex<int>>> path = graph.AStar(0, 35);


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

#pragma endregion congaline