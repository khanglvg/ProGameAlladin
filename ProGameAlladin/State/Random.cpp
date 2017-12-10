#include "Random.h"
#include <time.h>
#include <stdlib.h>
US_NS_JK

Random*Random::_instance = nullptr;


Random* Random::getInstance()
{
	if (_instance == nullptr)
	{
		_instance = new Random();
	}
	return _instance;
}

void Random::setRdNumb(int& rdnumb)
{
	_rdnum = rdnumb;
}

int Random::getRdNumb()
{
	return _rdnum;
}

int Random::generateRdnum()
{
	int n = 100;
	for (int i =0;i<n;i++)
	{
		srand(time(NULL));
		_rdnum = rand() % 100 + 1;
	}
	return _rdnum;
}

Random::~Random()
{
}

