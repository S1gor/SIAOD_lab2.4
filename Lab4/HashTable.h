#pragma once

#include <iostream>
#include <string>

class Student
{
public:
    std::string name;
    int score;
};

class HashTable
{
private:
    static const int table_size = 10;

    class Entry
    {
    public:
        Student student;
        Entry* next;
    };

    Entry* table[table_size];

    int HashFunction(std::string key);

public:
    HashTable();
    ~HashTable();

    void Insert(Student student);
    void Remove(std::string key);
    Student* Search(std::string key);
};