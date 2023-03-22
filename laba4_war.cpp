#include <iostream>
#include <string>
#include <windows.h>
#include <fstream>
using namespace std;
int zadanie1();
int zadanie2();


int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    zadanie2();

}

int zadanie1() {
    cout << "Введите текст: ";

    char ch;
    size_t count = 0;
    while ((ch =cin.get()) != '\n') {

        if (ch >= '0' && ch <= '9')
            ++count;
    }
    cout << "Здесь " << count << " цифры ";
    return 0;
}

int zadanie2() {
    char str[256] = "";
    cin.getline(str, sizeof(str));

    const char* delim = " ,.:;?!\t";
    char* token[256] = { NULL };
    int n = 0;

    // разбиваем строку на слова
    token[n] = strtok(str, delim);
    while (token[n] != NULL)
    {
        ++n;
        token[n] = strtok(NULL, delim);
    }

    // удаляем повторы
    for (int i = 0; i < n - 1; ++i)
    {
        int src_idx = i + 1;
        int dest_idx = src_idx;

        while (src_idx < n)
        {
            if (strcmp(token[src_idx], token[i]) != 0)
            {
                token[dest_idx] = token[src_idx];
                ++dest_idx;
            }
            ++src_idx;
        }

        n = dest_idx;
    }

    // выводим результат
    for (int i = 0; i < n; ++i)
        cout << token[i] << '\n';


}
