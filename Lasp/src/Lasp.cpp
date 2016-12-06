//============================================================================
// Name        : Lasp.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "ParseInput.h"

using namespace std;
using namespace lasp;

int main() {

	ParseInput p;
	p.parseFile("/home/davide/git/lasp/Lasp/ground");
	vector<Clause> formula=move(p.getFormula());
	for(auto& c:formula)
		cout<<c<<endl;


	return 0;
}
