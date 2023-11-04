namespace zeroref{
  class SocketObj;
  class BasicSocket{
    friend class SocketObj;
    protected:
    virtual void mSendMsg(&SocketObj sobj)=0;
    virtual void mWriteMsg(&SocketObj sobj)=0;
  };
  class TCPSocketServer : public BasicSocket{
    friend class SocketObj;
    public:
    virtual TCPSocketServer(struct sockaddr_in6 addr);
    virtual TCPSocketServer();
    virtual ~TCPSocketServer();
  };
};