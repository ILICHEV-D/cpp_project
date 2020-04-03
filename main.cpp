#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>
#include <tuple>
#include <fstream>


using namespace std;

typedef vector<vector<tuple<int, string, string>>> element_tablic; /// Тип данных для быстрого обращеня
    
extern int posledn_elem_c1 = 0;
extern int kolich_vershin = 0;

extern bool error(){ ///Ловим ошибки пользователя
    if (std::cin.fail()){
        std::cin.clear();
        cout << "   !!!" << endl << "!Вы ввели не число, выберите команду заного!" << endl << "   !!!" << endl;
        return true;
    }
    return false;
}

void VivodTabl(element_tablic& kok){    ///Выводит  матрицу смежности пользователю
    int dl, sh;
    sh = 1;
    dl = 1;
    cout << "   ";
    for (int dlina = 1; dlina <= kolich_vershin; ++dlina){
        cout << setw(3) << dlina;
    }
    cout << endl;
    for (auto i: kok){
        cout << setw(2) << sh << ": ";
        ++sh;
        for (auto j: i){
            cout << setw(2) << get<0>(j) << " ";
            }
        cout << endl;
    }
}
 
void Nachalo(int ishodnoe_polozh, element_tablic& kok){    ///Добавляет первые разветвления от первой вершины
    cout << "Сколько развилок вы хотите?" << endl;
    int kolichestvo_razvilok;
    cin >> kolichestvo_razvilok;
    int kol_raz1 = kolichestvo_razvilok;
    posledn_elem_c1 = ishodnoe_polozh + kolichestvo_razvilok - 1;
    for (kolichestvo_razvilok; kolichestvo_razvilok !=0; --kolichestvo_razvilok){
        string first = get<1>(kok[ishodnoe_polozh-1][ishodnoe_polozh - 1 + kolichestvo_razvilok]);
        string second = get<2>(kok[ishodnoe_polozh-1][ishodnoe_polozh - 1 + kolichestvo_razvilok]);
        kok[ishodnoe_polozh-1][ishodnoe_polozh - 1 + kolichestvo_razvilok] = make_tuple(1, first, second);
    }
    cout << "Теперь из ветки номер " << ishodnoe_polozh << " выходят ветки с номерами ";
    for (kol_raz1; kol_raz1 !=0; --kol_raz1){
        cout << kolichestvo_razvilok + kol_raz1 + 1<< " ";
    }
    cout << endl;
}

void Prodol(int ishodnoe_polozh, element_tablic& kok){    ///Добавляет новые разветвления с определенной вершины
    cout << "Сколько развилок вы хотите?" << endl;
    int kolichestvo_razvilok;
    cin >> kolichestvo_razvilok;
    int kol_raz1 = kolichestvo_razvilok;
    int kol_raz2 = kolichestvo_razvilok;
    for (kolichestvo_razvilok; kolichestvo_razvilok !=0; --kolichestvo_razvilok){
        string first = get<1>(kok[ishodnoe_polozh-1][posledn_elem_c1 + kolichestvo_razvilok]);
        string second = get<2>(kok[ishodnoe_polozh-1][posledn_elem_c1 + kolichestvo_razvilok]);
        kok[ishodnoe_polozh-1][posledn_elem_c1 + kolichestvo_razvilok] = make_tuple(1, first, second);
    }
    cout << "Теперь из ветки номер " << ishodnoe_polozh << " выходят ветки с номерами ";
    for (kol_raz1; kol_raz1 !=0; --kol_raz1){
        cout << posledn_elem_c1 + kol_raz1 + 1<< " ";
    }
    cout << endl;
    posledn_elem_c1 += kol_raz2;
}
 
void Dobavit_text1(int otkuda, int kuda, element_tablic& kok) { ///Добавляет текст вершины, когда на нее ещё не зашли
    string new_text;
    getline(cin, new_text);
    cout << "Введите текст: ";
    cin >> new_text;
    string text_ishod = get<2>(kok[otkuda-1][kuda-1]);
    kok[otkuda-1][kuda-1] = make_tuple(1, new_text, text_ishod);
    }

void text_pri_popad_na_versh(element_tablic& kok){    ///Добавляет текст вершины, когда на нее уже зашли
    cout << "Введите номер вершины из которой выходит герой (см. по Y): ";
    int nomer;
    cin >> nomer;
    bool check1 = error();
    if (check1 == true){return;}
    cout << "Введите текст: ";
    string text;
    getline(cin, text);
    cin >> text;
    for (int i = 0; i != kolich_vershin; ++i){
        int chislo = get<0>(kok[nomer-1][i]);
        string text_old = get<1>(kok[nomer-1][i]);
        kok[nomer-1][i] = make_tuple(chislo, text_old, text);
    };
}

void infa_element(element_tablic kok){  /// Выводит  информацию о определенной вершине графа
    cout << "Введите значение элемента по Х:";
    int x_;
    cin >> x_;
    bool check1 = error();
    if (check1 == true){return;}
    cout << "Введите значение элемента по Y:";
    int y_;
    cin >> y_;
    bool check2 = error();
    if (check2 == true){return;}
    cout << "Число: " << get<0>(kok[y_-1][x_-1]) << endl;
    cout << "Текст выбора: " << get<1>(kok[y_-1][x_-1]) << endl;
    cout << "Текст исхода: " << get<2>(kok[y_-1][x_-1]) << endl;
}

