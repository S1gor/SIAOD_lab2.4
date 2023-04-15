/*Таблица содержит данные об успеваемости студентов, в качестве ключа используется фамилии студента.Разработать функции включения, удаления и поиска записи по ключу.
Хеш-таблица с внешними цепочками, строка таблицы содержит первую запись по данному входу и указатель начала внешней цепочки по данному входу;*/

#include"HashTable.h"

int main()
{
    HashTable table;

    Student record1 = { "Ivanov", 5 }; // 1
    Student record2 = { "Petrov", 4 };
    Student record3 = { "Sidorov", 3 };
    Student record4 = { "sfdbvfdb", 8 };
    Student record5 = { "fgdg", 9 };
    Student record6 = { "sdfa", 10 };
    Student record7 = { "adsav", 11 }; // 1
    Student record8 = { "nbvcx", 15 };
    Student record9 = { "jutkuyre", 28 };
    table.Insert(record1);
    table.Insert(record2);
    table.Insert(record3);
    table.Insert(record4);
    table.Insert(record5);
    table.Insert(record6);
    table.Insert(record7);
    table.Insert(record8);
    table.Insert(record9);

    Student* result = table.Search("adsav");
    if (result != nullptr)
        std::cout << "Found student:\nName - " << result->name << "\nScore - " << result->score << std::endl;
    return 0;
}