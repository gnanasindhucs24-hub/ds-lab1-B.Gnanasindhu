#include <stdio.h>

#define MAX 100

int hashTable[MAX];
int m;

/* Initialize hash table */
void initialize()
{
    for (int i = 0; i < m; i++)
        hashTable[i] = -1;
}

/* Insert key using linear probing */
void insert(int key)
{
    int index = key % m;

    if (hashTable[index] == -1)
    {
        hashTable[index] = key;
    }
    else
    {
        printf("Collision occurred at index %d for key %d\n", index, key);
        int i = (index + 1) % m;

        while (i != index)
        {
            if (hashTable[i] == -1)
            {
                hashTable[i] = key;
                return;
            }
            i = (i + 1) % m;
        }

        printf("Hash table is full, cannot insert key %d\n", key);
    }
}

/* Display hash table */
void display()
{
    printf("\nHash Table Contents:\n");
    for (int i = 0; i < m; i++)
    {
        if (hashTable[i] != -1)
            printf("Index %d : %d\n", i, hashTable[i]);
        else
            printf("Index %d : ---\n", i);
    }
}

int main()
{
    int n, key;

    printf("Enter size of hash table (m): ");
    scanf("%d", &m);

    initialize();

    printf("Enter number of employee records: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("Enter 4-digit employee key: ");
        scanf("%d", &key);
        insert(key);
    }

    display();
    return 0;
}
