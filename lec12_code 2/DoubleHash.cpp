// CPP program to implement double hashing
#include <iostream>
using namespace std;

// Hash table size
#define TABLE_SIZE 13

// Used in second hash function.
#define PRIME 7

template <typename Comparable>
class DoubleHash
{
    // Pointer to an array containing buckets
    Comparable *hashTable;
    int curr_size;

public:
    DoubleHash();

    // function to check if hash table is full
    bool isFull();

    // function to calculate first hash
    int hash1(Comparable key);

    // function to calculate second hash
    int hash2(Comparable key);

    // function to insert key into hash table
    void insertHash(Comparable key);

    // function to search key in hash table
    void search(Comparable key);

    // function to display the hash table
    void displayHash();
};

template <typename Comparable>
DoubleHash<Comparable>::DoubleHash()
{
    hashTable = new int[TABLE_SIZE];
    curr_size = 0;

    for (int i = 0; i < TABLE_SIZE; i++)
    {
        hashTable[i] = -1;
    }
}

// function to check if hash table is full
template <typename Comparable>
bool DoubleHash<Comparable>::isFull()
{
    // if hash size reaches maximum size
    return (curr_size == TABLE_SIZE);
}

// function to calculate first hash
template <typename Comparable>
int DoubleHash<Comparable>::hash1(Comparable key)
{
    return (key % TABLE_SIZE);
}

// function to calculate second hash
template <typename Comparable>
int DoubleHash<Comparable>::hash2(Comparable key)
{
    return (PRIME - (key % PRIME));
}

// function to insert key into hash table
template <typename Comparable>
void DoubleHash<Comparable>::insertHash(Comparable key)
{
    // if hash table is full
    if (isFull())
        return;

    // get index from first hash
    int index = hash1(key);

    // if collision occurs
    if (hashTable[index] != -1)
    {
        // get index2 from second hash
        int index2 = hash2(key);
        int i = 1;
        while (1)
        {
            // get newIndex
            int newIndex = (index + i * index2) % TABLE_SIZE;

            // if no collision occurs, store the key
            if (hashTable[newIndex] == -1)
            {
                hashTable[newIndex] = key;
                break;
            }
            i++;
        }
    }  
    else // if no collision occurs
        hashTable[index] = key;
    curr_size++;
}

// function to search key in hash table
template <typename Comparable>
void DoubleHash<Comparable>::search(Comparable key)
{
    int index1 = hash1(key);
    int index2 = hash2(key);
    int i = 0;

    while (hashTable[(index1 + i * index2) % TABLE_SIZE] != key)
    {
        if (hashTable[(index1 + i * index2) % TABLE_SIZE] == -1)
        {
            cout << key << " does not exist" << endl;
            return;
        }
        i++;
    }
    cout << key << " found" << endl;
}

// function to display the hash table
template <typename Comparable>
void DoubleHash<Comparable>::displayHash()
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        if (hashTable[i] != -1)
            cout << i << " --> " << hashTable[i] << endl;
        else
            cout << i << endl;
    }
}
