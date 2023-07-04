#include <iostream>
#include <Windows.h>
#include <time.h>
#include <stdlib.h>
#include <string>
using namespace std;

void pole(char POLE[9]) {
    cout << "[" << " " << POLE[0] << " " << "]" << "[" << " " << POLE[1] << " " << "]" << "[" << " " << POLE[2] << " " << "]" << endl;
    cout << "[" << " " << POLE[3] << " " << "]" << "[" << " " << POLE[4] << " " << "]" << "[" << " " << POLE[5] << " " << "]" << endl;
    cout << "[" << " " << POLE[6] << " " << "]" << "[" << " " << POLE[7] << " " << "]" << "[" << " " << POLE[8] << " " << "]" << endl;
}

bool checkwin(char POLE[9]) {
    for (int i = 0; i < 7; i += 3) {
        if (POLE[i] == POLE[i + 1] && POLE[i] == POLE[i + 2])
            return true;
    }
    for (int i = 0; i < 3; i++) {
        if (POLE[i] == POLE[i + 3] && POLE[i] == POLE[i + 6])
            return true;
    }
    if ((POLE[0] == POLE[4] && POLE[0] == POLE[8]) || (POLE[2] == POLE[4] && POLE[2] == POLE[6]))
        return true;
    return false;
}

bool checkdraw(char POLE[9]) {
    for (int i = 0; i < 9; i++) {
        if (POLE[i] != 'x' && POLE[i] != 'o') {
            return false;
        }
    }
    return true;
}

