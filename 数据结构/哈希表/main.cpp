#define DEFAULT_SIZE 16 //Ĭ����������Ĵ�С
#include <iostream>
using namespace std;

//����Ԫ������ڵ�
typedef struct _ListNode
{
	_ListNode* next;
	int key;
	void* data;
}ListNode, *pListNode;

//�����ϣ��
typedef struct _HashTable
{
	int tableSize; //Ͱ������������������Ĵ�С��
	pListNode* theList;
}HashTable, *pHashTable;

//��ϣ����
int Hash(int key, int tableSize)
{
	return (key % tableSize);
}

//��ʼ����ϣ��
HashTable* InitHash(int tableSize)
{
	int i = 0;
	HashTable* hTable = NULL;

	if (tableSize <= 0)
	{
		tableSize = DEFAULT_SIZE;
	}

	hTable = (HashTable*)malloc(sizeof(HashTable));

	hTable->tableSize = tableSize;

	//Ϊ��ϣͰ�����ڴ�ռ䣬��Ϊһ��ָ������
	hTable->theList = (pListNode*)malloc(sizeof(pListNode)*tableSize);
	if (NULL == hTable->theList)
	{
		printf("HashTable malloc error\n");
		free(hTable);
		return NULL;
	}

	//Ϊ��ϣͰ��Ӧ��ָ�������ʼ������ڵ�
	for (int i = 0; i < tableSize; i++)
	{
		hTable->theList[i] = (ListNode*)malloc(sizeof(ListNode));
		if (NULL == hTable->theList[i])
		{
			printf("HashTable malloc error\n");
			free(hTable->theList);
			free(hTable);
			return NULL;
		}
		else
		{
			memset(hTable->theList[i], 0, sizeof(ListNode)); //��ʼ�� next key data
		}
	}
	return hTable;
}

//����
pListNode Find(pHashTable hashTable, int key)
{
	int i = Hash(key, hashTable->tableSize); //Ͱ���±�
	pListNode L = hashTable->theList[i]; //Ͱ����Ԫ��
	pListNode e = NULL; //Ҫ���ҵ�Ԫ��
						//Ͱ����Ԫ�ز���ֵ
	e = L->next;
	while (e != NULL && e->key != key)
	{
		e = e->next;
	}
	return e;
}

//����
void Insert(pHashTable hashTable, int key, void *value)
{
	pListNode e = NULL; //Ԫ��
	pListNode tmp = NULL;
	pListNode L = NULL; //����
	e = Find(hashTable, key);

	if (NULL == e)
	{
		tmp = (pListNode)malloc(sizeof(ListNode));
		if (NULL == tmp)
		{
			printf("malloc error\n");
			return;
		}
		//ǰ�巨���룬����Ԫ�ط���Ͱ�ĵڶ���λ��
		L = hashTable->theList[Hash(key, hashTable->tableSize)];
		tmp->data = value;
		tmp->key = key;
		//����Ĳ���
		tmp->next = L->next;
		L->next = tmp;
	}
	else
	{
		printf("the key already exist\n");
	}
}

//ɾ��
void Delete(pHashTable hashTable, int key)
{
	int i = Hash(key, hashTable->tableSize);
	pListNode L = hashTable->theList[i];

	pListNode last = L; //ɾ������һ��Ԫ��
	pListNode e = L->next; //Ҫɾ����Ԫ��
	while (e != NULL && e->key != key)
	{
		last = e;
		e = e->next;
	}

	if (e) //���e����
	{
		last->next = e->next;
		free(e);
	}
}

//����
void Destory(pHashTable hashTable)
{
	pListNode L = NULL;
	pListNode cur = NULL;
	pListNode next = NULL;
	for (int i = 0; i < hashTable->tableSize; i++)
	{
		L = hashTable->theList[i];
		cur = L->next;
		while (cur != NULL && cur->next != NULL)
		{
			next = cur->next;
			free(cur);
			cur = next;
		}
		free(L);
	}
}

//��ϣ��Ԫ������ȡ����
void* Retrieve(pListNode e)
{
	return e ? e->data : NULL;
}

int main() 
{
	char* elems[] = { "�ŷ�","����","����" };

	HashTable *hTable = NULL;
	hTable = InitHash(31);
	Insert(hTable, 1, elems[0]);
	Insert(hTable, 2, elems[1]);
	Insert(hTable, 3, elems[2]);
	Delete(hTable, 1);

	for (int i = 0; i < 4; i++)
	{
		pListNode e = Find(hTable, i);
		if (e)
		{
			printf("%s\n", (const char*)Retrieve(e));
		}
		else 
		{
			printf("Not found [key:%d]\n", i);
		}
	}
	Destory(hTable);
	system("pause");
	return 0;
}