#include <iostream>

#define MAX 100

using namespace std;

class Queue{
	protected:
		int front = -1;
		int rear = -1;
		int que[MAX];
	public:
		int isempty()
		{
			if(front ==rear)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		
		int isfull()
		{
			int temp = (rear+front)%MAX;
			if(temp ==front)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		
		void dequeue(int value)
		{
			if(isfull()==true)
			{
				cout<<"Queue is full"<<endl;
			}
			else
			{
				que[rear++] =value;
			}
		}
		
		int deleteq()
		{
			if(isempty())
			{
				cout<<"Queue is empty"<<endl;
			}
			else
			{
				front = (front + 1)%MAX;
				return que[front];
			}
		}
};

int main()
{
	Queue q;
	for(int i =0; i<10; i++)
	{
		q.dequeue(i);
	}
	for(int i =0; i<10; i++)
	{
		cout<<q.deleteq()<<endl;
	}
}
