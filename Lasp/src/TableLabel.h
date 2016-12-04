/*
 * TableLabel.h
 *
 *  Created on: Dec 3, 2016
 *      Author: david
 */

#ifndef TABLELABEL_H_
#define TABLELABEL_H_

#include <unordered_map>
#include <memory>

using namespace std;

namespace lasp {

class TableLabel {
	using table = unordered_map<unsigned,string>;
public:

	void insert(unsigned k,string& v){
		table_map.insert({k,v});
	}

	string getValue(unsigned k){
		auto it=table_map.find(k);
		if(it==table_map.end())
			return "";
		return it->second;
	}

	static shared_ptr<TableLabel> getInstances(){
		if(tl==nullptr)
			tl=make_shared<TableLabel>();
		return tl;
	}


	TableLabel(){};

private:

	static shared_ptr<TableLabel> tl;
	table table_map;
};

} /* namespace lasp */

#endif /* TABLELABEL_H_ */
