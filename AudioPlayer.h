#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

class AudioPlayer
{
private:
	sf::Sound snd;
public:
	AudioPlayer();
	~AudioPlayer(void);
	void togglePlayback();
	bool processPackets(sf::Packet &sampleP, sf::Packet &infoP);
};

