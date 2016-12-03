/*
 * Clause.cpp
 *
 *  Created on: Dec 3, 2016
 *      Author: david
 */

#include "Clause.h"

namespace lasp {

bool Clause::isSatisfied(Assignment ass){
	for(auto l:pos_literals)
		if(ass.getValue(l))
			return true;
	for(auto l:neg_literals)
		if(!ass.getValue(l))
			return true;
	return false;
}

} /* namespace lasp */
