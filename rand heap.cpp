#include <iostream>
#include <cstdlib>
#include <time.h>

#define heap_size 256
#define array_size 100

using namespace std;

int heap[heap_size];
int heap_count = 0;

class heapfunc{
	public:
		void swap(int *a,int *b)
		{
			int temp = *a;
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
			
			int child = heap_count;
			int parent = child/2;
			
			while(child >1 && heap[parent] < heap[child])
			{
				swap(&heap[parent], &heap[child]);
				child = parent;
				parent = child/2;
			}
		}
		
		int pop()
		{
			int result = heap[1];
			
			swap(&heap[1], &heap[heap_count]);
			heap_count--;
			
			int parent = 1;
			int child = parent * 2;
			
			if(child+1 <=heap_count)
			{
				child = (heap[child] > heap[child +1]) ? child : child +1; 
			}
			
			while(child <=heap_count && heap[parent] < heap[child])
			{
				swap(&heap[parent], &heap[child]);
				
				parent = child;
				child = child * 2;
				if(child +1 <=heap_count)
				{
					child = (heap[child] > heap[child+1]) ? child : child + 1;
				}
			}
			
			return result;
		}
};

int main()
{
	heapfunc h;
	int arr[array_size];
	
	srand(time(NULL));
	
	for(int i =0; i<array_size; i++)
	{
		arr[i] = rand() % 300 + 1;
	}
	
	for(int i =0; i<array_size; i++)
	{
		h.push(arr[i]);
	}
	
	for(int i = 0; i<array_size; i++)
	{
		cout << h.pop()<< ' ';
	}
	cout<<endl;
	
	return 0;
}
