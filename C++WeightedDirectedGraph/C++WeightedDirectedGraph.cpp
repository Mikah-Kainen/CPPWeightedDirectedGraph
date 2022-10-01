// C++WeightedDirectedGraph.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Graph.cpp"
#include <string>

int main()
{
	std::string input;
	while (true)
	{
		std::cin >> input;
		Graph<int> graph = Graph<int>();
		graph.AddVertex(0);
		graph.AddVertex(1);
		for (int i = 2; i < 1000; i++)
		{
			graph.AddVertex(i);
			graph.AddEdge(i - 1, i, i);
			graph.AddEdge(i - 2, i, i);
		}
		for (int i = 100; i < 200; i ++)
		{
			graph.AddEdge(i, i + 1, i + 1);
			graph.AddEdge(i, i + 2,  i + 2);
		}
		//graph.AddVertex(1);
		//graph.AddVertex(2);
		//graph.AddVertex(3);
		//graph.AddVertex(4);

		//graph.AddEdge(1, 2, 2);
		//graph.AddEdge(1, 3, 3);
		//graph.AddEdge(2, 3, 3);
		//graph.AddEdge(2, 4, 4);
		//graph.AddEdge(3, 4, 4);
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
