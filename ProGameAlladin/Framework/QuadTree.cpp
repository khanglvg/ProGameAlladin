#include "QuadTree.h"

US_NS_JK

QuadTree::QuadTree(const int& level, Rect* bound)
{
	this->_level = level;
	this->Bound = bound;
}

QuadTree::~QuadTree()
{
}

void QuadTree::clear()
{
	if (_quadNodes)
	{
		for (auto i = 0; i < 4; i++)
		{
			_quadNodes[i]->clear();
			delete _quadNodes[i];
		}
		delete[] _quadNodes;
	}
}

void QuadTree::insertObject(GameObject * object)
{
	const auto index = getIndex(object->getRect());

	if (_quadNodes != nullptr)
	{
		if (index != -1)
		{
			_quadNodes[index]->insertObject(object);
			return;
		}
	}

	if (index == -1)
	{
		this->_listObject.push_back(object);
	}
	else
	{
		if (_quadNodes == nullptr)
		{
			split();
		}

		_quadNodes[index]->insertObject(object);
	}
}

void QuadTree::getAllObjects(vector<GameObject*>& objectresult)
{
	for (auto child : _listObject)
	{
		objectresult.push_back(child);
	}

	if (_quadNodes)
	{
		for (size_t i = 0; i < 4; i++)
		{
			_quadNodes[i]->getAllObjects(objectresult);
		}
	}
}

int QuadTree::getTotalObjects() const
{
	int total = _listObject.size();

	if (_quadNodes)
	{
		for (size_t i = 0; i < 4; i++)
		{
			total += _quadNodes[i]->getTotalObjects();
		}
	}

	return total;
}

Rect QuadTree::getVisibilityArea(GameObject *object) const
{
	Rect objectRect = object->getRect();
	Rect result;

	/*result.setX(objectRect.getX() - 200);
	result.setWidth(objectRect.getWidth() + 400);
	result.setY(objectRect.getY() - 300);
	result.setHeight(objectRect.getHeight() + 300);*/
	result.setX(objectRect.getX() - 350);
	result.setWidth(750);
	result.setY(objectRect.getY() - 250);
	result.setHeight(300);
	return result;
}

void QuadTree::getObjectsVisibility(vector<GameObject*>& objectresult, Rect visibleRect, int _level)
{
	const auto index = this->getIndex(visibleRect);
	if (this->_level < _level && index != -1)
	{
		if (_quadNodes)
		{
			_quadNodes[index]->getObjectsVisibility(objectresult, visibleRect, _level);
			return;
		}
		else
		{
			return;
		}
	}

	if (index != -1)
	{
		//nhung Entity o day se la nam tren 2 node con nen chung ta cung se lay de set va cham
		for (auto child : _listObject)
		{
			objectresult.push_back(child);
		}

		if (_quadNodes != nullptr)
		{
			//kiem tra va lay cac node trong node con
			_quadNodes[index]->getObjectsVisibility(objectresult, visibleRect, _level);
		}
	}
	else
	{
		getAllObjects(objectresult);
	}
}

QuadTree ** QuadTree::getQuadNodes() const
{
	return _quadNodes;
}

int QuadTree::getIndex(Rect body) const
{
	const auto middleVerticle = Bound->getX() + Bound->getWidth() / 2.0f;
	const auto middleHorizontal = Bound->getY() + Bound->getHeight() / 2.0f;

	if (body.getY() > Bound->getY() && (body.getY() + body.getHeight()) < middleHorizontal)
	{
		//nam phia ben tren
		if (body.getX() > Bound->getX() && (body.getX() + body.getWidth()) < middleVerticle)
		{
			//nam phia ben trai
			return 0;
		}
		else if (body.getX() > middleVerticle && (body.getX() + body.getWidth()) < (Bound->getX() + Bound->getWidth()))
		{
			//nam phia ben phai
			return 1;
		}
	}
	else if (body.getY() > middleHorizontal && (body.getY() + body.getHeight()) < (Bound->getY() + Bound->getHeight()))
	{
		//nam phia ben duoi
		if (body.getX() > Bound->getX() && (body.getX() + body.getWidth()) < middleVerticle)
		{
			//nam phia ben trai
			return 2;
		}
		else if (body.getX() > middleVerticle && (body.getX() + body.getWidth()) < (Bound->getX() + Bound->getWidth()))
		{
			//nam phia ben phai
			return 3;
		}
	}

	return -1;
}

void QuadTree::split()
{
	_quadNodes = new QuadTree*[4];

	_quadNodes[0] = new QuadTree(_level + 1,
		new Rect(Bound->getX(), Bound->getY(), Bound->getWidth() / 2, Bound->getHeight() / 2));
	_quadNodes[1] = new QuadTree(_level + 1,
		new Rect(Bound->getX() + Bound->getWidth() / 2, Bound->getY(), Bound->getWidth() / 2, Bound->getHeight() / 2));
	_quadNodes[2] = new QuadTree(_level + 1,
		new Rect(Bound->getX(), Bound->getY() + Bound->getHeight() / 2, Bound->getWidth() / 2, Bound->getHeight() / 2));
	_quadNodes[3] = new QuadTree(_level + 1,
		new Rect(Bound->getX() + Bound->getWidth() / 2,
			Bound->getY() + Bound->getHeight() / 2, Bound->getWidth() / 2, Bound->getHeight() / 2));
}

bool QuadTree::isContain(GameObject * object) const
{
	auto rect = object->getRect();

	return !(rect.getX() + rect.getWidth() < Bound->getX() ||
		rect.getY() + rect.getHeight() < Bound->getY() ||
		rect.getX() > Bound->getX() + Bound->getWidth() ||
		rect.getY() > Bound->getY() + Bound->getHeight());
}
