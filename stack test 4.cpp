#include <iostream>

#define MAX 100

using namespace std;

class stack{
	protected:
		int stacks[MAX];
		int top = 0;
	public:
		int isempty()
		{
			if(top > MAX)
			{
				return true;
			}
			else
			{
				false;
			}
		}
		
		int isfull()
		{
			if(top > MAX)
			{
				return true;
			}
			else
			{
				false;
			}
		}
		
		void push(int value)
		{
			if(isfull()==true)
			{
				cout<<"stack is full"<<endl;
			}
			else
			{
				stacks[top++] = value;
			}
		}
		
		int pop()
		{
			if(isempty()==true)
			{
				cout<<"stack is empty"<<endl;
			}
			else
			{
				return stacks[top--];
			}
		}
};

int main()
{
	stack st;
	st.push(5);
	st.push(3);
	st.push(100);
	st.push(98);
	for(int i =0; i<4; i++)
	{
		cout<<st.pop()<<endl;
	}
}
