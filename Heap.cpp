//Implementation of MaxHeap

#include<iostream>
#include<cstdlib>
using namespace std;

class ManageHeap
{
private:
	int heapSize, arrSize;
	int* heap;
public:
	ManageHeap()
	{
		heapSize = 0;
		arrSize = 0;
	}
	void insertElement(int val)
	{
		if(heapSize != 0)
		{
			heap = (int*)realloc(heap, (heapSize+1) * sizeof(int));
			heap[heapSize] = val;
			int i = heapSize;
			if(heap[i] > heap[(i-1)/2])
			{
				while(i != 0)
				{
					if(heap[i] > heap[(i-1)/2])
					{
						int temp = heap[(i-1)/2];
						heap[(i-1)/2] = heap[i];
						heap[i] = temp;
					}
					i = (i-1)/2;
				}
			}
		}
		else
		{
			heap = (int*)malloc(sizeof(int));
			heap[0] = val;
		}
		++heapSize;
		++arrSize;
		cout << val << " is inserted at heap successfully" << endl;
	}
	void deleteElement()
	{
		if(heapSize != 0)
		{
			int temp;
			temp = heap[0];
			heap[0] = heap[heapSize-1];
			heap[heapSize-1] = temp;
			--heapSize;
			cout << temp << " is deleted successfully" << endl;
			int i = 0;
			while(i*2+1 < heapSize)
			{
				if(i*2+2 < heapSize)
				{
					if(heap[i*2+1] > heap[i*2+2])
					{
						if(heap[i] < heap[i*2+1])
						{
							temp = heap[i];
							heap[i] = heap[i*2+1];
							heap[i*2+1] = temp;
						}
						i = i*2+1;
					}
					else
					{
						if(heap[i] < heap[i*2+2])
						{
							temp = heap[i];
							heap[i] = heap[i*2+2];
							heap[i*2+2] = temp;
						}
						i = i*2+2;
					}
				}
				else
				{
					if(heap[i] < heap[i*2+1])
					{
						temp = heap[i];
						heap[i] = heap[i*2+1];
						heap[i*2+1] = temp;
					}
					i = i*2+1;
				}
			}
			return;
		}
		cout << "Empty heap. Nothing to delete" << endl;
	}
	void display()
	{
		if(heapSize != 0)
		{
			for(int i = 0; i < heapSize; i++)
				cout << heap[i] << " ";
			cout << endl;
			return;
		}
		cout << "Empty heap. Nothing to display" << endl;
	}
	void heapSort()
	{
		if(arrSize != 0 && heapSize == 0)
		{
			cout << "Sorted heap:" << endl;
			for(int i = 0; i < arrSize; i++)
				cout << heap[i] << " ";
			cout << endl;
			free(heap);
			arrSize = 0;
			return;
		}
		else if(arrSize == 0)
		{
			cout << "Warning: Empty heap. Insert and delete elements to sort" << endl;
		}
		else if(heapSize != 0)
		{
			cout << "Warning: Delete all the element to sort" << endl;
		}
	}
};

int main()
{
	int choice, val;
	ManageHeap heap;
	while(1)
	{
		cout << endl;
		cout << "1 -> Insert at heap" << endl;
		cout << "2 -> Delete from heap" << endl;
		cout << "3 -> Display heap" << endl;
		cout << "4 -> Heap sort and free" << endl;
		cout << "0 -> Exit menu" << endl;
		cout << "Enter your choice" << endl;
		cin >> choice;
		switch(choice)
		{
			case 1:
				cout << "Enter the value: ";
				cin >> val;
				heap.insertElement(val);
				break;
			case 2:
				heap.deleteElement();
				break;
			case 3:
				heap.display();
				break;
			case 4:
				heap.heapSort();
				break;
			case 0:
				exit(0);
			default:
				cout << "Error: Wrong entry. Enter again." << endl;
		}
	}
	return 0;
}
