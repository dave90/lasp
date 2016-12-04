/*
 * ParseInput.h
 *
 *  Created on: Dec 3, 2016
 *      Author: david
 */

#ifndef PARSEINPUT_H_
#define PARSEINPUT_H_

#include <string>
#include <sstream>
#include <stdlib.h>
#include <unordered_set>

#include "TableLabel.h"
#include "Clause.h"

namespace lasp {

class ParseInput {
	using formula=Clause::formula;
public:
	ParseInput():parseTable(false),tl(TableLabel::getInstances()),end(false){};

	void parseFile(string name);
	void parseLine(const string& l);

	void addInTable(const string&l);

	void pasrseConstraint(const string & l);
	void pasrseBasicRule(const string & l);
	void pasrseChoiceRule(const string & l);
	void pasrseDisjRule(const string & l);

	formula& getFormula(){return form;}
private:
	formula form;


	bool parseTable;
	shared_ptr<TableLabel> tl;
	bool end;


	static constexpr char B_RULE='1';
	static constexpr char C_RULE='3';
	static constexpr char D_RULE='8';
	static constexpr char SPLIT_CHAR=' ';

	static constexpr char END='0';

};

} /* namespace lasp */

#endif /* PARSEINPUT_H_ */
