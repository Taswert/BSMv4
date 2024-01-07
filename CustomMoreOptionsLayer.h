#pragma once
#include <gd.h>
#include <cocos2d.h>
#include <cocos-ext.h>

class CustomMoreOptionsLayer : public gd::FLAlertLayer {
public:
    

    //bool init();
    //static CustomMoreOptionsLayer* create();
    void addToggle(std::string description, std::string key, std::string name);
    void menuRedraw(cocos2d::CCMenu* btnMenu);

    void drawGraphicsLayer(cocos2d::CCMenu* btnMenu);
    void drawGameplayLayer(cocos2d::CCMenu* btnMenu);
    void drawPracticeLayer(cocos2d::CCMenu* btnMenu);
    void drawPerformanceLayer(cocos2d::CCMenu* btnMenu);
    void drawAudioLayer(cocos2d::CCMenu* btnMenu);
    void drawOtherLayer(cocos2d::CCMenu* btnMenu);

    void onGameplay(CCObject* sender);
    void onPractice(CCObject* sender);
    void onPerformance(CCObject* sender);
    void onAudio(CCObject* sender);
    void onOther(CCObject* sender);
    void onGraphics(CCObject* sender);
    
    void mySetup();
    
};