#include <iostream>
#include "Node.h"


int main(){
	int targetDepth;
	int branchingFactor;


	std::cout<<"Qual a profundidade da árvore?"<<std::endl;
	std::cin>>targetDepth;

	std::cout<<"Qual o fator de ramificação da árvore?"<<std::endl;
	std::cin>>branchingFactor;

	Node root = Node(0, targetDepth, branchingFactor);

	std::cout<<std::endl;
	root.seekValue();

	std::cout<<"Melhor valor alcançado: "<<root.value<<std::endl;

	root.destroyRecursive();

	std::cout<<"Rota escolhida: ";

	root.choiceRoute();

	std::cout<<std::endl;

	return 0;
}