void add_new_vershina(element_tablic& kok){  /// Связывает вершины
    cout << "Введите значение элемента по Х:";
    int x;
    cin >> x;
    bool check1 = error();
    if (check1 == true){return;}
    cout << "Введите значение элемента по Y:";
    int y;
    cin >> y;
    bool check2 = error();
    if (check2 == true){return;}
    kok[y-1][x-1] = make_tuple(1,"", "");
}
    
    
void Game(const element_tablic& kok){  /// Начинает игру
    int chetchik = 1;
    int place = 1;
    bool check = true;
    while (chetchik != 0){
        cout << get<2>(kok[place-1][1]) << endl;
        int i = 0;
        bool check = false;
        for (auto k: kok[place-1]){
            ++i;
            if (get<0>(k) == 1){
                cout << i << " - " << get<1>(k) << endl;
                check = true;
            }
         }
        if (check == false){
            chetchik = 0;
            cout << "Конец игры" << endl;
        }
        else {
        cout << "Выберите номера вашего хода: ";
        cin >> place;
        bool check1 = error();
        if (check1 == true){return;}
        }
    }
}

void komandi(){  ///Выводит доступные команды
        cout << "Выберите команду:" << endl << " 0 - 'Вывести список команд'" << endl << " 1 - 'Продолжить создавать разветвления'" << endl << " 2 - 'Добавить текст перехода из одной вершины в другую'" << endl << " 3 - 'Добавить текст при попадании на данную вершину'" << endl << " 4 - 'Завершить'" << endl << " 5 - 'Информация о вершине'" << endl << " 6 - 'Связать две вершины'" << endl << " 7 - 'Вывести таблицу'" << endl <<" 8 - 'Начать игру'" << endl << " 9 - 'Сохранить'" << endl << "10 - 'Открыть игру из файла" << endl;
}

int main()
{
    cout << "Сколько будет вершин?" << endl;
    cin >> kolich_vershin;
    element_tablic kok;
    kok.resize(kolich_vershin);
    for (int i = 0; i != kolich_vershin; ++i) {
        kok[i].resize(kolich_vershin);
        for (int j = 0; j != kolich_vershin; ++j) {
            kok[i][j] = make_tuple(0, " ", " ");
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
            Dobavit_text1(nomer1, nomer2, kok);
            cout << "Готово" << endl;
            cout << "Введите команду: ";
        }
        
        if (komanda == "5") {
            infa_element(kok);
            cout << "Готово" << endl;
            cout << "Введите команду: ";
        }
        if (komanda == "3") {
            text_pri_popad_na_versh(kok);
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
        add_new_vershina(kok);
        cout << "Готово" << endl;
        cout << "Введите команду: ";
        }
        
        if (komanda == "9"){
            string path = "input1.txt";
            ofstream fout;
            fout.open(path, ofstream::app);
            if (!fout.is_open()){
                cout << "Не найден файл" << endl;
            }
            else
            {
         //       fout.write((char*)&kok, sizeof(kok));
                int dlina = kok.size();
                cout << dlina;
                fout << dlina << endl;
                for (int i = 0; i < dlina; ++i){
                    for (int j = 0; j < dlina; ++j){
                        fout << get<0>(kok[i][j]) <<  ";" << get<1>(kok[i][j]) << ";" << get<2>(kok[i][j]) << ";" <<endl;
                    }
                }
                cout << "Файл успешно сохранён" << endl;
            }
            fout.close();
            
        }
        if (komanda == "10") {
            element_tablic kok_;
            string path = "input1.txt";
            ifstream output;
            output.open(path);
            if (!output.is_open()){
                cout << "Не найден файл" << endl;
            }
            else{

                int kolich_vershin_;
                output >> kolich_vershin;
                
                string stroka;
                getline(output, stroka);

                
                kok_.resize(kolich_vershin);
                for (int i = 0; i != kolich_vershin; ++i) {
                    kok_[i].resize(kolich_vershin);
                    string stroka;
                        
                    for (int j = 0; j != kolich_vershin; ++j) {
                        int check_ = 0;
                        int chislo_;
                        string obch;
                        string text1_ , text2_, stroka;
                        getline(output, stroka);
                        for (int k = 0; k < stroka.size(); ++k){
                            if (stroka[k] != ';'){
                                obch.push_back(stroka[k]);
                            }
                            else{
                                check_ += 1;
                                if (check_ == 1){
                                    chislo_ = stoi(obch);
                                    obch.clear();
                                }
                                if (check_ == 2){
                                    text1_ = obch;
                                    obch.clear();
                                }
                                if (check_ == 3){
                                    text2_ = obch;
                                    obch.clear();
                                }
                            }
                        }

                        kok_[i][j] = make_tuple(chislo_, text1_, text2_);

                        }
                }
                cout << "Файл успешно открыт" << endl;
            }
            kok = kok_;
        }
    }
    return 0;
}


