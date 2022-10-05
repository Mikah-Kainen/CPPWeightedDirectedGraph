
#pragma once
#include <functional>
#include <vector>



template <typename T>
class PriorityQueue
{
private:
	std::vector<T> backingArray;
	bool (*shouldSwap)(T, T);

	int parentIndex(int targetIndex)
	{
		return (targetIndex + 1) / 2 - 1;
	}

	int leftIndex(int targetIndex)
	{
		return (targetIndex + 1) * 2 - 1;
	}

	int rightIndex(int targetIndex)
	{
		return (targetIndex + 1) * 2;
	}

	void swap(int index1, int index2)
	{
		T temp = backingArray[index1];
		backingArray[index1] = backingArray[index2];
		backingArray[index2] = temp;
	}


public:
	PriorityQueue(bool (*shouldSwap)(T, T))
		: shouldSwap{shouldSwap}
	{
	}

	~PriorityQueue()
	{
		backingArray = std::vector<T>();
	}

	void Enqueue(T newValue)
	{
		backingArray.push_back(newValue);

		int current = backingArray.size() - 1;
		int parent = parentIndex(current);
		while (parent >= 0 && shouldSwap(backingArray[current], backingArray[parent]))
		{
			swap(current, parent);
			current = parent;
			parent = parentIndex(current);
		}
	}

	T Dequeue()
	{
		T returnValue = backingArray[0];
		backingArray[0] = backingArray[backingArray.size() - 1];
		backingArray.pop_back();

		int previousCurrent = -1;
		int current = 0;
		int left = leftIndex(current);
		int right = rightIndex(current);
		while (previousCurrent != current && right < backingArray.size())
		{
			previousCurrent = current;
			if (shouldSwap(backingArray[left], backingArray[right]))
			{
				if(shouldSwap(backingArray[left], backingArray[current]))
				{
					swap(left, current);
					current = left;
				}
			}
			else if(shouldSwap(backingArray[right], backingArray[current]))
			{
				swap(right, current);
				current = right;
			}
			left = leftIndex(current);
			right = rightIndex(current);
		}
		if (left < backingArray.size() && shouldSwap(backingArray[left], backingArray[current]))
		{
			swap(left, current);
		}

		return returnValue;
	}

	int GetCount()
	{
		return backingArray.size();
	}

};
