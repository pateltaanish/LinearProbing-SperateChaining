//
//  main.cpp
//  HW14
//
//  Created by Taanish Patel on 4/27/24.
//

#include <iostream>

using namespace std;

const int MaxSize = 10;

int arr[MaxSize];

void linearProbing(int arr[], int key)
{
    int index;
    index = key % MaxSize;
     if (arr[index] == 0)
        arr[index] = key;
    else
    {
        int i = (index + 1) % MaxSize;
        while (arr[i] != 0 && i != index)
            i = (i + 1) % MaxSize;
         if (i == index)
            cout << "Array is full" << endl;
        else
            arr[i] = key;
    }
}

class HashEntry {
public:
    int data;
    HashEntry* next;

    HashEntry(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

//--------------------Spereate Chainging-----------------------------

class HashTable {
private:
    HashEntry **table;
public:
    HashTable()
    {
        table = new HashEntry*[MaxSize];
        for (int i = 0; i < MaxSize; i++)
            table[i] = NULL;
    }

    int get(int key)
    {
        int hash = (key % MaxSize);
        if (table[hash] == NULL)
            return -1;
        else {
            HashEntry* entry = table[hash];
            while (entry != NULL && entry->data != key)
                entry = entry->next;
            if (entry == NULL)
                return -1;
            else
                return entry->data;
        }
    }
    void put(int key)
    {
        int hash = (key % MaxSize);
        if (table[hash] == NULL)
            table[hash] = new HashEntry(key);
        else {
            HashEntry* entry = table[hash];
            while (entry->next != NULL)
                entry = entry->next;
            entry->next = new HashEntry(key);
        }
    }
};

int main(){
    int H_arr[MaxSize] = {0};
    
    linearProbing(H_arr, 7);
    linearProbing(H_arr, 21);
    linearProbing(H_arr, 13);
    linearProbing(H_arr, 53);
    linearProbing(H_arr, 37);
    linearProbing(H_arr, 3);
 
    cout << "Array after linear probing:" << endl;
    for (int i = 0; i < MaxSize; i++)
        cout << H_arr[i] << " ";
    cout << endl;
    HashTable hash;
//--------------------Hash Entry-----------------------------
    hash.put(7);
    hash.put(21);
    hash.put(13);
    hash.put(53);
    hash.put(37);
    hash.put(3);
    
    cout << endl;
    cout << "Array after separate chaining:" << endl;
    cout << "7 :" << hash.get(7) << endl;
    cout << "21 :" << hash.get(21) << endl;
    cout << "13 :" << hash.get(13) << endl;
    cout << "53 :" << hash.get(53) << endl;
    cout << "37 :" << hash.get(37) << endl;
    cout << "3 :" << hash.get(3) << endl;
    cout << "0 :" << hash.get(0) << endl;


    return 0;
}


/*
 Output:
 
 Array after linear probing:
 0 21 0 13 53 3 0 7 37 0

 Array after separate chaining:
 7 :7
 21 :21
 13 :13
 53 :53
 37 :37
 3 :3
 0 :-1   // -1 if missing
 
 */
