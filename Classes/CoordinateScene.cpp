#include "CoordinateScene.h"

USING_NS_CC;

/**
* 创建一个Scene，之后把坐标layer 加入进去
**/
Scene* Coordinate::createScene()
{
	auto scene = Scene::create();
	auto layer = Coordinate::create();
	scene->addChild(layer); 
	return scene;
}

//初始化场景，全部显显示从这里开始
bool Coordinate::init()
{
	if(!Layer::init()){
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	//创建一个Layer，size(屏幕的一半)
	auto red = LayerColor::create(Color4B(255, 100, 100, 128), visibleSize.width/2, visibleSize.height/2);
	red->ignoreAnchorPointForPosition(true); //忽略AnchorPoint，这个是AnchorPoint在左下角
	red->ignoreAnchorPointForPosition(false);
	red->setAnchorPoint(Point(0.5,0.5));//设置Anchor Point在中间
	red->setPosition(Point(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

	//创建一个Layer，size(屏幕的1/4)
	auto green = LayerColor::create(Color4B(100, 255, 100, 128), visibleSize.width/4, visibleSize.height/4);
	green->ignoreAnchorPointForPosition(true);
	green->ignoreAnchorPointForPosition(false);
	green->setAnchorPoint(Point(1,1));//设置Anchor Point在右上角


	red->addChild(green);

	this->addChild(red, 0);

	return true;
}

void Coordinate::back(Ref* sSender){
	


}