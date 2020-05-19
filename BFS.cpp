#include <stdio.h>
#include <stdlib.h>

int vertex = 0;
int index = 0;

typedef struct Queue {
	int data;
	struct Queue* next;
	struct Queue* prev;
}Queue;

typedef struct List {
	struct Queue* tail;
	int count;
}List;

List *init() {
	List *list = (List *)malloc(sizeof(List));
	if(list == NULL) printf("err\n");
	else {	
		list->tail = NULL;
		list->count = 0;
	}
	
	return list;
}

void enqueue(List *list,int index, int data) {
	Queue *newQueue = (Queue *)malloc(sizeof(Queue));
	Queue *preQueue = list->tail;
	newQueue->data = data;
	
	if(list->count == 0) {
		newQueue->next = newQueue;
		newQueue->prev = newQueue;
		list->tail = newQueue;
		list->count++;
	}
	else {
		
		newQueue->next = preQueue->next;
		newQueue->prev = preQueue;
		preQueue->next = newQueue;
		newQueue->next->prev = newQueue;
		
		if(list->count == index) {
			list->tail = newQueue;
		}
		list->count++;
	}
}

void deleteQueue(List *list) {
	Queue *curQueue = list->tail;
	Queue *preQueue = list->tail;
	
	if(list->count == 0){
		printf("err\n");
		return;
	}
	else {
		for(int i =0; i<list->count; i++) {
			list->tail = list->tail->next;
		}
		curQueue = list->tail->next;
		list->tail->next = curQueue->next;
		curQueue->next->prev = list->tail;
		free(curQueue);
		list->count--;
		index--;
	}
}

int frontQueue(List *list) {
	Queue *curQueue = list->tail;
	return curQueue->next->data;
}

void printQueue(List *list) {
	int i;
	
	if(list->count == 0) {
		printf("none\n");
		return;
	}
	else {
		printf("%d ",list->tail->next->data);
	}
}

void printQ(List *list) {
	int i;
	Queue *curQueue;
	
	if(list->count == 0) {
		printf("none\n");
		return;
	}
	else {
		for(i = 0, curQueue = list->tail->next; i<list->count; i++,curQueue = curQueue->next) {
			printf("%d ",curQueue->data);
		}
	}
}

void BFS(int **map,Queue *queue,List * list,int *visit,int start) {
	visit[start] = 1;
	enqueue(list,index++,start);
	printQueue(list);
	while(list->count != 0) {
		start = frontQueue(list);
		deleteQueue(list);
		for(int i = 1; i<vertex; i++) {
			if(map[start][i] == 1 && visit[i] == 0) {
				visit[i] = 1;
				enqueue(list,index++,i);
				printf("%d ",i);
			}
		}
	}
}

int main() {
	List *list = init();
	Queue *queue;
	int number;
	int data1,data2;
	int start;
	printf("input link data count : ");
	scanf("%d",&number);
	printf("\n");
	int **map = (int **)malloc(sizeof(int *) * number);
	for(int i =0; i<=number; i++) {
		map[i] = (int *)malloc(sizeof(int) * number);
	}
	int *visit = (int *)malloc(sizeof(int) * number);
	
	for(int i =0; i<number; i++) {
		printf("input data1, data2 : ");
		scanf("%d %d",&data1,&data2);
		map[data1][data2] = map[data2][data1] = 1;
		visit[i] = 0;
		vertex++;
	}
	
	printf("input start : ");
	scanf("%d",&start);
	printf("\n");
	BFS(map,queue,list,visit,start);
	
	for(int i =0; i<=number; i++) {
		free(map[i]);
	}
	free(map);
	free(visit);
	return 0;
}
