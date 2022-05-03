
#include <iostream>
#include "Composant1.h"
#include "Composant2.h"
#include <string.h>
#include <dlfcn.h>

int main(int argc, char ** argv)
{
	void    *handle1 ,*handle2;
	int     (*fptr1)(int), (*fptr2)(int);
	
	int data1=3;
	int data2=5;

	int valeur1;
	int valeur2;
	
	std::string my_object1, my_object2;
	const char* s1, s2;
	
	std::cout << "Type the first object (Composant1 or Composant2)" << std::endl;
	std::cin >> my_object1;
	
	std::cout << "Type the second object" << std::endl;
	std::cin >> my_object2;
	
	my_object1 = "/lib_partageable_linux_2022/bin/lib"+my_object1+".so";
	my_object2 = "/lib_partageable_linux_2022/bin/lib"+my_object2+".so";
	s1 = my_object1.c_str();
	s2 = my_object2.c_str();

	/* open the needed object */
	handle1 = dlopen(s1, RTLD_LOCAL | RTLD_LAZY);
	handle2 = dlopen(s2, RTLD_LOCAL | RTLD_LAZY);

	/* find the address of function and data objects */
	fptr1 = (int (*)(int))dlsym(handle1, composant1);
	fptr2 = (int (*)(int))dlsym(handle2, composant2);

	/* invoke function, passing value of integer as a parameter */
	//(*fptr)(*iptr);

	//valeur1=composant1(data1,data2);
	valeur1=(*fptr1)(data1,data2);

	//valeur2=composant2(data1,data2);
	valeur2=(*fptr2)(data1,data2);

	std::cout << getComposant1Version() << std::endl;
	std::cout << "valeur 1 :" << valeur1 << " valeur 2 :" << valeur2 << std::endl;
}
