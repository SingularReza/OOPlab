/*
Name:- Bhagam Chandan Chowdary
Roll.No:- 17CS8028
Assignment-6:- Connected Components
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    string line;
    int no, count, setno = 0;

    ifstream input("./inputfile.txt");

    //getting the no of vertices
    getline(input, line);
    no = stoi(line);
    cout<<no;

    //connected array is used to seperate vertices into connected sets defined by the number in the corresponding index
    int vertices[no], connected[no], hold[2];
    no = 0;

    while(getline(input,line)) {
        int i = 0, j = 0;
        string temp = "";

        //converting input to integers
        while(i++) {
            if(line[i]!=' '||line[i]!='\0') {
                temp = temp+line[i];
            }
            else {
                hold[j] = stoi(temp);
                j++;
            }
        }

        count = no;

        //checking whether the vertices are already visited
        while(count>=0) {
            //if one vertix is visited checks for other one. If the other isn't visited it will eb added to the cotrresponding set
            if(hold[0]==vertices[count]) {
               int count2 = no;
               while(count2>=0) {
                   if(hold[1]==vertices[count]) {
                       j = min(connected[count], connected[count2]);
                       i = max(connected[count], connected[count2]);
                       break;
                   }
                   else if(count==0) {
                       vertices[++no] = hold[1];
                       connected[no] = connected[count];
                   }
               }
               break;
           }
           else if(hold[1]==vertices[count]) {
               int count2 = no;
               while(count2>=0) {
                   if(hold[0]==vertices[count]) {
                       j = min(connected[count], connected[count2]);
                       i = max(connected[count], connected[count2]);
                       break;
                   }
                   else if(count==0) {
                       vertices[++no] = hold[1];
                       connected[no] = connected[count];
                   }
               }
               break;

           }
           //if both are not visited then they are created as a seperate set
           else if(count==0) {
                vertices[++no] = hold[0];
                connected[no] = ++setno;
                vertices[++no] = hold[1];
                connected[no] = setno; 
            } 
            count--;
        }

        count = no;

        while(count--) {
            if(connected[count] == i)
                connected[count] = j;
        }
    }

    //printing out the sets with the corresponding set number
    while(no) {
        cout<<vertices[no]<<" "<<connected[no]<<endl;
        no--;
    }

}