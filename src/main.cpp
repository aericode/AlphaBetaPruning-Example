#include <chrono>
#include <ctime>
#include <iostream>
#include "Node.h"

typedef std::chrono::time_point<std::chrono::system_clock> Time;

int main(){
	int targetDepth;
	int branchingFactor;
	char optionLeafValue;
	bool printValues;

	Time start;
	Time end;

	std::cout<<"ALPHA BETA PRUNING APLICADO"<<std::endl<<std::endl;

	std::cout<<"Qual a profundidade da árvore?"<<std::endl;
	std::cin>>targetDepth;

	std::cout<<"Qual o fator de ramificação da árvore?"<<std::endl;
	std::cin>>branchingFactor;

	std::cout<<"Exibir o valor dos leaf nodes? S/N"<<std::endl;
	std::cin>>optionLeafValue;

	if(optionLeafValue=='S'||optionLeafValue=='s'){
		printValues = true;
		std::cout<<"Valores das folhas"<<std::endl;
	}else{
		printValues = false;
	}

	Node root = Node(0, targetDepth, branchingFactor, printValues);

	std::cout<<std::endl;

	start = std::chrono::high_resolution_clock::now();

	root.seekValue();

	end = std::chrono::high_resolution_clock::now();    
    std::chrono::duration<double> delta = end - start;

    int ms = std::chrono::duration_cast<std::chrono::microseconds >(delta).count();
    int ns = std::chrono::duration_cast<std::chrono::nanoseconds >(delta).count();

    std::cout<<"tempo de execução: "<< ms <<" ns"<<std::endl;
    std::cout<<"tempo de execução: "<< ns <<" ms"<<std::endl;

	std::cout<<"Melhor valor alcançado: "<<root.value<<std::endl;

	root.destroyRecursive();

	return 0;
}