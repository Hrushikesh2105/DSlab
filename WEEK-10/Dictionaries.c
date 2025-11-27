#include <stdio.h>
#include <string.h>

#define SIZE 10
#define EMPTY -1

typedef struct
{
int key;
char value[50];
}
DictEntry;

DictEntry table[SIZE];

int hash(int key)
{
return key % SIZE;//(k mod m)
}

void init()
{
int i=0;
for(i = 0; i < SIZE; i++)
{
table[i].key = EMPTY;//assigning the centinental values in the has table

}
}

void insert(int key, char value[])
{
int index = hash(key);

while (table[index].key != EMPTY)
{
index = (index + 1) % SIZE; // linear probing(if collision occured so we are incrementing the index)
}

table[index].key = key; //101
strcpy(table[index].value, value); //vjit(here the "vjit" is copied in the 101 column)
}

char* search(int key)
{
int index = hash(key);
int i=0;
for(i = 0; i < SIZE; i++)
{
if (table[index].key == key)
return table[index].value;
index = (index + 1) % SIZE;
}

return NULL;
}

int main()
{
init();

insert(101, "VJIT");
insert(102, "CBIT");
insert(103, "MGIT");
insert(11001,"6");
insert(11000,"16");
char* result = search(11001);
if (result != NULL)
printf("Value = %s\n", result);
else
printf("Key not found\n");

return 0;
}
