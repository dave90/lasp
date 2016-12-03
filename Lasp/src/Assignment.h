/*
 * Assignment.h
 *
 *  Created on: Dec 3, 2016
 *      Author: david
 */

#ifndef ASSIGNMENT_H_
#define ASSIGNMENT_H_

#include <vector>

using namespace std;

namespace lasp {

class Assignment {

	using assignment_listerals = vector<bool>;
	using literal = unsigned;
public:
	Assignment(){};
	Assignment(unsigned size):literals(size,false){};

	void flip(literal l){
		//TODO we can optimize double []
		literals[l]=!literals[l];
	}

	bool getValue(literal l){
		return literals[l];
	}

private:
	assignment_listerals literals;
};

} /* namespace lasp */

#endif /* ASSIGNMENT_H_ */
