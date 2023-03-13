#include <iostream>
#include <string>
#include <windows.h>
#include <fstream>
using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    string* AS; // массив вводимых строк, это результат
    string* AS2; // дополнительный массив строк
    int count; // количество элементов в массиве
    string s; // дополнительная переменная-строка
    char buf[80]; // буфер для ввода строк

    // 2. Цикл ввода строк, конец ввода - пустая строка ""
    cout << "Введите строки\n";
    count = 0;
    AS = nullptr;

    do
    {
        cout << "=> ";
        cin.getline(buf, 80, '\n'); // строки вводятся с пробелами
        s = buf;
        char* pch = strtok(buf, " "),  // получаем первое слово
            * word = 0; // самое длинное слово

        int length = strlen(pch);
        int maxLen = 0; // самое длинное слово

        while (pch != NULL) // пока есть слова
        {
            length = strlen(pch);// определяем длинну слова

            if (maxLen < length) // определяем самое длинное слово
            {
                maxLen = length;
                word = pch; // сохраняем указатель на текущее слово
            }

            pch = strtok(NULL, " "); // получаем следующее слово
        }
        cout << "Самое длинное слово: " << word<<endl; // само слово


        if (s != "")
        {
            int pos = s.find("quit");// поиск слова "quit"
            if (pos == -1) {
                count++;

                AS2 = new string[count];

                for (int i = 0; i < count - 1; i++)
                    AS2[i] = AS[i];

                AS2[count - 1] = s;

                if (AS != nullptr)
                    delete[] AS;

                AS = AS2;
            }
            else
                break;
        }
    } while (s != "");

    // 3. Вывод нового массива
    cout << "\nМассив строк:\n";
    if (count > 0)
        for (int i = 0; i < count; i++)
            cout << "AS[" << i << "] = " << AS[i] << ::endl;
    else
        cout << "array AS is empty.";

    // 4. После использования массива AS освободить память, выделенную для него
    delete[] AS;
}
