#include <iostream>
#include "data.h"
using namespace PhpInMemory;

Data::Data():m_value("PhpInMemory") {
}
 
string Data::get() {
	return m_data;
}
 
void Data::set(string value) {
	m_data = value;
}
