#define CAC_PROJ_NAME "Template"

#if __APPLE__
	#include <CacKit>
	using namespace cocos2d;
#else
	#include "win32cac.h"
#endif

#include <extensions/cocos-ext.h>

#define MEMBERBYOFFSET(type, class, offset) *reinterpret_cast<type*>(reinterpret_cast<uintptr_t>(class) + offset) 
#define MBO MEMBERBYOFFSET 

#include "CustomMoreOptionsLayer.h"


bool(__thiscall* OptionsLayer_customSetup)(gd::OptionsLayer* self);
bool __fastcall OptionsLayer_customSetup_H(gd::OptionsLayer* self, void*) {
    //if (!OptionsLayer_customSetup(self)) return false;

    auto dropLayer = self->getDropdownLayer();
    
    auto btnMenu = CCMenu::create();
    auto accountButtonSprite = gd::ButtonSprite::create("Account", 255, 1, "goldFont.fnt", "GJ_button_01.png", 0, 1.f);
    auto accountButton = gd::CCMenuItemSpriteExtra::create(accountButtonSprite, self, menu_selector(gd::OptionsLayer::onAccount));
    accountButton->setPosition({ 0, 80 });
    btnMenu->addChild(accountButton);
    dropLayer->addChild(btnMenu);

    auto optionsButtonSprite = gd::ButtonSprite::create("Options", 255, 1, "goldFont.fnt", "GJ_button_01.png", 0, 1.f);
    auto optionsButton = gd::CCMenuItemSpriteExtra::create(optionsButtonSprite, self, menu_selector(OptionsLayer::onOptions));
    optionsButton->setPosition({ 0, 40 });
    btnMenu->addChild(optionsButton);
    dropLayer->addChild(btnMenu);

    auto creditsButtonSprite = gd::ButtonSprite::create("Credits", 255, 1, "goldFont.fnt", "GJ_button_01.png", 0, 1.f);
    auto creditsButton = gd::CCMenuItemSpriteExtra::create(creditsButtonSprite, self, menu_selector(OptionsLayer::onCredits));
    btnMenu->addChild(creditsButton);
    dropLayer->addChild(btnMenu);


    CCNode* gameStatsManager = reinterpret_cast<CCNode * (__thiscall*)()>(gd::base + 0x165df0)();
    int userCoins = reinterpret_cast<int(__thiscall*)(CCNode*, const char*)>(gd::base + 0x168680)(gameStatsManager, "12");

    auto lockSprite = CCSprite::createWithSpriteFrameName("GJ_lock_open_001.png");
    if (userCoins < 10) {
        lockSprite = CCSprite::createWithSpriteFrameName("GJ_lockGray_001.png");
        auto coinSprite = CCSprite::createWithSpriteFrameName("GJ_coinsIcon2_001.png");
        auto coinLabel = CCLabelBMFont::create("10", "bigFont.fnt");

        lockSprite->addChild(coinSprite);
        lockSprite->addChild(coinLabel);

        coinSprite->setPosition({ lockSprite->getContentSize().width * 0.5f + 7.5f, lockSprite->getContentSize().height * 0.5f - 21.f });
        coinSprite->setScale(0.5f);
        coinLabel->setPosition({ lockSprite->getContentSize().width * 0.5f - 7.5f, lockSprite->getContentSize().height * 0.5f - 21.f });
        coinLabel->setScale(0.4f);
    }

    auto lockBtn = gd::CCMenuItemSpriteExtra::create(lockSprite, self, menu_selector(OptionsLayer::onLock));
    btnMenu->addChild(lockBtn);
    lockBtn->setPosition({
        CCDirector::sharedDirector()->getWinSize().width - 20.f - btnMenu->getPositionX(),
        CCDirector::sharedDirector()->getWinSize().height - 18.f - btnMenu->getPositionY()
        });


    auto musicLabel = CCLabelBMFont::create("Music", "bigFont.fnt");
    musicLabel->setScale(0.6f);
    musicLabel->setPosition(dropLayer->getContentSize().width * 0.5f, dropLayer->getContentSize().height * 0.5f - 34);
    dropLayer->addChild(musicLabel);

    auto sfxLabel = CCLabelBMFont::create("SFX", "bigFont.fnt");
    sfxLabel->setScale(0.6f);
    sfxLabel->setPosition(dropLayer->getContentSize().width * 0.5f, dropLayer->getContentSize().height * 0.5f - 74);
    dropLayer->addChild(sfxLabel);


    auto fmod = gd::FMODAudioEngine::sharedEngine();

    auto musicSlider = Slider::create(dropLayer, menu_selector(OptionsLayer::musicSliderChanged), "slidergroove.png", "sliderthumb.png", "sliderthumbsel.png", 1.f);
    musicSlider->setPosition(dropLayer->getContentSize().width * 0.5f, dropLayer->getContentSize().height * 0.5f - 54);
    SliderThumb* musicSliderThumb = musicSlider->getSliderTouchLogic()->getThumb();
    musicSliderThumb->setValue(fmod->getMusicVolume());
    musicSlider->updateBar();
    dropLayer->addChild(musicSlider);

    auto sfxSlider = Slider::create(dropLayer, menu_selector(OptionsLayer::sfxSliderChanged), "slidergroove.png", "sliderthumb.png", "sliderthumbsel.png", 1.f);
    sfxSlider->setPosition(dropLayer->getContentSize().width * 0.5f, dropLayer->getContentSize().height * 0.5f - 94);
    SliderThumb* sfxSliderThumb = sfxSlider->getSliderTouchLogic()->getThumb();
    sfxSliderThumb->setValue(fmod->getSFXVolume());
    sfxSlider->updateBar();
    dropLayer->addChild(sfxSlider);

    auto label = CCLabelBMFont::create("", "bigFont.fnt");
    label->setAnchorPoint({ 0.f, 0.5f });
    label->setScale(0.5f);
    label->setOpacity(128);
    label->setString(CCString::createWithFormat("0x%p", musicSliderThumb)->getCString());
    label->setPosition(25, 25);
    dropLayer->addChild(label);

    auto label2 = CCLabelBMFont::create("", "bigFont.fnt");
    label2->setAnchorPoint({ 0.f, 0.5f });
    label2->setScale(0.5f);
    label2->setOpacity(128);
    label2->setString(CCString::createWithFormat("user coins: %d", userCoins)->getCString());
    label2->setPosition(25, 40);
    dropLayer->addChild(label2);
    return true;
}

