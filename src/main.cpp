#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>
#include <tuple>
#include <fstream>
#include "Header.h"

using namespace std;

typedef vector<vector<Vershina>> element_tablic; /// Тип данных для быстрого обращеня


int main() {
    string komanda;
    int posledn_elem_c1 = 0;
    int kolich_vershin = 0;
    cout << "Хотите загрузить уже готовую игру или создать новую?" << "\n";
    cout << "1 - Загрузить игру" << "\n" << "2 - Создать новую игру" << "\n";
    cout << "Введите команду: ";
    int opredelit = 0;
    cin >> opredelit;
    while (opredelit != 1 and opredelit != 2) {
        cerr << "\n" << "Введите число 1 или 2" << "\n";
        cout << "Введите команду заного ";
        cin >> opredelit;
        bool check1 = error();
        if (check1 == true) { break; }
    }
    element_tablic kok;
    if (opredelit == 1) {
        element_tablic kok_;
        kok = reading(kok_, kok, kolich_vershin);
    } else if (opredelit = 2) {
        cout << "Сколько будет вершин?" << "\n";
        cin >> kolich_vershin;

        if (cin.fail()) {
            cout << "Вы ввели не число, начните заного";
            exit(0);
        }
        while (kolich_vershin <= 0) {
            cerr << "Вершин не может быть меньше 1" << "\n";
            cerr << "Введите число заного: ";
            cin >> kolich_vershin;
            if (cin.fail()) {
                cout << "Вы ввели не число, начните заного";
                exit(0);
            };
        }

        kok.resize(kolich_vershin);
        for (int i = 0; i != kolich_vershin; ++i) {
            kok[i].resize(kolich_vershin);
            for (int j = 0; j != kolich_vershin; ++j) {
                Vershina gg{0, " ", " "};
                kok[i][j] = gg;
            }
        }


        Nachalo(1, kok, posledn_elem_c1, kolich_vershin);
        VivodTabl(kok, kolich_vershin);
    }

    komandi();
    int chetchik = 1;

    while (chetchik != 0) {
        getline(cin, komanda);

        if (komanda != "") {
            while (!IsNumber(komanda) || (stoi(komanda) < 0) || (stoi(komanda)) > 10) {
                cerr << "Вы ввели неправильное число" << "\n";
                cerr << "Введите еще раз: ";
                cin >> komanda;
            }
        }

        if (komanda == "1") {
            cout << "Введите номер начала развилки: ";

            int nomer;

            cin >> nomer;
            error_(nomer, kolich_vershin);
            bool check = error();
            if (check == true) { continue; }


            Prodol(nomer, kok, posledn_elem_c1, kolich_vershin);
            VivodTabl(kok, kolich_vershin);
            cout << "Введите команду: ";
        }

        if (komanda == "4") {
            chetchik = 0;
        }

        if (komanda == "2") {
            cout << "Введите номер вершины из которой выходит герой(см. по Y): ";
          //  bool check1;
         //   int nomer1;
            auto [check1, nomer1]  = VvodChislaPolsovat(kolich_vershin);

            if (check1 == true) { continue; }
            cout << "Введите номер вершины в которую входит герой(см. по X): ";

            auto [check2, nomer2] = VvodChislaPolsovat(kolich_vershin);

            if (check2 == true) { continue; }
            string new_text;
            getline(cin, new_text);
            cout << "Введите текст: ";
            cin >> new_text;
            Dobavit_text1(nomer1, nomer2, kok, new_text);
            TextNovoiKomandi();
        }

        if (komanda == "5") {
            infa_element(kok, kolich_vershin);
            TextNovoiKomandi();
        }
        if (komanda == "3") {
            cout << "Введите номер вершины из которой выходит герой (см. по Y): ";
            auto [check1, nomer] = VvodChislaPolsovat(kolich_vershin);

            if (check1 == true) { continue; }
            cout << "Введите текст: ";
            string text;
            getline(cin, text);
            cin >> text;
            text_pri_popad_na_versh(kok, nomer, text, kolich_vershin);
            TextNovoiKomandi();
        }

        if (komanda == "8") {
            Game(kok, kolich_vershin);
            TextNovoiKomandi();
        }

        if (komanda == "7") {
            VivodTabl(kok, kolich_vershin);
            cout << "Введите команду: ";
        }

        if (komanda == "0") {
            komandi();
            cout << "Введите команду: ";
        }

        if (komanda == "6") {
            cout << "Введите значение элемента по Х:";
            auto [check1, x] = VvodChislaPolsovat(kolich_vershin);

            if (check1 == true) { continue; }
            cout << "Введите значение элемента по Y:";

            auto [check2, y] = VvodChislaPolsovat(kolich_vershin);
            if (check2 == true) { continue; }
            add_new_vershina(kok, x, y);
            TextNovoiKomandi();
        }

        if (komanda == "9") {
            writing(kok);
        }
        if (komanda == "10") {
            element_tablic kok_;
            kok = reading(kok_, kok, kolich_vershin);
            komandi();
        }
    }
    return 0;
}
