
#include <iostream>
#include "Composant1.h"
#include "Composant2.h"
#include <string.h>
#include <dlfcn.h>

int main(int argc, char ** argv)
{
	void *handle1 = dlopen("libComposant1.so", RTLD_LAZY);
	void *handle2 = dlopen("libComposant2.so", RTLD_LAZY);
	int (*fptr1)(int, int);
	int (*fptr2)(int, int);
	
	int data1 = 3;
	int data2 = 5;

	int valeur1;
	int valeur2;
	
	std::string my_function1, my_function2, lib1, lib2;
	const char* s1;
	const char* s2;
	
	std::cout << "Type the first function (composant1 or composant2)" << std::endl;
	std::cin >> my_function1;
	
	std::cout << "Type the second object" << std::endl;
	std::cin >> my_function2;
	
	if (my_function1=="composant1"){
		lib1 = "libComposant1.so";
		lib2 = "libComposant2.so";
	}
	else{
		lib1 = "libComposant2.so";
		lib2 = "libComposant1.so";
	}

	/* open the needed object */
	handle1 = dlopen(lib1.c_str(), RTLD_LAZY);
	handle2 = dlopen(lib2.c_str(), RTLD_LAZY);

	/* find the address of function and data objects */
	fptr1 = (int (*)(int, int))dlsym(handle1, my_function1.c_str());
	fptr2 = (int (*)(int, int))dlsym(handle2, my_function2.c_str());
	
	if (handle1==NULL || handle2==NULL || fptr1==NULL || fptr2==NULL){
		printf("ERROR NULL");
		exit(1);
	}

	/* invoke function, passing value of integer as a parameter */
	//(*fptr)(*iptr);

	//valeur1=composant1("3,5");
	valeur1=(*fptr1)(data1, data2);

	//valeur2=composant2("3,5");
	valeur2=(*fptr2)(data1, data2);

	std::cout << getComposant1Version() << std::endl;
	std::cout << "valeur 1 :" << fptr1(data1, data2) << " valeur 2 :" << fptr2(data1, data2) << std::endl;
}
