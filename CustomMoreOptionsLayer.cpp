#include "CustomMoreOptionsLayer.h"
#include <gd.h>
#include <cocos2d.h>
#include <cocos-ext.h>
using namespace cocos2d;

short layer = 0;
CCArray btnArr;

//URAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA
void CustomMoreOptionsLayer::drawGraphicsLayer(cocos2d::CCMenu* btnMenu) {
	//main section
	//auto buttonSprite = CCSprite::createWithSpriteFrameName("GJ_optionsBtn_001.png");
	//buttonSprite->setScale(0.8f);
	//auto button = gd::CCMenuItemSpriteExtra::create(buttonSprite, this, menu_selector(gd::MenuLayer::onOptions));
	//btnMenu->addChild(button);


	//advBtn is crashing layer sometimes... //Because of ButtonSprite. Strange...
						//gd::ButtonSprite::create("Options", 255, 1, "goldFont.fnt", "GJ_button_01.png", 0, 1.f);
	std::cout << "I am drawing the button" << std::endl;
	auto advBtnSprite = gd::ButtonSprite::create("Advanced", 60, 1, "goldFont.fnt", "GJ_button_04.png", 25.f, 0.6f);
	std::cout << "Still drawing..." << std::endl;
	auto advBtn = gd::CCMenuItemSpriteExtra::create(advBtnSprite, this, menu_selector(gd::VideoOptionsLayer::onAdvanced));
	std::cout << "Almost..." << std::endl;
	btnMenu->addChild(advBtn);
	std::cout << "Done!" << std::endl<<std::endl;
	advBtn->setPosition({ 150.f, 115.f });
	//gd::ButtonSprite::create("Advanced", 0x3c, 0, 0.6, false, "goldFont.fnt", "GJ_button_04.png", 25.0);

	//adding to array section
	//btnArr.addObject(button);
	btnArr.addObject(advBtn);
}

void CustomMoreOptionsLayer::drawGameplayLayer(cocos2d::CCMenu* btnMenu) {

}

void CustomMoreOptionsLayer::drawPracticeLayer(cocos2d::CCMenu* btnMenu) {

}

void CustomMoreOptionsLayer::drawPerformanceLayer(cocos2d::CCMenu* btnMenu) {

}

void CustomMoreOptionsLayer::drawAudioLayer(cocos2d::CCMenu* btnMenu) {

}

void CustomMoreOptionsLayer::drawOtherLayer(cocos2d::CCMenu* btnMenu) {

}

