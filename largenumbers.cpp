#include <iostream>
#include<fstream>
#include <string>

using namespace std;

class Arithmetic {

    private:
        string input1;
        string input2;
        string output;

    public:
        //sets input values
        void input(string in1, string in2) {
            input1 = in1;
            input2 = in2;
        }

        string add() {
            //no adds 0 to smaller string to make their length equal
            int no = 0, no1, no2;
            //string length
            int len1 = input1.length()-2;
            int len2 = input2.length()-1;
            cout<<len1<<'\n'<<len2<<endl;
            no = len1-len2;

            //string to held the "000.." part to be appended
            string temp;

            if(no) {
                while(no) {
                    temp = temp+'0';
                    no--;
                }
                input2 = temp+input2;
            }
            else {
                no = no*-1;
                while(no) {
                    temp = temp+'0';
                    no--;
                }
                input1 = temp+input1;
                len1 = len2;
            }
            no = 0;
            cout<<output<<endl;
            while(len1>=0) {
                no1 = input1[len1] - '0';
                no2 = input2[len1] - '0';
                no = no1+no2+no;
                no1 = no%10;
                no = no/10;
                
                //appending the 1's part of the added number to the resultant string
                output = to_string(no1)+output;
                len1--;
            }

            return output;
        };
}; 

int main() {
    string line1, line2;
    ifstream inputfile("./inputfile.txt");
    Arithmetic calc;
    getline(inputfile, line1);
    getline(inputfile, line2);

    calc.input(line1, line2);
    
    cout<<calc.add()<<endl;

    return 0;
}