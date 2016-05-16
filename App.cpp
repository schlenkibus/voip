#include "App.h"
#include <SFML/Network.hpp>
#include "AufnehmButton.h"

App::App(void)
{
	aButton = 0;
	recorder = 0;
}


App::~App(void)
{
	if(recorder)
		delete recorder;
}

void App::setButton(AufnehmButton * butt)
{
	aButton = butt;
}

bool App::toggleAufnahme()
{
	if(recorder != 0)
	{
		recorder->stop();
		processBuffer(recorder->getBuffer());
		delete recorder;
		recorder = 0;
		aButton->setString("Aufnahme");
		return false;
	}
	else
	{
		recorder = new sf::SoundBufferRecorder;
		recorder->start(22050);
		aButton->setString("Stop");
		return true;
	}
}

void App::processBuffer(const sf::SoundBuffer &buffer)
{
	sf::Packet packetSamples, packetInfos;
	packetSamples.append(buffer.getSamples(), buffer.getSampleCount() * buffer.getChannelCount() * 2);
	packetInfos << buffer.getChannelCount();
	sendBuffer(connector, packetSamples, packetInfos);
}

void App::sendBuffer(TCPconnection &connector, sf::Packet &sampleP, sf::Packet &infoP)
{
	makeIPAdress();
	connector.connectWithSocket(m_ipAddress, sampleP, infoP);
}

void App::ConnectorW8()
{
	connector.waitForConnections();
}

void App::setIP(std::string &str)
{
	m_ipString = str;
}

void App::makeIPAdress()
{
	m_ipAddress = m_ipString;
}
