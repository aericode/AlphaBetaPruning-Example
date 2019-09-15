#include <iostream>
#include <random>
#include "Node.h"
#include <limits>
//maior valor possível para uma folha
#define MAXLEAFVALUE 100
#define INFMAX std::numeric_limits<int>::max()
#define INFMIN std::numeric_limits<int>::min()

int getRandom(int maxValue){
	std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist(1, maxValue);
    return dist(rng);
}

Node::Node(){}

Node::Node(int currentDepth, int targetDepth, int branchingFactor){
	if(currentDepth==0){
		alpha = INFMIN;
		beta  = INFMAX;
	}


	if(currentDepth == targetDepth){
		nodeType = LEAF;
		childCount = 0;
	}else{
		nodeType = (currentDepth % 2 ==  0)?(MAX):(MIN);
	}

	if(nodeType==LEAF){
		value = getRandom(MAXLEAFVALUE);
	}else{
		if(nodeType == MAX){
			value = INFMIN;
		}else if(nodeType == MIN){
			value = INFMAX;
		}

		childCount = branchingFactor;

		childs =  new Node*[branchingFactor];

		for(int i=0;i < branchingFactor;i++){
			childs[i] = new Node(currentDepth + 1, targetDepth, branchingFactor);
		}

	}
}


void Node::destroyRecursive()
{  
	if(nodeType!=LEAF){
	    for(int i=0;i< childCount ;i++){
	    	//std::cout<<"type: "<<nodeType<<std::endl;
	    	childs[i]->destroyRecursive();
	    }
	}

	delete[] childs;
}

void Node::seekValue(){

	if(nodeType==LEAF){
		//saying value
		std::cout<<value<<" "<<std::endl;
		return;
	}else if(nodeType==MAX){
		for(int i=0;i< childCount ;i++){
	    	childs[i]->seekValue();
	    }
	    for(int i=0;i < childCount ;i++){
	    	if(childs[i]->value > value){
	    		value = childs[i]->value;
	    	}
	    }
	}else if(nodeType==MIN){
		for(int i=0;i< childCount ;i++){
	    	childs[i]->seekValue();
	    }
	    for(int i=0;i < childCount ;i++){
	    	if(childs[i]->value < value){
	    		value = childs[i]->value;
	    	}
	    }
	}
}