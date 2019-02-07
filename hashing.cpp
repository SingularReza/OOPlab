#include <iostream>

using namespace std;

void insert(int k, int **table, int count) {
    int row[2];
    row[0] = k%10;
    row[1] = k;
    table[count] = &row[0];
};

void search(int k, int **table) {
    int i = 0;

    while(i <= 2) {
        int *row = table[i];
        cout<<&row<<endl;
        /*if(table[i][1] == k) {
            cout<<"Found"<<endl;
        }*/
        i++;
    }
};

void print(int **table) {

};

void del(int k, int **table) {

};

int main() {
    int input, i = 0, choice = 1;
    int **p;

    while(choice) {
        cout<<"Enter a value"<<endl;
        cin>>input;

        p = (int **)malloc(sizeof(int *)*(i+1)*4);

        insert(input, p, i);
        i++;

        cout<<"1.continue 0. exit"<<endl;
        cin>>choice;
    }

    cout<<"search"<<endl;
    cin>>input;
    search(input, p);
    
    return 0;
}