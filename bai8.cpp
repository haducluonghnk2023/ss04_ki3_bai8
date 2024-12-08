#include<stdio.h>
#include<stdlib.h>
typedef struct Node {
	int data;
	struct Node* next;
} Node;
Node* createNode(int value){
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = value;
	newNode->next = NULL; 
	return newNode;
}
void append(Node** head,int value){
	Node* newNode = createNode(value);
	if(*head == NULL){
		*head = newNode;
		return;
	}
	Node* temp = *head;
	while(temp->next != NULL){
		temp = temp->next;
	}
	temp->next = newNode;
}
int findMax(Node* head){
	if (head == NULL) { 
        printf("ds rong.\n");
        return -1; 
    }
	int max = head->data;
	Node* temp = head;
	while(temp != NULL){
		if(temp->data > max){
			max = temp->data;
		}
		temp = temp->next;
	}
	return max;
}

int main(){
	Node* head = NULL;
	int n,value;
	printf("nhap so luong phan tu :");
	scanf("%d",&n);
	for(int i = 0; i < n; i++){
		printf("nhap phan tu %d :",i + 1);
		scanf("%d",&value);
		append(&head,value);
	}
	int maxValue = findMax(head);
	if(maxValue != -1){
		printf("gia tri lon nhat trong day la %d\n",maxValue);
	}
	return 0;
}

