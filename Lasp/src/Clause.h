/*
 * Clause.h
 *
 *  Created on: Dec 3, 2016
 *      Author: david
 */

#ifndef CLAUSE_H_
#define CLAUSE_H_

#include "Assignment.h"

#include <vector>
#include <iostream>

using namespace std;

namespace lasp {

class Clause {
	using clause_set = vector<unsigned>;
public:
	Clause(){};
	Clause(unsigned psize,unsigned nsize){pos_literals.reserve(psize);neg_literals.reserve(nsize);};

//	Clause(const Clause& c):pos_literals(c.pos_literals),neg_literals(c.neg_literals){cout<<"CAPY"<<endl;};

	Clause(Clause&& c) noexcept :pos_literals(move(c.pos_literals)),neg_literals(move(c.neg_literals))  {};
	Clause& operator=(Clause&& c){
		pos_literals=move(c.pos_literals);
		neg_literals=move(c.neg_literals);
		return *this;
	}

	void reserve(unsigned psize,unsigned nsize){pos_literals.reserve(psize);neg_literals.reserve(nsize);};

	bool isSatisfied(Assignment ass);

	void addPositive(unsigned l){
		pos_literals.push_back(l);
	}

	void addNegative(unsigned l){
		neg_literals.push_back(l);
	}

friend ostream& operator<<(ostream& out,const Clause& c){
	out<<"( | ";
	for(auto l:c.pos_literals)
		out<<l<<" | ";
	for(auto l:c.neg_literals)
		out<<"-"<<l<<" | ";
	out<<")";
	return out;
}

private:
	clause_set pos_literals;
	clause_set neg_literals;
};

} /* namespace lasp */

#endif /* CLAUSE_H_ */
