#include <stdio.h>

#include "main.cpp"
#include <iostream>
#include <cassert>


using namespace std;

bool EqualFile(string name1, string name2){
    bool check = true;
    ifstream file1(name1);
    ifstream  file2(name2);
    string str1, str2;
    while (getline(file1, str1)) {
        getline(file2, str2);
        if (str1 != str2){
            check = false;
        }
    }
    if (getline(file2, str1)){
        check = false;
    }
    return check;
}


void Test1() { // разветвление
    fstream clear_file("input1.txt", ios::out);
    fstream clear_file_("input2.txt", ios::out);

    const string way = "input1.txt";
    ofstream fout(way);
    fout << " 3\nX к.: 0, Y к.: 0    |0; ;Hello.;\nX к.: 1, Y к.: 0    |1;love;Hello.;\nX к.: 2, Y к.: 0    |1;death;Hello.;\nX к.: 0, Y к.: 1    |0; ;WIN;\nX к.: 1, Y к.: 1    |0; ;WIN;\nX к.: 2, Y к.: 1    |0; ;WIN;\nX к.: 0, Y к.: 2    |0; ;LOSE;\nX к.: 1, Y к.: 2    |0; ;LOSE;\nX к.: 2, Y к.: 2    |0; ;LOSE;" << endl;

    element_tablic kok1_, kok1;
    kok1 = reading(kok1_);

    Dobavit_text1(1, 2, kok1, "YES");
    text_pri_popad_na_versh(kok1, 2, "OH");
    add_new_vershina(kok1, 2, 3);


    fstream clear_file__("input1.txt", ios::out);
    writing(kok1);


    string path_ = "input2.txt";
    ofstream fout_;
    fout_.open(path_, ofstream::app);
    fout_ << "3\nX к.: 0, Y к.: 0    |0; ;Hello.;\nX к.: 1, Y к.: 0    |1;YES;Hello.;\nX к.: 2, Y к.: 0    |1;death;Hello.;\nX к.: 0, Y к.: 1    |0; ;OH;\nX к.: 1, Y к.: 1    |0; ;OH;\nX к.: 2, Y к.: 1    |0; ;OH;\nX к.: 0, Y к.: 2    |0; ;LOSE;\nX к.: 1, Y к.: 2    |1;;;\nX к.: 2, Y к.: 2    |0; ;LOSE;" << endl;

    assert(EqualFile("input1.txt", "input2.txt"));
    cout << "Тест 1 пройден" << endl;

}


void Test2() {    //линеный
    fstream clear_file("input1.txt", ios::out);
    fstream clear_file_("input2.txt", ios::out);

    const string way = "input1.txt";
    ofstream fout(way);
    fout <<  "3\nX к.: 0, Y к.: 0    |0; ;first;\nX к.: 1, Y к.: 0    |1;go;first;\nX к.: 2, Y к.: 0    |0; ;first;\nX к.: 0, Y к.: 1    |0; ;second;\nX к.: 1, Y к.: 1    |0; ;second;\nX к.: 2, Y к.: 1    |1;go!;second;\nX к.: 0, Y к.: 2    |0; ;win;\nX к.: 1, Y к.: 2    |0; ;win;\nX к.: 2, Y к.: 2    |0; ;win;" << endl;

    element_tablic kok1_, kok1;
    kok1 = reading(kok1_);

    Dobavit_text1(1, 2, kok1, "hmm");
    text_pri_popad_na_versh(kok1, 1, "FIRST");
    add_new_vershina(kok1, 1, 3);


    fstream clear_file__("input1.txt", ios::out);
    writing(kok1);


    string path_ = "input2.txt";
    ofstream fout_;
    fout_.open(path_, ofstream::app);
    fout_ << "3\nX к.: 0, Y к.: 0    |0; ;FIRST;\nX к.: 1, Y к.: 0    |1;hmm;FIRST;\nX к.: 2, Y к.: 0    |0; ;FIRST;\nX к.: 0, Y к.: 1    |0; ;second;\nX к.: 1, Y к.: 1    |0; ;second;\nX к.: 2, Y к.: 1    |1;go!;second;\nX к.: 0, Y к.: 2    |1;;;\nX к.: 1, Y к.: 2    |0; ;win;\nX к.: 2, Y к.: 2    |0; ;win;" << endl;

    assert(EqualFile("input1.txt", "input2.txt"));
    cout << "Тест 2 пройден" << endl;
}

void Test3() {    //замкнутый круг
    fstream clear_file("input1.txt", ios::out);
    fstream clear_file_("input2.txt", ios::out);

    const string way = "input1.txt";
    ofstream fout(way);
    fout <<  "3\nX к.: 0, Y к.: 0    |0; ;fi;\nX к.: 1, Y к.: 0    |1; ;fi;\nX к.: 2, Y к.: 0    |0; ;fi;\nX к.: 0, Y к.: 1    |0; ;se;\nX к.: 1, Y к.: 1    |0; ;se;\nX к.: 2, Y к.: 1    |1; ;se;\nX к.: 0, Y к.: 2    |1;;th;\nX к.: 1, Y к.: 2    |0; ;th;\nX к.: 2, Y к.: 2    |0; ;th;" << endl;

    element_tablic kok1_, kok1;
    kok1 = reading(kok1_);

    text_pri_popad_na_versh(kok1, 1, "AAA");
    text_pri_popad_na_versh(kok1, 2, "BBB");
    text_pri_popad_na_versh(kok1, 3, "CCC");

    Dobavit_text1(1, 2, kok1, "a");
    Dobavit_text1(2, 3, kok1, "b");
    Dobavit_text1(3, 1, kok1, "c");

    fstream clear_file__("input1.txt", ios::out);
    writing(kok1);

    string path_ = "input2.txt";
    ofstream fout_;
    fout_.open(path_, ofstream::app);
    fout_ << "3\nX к.: 0, Y к.: 0    |0; ;AAA;\nX к.: 1, Y к.: 0    |1;a;AAA;\nX к.: 2, Y к.: 0    |0; ;AAA;\nX к.: 0, Y к.: 1    |0; ;BBB;\nX к.: 1, Y к.: 1    |0; ;BBB;\nX к.: 2, Y к.: 1    |1;b;BBB;\nX к.: 0, Y к.: 2    |1;c;CCC;\nX к.: 1, Y к.: 2    |0; ;CCC;\nX к.: 2, Y к.: 2    |0; ;CCC;" << endl;

    assert(EqualFile("input1.txt", "input2.txt"));
    cout << "Тест 3 пройден" << endl;
}