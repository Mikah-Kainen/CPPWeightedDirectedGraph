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
		for (int i = 0; i < 35; i ++)
		{
			graph.AddVertex(i);
		}
		for (int a = 1; a < 10; a++)
		{
			graph.AddEdge(0, a, a);
			for (int b = 11; b < 20; b ++)
			{
				graph.AddEdge(a, a, b);
				for (int c = 21; c < 30; c ++)
				{
					graph.AddEdge(b, b, c);
					graph.AddEdge(c, 1, 35);
				}
			}
		}
		std::vector<std::shared_ptr<Vertex<int>>> path = graph.GetPath(0, 35);
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
	}
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
