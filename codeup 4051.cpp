#include <stdio.h>
#include <stdlib.h>

int result = 0;
int index = 0;

typedef struct node {
	float time;
	float atTime;
	int check;
	struct node* next;
}node;

typedef struct List {
	struct node* head;
	int count;
}List;

List* init() {
	List* list = (List*)malloc(sizeof(List));

	if (list == NULL) {
		printf("err\n");
	}
	else {
		list->head = NULL;
		list->count = 0;
		return list;
	}
}

void insert(List* list, float time, float atTime) {
	node* newNode = (node*)malloc(sizeof(node));
	node* preNode = list->head;
	newNode->time = time;
	newNode->atTime = atTime;
	newNode->check = 0;
	newNode->next = NULL;

	if (list->count == 0) {
		newNode->next = newNode;
		list->head = newNode;
		index++;
	}
	else {
		for (int i = 0; i < index; i++) {
			preNode = preNode->next;
		}
		newNode->next = preNode->next;
		preNode->next = newNode;
	}
	list->count++;
}

void check(List* list) {
	float timecheck, count;
	node* curNode = list->head;
	if (list->count == 0) return;
	if (list->head->check == 0) {
		if (list->head->atTime <= list->head->time + 1) {
			list->count--;
			list->head = list->head->next;
			free(curNode);
			check(list);
		}
		else {
			timecheck = list->head->atTime - (list->head->time + 1);
			count = timecheck / 0.5;
			if (count >= 8) {
				result += 40000;
			}
			else {
				result += count * 5000;
			}
			list->count--;

			list->head = list->head->next;
			free(curNode);
			check(list);
		}
	}
}

int main() {
	List* list = init();
	float time, atTime;
	for (int i = 0; i < 5; i++) {
		float time, atTime;
		scanf("%f %f", &time, &atTime);
		insert(list, time, atTime);
	}
	check(list);
	if (result >= 150000) {
		result = result - (result * 0.05);
	}
	else if (result <= 50000) {
		result = result + (result * 0.05);
	}
	printf("%d", result);
	
	free(list);
	return 0;
}
