// C++WeightedDirectedGraph.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Graph.cpp"
#include "PriorityQueue.cpp"
#include <string>

static bool shouldSwap(int a, int b)
{
	return a > b;
}

int main()
{
	std::string input;
	while (true)
	{
		//std::cin >> input;
		//Graph<int> graph = Graph<int>();
		PriorityQueue<int> queue = PriorityQueue<int>(shouldSwap);
		for (int i = -10; i <= 0; i ++)
		{
			queue.Enqueue(i);
		}
		for (int i = 100; i > 0; i -= 2)
		{
			queue.Enqueue(i);
		}
		for (int i = 99; i > 0; i -= 2)
		{
			queue.Enqueue(i);
		}
		int QueueCount = queue.GetCount();
		for (int i = 0; i < QueueCount; i ++)
		{
			std::cout << queue.Dequeue() << std::endl;
		}
		std::cin >> input;
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
