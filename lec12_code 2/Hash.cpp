// CPP program to implement hashing with chaining
#include <iostream>
#include <list>
using namespace std;

template <typename Comparable>
class Hash
{
    int BUCKET; // No. of buckets

    // Pointer to an array containing buckets
    list<Comparable> *table;

public:
    Hash(Comparable b); // Constructor

    // inserts a key into hash table
    void insertItem(Comparable key);

    // deletes a key from hash table
    void deleteItem(Comparable key);

    // hash function to map values to key
    Comparable hashFunction(Comparable x)
    {
        return (x % BUCKET);
    }

    void displayHash();
};

template <typename Comparable>
Hash<Comparable>::Hash(Comparable b)
{
    this->BUCKET = b;
    table = new list<Comparable>[BUCKET];
}

template <typename Comparable>
void Hash<Comparable>::insertItem(Comparable key)
{
    int index = hashFunction(key);
    table[index].push_back(key);
}

template <typename Comparable>
void Hash<Comparable>::deleteItem(Comparable key)
{
    // get the hash index of key
    int index = hashFunction(key);

    // find the key in (index)th list
    list<int>::iterator itr;
    for (itr = table[index].begin(); itr != table[index].end(); itr++)
    {
        if (*itr == key)
            break;
    }

    // if key is found in hash table, remove it
    if (itr != table[index].end())
        table[index].erase(itr);
}

// function to display hash table
template <typename Comparable>
void Hash<Comparable>::displayHash()
{
    for (int i = 0; i < BUCKET; i++)
    {
        cout << i;
        for (auto x : table[i])
            cout << " --> " << x;
        cout << endl;
    }
}