//FUCKING FUNCTION THAT CAN'T WORK WELL FUCK YOU SO MUCH OMG
void CustomMoreOptionsLayer::menuRedraw(CCMenu* btnMenu) {
	std::cout << "menuRedraw" << std::endl;
	while (btnArr.count()) {
		static_cast<CCNode*>(btnArr.lastObject())->removeMeAndCleanup();
		btnArr.removeLastObject();
	}
	
	auto graphBtnSpriteOn = CCSprite::createWithSpriteFrameName("GJ_longBtn02_001.png");
	auto graphBtnSprite = CCSprite::createWithSpriteFrameName("GJ_longBtn01_001.png");
	auto graphLabel = CCLabelBMFont::create("Graphics", "bigFont.fnt");
	graphBtnSpriteOn->setAnchorPoint({ 0.f, 0.f });
	graphBtnSprite->addChild(graphBtnSpriteOn);
	if (layer != 0) graphBtnSpriteOn->setVisible(false);
	graphBtnSprite->addChild(graphLabel);
	graphLabel->setPosition({ graphBtnSprite->getContentSize().width / 2, graphBtnSprite->getContentSize().height / 2 });
	graphLabel->setScale(0.5f);
	//std::cout << "parent = 0x" << btnMenu << std::endl;
	auto graphBtn = gd::CCMenuItemSpriteExtra::create(graphBtnSprite, this, menu_selector(CustomMoreOptionsLayer::onGraphics)); //-
	btnMenu->addChild(graphBtn);
	graphBtn->setPosition({ -130.f, 100.f });
	graphBtn->setTag(4571);

	auto gpBtnSpriteOn = CCSprite::createWithSpriteFrameName("GJ_longBtn02_001.png");
	auto gpBtnSprite = CCSprite::createWithSpriteFrameName("GJ_longBtn01_001.png");
	auto gpLabel = CCLabelBMFont::create("Gameplay", "bigFont.fnt");
	gpBtnSpriteOn->setAnchorPoint({ 0.f, 0.f });
	gpBtnSprite->addChild(gpBtnSpriteOn);
	if (layer != 1) gpBtnSpriteOn->setVisible(false);
	gpBtnSprite->addChild(gpLabel);
	gpLabel->setPosition({ gpBtnSprite->getContentSize().width / 2, gpBtnSprite->getContentSize().height / 2 });
	gpLabel->setScale(0.5f);
	auto gpBtn = gd::CCMenuItemSpriteExtra::create(gpBtnSprite, this, menu_selector(CustomMoreOptionsLayer::onGameplay));
	btnMenu->addChild(gpBtn);
	gpBtn->setPosition({ -130.f, 60.f });
	gpBtn->setTag(4572);

	auto pracBtnSpriteOn = CCSprite::createWithSpriteFrameName("GJ_longBtn02_001.png");
	auto pracBtnSprite = CCSprite::createWithSpriteFrameName("GJ_longBtn01_001.png");
	auto pracLabel = CCLabelBMFont::create("Practice", "bigFont.fnt");
	pracBtnSpriteOn->setAnchorPoint({ 0.f, 0.f });
	pracBtnSprite->addChild(pracBtnSpriteOn);
	if (layer != 2) pracBtnSpriteOn->setVisible(false);
	pracBtnSprite->addChild(pracLabel);
	pracLabel->setPosition({ pracBtnSprite->getContentSize().width / 2, pracBtnSprite->getContentSize().height / 2 });
	pracLabel->setScale(0.5f);
	auto pracBtn = gd::CCMenuItemSpriteExtra::create(pracBtnSprite, this, menu_selector(CustomMoreOptionsLayer::onPractice));
	btnMenu->addChild(pracBtn);
	pracBtn->setPosition({ -130.f, 20.f });
	pracBtn->setTag(4573);

	auto perfBtnSpriteOn = CCSprite::createWithSpriteFrameName("GJ_longBtn02_001.png");
	auto perfBtnSprite = CCSprite::createWithSpriteFrameName("GJ_longBtn01_001.png");
	auto perfLabel = CCLabelBMFont::create("Performance", "bigFont.fnt");
	perfBtnSpriteOn->setAnchorPoint({ 0.f, 0.f });
	perfBtnSprite->addChild(perfBtnSpriteOn);
	if (layer != 3) perfBtnSpriteOn->setVisible(false);
	perfBtnSprite->addChild(perfLabel);
	perfLabel->setPosition({ perfBtnSprite->getContentSize().width / 2, perfBtnSprite->getContentSize().height / 2 });
	perfLabel->setScale(0.35f);
	auto perfBtn = gd::CCMenuItemSpriteExtra::create(perfBtnSprite, this, menu_selector(CustomMoreOptionsLayer::onPerformance));
	btnMenu->addChild(perfBtn);
	perfBtn->setPosition({ -130.f, -20.f });
	perfBtn->setTag(4574);

	auto audioBtnSpriteOn = CCSprite::createWithSpriteFrameName("GJ_longBtn02_001.png");
	auto audioBtnSprite = CCSprite::createWithSpriteFrameName("GJ_longBtn01_001.png");
	auto audioLabel = CCLabelBMFont::create("Audio", "bigFont.fnt");
	audioBtnSpriteOn->setAnchorPoint({ 0.f, 0.f });
	audioBtnSprite->addChild(audioBtnSpriteOn);
	if (layer != 4) audioBtnSpriteOn->setVisible(false);
	audioBtnSprite->addChild(audioLabel);
	audioLabel->setPosition({ audioBtnSprite->getContentSize().width / 2, audioBtnSprite->getContentSize().height / 2 });
	audioLabel->setScale(0.5f);
	auto audioBtn = gd::CCMenuItemSpriteExtra::create(audioBtnSprite, this, menu_selector(CustomMoreOptionsLayer::onAudio));
	btnMenu->addChild(audioBtn);
	audioBtn->setPosition({ -130.f, -60.f });
	audioBtn->setTag(4575);

	auto otherBtnSpriteOn = CCSprite::createWithSpriteFrameName("GJ_longBtn02_001.png");
	auto otherBtnSprite = CCSprite::createWithSpriteFrameName("GJ_longBtn01_001.png");
	auto otherLabel = CCLabelBMFont::create("Other", "bigFont.fnt");
	otherBtnSpriteOn->setAnchorPoint({ 0.f, 0.f });
	otherBtnSprite->addChild(otherBtnSpriteOn);
	if (layer != 5) otherBtnSpriteOn->setVisible(false);
	otherBtnSprite->addChild(otherLabel);
	otherLabel->setPosition({ otherBtnSprite->getContentSize().width / 2, otherBtnSprite->getContentSize().height / 2 });
	otherLabel->setScale(0.5f);
	auto otherBtn = gd::CCMenuItemSpriteExtra::create(otherBtnSprite, this, menu_selector(CustomMoreOptionsLayer::onOther));
	btnMenu->addChild(otherBtn);
	otherBtn->setPosition({ -130.f, -100.f });
	otherBtn->setTag(4576);

	btnArr.addObject(graphBtn);
	btnArr.addObject(gpBtn);
	btnArr.addObject(pracBtn);
	btnArr.addObject(perfBtn);
	btnArr.addObject(audioBtn);
	btnArr.addObject(otherBtn);

	switch (layer)
	{
	case 0:
		drawGraphicsLayer(btnMenu);
		break;
	case 1:
		drawGameplayLayer(btnMenu);
		break;
	case 2:
		drawPracticeLayer(btnMenu);
		break;
	case 3:
		drawPerformanceLayer(btnMenu);
		break;
	case 4:
		drawAudioLayer(btnMenu);
		break;
	case 5:
		drawOtherLayer(btnMenu);
		break;
	default:
		drawGraphicsLayer(btnMenu);
		break;
	}
	//std::cout << btnArr.count() << std::endl << std::endl;
}
//auto btnMenu = static_cast<CCMenu*>(static_cast<gd::CCMenuItemSpriteExtra*>(sender)->getParent());

