#include <iostream>
#include <string>
#include <windows.h>
#include <fstream>
using namespace std;
void zadanie1();
void zadanie2();
void zadanie3();

struct order{
    
    unsigned int plat, pol;
    int summa;
    string descrp;
};


int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    zadanie2();
    
}

void zadanie1() {

    string* AS; // массив вводимых строк, это результат
    string* AS2; // дополнительный массив строк
    int count; // количество элементов в массиве
    string s; // дополнительная переменная-строка
    char buf[80]; // буфер для ввода строк

    //Цикл ввода строк, конец ввода - пустая строка ""
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
        cout << "Самое длинное слово: " << word << endl; // само слово


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

    //Вывод нового массива
    cout << "\nМассив строк:\n";
    if (count > 0)
        for (int i = 0; i < count; i++)
            cout << "AS[" << i << "] = " << AS[i] << ::endl;
    else
        cout << "array AS is empty.";

    //После использования массива AS освободить память, выделенную для него
    delete[] AS;

}

void zadanie2(){
    string s;
    int i =1;
    ifstream file("first.txt");
    ofstream end("final.txt");

    if (!file.is_open())
        cout << "Файл не найден" << endl;
    if (file.is_open())
        cout << "Нумерация прошла успешно:)"<<endl;
    while (!file.eof())//считывает до конца файла
    {   //чтение файла и нумерация строк
        getline(file, s);
        end << i++ <<" ";
        end << s << endl;

    }
    file.close();
 }

void zadanie3() {
    const int n = 1;//кол-во записей 
    order spisok[n];
    for (int i = 0; i < n; i++) {
        cout << "Введите расчетный счет плательщика: " << endl;
        cin >> spisok[i].plat;
        cout << "Введите расчетный счет получателя: " << endl;
        cin >> spisok[i].pol;
        cout << "Описание назначения платежа: " << endl;
        cin.ignore(sizeof(int), '\n');
        getline(cin, spisok[i].descrp);
        cout << "Введите сумму: " << endl;
        cin >> spisok[i].summa;
    }

    cout << endl;

    for (int i = 0; i < n; i++) {
        unsigned int shet;
        cout << "Введите расчетный счет плательщика, чтобы узнат сумму списания:" << endl;
        cin >> shet;
        if (shet == spisok[i].plat)
            cout << "Со счета №" << spisok[i].plat << " было списано: " << spisok[i].summa << " руб." << endl;
        else
            cout << "Такого расчетного счета не существует" << endl;
        break;
    }
}
