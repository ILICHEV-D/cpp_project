#include "Header.h"

#include <iostream>
#include <cassert>

#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include <string>
#include <random>
#include <sstream>


using namespace std;

bool EqualFile(string name1, string name2) {
    bool check = true;
    ifstream file1(name1);
    ifstream file2(name2);
    string str1, str2;
    while (getline(file1, str1)) {
        getline(file2, str2);
        if (str1 != str2) {
            check = false;
        }
    }
    if (getline(file2, str1)) {
        check = false;
    }
    return check;
}


TEST_CASE("First") { //разветвление
    char newline = '\n';
    const string way = "input1.txt";
    ofstream fout(way);
    fout
            << R"(3)" << newline << R"(X к.: 0, Y к.: 0    |0; ;Hello.;)" << newline
            << R"(X к.: 1, Y к.: 0    |1;love;Hello.;)" << newline << R"(X к.: 2, Y к.: 0    |1;death;Hello.;)"
            << newline << R"(X к.: 0, Y к.: 1    |0; ;WIN;)" << newline << R"(X к.: 1, Y к.: 1    |0; ;WIN;)" << newline
            << R"(X к.: 2, Y к.: 1    |0; ;WIN;)" << newline << R"(X к.: 0, Y к.: 2    |0; ;LOSE;)" << newline
            << R"(X к.: 1, Y к.: 2    |0; ;LOSE;)" << newline << R"(X к.: 2, Y к.: 2    |0; ;LOSE;)"
            << endl;

    element_tablic kok1_, kok1;
    int kolich_vershin = 0;
    kok1 = reading(kok1_, kok1_, kolich_vershin);


    Dobavit_text1(1, 2, kok1, "YES");
    writing(kok1);
    string path_ = "input2.txt";
    ofstream fout_;
    fout_.open(path_);
    fout_
            << R"(3)" << newline << R"(X к.: 0, Y к.: 0    |0; ;Hello.;)" << newline
            << R"(X к.: 1, Y к.: 0    |1;YES;Hello.;)" << newline << R"(X к.: 2, Y к.: 0    |1;death;Hello.;)"
            << newline << R"(X к.: 0, Y к.: 1    |0; ;WIN;)" << newline << R"(X к.: 1, Y к.: 1    |0; ;WIN;)" << newline
            << R"(X к.: 2, Y к.: 1    |0; ;WIN;)" << newline << R"(X к.: 0, Y к.: 2    |0; ;LOSE;)" << newline
            << R"(X к.: 1, Y к.: 2    |0; ;LOSE;)" << newline << R"(X к.: 2, Y к.: 2    |0; ;LOSE;)"
            << endl;
    REQUIRE(EqualFile("input1.txt", "input2.txt") == true);
    fout_.close();

    text_pri_popad_na_versh(kok1, 2, "OH", kolich_vershin);

    writing(kok1);
    fout_.open(path_);
    fout_
            << R"(3)" << newline << R"(X к.: 0, Y к.: 0    |0; ;Hello.;)" << newline
            << R"(X к.: 1, Y к.: 0    |1;YES;Hello.;)" << newline << R"(X к.: 2, Y к.: 0    |1;death;Hello.;)"
            << newline << R"(X к.: 0, Y к.: 1    |0; ;OH;)" << newline << R"(X к.: 1, Y к.: 1    |0; ;OH;)" << newline
            << R"(X к.: 2, Y к.: 1    |0; ;OH;)" << newline << R"(X к.: 0, Y к.: 2    |0; ;LOSE;)" << newline
            << R"(X к.: 1, Y к.: 2    |0; ;LOSE;)" << newline << R"(X к.: 2, Y к.: 2    |0; ;LOSE;)"
            << endl;
    REQUIRE(EqualFile("input1.txt", "input2.txt") == true);
    fout_.close();


    add_new_vershina(kok1, 2, 3);
    writing(kok1);
    fout_.open(path_);
    fout_
            << R"(3)" << newline << R"(X к.: 0, Y к.: 0    |0; ;Hello.;)" << newline
            << R"(X к.: 1, Y к.: 0    |1;YES;Hello.;)" << newline << R"(X к.: 2, Y к.: 0    |1;death;Hello.;)"
            << newline << R"(X к.: 0, Y к.: 1    |0; ;OH;)" << newline << R"(X к.: 1, Y к.: 1    |0; ;OH;)" << newline
            << R"(X к.: 2, Y к.: 1    |0; ;OH;)" << newline << R"(X к.: 0, Y к.: 2    |0; ;LOSE;)" << newline
            << R"(X к.: 1, Y к.: 2    |1;;;)" << newline << R"(X к.: 2, Y к.: 2    |0; ;LOSE;)"
            << endl;

    REQUIRE(EqualFile("input1.txt", "input2.txt") == true);
}


