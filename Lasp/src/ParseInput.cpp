/*
 * ParseInput.cpp
 *
 *  Created on: Dec 3, 2016
 *      Author: david
 */

#include "ParseInput.h"

#include <fstream>

namespace lasp {


void ParseInput::parseLine(const string& l) {

	if(end)return;

	if(parseTable)
		return addInTable(l);


	switch (l[0]) {
		case B_RULE:
			if(l[2]=='1')
				pasrseConstraint(l);
			else
				pasrseBasicRule(l);
			break;
		case C_RULE:
			pasrseChoiceRule(l);
			break;
		case D_RULE:
			pasrseDisjRule(l);
			break;

		case END:
			parseTable=!parseTable;
			if(!parseTable)
				end=true;
			break;

		default:
			break;
	}

}



void ParseInput::parseFile(string name) {

	  string line;
	  ifstream myfile (name);
	  if (myfile.is_open())
	  {
	    while ( getline (myfile,line) )
	    {
	    	parseLine(line);
	    }
	    myfile.close();
	  }

	  else cerr << "Unable to open file";

}


void ParseInput::addInTable(const string&l){
	istringstream split(l);
	string each;
	getline(split, each, SPLIT_CHAR);
	unsigned lit=atoi(each.c_str());
	getline(split, each, SPLIT_CHAR);
	tl->insert(lit,each);
}

void ParseInput::pasrseConstraint(const string& l) {
	istringstream split(l);
	string each;
	unsigned literals;
	unsigned literalsNegative;
	unsigned lit;
	Clause c;
    for(int count=-1;getline(split, each, SPLIT_CHAR);count++ ){
    	if(count<=0)continue;
    	if(count==1){
    		literals=atoi(each.c_str());
    		continue;
    	}
    	if(count==2){
    		literalsNegative=atoi(each.c_str());
    		c.reserve(literals-literalsNegative,literalsNegative);
    		continue;
    	}
    	lit=atoi(each.c_str());
    	if(literalsNegative){
    		c.addPositive(lit);
    		--literalsNegative;
    	}else{
       		c.addNegative(lit);
    	}
    	count++;
    }
    form.emplace_back(move(c));
}

void ParseInput::pasrseBasicRule(const string& l) {
	istringstream split(l);
	string each;
	unsigned literals;
	unsigned literalsNegative;
	unsigned lit;
	Clause c;
    for(int count=0;getline(split, each, SPLIT_CHAR);count++ ){
    	if(!count)continue;
    	if(count==1){
        	lit=atoi(each.c_str());
        	c.addPositive(lit);
        	continue;
    	}
    	if(count==2){
    		literals=atoi(each.c_str());
    		continue;
    	}
    	if(count==3){
    		literalsNegative=atoi(each.c_str());
    		c.reserve(literals-literalsNegative,literalsNegative);
    		continue;
    	}
    	lit=atoi(each.c_str());
    	if(literalsNegative){
    		c.addPositive(lit);
    		--literalsNegative;
    	}else{
       		c.addNegative(lit);
    	}
    	count++;
    }
    form.emplace_back(move(c));
}

void ParseInput::pasrseChoiceRule(const string& l) {
}


void ParseInput::pasrseDisjRule(const string& l) {
	istringstream split(l);
	string each;
	int literals=-1;
	int literalsNegative=-1;
	unsigned heads;
	unsigned lit;
	Clause c;
    for(int count=0;getline(split, each, SPLIT_CHAR);count++ ){
    	if(!count)continue;
    	if(count==1){
        	heads=atoi(each.c_str());
        	continue;
    	}
    	if(heads){
    		lit=atoi(each.c_str());
    		c.addPositive(lit);
    		--heads;
    		continue;
    	}
    	if(literals==-1){
    		literals=atoi(each.c_str());
    		continue;
    	}
    	if(literalsNegative==-1){
    		literalsNegative=atoi(each.c_str());
    		c.reserve(literals-literalsNegative,literalsNegative);
    		continue;
    	}
    	lit=atoi(each.c_str());
    	if(literalsNegative){
    		c.addPositive(lit);
    		--literalsNegative;
    	}else{
       		c.addNegative(lit);
    	}
    	count++;
    }
    form.emplace_back(move(c));
}

} /* namespace lasp */
