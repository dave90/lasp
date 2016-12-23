/*
 * Clause.h
 *
 *  Created on: Dec 3, 2016
 *      Author: david
 */

#ifndef CLAUSE_H_
#define CLAUSE_H_

#include "Assignment.h"
#include "TableLabel.h"

#include <vector>
#include <iostream>

using namespace std;

namespace lasp {

class Clause {
	using clause_set = vector<unsigned>;
public:
	using formula = vector<Clause>;


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

	const clause_set& getPositive(){
		return pos_literals;
	}

	const clause_set& getNegative(){
		return neg_literals;
	}

	unsigned size(){
		return pos_literals.size()+neg_literals.size();
	}

	unsigned getLit(unsigned i){
		if(i<neg_literals.size())return neg_literals[i];
		return pos_literals[i-neg_literals.size()];
	}


friend ostream& operator<<(ostream& out,const Clause& c){
	auto tl=TableLabel::getInstances();
	auto printFunc=[&tl,&out](unsigned k,bool neg){
		auto lab=tl->getValue(k);
		string n=(neg)?"-":"";
		if(lab.empty())
			out<<n<<k<<" | ";
		else
			out<<n<<lab<<" | ";
	};
	out<<"( | ";
	for(auto l:c.pos_literals){
		printFunc(l,false);
	}
	for(auto l:c.neg_literals)
		printFunc(l,true);
	out<<")";
	return out;
}

private:
	clause_set pos_literals;
	clause_set neg_literals;
};

} /* namespace lasp */

#endif /* CLAUSE_H_ */
