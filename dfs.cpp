#include <stdio.h>
#include <stdlib.h>

int index = 0;
int vertex = 0;

typedef struct Stack {
	struct Stack* next;
	struct Stack* prev;
	int data;
}Stack;

typedef struct Tree {
	struct Stack* head;
	struct Stack* tail;
	int count;
}Tree;

Tree *init() {
	Tree* tree = (Tree *)malloc(sizeof(Tree));
	if(tree ==NULL) {
		printf("err\n");
	}
	else {
		tree->tail = NULL;
		tree->head = NULL;
		tree->count = 0;
		return tree;
	}
}

void push(Tree *tree,int index, int data) {
	Stack *stack = (Stack *)malloc(sizeof(Stack));
	Stack *preStack = tree->tail;
	stack->data = data;
	
	if(tree->count == 0) {
		stack->next = stack;
		stack->prev = stack;
		tree->tail = stack;
		tree->head = stack;
		tree->count++;
	}
	else {
		stack->next = preStack->next;
		stack->prev = preStack;
		preStack->next = stack;
		stack->next->prev = stack;
		
		if(tree->count == index) {
			tree->tail = stack;
		}
		tree->count++;
		index++;
	}
}

int backStack(Tree *tree) {
	Stack *curStack = tree->tail;
	return curStack->next->data;
}

void pop(Tree *tree) {
	Stack *curStack = tree->tail;
	Stack *preStack = tree->tail;
	
	if(tree->count == 0) {
		printf("err\n");
		return;
	}
	else {
		for(int i =0; i<tree->count; i++) {
			preStack = preStack->next;
		}
		curStack = preStack->next;
		preStack->next = curStack->next;
		curStack->next->prev = tree->tail;
		free(curStack);
		tree->count--;
		index--;
	}
}

void print(Tree *tree) {
	int i;
	Stack *curStack;
	if(tree->count == 0) {
		printf("none\n");
		return;
	}
	else {
		for(i = 0,curStack = tree->tail; i<tree->count; i++,curStack = curStack->prev) {
			printf("%d ",curStack->data);
		}
	}
}

void DFS(Tree *tree,Stack *stack,int **map,int *visit,int start) {
	if(tree->count!=0) {
		pop(tree);
	}
	else {
		visit[start] = 1;
		printf("%d ",start);
		push(tree,index,start);
	}
	printf("stack : ");
	print(tree);
	printf("\n");
	start = backStack(tree);
	for(int i = start; i<=vertex; i++) {
		if(map[start][i] == 1 && visit[i] == 0) {
			visit[i] = 1;
			push(tree,index,i);
			start = backStack(tree);
			printf("%d ",i);
		}
	}

	if(tree->count == 0) return;
	else DFS(tree,stack,map,visit,start);
	
}

int main() {
	Tree *tree = init();
	Stack *stack;
	int number = 0;
	int start = 0;
	int one,two;
	printf("input number : ");
	scanf("%d",&number);
	printf("\n");
	int **map =(int **)malloc(sizeof(int) * number+1);
	for(int i =0; i<=number+1; i++) {
		map[i] = (int *)malloc(sizeof(int) * number);
	}
	int *visit = (int *)malloc(sizeof(int) * number+1);
	
	for(int i = 1; i<=number; i++) {
		printf("input data1 , data2 : ");
		scanf("%d %d",&one,&two);
		printf("\n");
		map[one][two] = map[two][one] = 1;
		visit[i] = 0;
		vertex++;
	}
	printf("input start : ");
	scanf("%d",&start);
	printf("\n");
	
	DFS(tree,stack,map,visit,start);
	
	return 0;
}
