#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    string line, temp = "";
    int len;

    ifstream input("./input.txt");
    ofstream output("./outfile.txt");

    while(getline(input, line)) {
        len = line.length() - 2;
        line = temp + line;
        if(line[len]=='{') {
            temp = temp + "    ";
        }
        output<<line;
        if(line[len]=='}') {
            temp = temp.erase(len, len-4);
        }
    }
    return 0;
}