int main()
{
    srand((unsigned)time(NULL));
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    char player = 'x';
    char POLE[9] = { '1', '2', '3', '4', '5', '6', '7', '8', '9' };
    int krock;

    string tere = "------------------------------------------------------------------------------------------------------------------------";
    string peredmova = "Ласкаво просимо до гри хрестики-нулики! Щоб почати гру, введіть 1, щоб прочитати правила, введіть 2. ";
    int pochatok;

    cout << peredmova << endl << tere << endl;
    cin >> pochatok;


    if (pochatok == 1) {
        bool play = true;
        while (play) {
            int mode;
            cout << endl << tere << "Виберіть режим гри" << endl << tere << endl;
            cout << "1 - User-User" << endl;
            cout << "2 - User-PC" << endl;
            cout << "3 - PC-PC" << endl << tere << endl;
            cin >> mode;
            cout << endl << tere;
            bool perevirka = true;

            if (mode == 1) {
                do {
                    pole(POLE);
                    cout << tere << "Будь ласка, введіть номер клітинки: " << endl << tere << endl;
                    cin >> krock;
                    cout << endl << tere;

                    if (player == 'x') {
                        if (krock >= 1 && krock <= 9 && POLE[krock - 1] != 'x' && POLE[krock - 1] != 'o') {
                            POLE[krock - 1] = 'x';
                            player = 'o';
                        }
                        else {
                            cout << "ТАК НЕ МОЖНА ПОХОДИТИ!" << endl << tere << endl;
                            continue;
                        }
                        if (checkwin(POLE)) {
                            pole(POLE);
                            cout << endl << tere;
                            cout << "Преміг гравець Х" << endl;
                            break;
                        }
                    }
                    else if (player == 'o') {
                        if (krock >= 1 && krock <= 9 && POLE[krock - 1] != 'x' && POLE[krock - 1] != 'o') {
                            POLE[krock - 1] = 'o';
                            player = 'x';
                        }
                        else {
                            cout << "ТАК НЕ МОЖНА ПОХОДИТИ!" << endl << tere << endl;
                            continue;
                        }
                        if (checkwin(POLE)) {
                            pole(POLE);
                            cout << endl << tere;
                            cout << "Преміг гравець o" << endl;
                            break;
                        }
                    }
                    perevirka = true;
                    if (checkdraw(POLE)) {
                        pole(POLE);
                        cout << endl << tere;
                        cout << "Гра завершилася нічиєю!" << endl;
                        break;
                    }
                } while (krock <= 9);
                break;
            }
            if (mode == 2) {
                do {
                    pole(POLE);
                    if (player == 'x') {
                        cout << tere << "Будь ласка, введіть номер клітинки: " << endl << tere << endl;
                        cin >> krock;
                        cout << endl << tere;
                        if (krock >= 1 && krock <= 9 && POLE[krock - 1] != 'x' && POLE[krock - 1] != 'o') {
                            POLE[krock - 1] = 'x';
                            player = 'o';
                        }
                        else {
                            cout << "ТАК НЕ МОЖНА ПОХОДИТИ!" << endl << tere << endl;
                            continue;
                        }
                        if (checkwin(POLE)) {
                            pole(POLE);
                            cout << endl << tere;
                            cout << "Преміг гравець Х" << endl;
                            break;
                        }
                    }
                    else {
                        cout << tere << "Вибір комп'ютера: " << endl << tere << endl;
                        krock = rand() % 9;
                        if (krock >= 1 && krock <= 9 && POLE[krock - 1] != 'x' && POLE[krock - 1] != 'o') {
                            cout << krock << endl << tere;
                            POLE[krock - 1] = 'o';
                            player = 'x';
                        }
                        if (checkwin(POLE)) {
                            pole(POLE);
                            cout << endl << tere;
                            cout << "Преміг гравець o" << endl;
                            break;
                        }
                    }
                    perevirka = true;
                    if (checkdraw(POLE)) {
                        pole(POLE);
                        cout << endl << tere;
                        cout << "Гра завершилася нічиєю!" << endl;
                        break;
                    }
                } while (krock <= 9);
                break;
            }
            if (mode == 3) {
                do {
                    pole(POLE);
                    if (player == 'x') {
                        cout << tere << "Вибір комп'ютера НОМЕР 1: " << endl << tere << endl;
                        do {
                            krock = rand() % 9 + 1;
                        } while (POLE[krock - 1] == 'x' || POLE[krock - 1] == 'o');

                        cout << krock << endl << tere;
                        POLE[krock - 1] = 'x';
                        player = 'o';

                        if (checkwin(POLE)) {
                            pole(POLE);
                            cout << endl << tere;
                            cout << "Преміг гравець Х" << endl;
                            break;
                        }
                    }
                    else {
                        cout << tere << "Вибір комп'ютера НОМЕР 2: " << endl << tere << endl;
                        do {
                            krock = rand() % 9 + 1;
                        } while (POLE[krock - 1] == 'x' || POLE[krock - 1] == 'o');

                        cout << krock << endl << tere;
                        POLE[krock - 1] = 'o';
                        player = 'x';

                        if (checkwin(POLE)) {
                            pole(POLE);
                            cout << endl << tere;
                            cout << "Преміг гравець o" << endl;
                            break;
                        }
                    }
                    perevirka = true;
                    if (checkdraw(POLE)) {
                        pole(POLE);
                        cout << endl << tere;
                        cout << "Гра завершилася нічиєю!" << endl;
                        break;
                    }
                } while (krock <= 9);
                break;

            }
            else {
                cout << "Введіть правильний режим!" << endl;
            }
        }
    }
    else if (pochatok == 2) {
        cout << "Хрестики-нулики — гра на папері для двох гравців. На кожному ході гравці мають ставити O чи X на ґратці розміром 3 на 3. Гравець, який першим поставив три однакові фігури в ряд по вертикалі, горизонталі або діагоналі, виграє. У випадку, якщо всі клітинки на ґратці заповнені, а жоден гравець не зібрав трьох фігур в ряд, гра вважається нічиєю." << endl;
        cout << tere;
        cout << main();
    }
    else {
        cout << tere;
        cout << "Введіть правильний варіант!" << endl;
        cout << tere;
        cout << main();
    }

}