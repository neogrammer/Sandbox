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
}

void Cfg::destroyTextures()
{
	
}


void Cfg::initFonts()
{
	fonts.load(Fonts::SandboxChoiceStateFont, "assets/fonts/Crusty.ttf");
}