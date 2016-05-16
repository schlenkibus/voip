#pragma once
#include <SFML/Network.hpp>
#include "AudioPlayer.h"

class TCPconnection
{
private:
	AudioPlayer player;
	sf::TcpListener listener;
	sf::TcpSocket socket, connection;
	sf::Packet recievedPackets[2];
public:
	TCPconnection(void);
	~TCPconnection(void);
	bool waitForConnections(); //Returns false if connection/portbind/packet recieveing fails
	void connectWithSocket(sf::IpAddress &ip, sf::Packet &sampleP, sf::Packet &infoP);
};
