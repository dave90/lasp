//============================================================================
// Name        : Lasp.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "ParseInput.h"
#include "Solver.h"

using namespace std;
using namespace lasp;

int main() {

	ParseInput p;
	p.parseFile("/home/davide/git/lasp/Lasp/ground");


	vector<Clause> formula=move(p.getFormula());
	for(auto& c:formula)
		cout<<c<<endl;

	Solver s(move(formula));
	s.init();
	cout<<s.solve()<<endl;
	cout<<"AAAAAAAA"<<endl;

	return 0;
}
