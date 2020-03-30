#include <iostream>
#include <vector>
#include <string>

using namespace std;

//typedef vector<vector<int>> element_tablic;
typedef vector<vector<tuple<int, string, string>>> element_tablic;
    
extern int posledn_elem_c1 = 0;


void VivodTabl(element_tablic& kok){
    int dl, sh;
    sh = 1;
    dl = 1;
    cout << "   ";
    for (int dlina = 1; dlina <= 10; ++dlina){
        cout << dlina << " ";
    }
    cout << endl;
    for (auto i: kok){
        cout << sh << ": ";
        ++sh;
        for (auto j: i){
            cout << get<0>(j) << " ";
            }
        cout << endl;
    }
}


void Nachalo(int ishodnoe_polozh, element_tablic& kok){
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

void Prodol(int ishodnoe_polozh, element_tablic& kok){
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
 
void Dobavit_text1(int otkuda, int kuda, element_tablic& kok) {
    string new_text;
    getline(cin, new_text);
    cout << "Введите текст: ";
    cin >> new_text;
    string text_ishod = get<2>(kok[otkuda-1][kuda-1]);
    kok[otkuda-1][kuda-1] = make_tuple(1, new_text, text_ishod);
    cout << endl;
    }

void Dobavit_text2(int otkuda, int kuda, element_tablic& kok) {
    string new_text;
    getline(cin, new_text);
    cout << "Введите текст: ";
    cin >> new_text;
    string text_ishod = get<1>(kok[otkuda-1][kuda-1]);
    kok[otkuda-1][kuda-1] = make_tuple(1, text_ishod, new_text);
    cout << endl;
}

vector<int> DostupnieVershini(element_tablic kok_, int number){   //показывает списки вершин, в которые можно перейти из данной вершины
    vector<int> nomera_vershin;
    int i = 0;
    for (auto k: kok_[number-1]){
        ++i;
        if (get<0>(k) == 1){
            nomera_vershin.push_back(i);
        }
    }
    return nomera_vershin;
}

void vivod_vershin(vector<int> joj){   // позже пригодится
    for (int i: joj){
        cout << i << " ";
    }
    cout << endl;
}


void infa_element(element_tablic kok){
    cout << "Введите значение элемента по Х:";
    int x_;
    cin >> x_;
    cout << "Введите значение элемента по Y:";
    int y_;
    cin >> y_;
    cout << "Число: " << get<0>(kok[y_-1][x_-1]) << endl;
    cout << "Текст выбора: " << get<1>(kok[y_-1][x_-1]) << endl;
    cout << "Текст исхода: " << get<2>(kok[y_-1][x_-1]) << endl;
}

void text_pri_popad_na_versh(element_tablic& kok){
    cout << "Введите номер вершины из которой выходит герой (см. по Y): ";
    int nomer;
    cin >> nomer;
    cout << endl;
    cout << "Введите текст: ";
    string text;
    getline(cin, text);
    cin >> text;
    cout << endl;
    for (int i = 0; i != 10; ++i){
        int chislo = get<0>(kok[nomer-1][i]);
        string text_old = get<1>(kok[nomer-1][i]);
        kok[nomer-1][i] = make_tuple(chislo, text_old, text);
        
    //    cout << "Текст исхода: " << get<2>(kok[nomer-1][i]) << endl; // потом удалить
    };
}

void Game(const element_tablic& kok){
    int chetchik = 1;
    int place = 1;
    while (chetchik != 0){
        cout << get<2>(kok[place-1][1]) << endl;
        vector<int> nomera_vershin;
        int i = 0;
        for (auto k: kok[place-1]){
            ++i;
            if (get<0>(k) == 1){
                cout << i << " - " << get<1>(k) << endl;
            }
         }
        cout << "Выберите номера вашего хода: ";
        cin >> place;
    }
}

int main()
{
    element_tablic kok;
    kok.resize(10);
    for (int i = 0; i != 10; ++i) {
        kok[i].resize(10);
        for (int j = 0; j != 10; ++j) {
            kok[i][j] = make_tuple(0, " ", " ");
            }
    }
    
    Nachalo(1, kok);
    VivodTabl(kok);

    
    cout << "Введите 'продолжить' или 'завершить' или 'дов' = 'Текст перехода' или 'п' = Текст при попадании на данную вершину или 'игра'" << endl;
//    string komanda;
  //  getline(cin, komanda);
    int chetchik = 1;
    while (chetchik != 0){
        string komanda;
        getline(cin, komanda);
        if (komanda == "продолжить") {
            cout << "Введите номер начала развилки: ";
            int nomer;
            cin >> nomer;
    //        cout << "Доступные вершины для перехода: ";
     //       vivod_vershin(DostupnieVershini(kok, nomer));
            Prodol(nomer, kok);
            VivodTabl(kok);
            cout << "Введите команду: ";
        }
        
        if (komanda == "завершить") {
            chetchik = 0;
        }
        
        if (komanda == "дов") {
            cout << "Введите номер вершины из которой выходит герой: (см. по Y)";
            int nomer1;
            cin >> nomer1;
            cout << "Введите номер вершины в которую входит герой: (см. по X)";
            int nomer2;
            cin >> nomer2;
            Dobavit_text1(nomer1, nomer2, kok);
            
            string komanda;
            getline(cin, komanda);
        }
        
        if (komanda == "инфа") {
            infa_element(kok);
        }
        if (komanda == "п") {
            text_pri_popad_na_versh(kok);
        }
        
        if (komanda == "игра") {
            Game(kok);
        }
    }

    return 0;
    
    
}
