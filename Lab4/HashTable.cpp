#include "HashTable.h"

int HashTable::HashFunction(std::string key)
{
    int hash = 0;
    for (int i = 0; i < key.length(); i++)
        hash += (int)key[i];
    return hash % table_size;
}

HashTable::HashTable()
{
    for (int i = 0; i < table_size; i++)
        table[i] = nullptr;
}

HashTable::~HashTable()
{
    for (int i = 0; i < table_size; i++)
    {
        Entry* current = table[i];
        while (current != nullptr)
        {
            Entry* next = current->next;
            delete current;
            current = next;
        }
    }
}

void HashTable::Insert(Student student)
{
    int index = HashFunction(student.name);
    Entry* entry = new Entry();
    entry->student = student;
    entry->next = nullptr;

    if (table[index] == nullptr)
        table[index] = entry;
    else
    {
        Entry* current = table[index];
        while (current->next != nullptr)
            current = current->next;
        current->next = entry;
    }
}

void HashTable::Remove(std::string key)
{
    int index = HashFunction(key);

    if (table[index] == nullptr)
        return;

    if (table[index]->student.name == key)
    {
        Entry* oldEntry = table[index];
        table[index] = table[index]->next;
        delete oldEntry;
    }
    else
    {
        Entry* current = table[index];
        while (current->next != nullptr && current->next->student.name != key)
            current = current->next;
        if (current->next != nullptr)
        {
            Entry* oldEntry = current->next;
            current->next = current->next->next;
            delete oldEntry;
        }
    }
}

Student* HashTable::Search(std::string key)
{
    int index = HashFunction(key);

    if (table[index] == nullptr)
        return nullptr;

    Entry* current = table[index];
    while (current != nullptr && current->student.name != key)
        current = current->next;

    if (current != nullptr)
        return &current->student;
    else
        return nullptr;
}