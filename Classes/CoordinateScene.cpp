#include "CoordinateScene.h"

USING_NS_CC;

/**
* ����һ��Scene��֮�������layer �����ȥ
**/
Scene* Coordinate::createScene()
{
	auto scene = Scene::create();
	auto layer = Coordinate::create();
	scene->addChild(layer); 
	return scene;
}

//��ʼ��������ȫ������ʾ�����￪ʼ
bool Coordinate::init()
{
	if(!Layer::init()){
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	//����һ��Layer��size(��Ļ��һ��)
	auto red = LayerColor::create(Color4B(255, 100, 100, 128), visibleSize.width/2, visibleSize.height/2);
	red->ignoreAnchorPointForPosition(true); //����AnchorPoint�������AnchorPoint�����½�
	red->ignoreAnchorPointForPosition(false);
	red->setAnchorPoint(Point(0.5,0.5));//����Anchor Point���м�
	red->setPosition(Point(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

	//����һ��Layer��size(��Ļ��1/4)
	auto green = LayerColor::create(Color4B(100, 255, 100, 128), visibleSize.width/4, visibleSize.height/4);
	green->ignoreAnchorPointForPosition(true);
	green->ignoreAnchorPointForPosition(false);
	green->setAnchorPoint(Point(1,1));//����Anchor Point�����Ͻ�


	red->addChild(green);

	this->addChild(red, 0);

	return true;
}

void Coordinate::back(Ref* sSender){
	


}