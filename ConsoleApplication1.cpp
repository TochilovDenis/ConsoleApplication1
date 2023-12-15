// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.


#include <iostream>
#include <ctime>
#include <string>
#include <vector>
using namespace std;
/*

Создайте приложение «Список дел».
Приложение должно позволять:

Backend - ходить в базу данных и сохранять или читать данные
Fronted - рисовать или печатать данные на экране

■ [+] Добавление дел. У дела есть:
    -[+] класс Дело:
        • название;
        • приоритет;
        • описание;
        • дата, время исполнения.
        • статус: выполнено / невыполнено
■ [+] Удаление дел.
■ [+] Редактирование дел.
■ [+] Поиск дел по:
    • [+] названию;
    • [+] приоритету;
    • [+] описанию;
    • [+] дате и времени исполнения.
■ [+] Отображение списка дел:
    • [+] на день;
    • на неделю;
    • на месяц.
■ [+] При отображении должна быть возможность сортировки:
    • [] по приоритету;
    • [] по дате и времени исполнения.
*/

struct Task
{
    /*
    • название;
    • приоритет;
    • описание;
    • дата создания;
    • дата - срок время исполнения.
    */
    string name;
    int priority;
    string description;
    time_t creationDate;
    time_t estimationDate;
    bool done; // <--- статус: выполнено (true) / невыполнено (false)

    Task(string n, int p, string d, time_t e) :
        name{ n }, priority{ p }, description{ d }, creationDate{ time(0) },
        estimationDate{ e }, done{ false } {};

    std::string GetString() {
        std::string result = "";
        result += "Name: " + name + " | ";
        result += "Priority: " + to_string(priority) + " \n";
        result += "Creation: " + to_string(creationDate) + " | ";
        result += "Estimation: " + to_string(estimationDate) + "\n";
        result += "Description: " + description;
        return result;
    }
};

struct TodoList {
    vector<Task> m_data;
    vector<int> intVector;

    void AddTask(string n, int p, string d, time_t e) {
        m_data.push_back({ n, p, d, e });
    }
    void DeleteTask(int index) {
        m_data.erase(m_data.begin() + index);
    }

    void EditTask(int index, string name = "", int p = -1, string d = "", time_t e = 0) {
        if (name != "")
            m_data[index].name = name;
        if (p != -1)
            m_data[index].priority = p;
        if (d != "")
            m_data[index].description = d;
        if (e != 0)
            m_data[index].estimationDate = e;
    }

    int SearchByName(string name) {
        for (size_t i = 0; i < m_data.size(); i++)
        {
            if (m_data[i].name == name)
                return i;
        }
        return -1; // -1 означает что такого элемента нет
    }

    int SearchByPriority(int priority) {
        for (size_t i = 0; i < m_data.size(); i++)
        {
            if (m_data[i].priority == priority)
                return i;
        }
        return -1; // -1 означает что такого элемента нет
    }

    int SearchByDescription(string description) {
        for (size_t i = 0; i < m_data.size(); i++)
        {
            if (m_data[i].description == description)
                return i;
        }
        return -1; // -1 означает что такого элемента нет
    }

    int SearchByEstimation(time_t estimation) {
        for (size_t i = 0; i < m_data.size(); i++)
        {
            if (m_data[i].estimationDate == estimation)
                return i;
        }
        return -1; // -1 означает что такого элемента нет
    }

    string GetListByDateRangeOnDay(time_t day) {
        string result = "";
        for (size_t i = 0; i < m_data.size(); i++)
        {
            if (m_data[i].creationDate < day && day <= m_data[i].estimationDate > day)
            {
                result += m_data[i].GetString();
            }
        }
        return result;
    }

    string GetListByDateRangeOnWeek(time_t day) {
        string result = "";
        for (size_t i = 0; i < m_data.size(); i++)
        {
            
        }
        return result;
    }

};



int main()
{
    Task task("name", 1, "some description", 0);
    std::cout << task.GetString();
}


