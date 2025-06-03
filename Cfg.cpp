#include "Cfg.h"


ResourceManager<sf::Texture, Cfg::Textures> Cfg::textures = {};
ResourceManager<sf::Font, Cfg::Fonts> Cfg::fonts = {};
ResourceManager<sf::Music, Cfg::Music> Cfg::music = {};
ResourceManager<sf::SoundBuffer, Cfg::Sounds> Cfg::sounds = {};

//ActionMap<int> Cfg::playerInputs = {};

void Cfg::Initialize()
{
    initTextures();
    initFonts();
	initMusic();
    initSounds();
}

void Cfg::Uninitialize()
{
	Cfg::textures.unloadAll();
}

void Cfg::initMusic()
{
}

void Cfg::initSounds()
{
}

void Cfg::initTextures()
{
	textures.load(Textures::UNKNOWN, "invariant.png");
	textures.load(Textures::Ship, "assets/textures/sandbox_choice_state/ship.png");
	textures.load(Textures::ChoiceStateBG, "assets/textures/sandbox_choice_state/choice_state_bg.jpg");
	textures.load(Textures::MyFaceUntriggered, "assets/textures/sandbox_choice_state/face_choice_not_triggered.png");
	textures.load(Textures::MyFaceTriggered, "assets/textures/sandbox_choice_state/face_choice_triggered.png");
	textures.load(Textures::CrashersBG, "assets/textures/sandbox_side_scroller/bg.png");
	textures.load(Textures::Crash_Intro_0, "assets/textures/sandbox_side_scroller_play/BG_CrashersIntro_layer0.png");
	textures.load(Textures::Crash_Intro_1, "assets/textures/sandbox_side_scroller_play/BG_CrashersIntro_layer1.png");
	textures.load(Textures::Crash_Intro_2, "assets/textures/sandbox_side_scroller_play/BG_CrashersIntro_layer2.png");
	textures.load(Textures::Crash_Intro_3, "assets/textures/sandbox_side_scroller_play/BG_CrashersIntro_layer3.png");


	
}

void Cfg::destroyTextures()
{
	
}


void Cfg::initFonts()
{
	fonts.load(Fonts::SandboxChoiceStateFont, "assets/fonts/Crusty.ttf");
}