//bool(__thiscall* MenuLayer_init)(CCLayer* self);
//bool __fastcall MenuLayer_init_H(CCLayer* self, void*) {
//    if (!MenuLayer_init(self)) return false;
//
//    return true;
//}

bool(__thiscall* PlayLayer_init)(CCLayer* self, CCObject* gjgamelvl, bool idk1, bool idk2);
bool __fastcall PlayLayer_init_H(CCLayer* self, void*, CCObject* gjgamelvl, bool idk1, bool idk2) {
    if (!PlayLayer_init(self, gjgamelvl, idk1, idk2)) return false;
    auto label = CCLabelBMFont::create("", "bigFont.fnt");
    label->setAnchorPoint({ 0.f, 0.5f });
    label->setScale(0.5f);
    label->setOpacity(128);
    label->setString(CCString::createWithFormat("0x%p", self)->getCString());
    label->setPosition(25, 25);
    self->addChild(label);

    return true;
}

bool(__thiscall* GJBaseGameLayer_init)(CCLayer* self);
bool __fastcall GJBaseGameLayer_init_H(CCLayer* self) {
    if (!GJBaseGameLayer_init(self)) return false;
    std::cout << "GJBaseGameLayer* = " << self << std::endl;
    return true;
}

bool(__thiscall* LevelInfoLayer_init)(CCLayer* self, int* i1, int* i2);
bool __fastcall LevelInfoLayer_init_H(CCLayer* self, void*, int* i1, int* i2) {
    if (!LevelInfoLayer_init(self, i1, i2)) return false;
    auto buttonSprite = CCSprite::createWithSpriteFrameName("GJ_optionsBtn_001.png");
    buttonSprite->setScale(0.8f);
    auto button = gd::CCMenuItemSpriteExtra::create(buttonSprite, self, menu_selector(gd::MenuLayer::onOptions));
    auto menu = CCMenu::create();
    auto touchDispatcher = cocos2d::CCDirector::sharedDirector()->getTouchDispatcher();

    auto label = CCLabelBMFont::create("", "bigFont.fnt");
    label->setAnchorPoint({ 0.f, 0.5f });
    label->setScale(0.5f);
    label->setOpacity(128);
    label->setZOrder(999);
    label->setString(CCString::createWithFormat("0x%p", touchDispatcher)->getCString());
    label->setPosition(25, 25);
    self->addChild(label);

    menu->addChild(button);
    menu->setPosition({
        70.f,
        CCDirector::sharedDirector()->getWinSize().height - 24.f });
    self->addChild(menu);
    return true;
}