TEST_CASE("Second") {   //линеный
    char newline = '\n';
    const string way = "input1.txt";
    ofstream fout(way);
    fout
            << R"(3)" << newline << R"(X к.: 0, Y к.: 0    |0; ;first;)" << newline
            << R"(X к.: 1, Y к.: 0    |1;go;first;)" << newline << R"(X к.: 2, Y к.: 0    |0; ;first;)" << newline
            << R"(X к.: 0, Y к.: 1    |0; ;second;)" << newline << R"(X к.: 1, Y к.: 1    |0; ;second;)" << newline
            << R"(X к.: 2, Y к.: 1    |1;go!;second;)" << newline << R"(X к.: 0, Y к.: 2    |0; ;win;)" << newline
            << R"(X к.: 1, Y к.: 2    |0; ;win;)" << newline << R"(X к.: 2, Y к.: 2    |0; ;win;)"
            << endl;

    element_tablic kok1_, kok1;
    int kolich_vershin = 0;
    kok1 = reading(kok1_, kok1_, kolich_vershin);

    Dobavit_text1(1, 2, kok1, "hmm");
    writing(kok1);
    string path_ = "input2.txt";
    ofstream fout_;
    fout_.open(path_);
    fout_
            << R"(3)" << newline << R"(X к.: 0, Y к.: 0    |0; ;first;)" << newline
            << R"(X к.: 1, Y к.: 0    |1;hmm;first;)" << newline << R"(X к.: 2, Y к.: 0    |0; ;first;)" << newline
            << R"(X к.: 0, Y к.: 1    |0; ;second;)" << newline << R"(X к.: 1, Y к.: 1    |0; ;second;)" << newline
            << R"(X к.: 2, Y к.: 1    |1;go!;second;)" << newline << R"(X к.: 0, Y к.: 2    |0; ;win;)" << newline
            << R"(X к.: 1, Y к.: 2    |0; ;win;)" << newline << R"(X к.: 2, Y к.: 2    |0; ;win;)"
            << endl;
    REQUIRE(EqualFile("input1.txt", "input2.txt") == true);
    fout_.close();


    text_pri_popad_na_versh(kok1, 1, "FIRST", kolich_vershin);
    writing(kok1);
    fout_.open(path_);
    fout_
            << R"(3)" << newline << R"(X к.: 0, Y к.: 0    |0; ;FIRST;)" << newline
            << R"(X к.: 1, Y к.: 0    |1;hmm;FIRST;)" << newline << R"(X к.: 2, Y к.: 0    |0; ;FIRST;)" << newline
            << R"(X к.: 0, Y к.: 1    |0; ;second;)" << newline << R"(X к.: 1, Y к.: 1    |0; ;second;)" << newline
            << R"(X к.: 2, Y к.: 1    |1;go!;second;)" << newline << R"(X к.: 0, Y к.: 2    |0; ;win;)" << newline
            << R"(X к.: 1, Y к.: 2    |0; ;win;)" << newline << R"(X к.: 2, Y к.: 2    |0; ;win;)"
            << endl;
    REQUIRE(EqualFile("input1.txt", "input2.txt") == true);
    fout_.close();


    add_new_vershina(kok1, 1, 3);
    writing(kok1);

    fout_.open(path_);
    fout_
            << R"(3)" << newline << R"(X к.: 0, Y к.: 0    |0; ;FIRST;)" << newline
            << R"(X к.: 1, Y к.: 0    |1;hmm;FIRST;)" << newline << R"(X к.: 2, Y к.: 0    |0; ;FIRST;)" << newline
            << R"(X к.: 0, Y к.: 1    |0; ;second;)" << newline << R"(X к.: 1, Y к.: 1    |0; ;second;)" << newline
            << R"(X к.: 2, Y к.: 1    |1;go!;second;)" << newline << R"(X к.: 0, Y к.: 2    |1;;;)" << newline
            << R"(X к.: 1, Y к.: 2    |0; ;win;)" << newline << R"(X к.: 2, Y к.: 2    |0; ;win;)"
            << endl;

    REQUIRE(EqualFile("input1.txt", "input2.txt") == true);
}

