#include <fstream>      // ifstream
#include <iostream>     // cout
#include <string>       // string, stoi
#include <string_view>  // string_view
#include <chrono>       // high_resolution_clock, duration_cast, nanoseconds
#include <sstream>      // stringstream
#include <vector>


#include "data_structure.hpp"

using namespace std;
using namespace itis;


static constexpr auto DATASET_PATH = "C:\\Users\\Mapct\\project\\Study\\semester-work-avl-tree\\dataset\\data";

int main(){
    const auto path = string(DATASET_PATH);
    const auto data_amount = 14;
    const string values_array[data_amount] = {"100", "500", "1000", "5000", "10000", "25000", "50000",
            "100000", "250000", "500000", "750000", "1000000", "2500000", "5000000"};

    string folders[10] = {"01", "02", "03", "04", "05", "06", "07", "08", "09", "10"};

    string line;
    string field;
    vector<int> list;
    for(int iter = 0; iter < 14; iter ++) {
        cout << "=========== " << values_array[iter] << " ==========" << endl;
        for(string set: folders) {
            for(int i = 0; i < 10; i ++) {

                AVLTree tree;

                string current_path = path + "\\" + set + "\\" + values_array[iter] + ".csv";


                auto input_file = ifstream(current_path);

                //заполняю массив данными
                while (getline(input_file, line)) {
                    stringstream ss(line);

                    while (getline(ss, field, ',')) {
                        if (field == "") {
//                        cout << "----------------" << field << endl;
                            field = "124538";
                        }
                        if (field.size() > 7) field = "353134";
                        int key = stoi(field);
                        list.push_back(key);
                    }
                }

                auto time_point_before = chrono::steady_clock::now();

                for (int key: list){
                    tree.insert(key);
                }

                auto time_point_after = chrono::steady_clock::now();

                // переводим время в наносекунды
                auto time_diff = time_point_after - time_point_before;
                long time_elapsed_ns = chrono::duration_cast<chrono::nanoseconds>(time_diff).count();

                if (time_elapsed_ns < 0) {
                    cout << time_elapsed_ns * -1 << endl;
                } else {
                    cout << time_elapsed_ns << endl;
                }

                list.clear();
                line.clear();
                field.clear();
            }
        }
    }
    return 0;
}
