/*
 * Solver.h
 *
 *  Created on: Dec 4, 2016
 *      Author: david
 */

#ifndef SOLVER_H_
#define SOLVER_H_

#include <unordered_set>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */


#include "Clause.h"
#include "Assignment.h"


namespace lasp {

class Solver {
	static constexpr unsigned MAX_IT=100000000;
public:
	Solver(Clause::formula&& f):formula(move(f)),rs(time(0)),max_iteration(MAX_IT){srand(rs);};

	void init();
	bool solve();
	bool check();


private:
	Clause::formula formula;
	Assignment ass;

	unsigned rs;
	unsigned max_iteration;

	vector<unsigned> getFalseClause(){
		vector<unsigned> fc;
		fc.reserve(formula.size());
		for(unsigned i=0;i<formula.size();i++){
			if(!formula[i].isSatisfied(ass))
				fc.push_back(i);
		}
		return fc;
	}

	unsigned getNumFalseClause(){
		unsigned count=0;
		for(unsigned i=0;i<formula.size();i++){
			if(!formula[i].isSatisfied(ass))
				count++;
		}
		return count;
	}

};

} /* namespace lasp */

#endif /* SOLVER_H_ */