void CustomMoreOptionsLayer::onGraphics(CCObject* sender) {
	layer = 0;
	std::cout << "onGraphics" << std::endl;
	auto btnMenu = static_cast<CCMenu*>(static_cast<gd::CCMenuItemSpriteExtra*>(sender)->getParent());
	menuRedraw(btnMenu);
}

void CustomMoreOptionsLayer::onGameplay(CCObject* sender) {
	layer = 1;
	//std::cout << btnArr.count() << std::endl;
	auto btnMenu = static_cast<CCMenu*>(static_cast<gd::CCMenuItemSpriteExtra*>(sender)->getParent());
	menuRedraw(btnMenu);
}

void CustomMoreOptionsLayer::onPractice(CCObject* sender) {
	layer = 2;
	//std::cout << btnArr.count() << std::endl;
	auto btnMenu = static_cast<CCMenu*>(static_cast<gd::CCMenuItemSpriteExtra*>(sender)->getParent());
	menuRedraw(btnMenu);
}

void CustomMoreOptionsLayer::onPerformance(CCObject* sender) {
	layer = 3;
	//std::cout << btnArr.count() << std::endl;
	auto btnMenu = static_cast<CCMenu*>(static_cast<gd::CCMenuItemSpriteExtra*>(sender)->getParent());
	menuRedraw(btnMenu);
}

void CustomMoreOptionsLayer::onAudio(CCObject* sender) {
	layer = 4;
	//std::cout << btnArr.count() << std::endl;
	auto btnMenu = static_cast<CCMenu*>(static_cast<gd::CCMenuItemSpriteExtra*>(sender)->getParent());
	menuRedraw(btnMenu);
}

void CustomMoreOptionsLayer::onOther(CCObject* sender) {
	layer = 5;
	//std::cout << btnArr.count() << std::endl;
	auto btnMenu = static_cast<CCMenu*>(static_cast<gd::CCMenuItemSpriteExtra*>(sender)->getParent());
	menuRedraw(btnMenu);
}

void CustomMoreOptionsLayer::mySetup() {

	auto bgSprite = cocos2d::extension::CCScale9Sprite::create("GJ_square01.png");
	auto director = CCDirector::sharedDirector();
	bgSprite->setPosition({ director->getWinSize().width / 2, director->getWinSize().height / 2 });
	bgSprite->setContentSize({ 400.f, 280.f });
	bgSprite->setZOrder(1);
	m_pLayer->addChild(bgSprite);
	m_pButtonMenu->setPosition({ director->getWinSize().width / 2, director->getWinSize().height / 2 });

	m_button1->removeAllChildren();
	m_button1->initWithSpriteFrameName("GJ_closeBtn_001.png");
	m_button1->setPosition({ m_button1->getContentSize().width / 2, m_button1->getContentSize().height / 2 });

	auto btn1ccmise = gd::from<gd::CCMenuItemSpriteExtra*>(m_button1, 0xC4);
	btn1ccmise->setContentSize(m_button1->getContentSize());
	btn1ccmise->setPosition({ -195.f, 135.f });
	
	btnArr.removeAllObjects();


	auto categoryBgSprite = cocos2d::extension::CCScale9Sprite::create("square02_001.png");
	categoryBgSprite->setZOrder(1);
	categoryBgSprite->setOpacity(100);
	categoryBgSprite->setPosition({ director->getWinSize().width / 2 - 130.f, director->getWinSize().height / 2 });
	categoryBgSprite->setContentSize({ 105.f, 245.f });
	m_pLayer->addChild(categoryBgSprite);

	//auto myAwesomeScrollView = cocos2d::extension::CCScrollView::create({ 100.f, 100.f }, );

	menuRedraw(m_pButtonMenu);
	

	auto label = CCLabelBMFont::create("", "bigFont.fnt");
	label->setAnchorPoint({ 0.f, 0.5f });
	label->setScale(0.5f);
	label->setOpacity(128);
	label->setString(CCString::createWithFormat("0x%p", m_scrollingLayer)->getCString()); //ButtonSprite 0xC4 - CCMenuItemSpriteExtra
	label->setPosition(25, 25);
	label->setZOrder(2);
	m_pLayer->addChild(label); 

	
	//m_button1->setPosition(btn1ccmise->getPosition());
	//auto closeBtn = gd::CCMenuItemSpriteExtra::create(closeBtnSprite, this, menu_selector(CustomMoreOptionsLayer::onBtn1));
	
}