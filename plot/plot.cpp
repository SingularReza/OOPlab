#include<iostream>
#include<iomanip>
#include<math.h>

using namespace std;

void sineplot(){
	float i,j,k;
	for(i=0;i<=6.28;i=(i+0.1)) {
		j=20*sin(i);
		
		if(j>=0) {
			cout<<setw(36)<<"|";
			for(k=36;k<=36+j;k++) {	
				cout<<"*";
			}
			cout<<endl;
		}
		else {
			cout<<setw(36+j);
			for(k=36+j;k<36;k++) {
				cout<<"*";
			}
			cout<<"|";
			cout<<endl;
		}
	}
}

void cosplot(){
	float i,j,k;

	for(i=0;i<=6.28;i=(i+0.1)) {
		j=20*cos(i);
		
		if(j>=0) {
			cout<<setw(36)<<"|";
			for(k=36;k<=36+j;k++) {	
				cout<<"*";
			}
			cout<<endl;
		}
		else {
			cout<<setw(36+j);
			for(k=36+j;k<36;k++) {
				cout<<"*";
			}
			cout<<"|";
			cout<<endl;
		}
	}
}

int main() {

	int cycles,choice;

	cout<<"1.sin 2.cos:";
	cin>>choice;

	cout<<"Enter cycles:";
	cin>>cycles;

	if(choice==1) {
		while(cycles--) {
			sineplot();
		}
	}
	else {
		while(cycles--) {
			cosplot();
		}
	}

	return 0;
}
