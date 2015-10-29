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
	std::cout << "port binded" << std::endl;
	if(connection.send(samplesP) != sf::Socket::Done)
		return;
	std::cout << "samples send!" << std::endl;
	if(connection.send(infosP) != sf::Socket::Done)
		return;
	std::cout << "infos send!" << std::endl;
	connection.disconnect();
}

bool TCPconnection::waitForConnections()
{
	if(listener.listen(53000) != sf::Socket::Done)
		return false;
	std::cout << "listens on port 53000\n";
	if(listener.accept(connection) != sf::Socket::Done)
		return false;
	std::cout << "connection acceptet: " << connection.getRemoteAddress() << std::endl;
	sf::Packet samplePacket, infoPacket;
	if(connection.receive(samplePacket) != sf::Socket::Done)
	{
		std::cout << "fehler beim empfangen des 1. Pakets\n";
		return false;
	}
	std::cout << "samples recieved\n";
	if(connection.receive(infoPacket) != sf::Socket::Done)
	{
		std::cout << "fehler beim empfangen des 2. Pakets\n";
		return false;
	}
	std::cout << "infos recieved\n";
	recievedPackets[0] = samplePacket;
	recievedPackets[1] = infoPacket;
	player.processPackets(recievedPackets[0], recievedPackets[1]);
	listener.close();
	connection.disconnect();
	waitForConnections();
	return true;
}

sf::Packet TCPconnection::getPacket(short i)
{
	if(i == 1 || i == 0)
		return recievedPackets[i];
	return recievedPackets[0]; //um out of range vorzubeugen
}