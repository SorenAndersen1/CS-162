#include <stdlib.h>

template<class type>
class vector {
private:
	type data;
	type other_data;
public:

	vector();
	~vector();
	vector()

	vector(vector<type> & other);
	vector operator=(vector<type> &cioy);
}