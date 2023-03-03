/*
	AUTHOR:			ADVAY AGGARWAL
*/

#include<bits/stdc++.h>
using namespace std;
#define mod		1000000007 //1e9+7	ans%mod
#define ll 	long long int
#define test_cases(x)	int x; cin>>x; while(x--)
#define vi vector<int>
#define setbits(x)      __builtin_popcountll(x)
#define endl "\n"
#define pii pair<int,int>
#define vvi vector<vi>

template <typename Type>
istream &operator>>(istream &in, vector<Type> &vec) {
	int n = vec.size();
	for (int i = 0; i < n; i++)	in >> vec[i];
	return in;
}

template <typename Type>
ostream &operator<<(ostream &out, vector<Type> &vec) {
	for (auto &val : vec)	out << val << " ";
	return out;
}

void starter()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

/*
	In Complete Binary Tree, leaf node lies from index (n/2 + 1) to n, considering index starts from 1
*/

class Heap {
public:
	int arr[100];
	int size;

	Heap()	//constructor
	{
		arr[0] = -1;
		size = 0;
	}

	void insert(int val) //O(logn)
	{
		size++;
		arr[size] = val;

		int index = size;
		while (index > 1)
		{
			int parent = index / 2;
			if (arr[parent] < arr[index])
			{
				swap(arr[parent], arr[index]);
				index = parent;
			}

			else break;
		}
	}

	void deleteFromHeap() //deletes the root node only - O(logn)
	{
		if (size < 1)
		{
			cout << "Heap is already empty";
			return;
		}

		arr[1] = arr[size];
		size--;

		//take root node to its correct position
		int i = 1;
		while (i <= size)
		{
			int leftIndex = 2 * i, rightIndex = 2 * i + 1;
			int temp = i;

			if (leftIndex <= size && arr[temp] < arr[leftIndex])
			{
				temp = leftIndex;
			}

			if (rightIndex <= size && arr[temp] < arr[rightIndex])
			{
				temp = rightIndex;
			}

			if (arr[temp] > arr[i]) //or temp!=i
			{
				swap(arr[temp], arr[i]); //swapping arr[i] with max(leftChild, rightChild)
				i = temp;
			}

			else return;
		}
	}

	void print()
	{
		for (int i = 1; i <= size; i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
	}
};

void heapify(int a[], int n, int i) //O(logn)
{
	int largest = i;
	int left = 2 * i, right = 2 * i + 1;

	if (left <= n && a[left] > a[largest])	largest = left;
	if (right <= n && a[right] > a[largest])	largest = right;

	if (largest != i)
	{
		swap(a[largest], a[i]);
		heapify(a, n, largest);
	}
}

void heapSort(int a[], int n) //O(nlogn)
{
	int size = n;
	while (size > 1)
	{
		swap(a[size], a[1]); //now last element will be the largest
		size--;
		heapify(a, size, 1);
	}
}

int main()
{
	starter();

	Heap h;
	h.insert(66);
	h.insert(57);
	h.insert(60);
	h.insert(55);
	h.insert(56);
	h.print();
	h.deleteFromHeap();
	h.print();

	int a[6] = { -1, 54, 53, 55, 52, 50};
	int n = sizeof(a) / sizeof(int) - 1;

	//Heap creation
	for (int i = n / 2 + 1; i > 0; i--) //O(n)
	{
		heapify(a, n, i);
	}

	for (int i = 1; i <= n; i++)	cout << a[i] << " ";
	cout << endl;

	//Heap Sort
	heapSort(a, n);
	for (int i = 1; i <= n; i++)	cout << a[i] << " ";
	cout << endl;
	return 0;
}