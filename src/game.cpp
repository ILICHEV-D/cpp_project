#include "Header.h"

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

typedef vector<vector<Vershina>> element_tablic; /// Тип данных для быстрого обращеня

extern bool error() {
    if (cin.fail()) {
        cin.clear();
        cerr << "   !!!" << "\n" << "!Вы ввели не число, выберите команду заного!" << "\n" << "   !!!" << "\n";
        return true;
    }
    return false;
}

extern void error_(int &nomer_vershini, int &kolich_vershin) {
    while ((kolich_vershin < nomer_vershini) || (nomer_vershini < 0)) {
        cerr << "Номер этой вершины выходит за рамки общего количества вершин" << "\n";
        cerr << "Введите заного количество вершин не больше  " << kolich_vershin << "\n";
        cout << "Введите: ";
        cin >> nomer_vershini;
    }
}

void TextNovoiKomandi() {
    cout << "Готово" << "\n";
    cout << "Введите команду: ";
}

void VivodTabl(element_tablic &kok, int &kolich_vershin) {
    int dl, sh;
    sh = 1;
    dl = 1;
    cout << "   ";
    for (int dlina = 1; dlina <= kolich_vershin; ++dlina) {
        cout << setw(3) << dlina;
    }
    cout << "\n";
    for (auto i: kok) {
        cout << setw(2) << sh << ": ";
        ++sh;
        for (auto j: i) {
            cout << setw(2) << j.chislo << " ";
        }
        cout << "\n";
    }
}

void Nachalo(int ishodnoe_polozh, element_tablic &kok, int &posledn_elem_c1, int &kolich_vershin) {
    cout << "Сколько развилок вы хотите?" << "\n";
    int kolichestvo_razvilok;
    cin >> kolichestvo_razvilok;

    if (cin.fail()) {
        cout << "Вы ввели не число, начните заного";
        exit(0);
    }
    while ((kolich_vershin <= kolichestvo_razvilok) || (kolichestvo_razvilok < 0)) {
        cerr << "Количество развилок выходит за рамки общего количества вершин" << "\n";
        cerr << "Введите заного количество вершин не больше  " << kolich_vershin << "\n";
        cout << "Введите: ";
        cin >> kolichestvo_razvilok;
        if (cin.fail()) {
            cout << "Вы ввели не число, начните заного";
            exit(0);
        };
    }
    int kol_raz1 = kolichestvo_razvilok;
    posledn_elem_c1 = ishodnoe_polozh + kolichestvo_razvilok - 1;
    for (kolichestvo_razvilok; kolichestvo_razvilok != 0; --kolichestvo_razvilok) {
        string first = kok[ishodnoe_polozh - 1][ishodnoe_polozh - 1 + kolichestvo_razvilok].text1;
        string second = kok[ishodnoe_polozh - 1][ishodnoe_polozh - 1 + kolichestvo_razvilok].text2;
        Vershina gg{1, first, second};
        kok[ishodnoe_polozh - 1][ishodnoe_polozh - 1 + kolichestvo_razvilok] = gg;
    }
    cout << "Теперь из ветки номер " << ishodnoe_polozh << " выходят ветки с номерами ";
    for (kol_raz1; kol_raz1 != 0; --kol_raz1) {
        cout << kolichestvo_razvilok + kol_raz1 + 1 << " ";
    }
    cout << "\n";
}

void Prodol(int ishodnoe_polozh, element_tablic &kok, int &posledn_elem_c1, int &kolich_vershin) {
    cout << "Сколько развилок вы хотите?" << "\n";
    int kolichestvo_razvilok;
    cin >> kolichestvo_razvilok;
    error_(kolichestvo_razvilok, kolich_vershin);
    bool check1 = error();
    if (check1 == true) { return; }
    int kol_raz1 = kolichestvo_razvilok;
    int kol_raz2 = kolichestvo_razvilok;
    for (kolichestvo_razvilok; kolichestvo_razvilok != 0; --kolichestvo_razvilok) {
        string first = kok[ishodnoe_polozh - 1][posledn_elem_c1 + kolichestvo_razvilok].text1;
        string second = kok[ishodnoe_polozh - 1][posledn_elem_c1 + kolichestvo_razvilok].text2;
        Vershina gg{1, first, second};
        kok[ishodnoe_polozh - 1][posledn_elem_c1 + kolichestvo_razvilok] = gg;
    }
    cout << "Теперь из ветки номер " << ishodnoe_polozh << " выходят ветки с номерами ";
    for (kol_raz1; kol_raz1 != 0; --kol_raz1) {
        cout << posledn_elem_c1 + kol_raz1 + 1 << " ";
    }
    cout << "\n";
    posledn_elem_c1 += kol_raz2;
}

void Dobavit_text1(int otkuda, int kuda, element_tablic &kok,
                   string new_text) {
    string text_ishod = kok[otkuda - 1][kuda - 1].text2;
    Vershina gg_{1, new_text, text_ishod};
    kok[otkuda - 1][kuda - 1] = gg_;
}

tuple<bool, int> VvodChislaPolsovat(int &kolich_vershin) {
    int chislo;
    cin >> chislo;
    error_(chislo, kolich_vershin);
    bool check1 = error();
    return make_tuple(check1, chislo);
}

void text_pri_popad_na_versh(element_tablic &kok, int nomer,
                             string text, int &kolich_vershin) {

    for (int i = 0; i != kolich_vershin; ++i) {
        int chislo = kok[nomer - 1][i].chislo;
        string text_old = kok[nomer - 1][i].text1;
        Vershina gg__{chislo, text_old, text};
        kok[nomer - 1][i] = gg__;
    };
}

