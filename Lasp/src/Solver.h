/*
 * Solver.h
 *
 *  Created on: Dec 4, 2016
 *      Author: david
 */

#ifndef SOLVER_H_
#define SOLVER_H_

#include <unordered_set>
#include "Clause.h"
#include "Assignment.h"

namespace lasp {

class Solver {
public:
	Solver(Clause::formula&& f):formula(move(f)){};

	void init();
	bool solve();
	bool check();

private:
	Clause::formula formula;
	Assignment ass;
};

} /* namespace lasp */

#endif /* SOLVER_H_ */
