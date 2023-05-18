#include <iostream>
#include <fstream>
#include <windows.h>
#include <unordered_map>
#include <sstream>

using namespace std;

// Определение класса CallRecord для хранения информации о звонке
class CallRecord {
public:
    CallRecord(const string& number, const string& dateTime, int duration, float cost)
        : number(number), dateTime(dateTime), duration(duration), cost(cost) {}

    const string& getNumber() const {
        return number;
    }

private:
    string number;
    string dateTime;
    int duration;
    float cost;
};

// Функция для извлечения номера абонента из строки записи о звонке
string extractPhoneNumber(const string& line) {
    istringstream iss(line);
    string number;
    iss >> number; // Предполагаем, что номер абонента является первым значением в строке
    return number;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    // Открытие файла с записями о звонках
    ifstream inputFile("calls.txt"); // Имя вашего файла с записями о звонках

    if (!inputFile) {
        cout << "Ошибка открытия файла." << endl;
        return 1;
    }

    // Создание хэш-таблицы для подсчета количества звонков по каждому номеру
    unordered_map<string, int> callCounts;

    // Чтение файла построчно и подсчет количества звонков для каждого номера
    string line;
    while (getline(inputFile, line)) {
        string phoneNumber = extractPhoneNumber(line);
        callCounts[phoneNumber]++;
    }

    inputFile.close(); // Закрытие файла

    int maxCallCount = 0;
    string maxCallNumber;

    // Поиск номера с максимальным количеством звонков
    for (const auto& pair : callCounts) {
        if (pair.second > maxCallCount) {
            maxCallCount = pair.second;
            maxCallNumber = pair.first;
        }
    }

    // Вывод информации о номере с максимальным количеством звонков или сообщения о отсутствии записей о звонках
    if (maxCallCount > 0) {
        cout << "Номер с максимальным количеством звонков: " << maxCallNumber << endl;
        cout << "Количество звонков: " << maxCallCount << endl;
    }
    else {
        cout << "Нет записей о звонках." << endl;
    }

    return 0;
}
