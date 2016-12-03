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

using namespace std;

namespace lasp {

class Clause {
	using clause_set = vector<unsigned>;
public:
	Clause(){};
	Clause(unsigned psize,unsigned nsize){pos_literals.reserve(psize);neg_literals.reserve(nsize);};

	bool isSatisfied(Assignment ass);

	void addPositive(unsigned l){
		pos_literals.push_back(l);
	}

	void addNegative(unsigned l){
		pos_literals.push_back(l);
	}

private:
	clause_set pos_literals;
	clause_set neg_literals;
};

} /* namespace lasp */

#endif /* CLAUSE_H_ */
