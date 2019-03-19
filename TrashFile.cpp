#include "Trash.h"
#include<stdlib.h>
#include<stdbool.h>
bool EstablishDatabase(Node *phead)
{
	if((*phead = (Node)malloc(sizeof(key)))==NULL){
	printf("Fail to create a new database!\n");
	return false;
	}
	(*phead)->next = NULL;
	printf("New database created!\n");
	return true;
}
bool Add(Node head,int KeyNum,int KeyValue)
{
	Node ptr = head;
	Node pnew = (Node) malloc(sizeof(key));
	if(pnew == NULL){
		printf("Fail to set a new key.\n");
		return false;
	}
	pnew->next = NULL;
	while(ptr->next!=NULL){
		ptr = ptr->next;
	}
	pnew->value = 114115; 
	ptr->next = pnew;
	ptr->keynum = KeyNum;
	ptr->value = KeyValue;
	return true;
}
int Get(Node head,int keynum){
	Node ptr = head;
	while(ptr->value!=keynum){
		if(ptr->value==114115){
			printf("key invalid.\n");
			return 114115;
		}
		ptr=ptr->next;
	}
	return ptr->value;
}
int Del(Node *phead,int keynum)
{
	
}
