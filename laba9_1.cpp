#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include <unordered_map>
#include <sstream>

using namespace std;

struct CallRecord {
    string number;
    string dateTime;
    int duration;
    float cost;
};

string extractPhoneNumber(const string& line) {
    istringstream iss(line);
    string number;
    iss >> number; // Предполагая, что номер телефона является первым значением в строке
    return number;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    ifstream inputFile("call_records.txt"); // Имя вашего файла с записями о звонках

    if (!inputFile) {
        cout << "Ошибка открытия файла." << endl;
        return 1;
    }

    unordered_map<string, int> callCounts;

    string line;
    while (getline(inputFile, line)) {
        string phoneNumber = extractPhoneNumber(line);
        callCounts[phoneNumber]++;
    }

    inputFile.close();

    int maxCallCount = 0;
    string maxCallNumber;

    for (const auto& pair : callCounts) {
        if (pair.second > maxCallCount) {
            maxCallCount = pair.second;
            maxCallNumber = pair.first;
        }
    }

    if (maxCallCount > 0) {
        cout << "Номер с максимальным количеством звонков: " << maxCallNumber << endl;
        cout << "Количество звонков: " << maxCallCount << endl;
    }
    else {
        cout << "Нет записей о звонках." << endl;
    }

    return 0;
}