TEST_CASE("Third") {    //замкнутый круг
    char newline = '\n';
    const string way = "input1.txt";
    ofstream fout(way);
    fout
            << R"(3)" << newline << R"(X к.: 0, Y к.: 0    |0; ;fi;)" << newline << R"(X к.: 1, Y к.: 0    |1; ;fi;)"
            << newline << R"(X к.: 2, Y к.: 0    |0; ;fi;)" << newline << R"(X к.: 0, Y к.: 1    |0; ;se;)" << newline
            << R"(X к.: 1, Y к.: 1    |0; ;se;)" << newline << R"(X к.: 2, Y к.: 1    |1; ;se;)" << newline
            << R"(X к.: 0, Y к.: 2    |1;;th;)" << newline << R"(X к.: 1, Y к.: 2    |0; ;th;)" << newline
            << R"(X к.: 2, Y к.: 2    |0; ;th;)"
            << endl;

    element_tablic kok1_, kok1;
    int kolich_vershin = 0;
    kok1 = reading(kok1_, kok1_, kolich_vershin);

    text_pri_popad_na_versh(kok1, 1, "AAA", kolich_vershin);
    text_pri_popad_na_versh(kok1, 2, "BBB", kolich_vershin);
    text_pri_popad_na_versh(kok1, 3, "CCC", kolich_vershin);

    writing(kok1);
    string path_ = "input2.txt";
    ofstream fout_;
    fout_.open(path_);
    fout_
            << R"(3)" << newline << R"(X к.: 0, Y к.: 0    |0; ;AAA;)" << newline << R"(X к.: 1, Y к.: 0    |1; ;AAA;)"
            << newline << R"(X к.: 2, Y к.: 0    |0; ;AAA;)" << newline << R"(X к.: 0, Y к.: 1    |0; ;BBB;)" << newline
            << R"(X к.: 1, Y к.: 1    |0; ;BBB;)" << newline << R"(X к.: 2, Y к.: 1    |1; ;BBB;)" << newline
            << R"(X к.: 0, Y к.: 2    |1;;CCC;)" << newline << R"(X к.: 1, Y к.: 2    |0; ;CCC;)" << newline
            << R"(X к.: 2, Y к.: 2    |0; ;CCC;)"
            << endl;

    REQUIRE(EqualFile("input1.txt", "input2.txt") == true);
    fout_.close();

    Dobavit_text1(1, 2, kok1, "a");
    Dobavit_text1(2, 3, kok1, "b");
    Dobavit_text1(3, 1, kok1, "c");
    writing(kok1);

    fout_.open(path_);
    fout_
            << R"(3)" << newline << R"(X к.: 0, Y к.: 0    |0; ;AAA;)" << newline << R"(X к.: 1, Y к.: 0    |1;a;AAA;)"
            << newline << R"(X к.: 2, Y к.: 0    |0; ;AAA;)" << newline << R"(X к.: 0, Y к.: 1    |0; ;BBB;)" << newline
            << R"(X к.: 1, Y к.: 1    |0; ;BBB;)" << newline << R"(X к.: 2, Y к.: 1    |1;b;BBB;)" << newline
            << R"(X к.: 0, Y к.: 2    |1;c;CCC;)" << newline << R"(X к.: 1, Y к.: 2    |0; ;CCC;)" << newline
            << R"(X к.: 2, Y к.: 2    |0; ;CCC;)"
            << endl;

    REQUIRE(EqualFile("input1.txt", "input2.txt") == true);
}

