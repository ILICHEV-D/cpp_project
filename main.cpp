#include <iostream>
#include <vector>

using namespace std;
 
extern int posledn_elem_c1 = 0;


void VivodTabl(vector<vector<int>>& kok){
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
            cout << j << " ";
            }
        cout << endl;
    }
}


void Nachalo(int ishodnoe_polozh, vector<vector<int>>& kok){
    cout << "Сколько развилок вы хотите?" << endl;
    int kolichestvo_razvilok;
    cin >> kolichestvo_razvilok;
    int kol_raz1 = kolichestvo_razvilok;
    posledn_elem_c1 = ishodnoe_polozh + kolichestvo_razvilok - 1;
    for (kolichestvo_razvilok; kolichestvo_razvilok !=0; --kolichestvo_razvilok){
        kok[ishodnoe_polozh-1][ishodnoe_polozh - 1 + kolichestvo_razvilok] = 1;
    }
    cout << "Теперь из ветки номер " << ishodnoe_polozh << " выходят ветки с номерами ";
    for (kol_raz1; kol_raz1 !=0; --kol_raz1){
        cout << kolichestvo_razvilok + kol_raz1 + 1<< " ";
    }
    cout << endl;
}

void Prodol(int ishodnoe_polozh, vector<vector<int>>& kok){
    cout << "Сколько развилок вы хотите?" << endl;
    int kolichestvo_razvilok;
    cin >> kolichestvo_razvilok;
    int kol_raz1 = kolichestvo_razvilok;
    int kol_raz2 = kolichestvo_razvilok;
    for (kolichestvo_razvilok; kolichestvo_razvilok !=0; --kolichestvo_razvilok){
        kok[ishodnoe_polozh-1][posledn_elem_c1 + kolichestvo_razvilok] = 1;
    }
    cout << "Теперь из ветки номер " << ishodnoe_polozh << " выходят ветки с номерами ";
    for (kol_raz1; kol_raz1 !=0; --kol_raz1){
        cout << posledn_elem_c1 + kol_raz1 + 1<< " ";
    }
    cout << endl;
    posledn_elem_c1 += kol_raz2;
}
 
int main()
{
    
    
    vector<vector<int>> kok;
    kok.resize(10);
    for (int i = 0; i != 10; ++i) {
        kok[i].resize(10);
        for (int j = 0; j != 10; ++j) {
            kok[i][j] = 0;
            }
    }
    
    Nachalo(1, kok);
    VivodTabl(kok);
    
    cout << "Введите 'продолжить' или 'завершить'" << endl;
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
            Prodol(nomer, kok);
            VivodTabl(kok);
            cout << "Введите команду: ";

        }
        if (komanda == "завершить") {
            chetchik = 0;
        }
        if (komanda == "добавить описание") {
            chetchik = 0;
        }
    }
    
    

    return 0;
    
    
}
