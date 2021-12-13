// Driver's code
#include "DoubleHash.cpp"

int main()
{
    int a[] = {19, 27, 36, 10, 64};
    int n = sizeof(a) / sizeof(a[0]);

    // inserting keys into hash table
    DoubleHash<int> h;
    for (int i = 0; i < n; i++)
    {
        h.insertHash(a[i]);
    }
    // searching some keys
    h.search(36);  // This key is present in hash table
    h.search(100); // This key does not exist in hash table
    // display the hash Table
    h.displayHash();
    return 0;
}



