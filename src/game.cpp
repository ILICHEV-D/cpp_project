#include "Header.h"

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

typedef vector<vector<Vershina>> element_tablic; /// Тип данных для быстрого обращеня

extern int posledn_elem_c1 = 0;
extern int kolich_vershin = 0;

extern bool error() { ///Ловим ошибки пользователя
    if (cin.fail()) {
        cin.clear();
        cerr << "   !!!" << endl << "!Вы ввели не число, выберите команду заного!" << endl << "   !!!" << endl;
        return true;
    }
    return false;
}

extern void error_(int &nomer_vershini) {
    while ((kolich_vershin < nomer_vershini) || (nomer_vershini < 0)) {
        cerr << "Номер этой вершины выходит за рамки общего количества вершин" << endl;
        cerr << "Введите заного количество вершин не больше  " << kolich_vershin << endl;
        cout << "Введите: ";
        cin >> nomer_vershini;
    }
}


void VivodTabl(element_tablic &kok) {    ///Выводит  матрицу смежности пользователю
    int dl, sh;
    sh = 1;
    dl = 1;
    cout << "   ";
    for (int dlina = 1; dlina <= kolich_vershin; ++dlina) {
        cout << setw(3) << dlina;
    }
    cout << endl;
    for (auto i: kok) {
        cout << setw(2) << sh << ": ";
        ++sh;
        for (auto j: i) {
            cout << setw(2) << j.chislo << " ";
        }
        cout << endl;
    }
}

void Nachalo(int ishodnoe_polozh, element_tablic &kok) {    ///Добавляет первые разветвления от первой вершины
    cout << "Сколько развилок вы хотите?" << endl;
    int kolichestvo_razvilok;
    cin >> kolichestvo_razvilok;

    if (cin.fail()) {
        cout << "Вы ввели не число, начните заного";
        exit(0);
    }
    while ((kolich_vershin <= kolichestvo_razvilok) || (kolichestvo_razvilok < 0)) {
        cerr << "Количество развилок выходит за рамки общего количества вершин" << endl;
        cerr << "Введите заного количество вершин не больше  " << kolich_vershin << endl;
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
    cout << endl;
}

void Prodol(int ishodnoe_polozh, element_tablic &kok) {    ///Добавляет новые разветвления с определенной вершины
    cout << "Сколько развилок вы хотите?" << endl;
    int kolichestvo_razvilok;
    cin >> kolichestvo_razvilok;
    error_(kolichestvo_razvilok);
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
    cout << endl;
    posledn_elem_c1 += kol_raz2;
}

void Dobavit_text1(int otkuda, int kuda, element_tablic &kok,
                   string new_text) { ///Добавляет текст вершины, когда на нее ещё не зашли
    string text_ishod = kok[otkuda - 1][kuda - 1].text2;
    Vershina gg_{1, new_text, text_ishod};
    kok[otkuda - 1][kuda - 1] = gg_;
}

void text_pri_popad_na_versh(element_tablic &kok, int nomer,
                             string text) {    ///Добавляет текст вершины, когда на нее уже зашли

    for (int i = 0; i != kolich_vershin; ++i) {
        int chislo = kok[nomer - 1][i].chislo;
        string text_old = kok[nomer - 1][i].text1;
        Vershina gg__{chislo, text_old, text};
        kok[nomer - 1][i] = gg__;
    };
}

void infa_element(element_tablic kok) {  /// Выводит  информацию о определенной вершине графа
    cout << "Введите значение элемента по Х:";
    int x_;
    cin >> x_;
    error_(x_);
    bool check1 = error();
    if (check1 == true) { return; }
    cout << "Введите значение элемента по Y:";
    int y_;
    cin >> y_;
    error_(y_);
    bool check2 = error();
    if (check2 == true) { return; }
    cout << "Число: " << kok[y_ - 1][x_ - 1].chislo << endl;
    cout << "Текст выбора: " << kok[y_ - 1][x_ - 1].text1 << endl;
    cout << "Текст исхода: " << kok[y_ - 1][x_ - 1].text2 << endl;
}

void add_new_vershina(element_tablic &kok, int x, int y) {  /// Связывает вершины
    Vershina gg___{1, "", ""};
    kok[y - 1][x - 1] = gg___;
}


void Game(const element_tablic &kok) {  /// Начинает игру
    int chetchik = 1;
    int place = 1;
    bool check = true;
    while (chetchik != 0) {
        cout << kok[place - 1][1].text2 << endl;
        int i = 0;
        bool check = false;
        for (auto k: kok[place - 1]) {
            ++i;
            if (k.chislo == 1) {
                cout << i << " - " << k.text1 << endl;
                check = true;
            }
        }
        if (check == false) {
            chetchik = 0;
            cout << "Конец игры" << endl;
        } else {
            cout << "Выберите номера вашего хода: ";
            cin >> place;
            error_(place);
            bool check1 = error();
            if (check1 == true) { return; }
        }
    }
}

void komandi() {  ///Выводит доступные команды
    cout << "Выберите команду:" << endl << " 0 - 'Вывести список команд'" << endl
         << " 1 - 'Продолжить создавать разветвления'" << endl
         << " 2 - 'Добавить текст перехода из одной вершины в другую'" << endl
         << " 3 - 'Добавить текст при попадании на данную вершину'" << endl << " 4 - 'Завершить'" << endl
         << " 5 - 'Информация о вершине'" << endl << " 6 - 'Связать две вершины'" << endl << " 7 - 'Вывести таблицу'"
         << endl << " 8 - 'Начать игру'" << endl << " 9 - 'Сохранить'" << endl << "10 - 'Открыть игру из файла" << endl;
}


void writing(element_tablic &kok) {
    string path = "input1.txt";
    ofstream fout;
    fout.open(path);
    if (!fout.is_open()) {
        cout << "Не найден файл" << endl;
    } else {
        int dlina = kok.size();
        fout << dlina << endl;
        for (int i = 0; i < dlina; ++i) {
            for (int j = 0; j < dlina; ++j) {
                fout << "X к.: " << j << ", Y к.: " << i << "    |" << kok[i][j].chislo << ";" << kok[i][j].text1 << ";"
                     << kok[i][j].text2 << ";" << endl;
            }
        }
        cout << "Файл успешно сохранён" << endl;
    }
    fout.close();
}

bool IsNumber(const string &s) {
    return all_of(s.cbegin(), s.cend(), [](const char &c) {
        return isdigit(c);
    });
}

element_tablic reading(element_tablic &kok_, element_tablic &kok_zapasnoi) {
    int chet_error = 0;

    string path = "input1.txt";
    ifstream output;
    output.open(path);
    if (!output.is_open()) {
        cout << "Не найден файл" << endl;
    } else {
        output >> kolich_vershin;

        if (kolich_vershin == 0) {
            cerr << "Некоректные исходные данные в файле" << endl;
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
                                cerr << "Некоректные исходные данные в файле" << endl;
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
                    cerr << "Некоректные исходные данные в файле" << endl;
                    return (kok_zapasnoi);
                }
                Vershina gg_{chislo_, text1_, text2_};
                kok_[i][j] = gg_;
            }
        }

        if (chet_error != kolich_vershin * kolich_vershin) {
            cerr << "Некоректные исходные данные в файле" << endl;
            return (kok_zapasnoi);
        }

        cout << "Файл успешно открыт" << endl;
    }
    return kok_;
}
