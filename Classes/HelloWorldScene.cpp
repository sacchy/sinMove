#include "HelloWorldScene.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    addListener();
    addPlayer();
    
    return true;
}

/*
 * リスナー登録
 */
void HelloWorld::addListener()
{
    auto taplistener = EventListenerTouchAllAtOnce::create();
    taplistener->onTouchesBegan = CC_CALLBACK_2(HelloWorld::onTouchesBegan, this);
    taplistener->onTouchesMoved = CC_CALLBACK_2(HelloWorld::onTouchesMoved, this);
    taplistener->onTouchesEnded = CC_CALLBACK_2(HelloWorld::onTouchesEnded, this);
    this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(taplistener, this);
}

/*
 * プレイヤーを表示
 */
void HelloWorld::addPlayer()
{
    Size visibleSize = Director::getInstance()->getVisibleSize();
    player = Player::create();
    player->setPosition(Point(visibleSize.width/2, visibleSize.height/2));
    this->addChild(player);
}

#pragma mark - タップアクション
void HelloWorld::onTouchesBegan(const std::vector<cocos2d::Touch*> &touches, cocos2d::Event* event)
{
    log("tapMe");
}

void HelloWorld::onTouchesMoved(const std::vector<cocos2d::Touch*> &touches, cocos2d::Event* event)
{

}

void HelloWorld::onTouchesEnded(const std::vector<cocos2d::Touch*> &touches, cocos2d::Event* event)
{

}
