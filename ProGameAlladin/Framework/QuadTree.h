#pragma once

#include <d3dx9.h>
#include <d3d9.h>
#include <vector>
#include "Node.h"
#include "Rect.h"

US_NS_JK

class QuadTree
{
public:

    QuadTree(int level, Rect* bound);
    ~QuadTree();
    void Clear();
    void insertObject(Node *object);
    
    void getObjectsCollideAble(std::vector<Node*> &objectresult,Node *object); 

    void getAllObjects(std::vector<Node*> &objectresult);

    int getTotalObjects();

    Rect* Bound;

    QuadTree **GetNodes();

protected:
    QuadTree **Nodes;
    std::vector<Node*> mListObject;

    /*lay vi tri cua Entity 
    0: nam trong Node con goc trai tren
    1: nam trong Node con goc phai tren
    2: nam trong Node con goc trai duoi
    3: nam trong Node con goc phai duoi
    -1: bi dinh > 2 node con*/
    int getIndex(Rect body);

    void split();

    bool isContain(Node *object);
    int mLevel;
};