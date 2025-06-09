#ifndef CFG_H__
#define CFG_H__

#include <SFML/Graphics.hpp>
#include "ResourceMgr.h"
#include <vector>
#include <SFML/Audio.hpp>
class Cfg
{
public:
	Cfg() = delete;
	Cfg(const Cfg&) = delete;
	Cfg& operator=(const Cfg&) = delete;


	//globals 
	//static sol::state lua; // globals are bad, but we'll use it for simpler implementation
	static void Initialize();
	static void Uninitialize();
	// Resource Enums 
	enum class Textures  { Ship, CrashersPlayerSheet, CrashersBG, Crash_Intro_0, Crash_Intro_1, Crash_Intro_2, Crash_Intro_3, ChoiceStateBG,  MyFaceUntriggered, MyFaceTriggered, UNKNOWN };
	enum class Fonts  { SandboxChoiceStateFont };
	enum class Music {  };
  enum class Sounds { };


	// resource buckets for each type of resource
	static ResourceManager<sf::Texture, Textures> textures;
	static ResourceManager<sf::Font, Fonts> fonts;
	static ResourceManager<sf::Music, Music> music;
	static ResourceManager<sf::SoundBuffer, Sounds> sounds;

	//static ActionMap<int> playerInputs;

private:
    // initalize the resources for the entire game
    static void initFonts();
    static void initMusic();
    static void initSounds();
    static void initTextures();
	static void destroyTextures();
};


#endif