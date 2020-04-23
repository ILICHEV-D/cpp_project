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

extern int posledn_elem_c1 = 0;
extern int kolich_vershin = 0;

int main()
{
    cout << "Сколько будет вершин?" << endl;
    cin >> kolich_vershin;
    element_tablic kok;
    kok.resize(kolich_vershin);
    for (int i = 0; i != kolich_vershin; ++i) {
        kok[i].resize(kolich_vershin);
        for (int j = 0; j != kolich_vershin; ++j) {
            Vershina gg{0, " ", " "};
            kok[i][j] = gg;
        }
    }

    Nachalo(1, kok);
    VivodTabl(kok);

    komandi();
    int chetchik = 1;
    while (chetchik != 0){
        string komanda;
        getline(cin, komanda);
        if (komanda == "1") {
            cout << "Введите номер начала развилки: ";
            int nomer;
            cin >> nomer;

            bool check = error();
            if (check == true){continue;}

            Prodol(nomer, kok);
            VivodTabl(kok);
            cout << "Введите команду: ";
        }

        if (komanda == "4") {
            chetchik = 0;
        }

        if (komanda == "2") {
            cout << "Введите номер вершины из которой выходит герой(см. по Y): ";
            int nomer1;
            cin >> nomer1;
            bool check1 = error();
            if (check1 == true){continue;}
            cout << "Введите номер вершины в которую входит герой(см. по X): ";
            int nomer2;
            cin >> nomer2;
            bool check2 = error();
            if (check2 == true){continue;}
            string new_text;
            getline(cin, new_text);
            cout << "Введите текст: ";
            cin >> new_text;
            Dobavit_text1(nomer1, nomer2, kok, new_text);
            cout << "Готово" << endl;
            cout << "Введите команду: ";
        }

        if (komanda == "5") {
            infa_element(kok);
            cout << "Готово" << endl;
            cout << "Введите команду: ";
        }
        if (komanda == "3") {
            cout << "Введите номер вершины из которой выходит герой (см. по Y): ";
            int nomer;
            cin >> nomer;
            bool check1 = error();
            if (check1 == true){continue;}
            cout << "Введите текст: ";
            string text;
            getline(cin, text);
            cin >> text;
            text_pri_popad_na_versh(kok, nomer, text);
            cout << "Готово" << endl;
            cout << "Введите команду: ";
        }

        if (komanda == "8") {
            Game(kok);
            cout << "Готово" << endl;
            cout << "Введите команду: ";
        }

        if (komanda == "7") {
            VivodTabl(kok);
            cout << "Введите команду: ";
        }

        if (komanda == "0"){
            komandi();
            cout << "Введите команду: ";
        }

        if (komanda == "6"){
            cout << "Введите значение элемента по Х:";
            int x;
            cin >> x;
            bool check1 = error();
            if (check1 == true){continue;}
            cout << "Введите значение элемента по Y:";
            int y;
            cin >> y;
            bool check2 = error();
            if (check2 == true){continue;}
            add_new_vershina(kok, x, y);
            cout << "Готово" << endl;
            cout << "Введите команду: ";
        }

        if (komanda == "11"){
            fstream clear_file("input1.txt", ios::out);
            clear_file.close();
            cout << "Готово" << endl;
            cout << "Введите команду: ";
        }

        if (komanda == "9"){
            writing(kok);
        }
        if (komanda == "10") {
            element_tablic kok_;
            kok = reading(kok_);
        }
    }
    return 0;
}
