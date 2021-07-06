#define DEFAULT_SIZE 16 //默认索引数组的大小
#include <iostream>
using namespace std;

//定义元素链表节点
typedef struct _ListNode
{
	_ListNode* next;
	int key;
	void* data;
}ListNode, *pListNode;

//定义哈希表
typedef struct _HashTable
{
	int tableSize; //桶的数量（或索引数组的大小）
	pListNode* theList;
}HashTable, *pHashTable;

//哈希函数
int Hash(int key, int tableSize)
{
	return (key % tableSize);
}

//初始化哈希表
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

	//为哈希桶分配内存空间，其为一个指针数组
	hTable->theList = (pListNode*)malloc(sizeof(pListNode)*tableSize);
	if (NULL == hTable->theList)
	{
		printf("HashTable malloc error\n");
		free(hTable);
		return NULL;
	}

	//为哈希桶对应的指针数组初始化链表节点
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
			memset(hTable->theList[i], 0, sizeof(ListNode)); //初始化 next key data
		}
	}
	return hTable;
}

//查找
pListNode Find(pHashTable hashTable, int key)
{
	int i = Hash(key, hashTable->tableSize); //桶的下标
	pListNode L = hashTable->theList[i]; //桶的首元素
	pListNode e = NULL; //要查找的元素
						//桶的首元素不存值
	e = L->next;
	while (e != NULL && e->key != key)
	{
		e = e->next;
	}
	return e;
}

//插入
void Insert(pHashTable hashTable, int key, void *value)
{
	pListNode e = NULL; //元素
	pListNode tmp = NULL;
	pListNode L = NULL; //链表
	e = Find(hashTable, key);

	if (NULL == e)
	{
		tmp = (pListNode)malloc(sizeof(ListNode));
		if (NULL == tmp)
		{
			printf("malloc error\n");
			return;
		}
		//前插法插入，把新元素放入桶的第二个位置
		L = hashTable->theList[Hash(key, hashTable->tableSize)];
		tmp->data = value;
		tmp->key = key;
		//链表的插入
		tmp->next = L->next;
		L->next = tmp;
	}
	else
	{
		printf("the key already exist\n");
	}
}

//删除
void Delete(pHashTable hashTable, int key)
{
	int i = Hash(key, hashTable->tableSize);
	pListNode L = hashTable->theList[i];

	pListNode last = L; //删除的上一个元素
	pListNode e = L->next; //要删除的元素
	while (e != NULL && e->key != key)
	{
		last = e;
		e = e->next;
	}

	if (e) //如果e存在
	{
		last->next = e->next;
		free(e);
	}
}

//销毁
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

//哈希表元素中提取数据
void* Retrieve(pListNode e)
{
	return e ? e->data : NULL;
}

int main() 
{
	char* elems[] = { "张飞","赵云","关羽" };

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