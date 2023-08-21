#include <unistd.h>
#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>
namespace FRPC
{
  class NetSocket
  {
    public:
      bool setConfig(bool isUDP,bool isServer);
      bool setAddr(sockaddr_in6 addr);
      bool setAddr(in_addr6 addr,unsigned short port);
      //bool setAddr(char* addr,unsigned short port);
      //bool setAddr(char* addr);
      bool open();
    private:
  };
};