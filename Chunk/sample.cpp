#include <iostream>
#include <tuple>
#include <cstdlib>
using namespace std;
int main() {
	cout<<"Hello World\n";
	cout<<"Adding new line\n";
	cout<<"added a new statement while in web-dev branch....\n";
	int roll;
	string name, paper;
	tuple<int, string, string> tt[3];
	for(int i=0; i<3; i++) {
		cin>>roll;
		fflush(stdin);
		getline(cin, name);
		getline(cin, paper);
		tt[i] = make_tuple(roll, name, paper);	
	}
	for(int i=0; i<3; i++) {
		cout<<"Roll number : "<<get<0>(tt[i])<<"\n";
		cout<<"Name : "<<get<1>(tt[i])<<"\n";
		cout<<"Paper : "<<get<2>(tt[i])<<"\n";	
	}

	return 0;
}