void(__thiscall* OptionsLayer_onOptions)(OptionsLayer* self, CCObject* sender);
void __fastcall OptionsLayer_onOptions_H(OptionsLayer* self, void*, CCObject* sender) {
    auto layer = static_cast<CustomMoreOptionsLayer*>(CustomMoreOptionsLayer::create(nullptr, nullptr, "nullptr", nullptr, " "));
    layer->mySetup();
    layer->FLAlertLayer::show();


    //layer->show();
}

//bool(__thiscall* MoreOptionsLayer_init)(MoreOptionsLayer* self);
//bool __fastcall MoreOptionsLayer_init_H(MoreOptionsLayer* self) {
//    if (!CCLayerColor::init()) return false;
//    return true;
//}


void inject() {
	#if _WIN32
	auto base = reinterpret_cast<uintptr_t>(GetModuleHandle(0));
	auto cocos = GetModuleHandleA("libcocos2d.dll");

	AllocConsole();
	freopen_s(reinterpret_cast<FILE**>(stdout), "CONOUT$", "w", stdout);
	//MH_CreateHook(
	//	(PVOID)(base + 0x276700),
	//	MenuLayer_init_H,
	//	(LPVOID*)&MenuLayer_init // note the &, this gets the address of the variable
	//);
	MH_CreateHook(
        (PVOID)(base + 0x2d69a0),
		PlayLayer_init_H,
        (LPVOID*)&PlayLayer_init
	);
	MH_CreateHook(
        (PVOID)(base + 0x2ab510),
		OptionsLayer_customSetup_H,
        (LPVOID*)&OptionsLayer_customSetup
	);

	MH_CreateHook(
        (PVOID)(base + 0x18CC80),
		GJBaseGameLayer_init_H,
        (LPVOID*)&GJBaseGameLayer_init
	);
	MH_CreateHook(
        (PVOID)(base + 0x24cd80),
		LevelInfoLayer_init_H,
        (LPVOID*)&LevelInfoLayer_init
	);
    MH_CreateHook(
        (PVOID)(base + 0x2ac1b0),
        OptionsLayer_onOptions_H,
        (LPVOID*)&OptionsLayer_onOptions
    );
    //MH_CreateHook(
    //    (PVOID)(base + 0x2ac880),
    //    MoreOptionsLayer_init_H,
    //    (LPVOID*)&MoreOptionsLayer_init
    //);

	//WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0xA76A4), "\xE9\x83\x00\x00\x00\x90", 6, NULL); // custom object bypass
	//WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0xA7854), "\x90\x90", 2, NULL); // custom object bypass

	//WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x2B3B0C), "\x90\x90", 2, NULL); // practice in platformer

	MH_EnableHook(MH_ALL_HOOKS);
	#endif
}

#if _WIN32
	WIN32CAC_ENTRY(inject)
#endif
