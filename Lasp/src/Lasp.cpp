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
//	p.pasrseLine("1 1 2 1 1 2");
//	p.pasrseLine("1 2 2 1 1 2");
	p.pasrseLine("8 2 3 4 2 0 5 6");
	vector<Clause> formula=move(p.getFormula());
	for(auto& c:formula)
		cout<<c<<endl;
	return 0;
}
