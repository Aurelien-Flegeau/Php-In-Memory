#include <iostream>
#include "data.h"
using namespace PhpInMemory;

Data::Data():m_value("PhpInMemory") {
}
 
string Data::getData() {
	return m_data;
}
 
void Data::setData(string value) {
	m_data = value;
}
