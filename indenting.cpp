#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    string line, temp = "";
    int len;

    ifstream input("./testfile.cpp");
    ofstream output("./outfile.cpp");

    while(getline(input, line)) {
        len = line.length() - 2;
        line = temp + line;
        if(line[len]=='{') {
            temp = temp + "    ";
        }
        output<<line;
    }
    return 0;
}