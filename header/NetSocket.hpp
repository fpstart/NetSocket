namespace FRPC
{
  class NetSocket
  {
    public:
      bool setConfig(bool isUDP,bool isServer);
      bool setAddr(sockaddr_in6 addr);
  };
};