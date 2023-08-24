#include <../header/NetSocket.hpp>
NetSocket(){}
NetSocket(sockaddr_in6 addr)
{
  this.address = addr;
}
bool FPRC::NetSocket::setConfig(bool isUDP,bool isServer)
{
  this.Protocol = isUDP;
  this.Way = isServer;
  return true;
}
bool FPRC::NetSocket::setAddr(sockaddr_in6 addr)
{
  this.address = addr;
  return true;
}
bool close(){
  int end;
  end = close(socketfd);
  if (end == -1) return false;
  return true;
}