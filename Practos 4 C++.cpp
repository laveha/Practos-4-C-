#include <iostream>
#include <string>
#include <algorithm>
#include <random>
#include <Windows.h>
using namespace std;
int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");

    wstring word = L"";
    int choice;

    wcout << L"Введите слово: ";
    wcin >> word;

    wcout << L"Выберите действие:\n1. Вывести слово задом наперед\n2. Вывести слово без гласных букв\n3. Вывести слово без согласных букв\n4. Рандомно вывести буквы данного слова" << endl;
    cin >> choice;

    switch (choice) {
    case 1:
        reverse(word.begin(), word.end());
        break;
    case 2:
        word.erase(remove_if(word.begin(), word.end(), [](wchar_t c) { return wstring(L"ауоиэыяюеёАУОИЭЫЯЮЕЁ").find(c) != wstring::npos; }), word.end());
        break;
    case 3:
        word.erase(remove_if(word.begin(), word.end(), [](wchar_t c) { return wstring(L"бвгджзйклмнпрстфхцчшщБВГДЖЗЙКЛМНПРСТФХЦЧШЩ").find(c) != wstring::npos; }), word.end());
        break;
    case 4:
        random_device rd;
        mt19937 g(rd());
        shuffle(word.begin(), word.end(), g);
        break;
    default:
        wcout << L"Некорректный выбор." << endl;
    }

    wcout << L"Результат: " << word;

    return 0;
}