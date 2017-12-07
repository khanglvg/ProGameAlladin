#ifndef _RANDOM_H__
#define _RANDOM_H__
#include "../Framework/definitions.h"

NS_JK_BEGIN

class Random
{
public:
	static Random*getInstance();
	void setRdNumb(int& rdnumb);
	int getRdNumb();
	int generateRdnum();
	~Random();
private:
	int _rdnum;
	static Random*_instance;
	
};
NS_JK_END
#endif //!__RANDOM_H__