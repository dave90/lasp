/*
 * Solver.cpp
 *
 *  Created on: Dec 4, 2016
 *      Author: david
 */

#include "Solver.h"

namespace lasp {

void Solver::init() {

	//find single clause and number of literals
	unordered_set<unsigned> literals;
	unordered_map<unsigned,bool> lit_value;

	for(auto&c:formula){
		if(c.getSize()==1){
			auto& pos=c.getPositive();
			if(pos.size()){
				auto value=pos[0];
				literals.insert(value);
				lit_value.insert({value,true});
			}else{
				auto& neg=c.getNegative();
				auto value=neg[0];
				literals.insert(value);
				lit_value.insert({value,false});
			}
		}else{
			for(auto l:c.getPositive())
				literals.insert(l);
			for(auto l:c.getNegative())
				literals.insert(l);
		}
	}

	//unitpropagation
	bool propagate=lit_value.size();

	while(propagate){
		propagate=false;
		for(auto& c:formula){
			unsigned assigned=0;
			long unassigned;
			for(auto& l:c.getNegative()){
				auto it=lit_value.find(l);
				if(it!=lit_value.end()){
					assigned++;
				}else
					unassigned=l*(-1);
			}
			for(auto& l:c.getPositive()){
				auto it=lit_value.find(l);
				if(it!=lit_value.end()){
					assigned++;
				}else
					unassigned=l;
			}
			if(assigned==c.getSize()-1){
				propagate=true;
				lit_value.insert({abs(unassigned),unassigned>0});
			}
		}
	}

	ass.resize(literals.size());
	for(auto& v:lit_value)
		ass.set(v.first,v.second);
}

bool Solver::solve() {
}

bool Solver::check() {
}


} /* namespace lasp */

