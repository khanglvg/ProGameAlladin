#ifndef __QUADTREE_H__

#define __QUADTREE_H__
#include <d3dx9.h>
#include <d3d9.h>
#include <vector>
#include "Node.h"
#include "Rect.h"

NS_JK_BEGIN

class QuadTree
{
public:

    QuadTree(const int& level, Rect* bound);
    ~QuadTree();

    void clear();

    void insertObject(Node *object);
    
    void getObjectsCollideAble(vector<Node*> &objectresult,Node *object); 

    void getAllObjects(std::vector<Node*> &objectresult);

    int getTotalObjects() const;

	Rect getVisibilityArea(Node *object) const;

	void getObjectsVisibility(vector<Node*> &objectresult, Rect visibleRect, int _level);

    Rect* Bound;

    QuadTree** getQuadNodes() const;

protected:
    QuadTree** _quadNodes;
    vector<Node*> _listObject;

    /*lay vi tri cua Entity 
    0: nam trong Node con goc trai tren
    1: nam trong Node con goc phai tren
    2: nam trong Node con goc trai duoi
    3: nam trong Node con goc phai duoi
    -1: bi dinh > 2 node con*/
    int getIndex(Rect body) const;

    void split();

    bool isContain(Node *object) const;

    int _level;
};

NS_JK_END

#endif __QUADTREE_H__