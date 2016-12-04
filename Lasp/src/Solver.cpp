/*
 * Solver.cpp
 *
 *  Created on: Dec 4, 2016
 *      Author: david
 */

#include "Solver.h"

namespace lasp {

void Solver::init() {

	//find single clause and number of literals
	unordered_set<unsigned> literals;
	unordered_set<unsigned> lit_value;

	for(auto&c:formula){
		if(c.getSize()==1){
			auto l=c[0];
			lit_value.insert(l);
			literals.insert(l);
		}else{
			for(unsigned i=0;i<c.getSize();i++)
				literals.insert(c[i]);
		}
	}

	//unitpropagation
	//TODO

	ass.resize(literals.size());
}

bool Solver::solve() {
}

bool Solver::check() {
}


} /* namespace lasp */

