#include "TCPconnection.h"
#include <iostream>

TCPconnection::TCPconnection(void)
{
}


TCPconnection::~TCPconnection(void)
{
}

void TCPconnection::connectWithSocket(sf::IpAddress &ip, sf::Packet &samplesP, sf::Packet &infosP)
{
	if(connection.connect(ip, 53000) != sf::Socket::Done)
		return;
	if(connection.send(samplesP) != sf::Socket::Done)
		return;
	if(connection.send(infosP) != sf::Socket::Done)
		return;
	connection.disconnect();
}

bool TCPconnection::waitForConnections()
{
	if(listener.listen(53000) != sf::Socket::Done)
		return false;
	if(listener.accept(connection) != sf::Socket::Done)
		return false;
	sf::Packet samplePacket, infoPacket;
	if(connection.receive(samplePacket) != sf::Socket::Done)
		return false;
	if(connection.receive(infoPacket) != sf::Socket::Done)
		return false;
	recievedPackets[0] = samplePacket;
	recievedPackets[1] = infoPacket;
	player.processPackets(recievedPackets[0], recievedPackets[1]);
	listener.close();
	connection.disconnect();
	waitForConnections();
	return true;
}