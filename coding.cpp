
#include <iostream>
#include <vector>
#include <sstream> 
#include <map>
using namespace std;



vector<int> _arr_target_sum() {
    int target;
    string line;
    vector<int> arr;

    vector<int> indices;
    getline(cin, line);
    stringstream ss(line);
    int number;

    while(ss >> number) {
        arr.push_back(number);
    }

    cin>>target;    

    int firstIndex, lastInde;
    unordered_map<int, int> num_map;
    // for(int i = 0; i < arr.size(); i++) {
    //     int check = arr.at(i);
    //     for(int j = i + 1; j < arr.size(); j++ ){
    //         if (check + arr[j] == target) {
    //             indices.push_back(i);
    //             indices.push_back(j);
    //         }
    //     }
    // }


    for(int i = 0; i < arr.size(); i++) {
        int complement = target - arr.at(i);
        if (num_map.find(complement) != num_map.end()) {
            indices.push_back(num_map[complement]);
            indices.push_back(i);
        }
        num_map[arr[i]] = i;
    }

    return indices;


}

 int main() {
     vector<int> indices = _arr_target_sum();
     int i = 0;
     for(; i < indices.size(); i++) {
         cout << "indices " << indices.at(i) << " & " << indices.at(++i)<< " \n" ;
     }
     return 0;
 }
