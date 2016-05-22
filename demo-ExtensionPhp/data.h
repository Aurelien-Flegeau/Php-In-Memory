#ifndef DATA_H
#define DATA_H

#include <string>
using namespace std;

namespace PhpInMemory {
	class Data {
		
		string m_value;
		
	public:
		Data();
		
		int getData();
		void setData(string);
	};
}
 
#endif /* DATA_H */
