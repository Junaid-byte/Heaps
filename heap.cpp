#include<iostream>
#include<conio.h>
#include<vector>
#include<iterator>

using namespace std;

class Heap
{
	private:
	
	vector <int> heap;
	int left(int parent);
	int right(int parent);
	int parent(int child);
	void heapifyup(int index);
	void heapifydown(int index);
	public:

	void InsertHeap(int data);
	void DeleteMinHeap();
	int ExtractMin();
	void Display();
	int Size();

};

int Heap::Size()
{
	return heap.size();
}

void Heap::InsertHeap(int data)
{
	heap.push_back(data);
	heapifyup(heap.size() - 1);
}

void Heap::DeleteMinHeap()
{
	if (heap.size() == 0)
	{
		cout << "Heap is Empty!" << endl;
		return;
	}
	heap[0] = heap.at(heap.size() - 1);
	heap.pop_back();
	heapifydown(0);
	cout << "Heap data is Deleted!" << endl;
}

int Heap::ExtractMin()
{
	if (heap.size() == 0)
	{
		return -1;
	}
	else
	{
		return heap.front();
	}

}


void Heap::Display()
{
	vector<int>::iterator pos = heap.begin();
	cout << "Heap->   ";
	while (pos != heap.end())
	{
		cout << *pos << " ";
		pos++;
	}
	cout << endl;
}

int Heap::left(int parent)
{
	int left = 2 * parent + 1;
	if (left < heap.size())
	{
		return left;
	}
	else
	{
		return -1;
	}
}

int Heap::right(int parent)
{
	int right = 2 * parent + 1;
	if (right < heap.size())
	{
		return right;
	}
	else
	{
		return -1;
	}
}

int Heap::parent(int child)
{
	int parent = (child - 1) / 2;
	if (child == 0)
	{
		return -1;
	}
	else
	{
		return parent;
	}

}

void Heap::heapifyup(int in)
{
	if (in >= 0 && parent(in) >= 0 && heap[parent(in)] > heap[in])
	{
		int temp = heap[in];
		heap[in] = heap[parent(in)];
		heap[parent(in)] = temp;
		heapifyup(parent(in));
	}

}

void Heap::heapifydown(int in)
{
	int child = left(in);
	int child1 = right(in);
	if (child >= 0 && child1 >= 0 && heap[child] > heap[child1])
	{
		child = child1;
	}
	if (child > 0)
	{
		int temp = heap[in];
		heap[in] = heap[child];
		heap[child] = temp;
		heapifydown(child);
	}
}




int main()
{
	Heap h;
	while (1)
	{
		cout << "-----Heap Operations-----" << endl;
		cout << "1) Insert " << endl;
		cout << "2) Delete " << endl;
		cout << "3) Extract Minimum Heap " << endl;
		cout << "4) Display Heap " << endl;
		cout << "5) Exit " << endl;
		int choice, element;
		cout << "Enter your choice:- ";
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			cout << "Enter The Element To Be Inserted In Heap:- ";
			cin >> element;
			h.InsertHeap(element);
			break;
		}
		case 2:
		{
			h.DeleteMinHeap();
			break;

		}
		case 3:
		{
			cout << "Minimum Element:- " << endl;
			if (h.ExtractMin() == -1)
			{
				cout << "Heap Is Empty!" << endl;
			}
			else
			{
				cout << "Minimum Element In Heap:- " << h.ExtractMin() << endl;
				break;
			}

		}
		case 4:
		{
			cout << "Displaying Elements Of Heap:- ";
			h.Display();
			break;
		}

		case 5:
		{
			exit(0);
		}
		default:
		{
			cout << "Sorry You Entered Wrong Choice!" << endl;
		}
		break;
		}
	}
	_getch();
	return 0;

}
/*
Follow me on my github ID https://github.com/Junaid-byte
Credits:-Junaid Jawed
*/
