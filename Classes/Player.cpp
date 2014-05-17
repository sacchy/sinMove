//
//  Player.cpp
//  SinMove
//
//  Created by Sacchy on 2014/05/17.
//
//

#include "Player.h"

namespace player
{
    int animeFrameCnt = 0;
}

Player::Player()
{
    pStatus_ = pStatus::isIdle;
}

Player* Player::create()
{
	Player *node = new Player();
	node->initialize()->autorelease();
	return node;
}

Player* Player::initialize()
{
    player_ = Sprite::create("res/heri_1.png");
    this->addChild(player_);
    
    // ヘリのアニメーション用
    HeriFrame_[0] = "res/heri_1.png";
    HeriFrame_[1] = "res/heri_2.png";
    HeriFrame_[2] = "res/heri_3.png";
    
    this->schedule(schedule_selector(Player::startAnimation));

    return this;
}

void Player::tapMe()
{
    pStatus_ = pStatus::isTap;
    log("Player - tapMe");
}

void Player::untapMe()
{
    pStatus_ = pStatus::isUnTap;
    log("Player - untapMe");
}

void Player::startAnimation(float delta)
{
    spriteFrameTime_ += delta;
    if (spriteFrameTime_ > 0.045)
    {
        spriteFrameTime_ = 0;
        player::animeFrameCnt = (player::animeFrameCnt+1)%HeriFrame_.size();
        player_->setTexture(Director::getInstance()->getTextureCache()->addImage(HeriFrame_[player::animeFrameCnt]));
    }
}
