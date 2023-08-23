#include <../header/NetSocket.hpp>
bool FPRC::NetSocket::setConfig(bool isUDP,bool isServer)
{
  this.Protocol = isUDP;
  this.Way = isServer;
  return true;
}
bool FPRC::NetSocket::setAddr(sockaddr_in6 addr)
{
  this.address = addr;
}