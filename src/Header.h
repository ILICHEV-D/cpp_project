#include <vector>
#include <string>

using namespace std;


extern struct Vershina{int chislo;string text1;string text2;};

typedef vector<vector<Vershina>> element_tablic;

extern void VivodTabl(element_tablic& kok);
extern void Nachalo(int ishodnoe_polozh, element_tablic& kok);
extern void Prodol(int ishodnoe_polozh, element_tablic& kok);
extern void Dobavit_text1(int otkuda, int kuda, element_tablic& kok, string new_text);
extern void text_pri_popad_na_versh(element_tablic& kok, int nomer, string text);
extern void infa_element(element_tablic kok);
extern void add_new_vershina(element_tablic& kok, int x, int y);
extern void Game(const element_tablic& kok);
//extern int main();


extern void komandi();
extern element_tablic reading(element_tablic& kok_);
extern void writing(element_tablic& kok);