void infa_element(element_tablic kok, int &kolich_vershin) {
    cout << "Введите значение элемента по Х:";
    bool check1;
    int x_;
    tie(check1, x_) = VvodChislaPolsovat(kolich_vershin);

    if (check1 == true) { return; }
    cout << "Введите значение элемента по Y:";

    bool check2;
    int y_;
    tie(check2, y_) = VvodChislaPolsovat(kolich_vershin);
    if (check2 == true) { return; }
    cout << "Число: " << kok[y_ - 1][x_ - 1].chislo << "\n";
    cout << "Текст выбора: " << kok[y_ - 1][x_ - 1].text1 << "\n";
    cout << "Текст исхода: " << kok[y_ - 1][x_ - 1].text2 << "\n";
}

void add_new_vershina(element_tablic &kok, int x, int y) {
    Vershina gg___{1, "", ""};
    kok[y - 1][x - 1] = gg___;
}


void Game(const element_tablic &kok, int &kolich_vershin) {
    int chetchik = 1;
    int place = 1;
    bool check = true;
    while (chetchik != 0) {
        cout << kok[place - 1][1].text2 << "\n";
        int i = 0;
        bool check = false;
        for (auto k: kok[place - 1]) {
            ++i;
            if (k.chislo == 1) {
                cout << i << " - " << k.text1 << "\n";
                check = true;
            }
        }
        if (check == false) {
            chetchik = 0;
            cout << "Конец игры" << "\n";
        } else {
            cout << "Выберите номера вашего хода: ";
            cin >> place;
            error_(place, kolich_vershin);
            bool check1 = error();
            if (check1 == true) { return; }
        }
    }
}

void komandi() {
    cout << "Выберите команду:" << "\n" << " 0 - 'Вывести список команд'" << "\n"
         << " 1 - 'Продолжить создавать разветвления'" << "\n"
         << " 2 - 'Добавить текст перехода из одной вершины в другую'" << "\n"
         << " 3 - 'Добавить текст при попадании на данную вершину'" << "\n" << " 4 - 'Завершить'" << "\n"
         << " 5 - 'Информация о вершине'" << "\n" << " 6 - 'Связать две вершины'" << "\n" << " 7 - 'Вывести таблицу'"
         << "\n" << " 8 - 'Начать игру'" << "\n" << " 9 - 'Сохранить'" << "\n" << "10 - 'Открыть игру из файла" << "\n";
}


void writing(element_tablic &kok) {
    string path = "input1.txt";
    ofstream fout;
    fout.open(path);
    if (!fout.is_open()) {
        cout << "Не найден файл" << "\n";
    } else {
        int dlina = kok.size();
        fout << dlina << "\n";
        for (int i = 0; i < dlina; ++i) {
            for (int j = 0; j < dlina; ++j) {
                fout << "X к.: " << j << ", Y к.: " << i << "    |" << kok[i][j].chislo << ";" << kok[i][j].text1 << ";"
                     << kok[i][j].text2 << ";" << "\n";
            }
        }
        cout << "Файл успешно сохранён" << "\n";
    }
    fout.close();
}

bool IsNumber(const string &s) {
    return all_of(s.cbegin(), s.cend(), [](const char &c) {
        return isdigit(c);
    });
}

element_tablic reading(element_tablic &kok_, element_tablic &kok_zapasnoi, int &kolich_vershin) {
    int chet_error = 0;

    string path = "input1.txt";
    ifstream output;
    output.open(path);
    if (!output.is_open()) {
        cout << "Не найден файл" << "\n";
    } else {
        output >> kolich_vershin;

        if (kolich_vershin == 0) {
            cerr << "Некоректные исходные данные в файле" << "\n";
            return (kok_zapasnoi);
        }

        string stroka;
        getline(output, stroka);


        kok_.resize(kolich_vershin);
        for (int i = 0; i != kolich_vershin; ++i) {
            kok_[i].resize(kolich_vershin);
            string stroka;

            for (int j = 0; j != kolich_vershin; ++j) {
                int check_ = 0;
                int chislo_ = -1;
                string obch;
                string text1_, text2_, stroka;
                getline(output, stroka);
                for (int k = 0; k < stroka.size(); ++k) {
                    if (stroka[k] == '|') {
                        obch.clear();
                        continue;
                    }
                    if (stroka[k] != ';') {
                        obch.push_back(stroka[k]);
                    } else {
                        check_ += 1;

                        if (check_ == 1) {
                            if (!IsNumber(obch)) {
                                cerr << "Некоректные исходные данные в файле" << "\n";
                                return (kok_zapasnoi);
                            }
                            chislo_ = stoi(obch);
                            obch.clear();
                            chet_error += 1;
                        }
                        if (check_ == 2) {
                            text1_ = obch;
                            obch.clear();
                        }
                        if (check_ == 3) {
                            text2_ = obch;
                            obch.clear();
                        }
                    }
                }
                if (chislo_ != 1 && chislo_ != 0) {
                    cerr << "Некоректные исходные данные в файле" << "\n";
                    return (kok_zapasnoi);
                }
                Vershina gg_{chislo_, text1_, text2_};
                kok_[i][j] = gg_;
            }
        }

        if (chet_error != kolich_vershin * kolich_vershin) {
            cerr << "Некоректные исходные данные в файле" << "\n";
            return (kok_zapasnoi);
        }

        cout << "Файл успешно открыт" << "\n";
    }
    return kok_;
}
