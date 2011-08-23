
#include <iostream>
#include <cstdlib>





#include "list"

using namespace stlport;
int main(int argv,char argc[])
{

list<int> lista;

	int i=0;
	system("pause");

	while(i<4000)
	{
		lista.push_back(i);
		std::cout<<"push[" <<  i << "] = "<< i<<std::endl;
		i++;
	}
	system("pause");
	while(lista.size()){
	
		std::cout<<"pop "<<std::endl;

	}




	system("pause");


	return 0;
}
