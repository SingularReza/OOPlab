#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    string line;
    int no, count, setno = 0;

    ifstream input("./inputfile.txt");

    getline(input, line);
    no = stoi(line);

    int vertices[no], connected[no], hold[2];
    no = 0;

    while(getline(input,line)) {
        int i = 0, j = 0;
        string temp = "";

        while(i++) {
            if(line[i]!=' '||line[i]!='\0') {
                temp = temp+line[i];
            }
            else {
                hold[j] = stoi(temp);
                j++;
            }
        }

        for(int h = 0; i<=1; i++) {
            count = no;
            while(count>=0) {
                if(hold[i]==vertices[count]) {
                    break;
                }
                count--;
            }
            if(count==0) {
                vertices[++no] = hold[i];
                connected[no] = ++setno; 
            } 
        }
    }

}