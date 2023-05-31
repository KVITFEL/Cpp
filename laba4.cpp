#include <iostream>
#include <fstream>
#include <vector>
#include <windows.h>
using namespace std;

class Tourist {
private:
    string name;
    string surname;
    int age;
    string email;
    string city;
    double totalCost;

public:
    // Конструктор класса
    Tourist(string n, string s, int a, string e, string c, double cost) {
        name = n;
        surname = s;
        age = a;
        email = e;
        city = c;
        totalCost = cost;
    }

    // Методы доступа к приватным членам класса
    string getName() { return name; }
    string getSurname() { return surname; }
    int getAge() { return age; }
    string getEmail() { return email; }
    string getCity() { return city; }
    double getTotalCost() { return totalCost; }

    void setName(string n) { name = n; }
    void setSurname(string s) { surname = s; }
    void setAge(int a) { age = a; }
    void setEmail(string e) { email = e; }
    void setCity(string c) { city = c; }
    void setTotalCost(double cost) { totalCost = cost; }
};

class TouristDatabase {
private:
    vector<Tourist> tourists;
    string filename;

public:
    // Конструктор класса
    TouristDatabase(string file) {
        filename = file;
    }

    // Метод для считывания данных из файла
    void loadData() {
        ifstream file(filename);
        if (file.is_open()) {
            string name, surname, email, city;
            int age;
            double totalCost;

            while (file >> name >> surname >> age >> email >> city >> totalCost) {
                Tourist tourist(name, surname, age, email, city, totalCost);
                tourists.push_back(tourist);
            }

            file.close();
            cout << "Данные успешно загружены из файла." << endl;
        }
        else {
            cout << "Ошибка при открытии файла." << endl;
        }
    }

    // Метод для добавления нового туриста
    void addTourist(Tourist tourist) {
        tourists.push_back(tourist);
        cout << "Новый турист добавлен." << endl;
    }

    // Метод для изменения данных туриста
    void updateTourist(string email) {
        for (Tourist& tourist : tourists) {
            if (tourist.getEmail() == email) {
                string name, surname, city;
                int age;
                double totalCost;

                cout << "Введите новые данные для туриста:" << endl;
                cout << "Имя: ";
                cin >> name;
                cout << "Фамилия: ";
                cin >> surname;
                cout << "Возраст: ";
                cin >> age;
                cout << "Город: ";
                cin >> city;
                cout << "Общая стоимость проживания: ";
                cin >> totalCost;

                tourist.setName(name);
                tourist.setSurname(surname);
                tourist.setAge(age);
                tourist.setCity(city);
                tourist.setTotalCost(totalCost);

                cout << "Данные туриста успешно обновлены." << endl;
                return;
            }
        }

        cout << "Турист с указанной электронной почтой не найден." << endl;
    }

    // Метод для поиска туриста по имени и фамилии
    void searchTourist(string name, string surname) {
        for (Tourist& tourist : tourists) {
            if (tourist.getName() == name && tourist.getSurname() == surname) {
                cout << "Имя: " << tourist.getName() << endl;
                cout << "Фамилия: " << tourist.getSurname() << endl;
                cout << "Возраст: " << tourist.getAge() << endl;
                cout << "Электронная почта: " << tourist.getEmail() << endl;
                cout << "Город: " << tourist.getCity() << endl;
                cout << "Общая стоимость проживания: " << tourist.getTotalCost() << endl;
                return;
            }
        }

        cout << "Турист с указанным именем и фамилией не найден." << endl;
    }

    // Метод для сохранения данных в файле
    void saveData() {
        ofstream file(filename);
        if (file.is_open()) {
            for (Tourist& tourist : tourists) {
                file << tourist.getName() << " " << tourist.getSurname() << " "
                    << tourist.getAge() << " " << tourist.getEmail() << " "
                    << tourist.getCity() << " " << tourist.getTotalCost() << endl;
            }

            file.close();
            cout << "Данные успешно сохранены в файле." << endl;
        }
        else {
            cout << "Ошибка при открытии файла." << endl;
        }
    }

    // Метод для вывода всех туристов
    void displayAllTourists() {
        if (tourists.empty())
        {
            cout << "База данных пуста. Нет доступных туристов." << endl;
        }
        else {
            cout << "Список всех туристов:" << endl;
            for (Tourist& tourist : tourists) {
                cout << "Имя: " << tourist.getName() << endl;
                cout << "Фамилия: " << tourist.getSurname() << endl;
                cout << "Возраст: " << tourist.getAge() << endl;
                cout << "Электронная почта: " << tourist.getEmail() << endl;
                cout << "Город: " << tourist.getCity() << endl;
                cout << "Общая стоимость проживания: " << tourist.getTotalCost() << endl;
                cout << "------------------------" << endl;
            }
        }
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    TouristDatabase database("tourists.txt");
    // Считываем данные из файла
    database.loadData();

    int choice;
    while (true) {
        cout << "Выберите действие:" << endl;
        cout << "1. Добавить нового туриста" << endl;
        cout << "2. Изменить данные туриста" << endl;
        cout << "3. Поиск туриста" << endl;
        cout << "4. Сохранить данные" << endl;
        cout << "5. Вывести всех туристов" << endl;
        cout << "6. Выход" << endl;
        cout << "Введите номер выбранного действия: ";
        cin >> choice;

        if (choice == 1) {
            string name, surname, email, city;
            int age;
            double totalCost;

            cout << "Введите данные нового туриста:" << endl;
            cout << "Имя: ";
            cin >> name;
            cout << "Фамилия: ";
            cin >> surname;
            cout << "Возраст: ";
            cin >> age;
            cout << "Электронная почта: ";
            cin >> email;
            cout << "Город: ";
            cin >> city;
            cout << "Общая стоимость проживания: ";
            cin >> totalCost;

            Tourist tourist(name, surname, age, email, city, totalCost);
            database.addTourist(tourist);
        }
        else if (choice == 2) {
            string email;

            cout << "Введите электронную почту туриста, данные которого нужно изменить: ";
            cin >> email;

            database.updateTourist(email);
        }
        else if (choice == 3) {
            string name, surname;

            cout << "Введите имя туриста для поиска: ";
            cin >> name;
            cout << "Введите фамилию туриста для поиска: ";
            cin >> surname;

            database.searchTourist(name, surname);
        }
        else if (choice == 4) {
            database.saveData();
        }
        else if (choice == 5) {
            database.displayAllTourists();
        }
        else if (choice == 6) {
            break;
        }
        else {
            cout << "Некорректный выбор. Повторите попытку." << endl;
        }

        cout << endl;
    }

    return 0;
}
