#include <iostream>
using namespace std;
#include "data.h"
using namespace PhpInMemory;

Data::Data():m_data("PhpInMemory") {
}
 
char* Data::get() {
	return m_data;
}
 
void Data::set(char* data) {
	m_data = data;
}
