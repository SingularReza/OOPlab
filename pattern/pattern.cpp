#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main() {
    int height, width = 1;
    string line = "", line2 = "";
    cin>>height;
    int temp = height;

    while(height--) {
        line = line+to_string(width);
        line2 = line+line2;
        cout<<setw(temp+width-1)<<line2<<endl;
        line2 = line;
        width++;
    }

    return 0;
}