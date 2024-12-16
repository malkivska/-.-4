#include <iostream>
using namespace std;

// Оголошення функцій
void SortDec3(float &A, float &B, float &C); // Завдання 1: Сортування трьох чисел за спаданням
void Proc16();                              // Головна процедура для Завдання 1
bool is_valid_coords(int x, int y);         // Завдання 2: Перевірка коректності координат шахівниці
bool is_white(int x, int y);                // Завдання 2: Перевірка, чи клітинка біла
void Boolean34();                           // Головна процедура для Завдання 2
bool is_three_digit(int num);               // Завдання 3: Перевірка, чи введено трицифрове число
int swap_digits(int num);                   // Завдання 3: Перестановка десятків і одиниць
void Integer16();                           // Головна процедура для Завдання 3
void Menu();                                // Завдання 4: Меню для вибору задач

// Завдання 1: Сортування трьох чисел за спаданням
void SortDec3(float &A, float &B, float &C) {
    if (A < B) swap(A, B);
    if (A < C) swap(A, C);
    if (B < C) swap(B, C);
}

void Proc16() {
    float A, B, C;
    cout << "Введіть три числа: ";
    cin >> A >> B >> C;
    SortDec3(A, B, C);
    cout << "Відсортовані за спаданням: " << A << " " << B << " " << C << endl;
}

// Завдання 2: Перевірка коректності координат шахівниці
bool is_valid_coords(int x, int y) {
    return (x >= 1 && x <= 8 && y >= 1 && y <= 8); // Координати в межах шахівниці
}

// Завдання 2: Перевірка кольору шахівної клітинки
bool is_white(int x, int y) {
    return (x + y) % 2 != 0; // Білими є клітинки з непарною сумою координат
}

void Boolean34() {
    int x, y;
    cout << "Введіть координати шахівниці (x, y): ";
    cin >> x >> y;

    if (!is_valid_coords(x, y)) {
        cout << "Некоректне введення! Координати повинні бути в діапазоні 1-8." << endl;
        return;
    }

    if (is_white(x, y)) {
        cout << "Клітинка біла." << endl;
    } else {
        cout << "Клітинка чорна." << endl;
    }
}

// Завдання 3: Перевірка, чи число трицифрове
bool is_three_digit(int num) {
    return (num >= 100 && num <= 999); // Перевірка, чи число трицифрове
}

// Завдання 3: Перестановка десятків і одиниць
int swap_digits(int num) {
    int hundreds = num / 100;
    int tens = (num / 10) % 10;
    int ones = num % 10;
    return hundreds * 100 + ones * 10 + tens; // Заміна десятків і одиниць
}

void Integer16() {
    int num;
    cout << "Введіть трицифрове число: ";
    cin >> num;

    if (!is_three_digit(num)) {
        cout << "Некоректне введення! Число повинно бути трицифровим." << endl;
        return;
    }

    int result = swap_digits(num);
    cout << "Результат: " << result << endl;
}

// Завдання 4: Меню
void Menu() {
    int choice;
    do {
        cout << "\nМеню:\n";
        cout << "1. Завдання 1 (Сортування чисел)\n";
        cout << "2. Завдання 2 (Колір шахівної клітинки)\n";
        cout << "3. Завдання 3 (Перестановка цифр)\n";
        cout << "0. Вихід\n";
        cout << "Ваш вибір: ";
        cin >> choice;

        switch (choice) {
        case 1:
            Proc16();
            break;
        case 2:
            Boolean34();
            break;
        case 3:
            Integer16();
            break;
        case 0:
            cout << "Програма завершена." << endl;
            break;
        default:
            cout << "Некоректний вибір! Спробуйте знову." << endl;
        }
    } while (choice != 0);
}

// Головна функція
int main() {
    Menu();
    return 0;
}
