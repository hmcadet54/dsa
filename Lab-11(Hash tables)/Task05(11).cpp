#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

void matchNutsAndBolts(vector<char>& nuts, vector<char>& bolts) {
    unordered_map<char, int> nutHash;

    for (int i = 0; i < nuts.size(); i++) {
        nutHash[nuts[i]] = i;
    }

    for (int i = 0; i < bolts.size(); i++) {
        if (nutHash.find(bolts[i]) != nutHash.end()) {
            nuts[i] = bolts[i];
        }
    }

    cout << "Matched Nuts and Bolts:" << endl;
    for (int i = 0; i < nuts.size(); i++) {
        cout << nuts[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < bolts.size(); i++) {
        cout << bolts[i] << " ";
    }
    cout << endl;
}

int main() {
    vector<char> nuts = {'@', '%', '$', '#', '^'};
    vector<char> bolts = {'%', '@', '#', '$', '^'};

    matchNutsAndBolts(nuts, bolts);

    return 0;
}
