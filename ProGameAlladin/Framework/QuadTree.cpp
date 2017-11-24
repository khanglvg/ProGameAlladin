#include "QuadTree.h"

QuadTree::QuadTree(int level, Rect* bound)
{
	this->mLevel = level;
	this->Bound = bound;
}

QuadTree::~QuadTree()
{
}

void QuadTree::Clear()
{
	if (Nodes)
	{
		for (int i = 0; i < 4; i++)
		{
			Nodes[i]->Clear();
			delete Nodes[i];
		}
		delete[] Nodes;
	}
}

void QuadTree::insertObject(Node * object)
{
	int index = getIndex(object->getRect());

	if (Nodes != NULL)
	{
		if (index != -1)
		{
			Nodes[index]->insertObject(object);
			return;
		}
	}

	if (index == -1)
	{
		this->mListObject.push_back(object);
	}
	else
	{
		if (Nodes == NULL)
		{
			split();
		}

		Nodes[index]->insertObject(object);
	}
}

void QuadTree::getObjectsCollideAble(std::vector<Node*>& objectresult, Node * object)
{
	int index = this->getIndex(object->getRect());

	if (index != -1)
	{
		//nhung Entity o day se la nam tren 2 node con nen chung ta cung se lay de set va cham
		for (auto child : mListObject)
		{
			objectresult.push_back(child);
		}

		if (Nodes != NULL)
		{
			//kiem tra va lay cac node trong node con
			Nodes[index]->getObjectsCollideAble(objectresult, object);
		}
	}
	else
	{
		getAllObjects(objectresult);
	}
}

void QuadTree::getAllObjects(std::vector<Node*>& objectresult)
{
	for (auto child : mListObject)
	{
		objectresult.push_back(child);
	}

	if (Nodes)
	{
		for (size_t i = 0; i < 4; i++)
		{
			Nodes[i]->getAllObjects(objectresult);
		}
	}
}

int QuadTree::getTotalObjects()
{
	int total = mListObject.size();

	if (Nodes)
	{
		for (size_t i = 0; i < 4; i++)
		{
			total += Nodes[i]->getTotalObjects();
		}
	}

	return total;
}

QuadTree ** QuadTree::GetNodes()
{
	return Nodes;
}

int QuadTree::getIndex(Rect body)
{
	float middleVerticle = Bound->getX() + Bound->getWidth() / 2.0f;
	float middleHorizontal = Bound->getY() + Bound->getHeight() / 2.0f;

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
	Nodes = new QuadTree*[4];

	Nodes[0] = new QuadTree(mLevel + 1,
		new Rect(Bound->getX(), Bound->getY(), Bound->getWidth() / 2, Bound->getHeight() / 2));
	Nodes[1] = new QuadTree(mLevel + 1,
		new Rect(Bound->getX() + Bound->getWidth() / 2, Bound->getY(), Bound->getWidth() / 2, Bound->getHeight() / 2));
	Nodes[2] = new QuadTree(mLevel + 1,
		new Rect(Bound->getX(), Bound->getY() + Bound->getHeight() / 2, Bound->getWidth() / 2, Bound->getHeight() / 2));
	Nodes[3] = new QuadTree(mLevel + 1,
		new Rect(Bound->getX() + Bound->getWidth() / 2,
			Bound->getY() + Bound->getHeight() / 2, Bound->getWidth() / 2, Bound->getHeight() / 2));
}

bool QuadTree::isContain(Node * object)
{
	Rect rect = object->getRect();

	return !(rect.getX() + rect.getWidth() < Bound->getX() ||
		rect.getY() + rect.getHeight() < Bound->getY() ||
		rect.getX() > Bound->getX() + Bound->getWidth() ||
		rect.getY() > Bound->getY() + Bound->getHeight());
}
