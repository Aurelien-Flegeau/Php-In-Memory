#include "data.h"
#include <iostream>
 
Data::Data():m_value(0){}
 
int Data::getData(){return m_value;}
 
void Data::setData(int value){m_value = value;}
