#pragma once

#include "SFML\System.hpp"
#include "SFML\Audio.hpp"
#include "TCPconnection.h"
#include "AudioPlayer.h"
#include "Textfeld.h"

class AufnehmButton;

class App
{
private:
	sf::SoundBufferRecorder * recorder;
	TCPconnection connector;
	sf::IpAddress m_ipAddress;
	std::string m_ipString;
	AufnehmButton * aButton;

public:
	App(void);
	~App(void);
	bool toggleAufnahme();
	void processBuffer(const sf::SoundBuffer &buffer);
	void sendBuffer(TCPconnection &connector, sf::Packet &sampleP, sf::Packet &infoP);
	void AnrufStart(std::string &ip);
	void ConnectorW8();
	void setButton(AufnehmButton * butt);
	void setIP(std::string &str);
	void makeIPAdress();
};

