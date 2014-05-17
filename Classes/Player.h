//
//  Player.h
//  SinMove
//
//  Created by Sacchy on 2014/05/17.
//
//

#ifndef __SinMove__Player__
#define __SinMove__Player__

#include "cocos2d.h"
USING_NS_CC;

enum class pStatus : int
{
    isIdle,
    isTap,
    isUnTap,
    isMoveUp,
    isMoveDown,
};

class Player : public Node
{
private:
    float spriteFrameTime_;
    Sprite *player_;
    std::map<int, std::string> HeriFrame_;
    void startAnimation(float delta);
    
public:
    Player();
    static Player* create();
    Player* initialize();
    
    pStatus pStatus_;
    void tapMe();
    void untapMe();
};

#endif /* defined(__SinMove__Player__) */
