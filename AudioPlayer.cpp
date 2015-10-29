#include "AudioPlayer.h"
#include <iostream>

AudioPlayer::AudioPlayer()
{
}


AudioPlayer::~AudioPlayer(void)
{
}

void AudioPlayer::togglePlayback()
{
	if(snd.Playing)
		snd.stop();
	else
		snd.play();
}

bool AudioPlayer::processPackets(sf::Packet &sampleP, sf::Packet &infoP)
{
	sf::SoundBuffer bufferino;
	sf::Uint64 samplecount;
	int channelcount;
	infoP >> channelcount;
	samplecount = sampleP.getDataSize() /  channelcount / 2;
	sf::Int16 * samples = (sf::Int16*)sampleP.getData();
	bufferino.loadFromSamples(samples, samplecount, channelcount, 22050); 
	snd.setBuffer(bufferino);
	sf::Clock clk;
	snd.play();
	while(clk.getElapsedTime().asMicroseconds() <= bufferino.getDuration().asMicroseconds())
	{
		//Nix machen
	}
	return true;
}