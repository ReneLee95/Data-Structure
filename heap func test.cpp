#include <iostream>
#include <algorithm>
#include <time.h>

using namespace std;

int heap[100];
int heap_count = 0;

class heapfunc{
	public:
		int swap(int *a, int *b)
		{
			int temp;
			temp = *a;
			*a = *b;
			*b = temp;
		}
		
		void init()
		{
			heap_count = 0;
		}
		
		int size()
		{
			return heap_count;
		}
		
		void push(int data)
		{
			heap[++heap_count] = data;
			int parent = 1;
			int child = heap_count;
			child = parent;
			parent = child / 2;
			
			while(child > 1&&heap[child] > heap[child + 1])
			{
				swap(&heap[child],&heap[child+1]);
				child = parent;
				parent = child / 2;
			}
			
		}
		
		int pop()
		{
			int result = heap[1];
			
			swap(&heap[1],&heap[heap_count]);
			heap_count--;
			
			int parent = 1;
			int child = parent * 2;
			
			if(child +1 <=heap_count)
			{
				child = (heap[child] > heap[child+1]) ? child : child + 1;
			}
			
			while(child <=heap_count && heap[parent] < heap[child])
			{
				swap(&heap[parent],&heap[child]);
				
				parent = child;
				child = child * 2;
				
				if(child + 1 <= heap_count)
				{
					child = (heap[child] > heap[child + 1]) ? child : child + 1;
				}
			}
			
			return result;
		}
};

int main()
{
	heapfunc h;
	int arr[100];
	
	srand(time(NULL));
	
	for(int i =0; i<50; i++)
	{
		arr[i] = rand() % 100 + 1;
	}
	
	for(int i =0; i<50; i++)
	{
		h.push(arr[i]);
	}
	
	for(int i =0; i<50; i++)
	{
		cout<<h.pop()<<' ';
	}
	
	return 0;
}
