#include "Hash.cpp"

// Driver program
int main()
{
    // array that contains keys to be mapped
    int a[] = {15, 11, 27, 8, 12};
    // number of keys in the array
    int n = sizeof(a) / sizeof(a[0]);

    // insert the keys into the hash table
    Hash<int> h(7); // 7 is count of buckets in hash table
    for (int i = 0; i < n; i++)
        h.insertItem(a[i]);

    // display the Hash table
    cout << "Initial hash table:" << endl;
    h.displayHash();

    // delete 12 from hash table
    h.deleteItem(12);

    cout << "\nUpdated hash table after deleting " 
         << "12 from the table:" << endl;
    // display the Hash table
    h.displayHash();

    return 0;
}