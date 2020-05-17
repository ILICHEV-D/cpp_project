#include <vector>
#include <string>
#include <tuple>

using namespace std;


extern struct Vershina {
    int chislo; /// Число, которое показывает, связь вершин в таблице смежности
    string text1; /// Текст, описывающий вершину, когда не нее еще не зашли
    string text2; /// Текст, описывающий вершину, когда не нее уже зашли
};

typedef vector<vector<Vershina>> element_tablic;

extern void error_(int &nomer_vershini, int &kolich_vershin); ///Ловим ошибки пользователя при вводе определенной вершины

extern bool error(); ///Ловим ошибки пользователя

extern void VivodTabl(element_tablic &kok, int &kolich_vershin); ///Выводит  матрицу смежности пользователю

extern void Nachalo(int ishodnoe_polozh, element_tablic &kok, int &posledn_elem_c1, int &kolich_vershin); ///Добавляет первые разветвления от первой вершины

extern void Prodol(int ishodnoe_polozh, element_tablic &kok, int &posledn_elem_c1, int &kolich_vershin); ///Добавляет новые разветвления с определенной вершины

extern void Dobavit_text1(int otkuda, int kuda, element_tablic &kok, string new_text); ///Добавляет текст вершины, когда на нее ещё не зашли

extern void text_pri_popad_na_versh(element_tablic &kok, int nomer, string text, int &kolich_vershin); ///Добавляет текст вершины, когда на нее уже зашли

extern void TextNovoiKomandi(); ///  Выводит текст завершения функции и просьбы написать номер новой команды

extern void infa_element(element_tablic kok, int &kolich_vershin); /// Выводит  информацию о определенной вершине графа

extern void add_new_vershina(element_tablic &kok, int x, int y); /// Связывает вершины

extern void Game(const element_tablic &kok, int &kolich_vershin); /// Начинает игру

extern bool IsNumber(const string &s); /// Находит в строке числа

extern tuple<bool, int> VvodChislaPolsovat(int &kolich_vershin); /// Возвращает ошибку пользователю, если указана несуществующая вершина

extern void komandi(); ///Выводит доступные команды

extern element_tablic reading(element_tablic &kok_, element_tablic &kok_zapasnoi, int &kolich_vershin); /// Считывает данные с текстового фалйа

extern void writing(element_tablic &kok); /// Заносит данные таблицы смежности в текстовый файл
