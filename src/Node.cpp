#include <iostream>
#include <random>
#include "Node.h"

//maior valor possível para uma folha
#define MAXLEAFVALUE 100

int getRandom(int maxValue){
	std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist(1, maxValue);
    return dist(rng);
}

Node::Node(){}

Node::Node(int currentDepth, int targetDepth, int branchingFactor){
	if(currentDepth == targetDepth){
		nodeType = LEAF;
		childCount = 0;
	}else{
		nodeType = (currentDepth % 2 ==  0)?(MAX):(MIN);
	}

	if(nodeType==LEAF){
		value = getRandom(MAXLEAFVALUE);
	}else{
		childCount = branchingFactor;
		untouched = true;

		childs =  new Node*[branchingFactor];

		for(int i=0;i < branchingFactor;i++){
			childs[i] = new Node(currentDepth + 1, targetDepth, branchingFactor);
		}
	}
}


void Node::destroyRecursive()
{  
	Node* node = this;
	if(nodeType!=LEAF){
	    for(int i=0;i< node->childCount ;i++){
	    	//std::cout<<"type: "<<nodeType<<std::endl;
	    	node->childs[i]->destroyRecursive();
	    }
	}

	delete[] childs;
}

void Node::seekValue(){
	Node* node = this;

	if(nodeType==LEAF){
		
		//saying value
		std::cout<<value<<" "<<std::endl;
		return;
	}else if(nodeType==MAX){
		for(int i=0;i< node->childCount ;i++){
	    	node->childs[i]->seekValue();
	    }
	    for(int i=0;i< node->childCount ;i++){
	    	if(node->childs[i]->value > this->value || untouched){
	    		this->value = node->childs[i]->value;
	    		untouched = false;
	    		node->myChoice = i;
	    	}
	    }
	}else if(nodeType==MIN){
		for(int i=0;i< node->childCount ;i++){
	    	node->childs[i]->seekValue();
	    }
	    for(int i=0;i< node->childCount ;i++){
	    	if(node->childs[i]->value < this->value || untouched){
	    		this->value = node->childs[i]->value;
	    		untouched = false;
	    		node->myChoice = i;
	    	}
	    }
	}
}

void Node::choiceRoute(){
	if(nodeType==LEAF){
		return;
	}else{
		std::cout<< myChoice <<' ';
		childs[myChoice]->choiceRoute();
	}
}