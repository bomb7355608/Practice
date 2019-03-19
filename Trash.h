#ifndef SERVER
#define SERVER
typedef struct keydata{
	int keynum;
	int value;
	struct keydata* next;
} key, * Node;
bool EstablishDatabase(Node *phead);
bool Add(Node head,int KeyNum,int KeyValue);
int Get(Node head,int keynum);
int Del(Node head,int keynum);



#endif
