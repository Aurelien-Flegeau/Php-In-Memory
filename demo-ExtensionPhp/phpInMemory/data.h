#ifndef DATA_H
#define DATA_H

#include <string>
using namespace std;

namespace PhpInMemory {
	class Data {
		
		char* m_data;
		
	public:
		Data();
		
		char* get();
		void set(char*);
	};
}
 
#endif /* DATA_H */
