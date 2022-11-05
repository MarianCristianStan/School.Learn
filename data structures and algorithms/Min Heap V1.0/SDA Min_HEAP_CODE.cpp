// A C++ program to demonstrate common Binary Heap Operations
#include<iostream>
#include<climits>
using namespace std;

// Prototype of a utility function to swap two integers
void swap(int* x, int* y);

// A class for Min Heap
class MinHeap
{
	int* harr; // pointer to array of elements in heap
	int capacity; // maximum possible size of min heap
	int heap_size; // Current number of elements in min heap
public:
	// Constructor
	MinHeap(int capacity);

	// to heapify a subtree with the root at given index
	void MinHeapify(int);

	int parent(int i) { return (i - 1) / 2; }

	// to get index of left child of node at index i
	int left(int i) { return (2 * i + 1); }

	// to get index of right child of node at index i
	int right(int i) { return (2 * i + 2); }

	// to extract the root which is the minimum element
	int extractMin();

	// Decreases key value of key at index i to new_val
	void decreaseKey(int i, int new_val);

	// Returns the minimum key (key at root) from min heap
	int getMin() { return harr[0]; }

	// Deletes a key stored at index i
	void deleteKey(int i);

	// Inserts a new key 'k'
	void insertKey(int k);

	void displayHeap();
	void displayAllChild();
};

// Constructor: Builds a heap from a given array a[] of given size
MinHeap::MinHeap(int cap)
{
	heap_size = 0;
	capacity = cap;
	harr = new int[cap];
}

// Inserts a new key 'k'
void MinHeap::insertKey(int k)
{
	if (heap_size == capacity)
	{
		cout << "\nOverflow: Could not insertKey\n";
		return;
	}

	// First insert the new key at the end
	heap_size++;
	int i = heap_size - 1;
	harr[i] = k;

	// Fix the min heap property if it is violated
	while (i != 0 && harr[parent(i)] > harr[i])   //condtie min*
	{
		swap(&harr[i], &harr[parent(i)]);
		i = parent(i);
	}
}

// Decreases value of key at index 'i' to new_val.  It is assumed that
// new_val is smaller than harr[i].
void MinHeap::decreaseKey(int i, int new_val)
{
	harr[i] = new_val;
	while (i != 0 && harr[parent(i)] > harr[i]) // conditie min*
	{
		swap(&harr[i], &harr[parent(i)]);
		i = parent(i);
	}
}

// Method to remove minimum element (or root) from min heap
int MinHeap::extractMin()
{
	if (heap_size <= 0)
		return INT_MAX;
	if (heap_size == 1)
	{
		heap_size--;
		return harr[0];
	}

	// Store the minimum value, and remove it from heap
	int root = harr[0];
	harr[0] = harr[heap_size - 1];
	heap_size--;
	MinHeapify(0);

	return root;
}


// This function deletes key at index i. It first reduced value to minus
// infinite, then calls extractMin()
void MinHeap::deleteKey(int i)
{
	decreaseKey(i, INT_MIN);
	extractMin();
}

// A recursive method to heapify a subtree with the root at given index
// This method assumes that the subtrees are already heapified
void MinHeap::MinHeapify(int i)
{
	int l = left(i);
	int r = right(i);
	int smallest = i;
	if (l < heap_size && harr[l] < harr[i]) // conditie min*
		smallest = l;
	if (r < heap_size && harr[r] < harr[smallest]) // conditie min*
		smallest = r;
	if (smallest != i)
	{
		swap(&harr[i], &harr[smallest]);
		MinHeapify(smallest);
	}
}



// A utility function to swap two elements
void swap(int* x, int* y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

void MinHeap::displayHeap()
{
	for (int i = 0; i < heap_size; i++)
	{
		cout << harr[i] << ' ';
	}
}

void MinHeap::displayAllChild()
{
	int l;
	int r;
	for (int i = 0; i < heap_size; i++)
	{
		l = left(i);
		r = right(i);
		cout << "Node:" << harr[i] << endl;
		
		if(l<heap_size) cout << "Left Child:" << harr[l] << endl;
		if (r < heap_size)cout << "Right Child: " << harr[r] << endl;

		cout << endl;
	}



}

// Driver program to test above functions
int main()
{
	MinHeap h(11);
	
	/*
	h.insertKey(3);
	h.insertKey(2);
	//h.deleteKey(1);
	h.insertKey(15);
	h.insertKey(5);
	h.insertKey(4);
	h.insertKey(45);
	h.displayHeap();

	cout << "\nDELETE at position 1: ";
	h.deleteKey(1);
    h.displayHeap();
	cout << endl;

	cout << "Extract Min ";
	cout << h.extractMin() << " " << endl;
	 h.displayHeap();
	 cout << endl;

	 cout << "MIN: ";
	 cout << h.getMin() << " " << endl;
	 h.displayHeap();
	 cout << endl;

	 cout << "Decrease at position 2 with 1: ";
	 h.decreaseKey(2, 1);
	 h.displayHeap();
	 cout << endl;


	 cout << "MIN: ";
	 cout << h.getMin() << " " << endl;
	 h.displayHeap();
	 cout << endl;
	 */

	bool menu = true;

	while (menu)
	{
		int key;
		cout << "\n1.Insert key \n2.Delete key \n3.Display MinHeap \n4.Display every node's child(1 or 2) \n0.Exit\n";
		cin >> key;
		switch (key)
		{
			
		case 1: {
			cout << "Insert the value of key:";
			int value;
			cin >> value;
			h.insertKey(value);
			cout << "Insert successfully!\n";
			break;
		}

		case 2: {
			cout << "Insert position of element  to delete:";
			int pos;
			cin >> pos;
			h.deleteKey(pos);
			cout << "Delete successfully!\n";
			break;
		}



		case 3:
		{
			h.displayHeap();
			break;
		}

		case 4:
		{
			h.displayAllChild();


			break;
		}
		case 0:
		{
			menu = false;
			cout <<"EXITING!";
			break;
		}


		default:
		{
			cout << "Invalid Option!";
			break;
		}
		}

	}



	return 0;
}