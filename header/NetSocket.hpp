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
      NetSocket();
      NetSocket(sockaddr_in6 addr);
      bool setConfig(bool isUDP,bool isServer);
      bool setAddr(sockaddr_in6 addr);
      //bool setAddr(in_addr6 addr,unsigned short port);
      //bool setAddr(char* addr,unsigned short port);
      //bool setAddr(char* addr);
      bool open();
      bool close();
      bool isClose();
      class AcceptObj
      {
        public:
          bool read(char* text);
          bool write(char* text);
          &AcceptObj operator<<(char* text);
          &AcceptObj operator<<(unsigned int text);
          &AcceptObj operator>>(char* text);
          &AcceptObj operator>>(unsigned int text);
          bool close();
          bool isClose();
        private:
          int linkfd;
          sockaddr_in6 address;
      };
      AcceptObj accept();
    private:
      int socketfd;
      sockaddr_in6 address;
      bool Protocol;
      bool Way;
      bool openTCPServer();
      bool openTCPClient();
      bool openUDPServer();
      bool openUDPClient();
  };
};