#include <iostream>
#include <vector>
#include <fstream>
//#include "data_structure.hpp"

using namespace std;

int main() {
    string path = "C:\\Users\\Mapct\\project\\Study\\semester-work-avl-tree\\src\\5.csv";
    ifstream fin;
    fin.open(path);

    string  s;
    char array[50];

//    getline(fin, s);
//    cout << s << endl;

    fin.get(array, 50);
    cout << array << endl;

    fin.get(array, 50);
    cout << array << endl;




    fin.close();

//    itis::AVLTree tree;
//    for(int i = 1; i < 6; i++){
//        tree.insert(i);
//    }
//    tree.remove(4);
//    tree.remove(5);
    return 0;
}