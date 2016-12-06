/*
 * Assignment.h
 *
 *  Created on: Dec 3, 2016
 *      Author: david
 */

#ifndef ASSIGNMENT_H_
#define ASSIGNMENT_H_

#include <vector>
#include <stdint.h>

using namespace std;

namespace lasp {

class Assignment {
	using value = uint16_t;
	using assignment_listerals = vector<value>;
	using literal = unsigned;
public:
	static constexpr uint16_t TRUE=1;
	static constexpr uint16_t FALSE=0;
	static constexpr uint16_t UNDEF=3;

	Assignment(){};
	Assignment(unsigned size):literals(size,UNDEF){};

	void resize(unsigned size){
		literals.resize(size,3);
	}

	void flip(literal l){
		//TODO we can optimize double []
		literals[l]=!literals[l];
	}

	void set(literal l,value v){
		literals[l]=v;
	}


	bool getValue(literal l){
		return literals[l];
	}

private:
	assignment_listerals literals;
};

} /* namespace lasp */

#endif /* ASSIGNMENT_H_ */
