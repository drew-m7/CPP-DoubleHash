#include "Hash.cpp"

// Driver program
int main()
{
    // array that contains keys to be mapped
    int a[] = {0, 81, 1, 64, 4, 25, 36, 16, 49, 9};
    // number of keys in the array
    int n = sizeof(a) / sizeof(a[0]);

    // insert the keys into the hash table
    Hash<int> h(10); // 10 is count of buckets in hash table
    for (int i = 0; i < n; i++)
        h.insertItem(a[i]);

    // display the Hash table
    cout << "Initial hash table:" << endl;
    h.displayHash();

    // delete 36 from hash table
    h.deleteItem(36);
    cout << "\nUpdated hash table after deleting " 
         << "36 from the table:" << endl;
    h.displayHash();

    // delete 4, 64 from hash table
    h.deleteItem(4);
    h.deleteItem(64);
    cout << "\nUpdated hash table after deleting " 
         << "4 and 64 from the table:" << endl;
    h.displayHash();

    return 0;
}