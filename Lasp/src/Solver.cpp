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
		if(c.size()==1){
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
			if(assigned==c.size()-1){
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
	vector<unsigned> fc=getFalseClause();
	unsigned i=0;
	for(;i<max_iteration&&fc.size();i++){
		unsigned selClaus=rand()%fc.size();
		auto& clause=formula[fc[selClaus]];
		cout<<"SELECT "<<clause<<endl;
		unsigned max=0;
		unsigned bestLit=0;
		for(unsigned j=0;j<clause.size();j++){
			auto lit=clause.getLit(j);
			ass.flip(lit);
			auto num=getNumFalseClause();
			if(num>max){
				max=num;
				bestLit=lit;
			}
			ass.flip(lit);
		}
		cout<<"FLIP "<<bestLit<<endl;
		ass.flip(bestLit);
	}
	return i!=max_iteration;
}

bool Solver::check() {
	return true;
}


} /* namespace lasp */

