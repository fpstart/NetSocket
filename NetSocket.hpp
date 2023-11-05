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
    enum Opt{LISTEN=0,NONE=1}
    virtual TCPSocketServer(struct sockaddr_in6 addr,Opt opt=LISTEN);
    virtual TCPSocketServer(TCPSocketServer&& src);
    virtual &TCPSocketServer operator=(TCPSocketServer&& rhs);
    virtual TCPSocketServer(TCPSocketServer& src)=delete;
    virtual &TCPSocketServer operator=(TCPSocketServer& rhs)=delete;
    virtual void listen();
    virtual void shutdown();
    virtual SocketObj accept();
    virtual ~TCPSocketServer();
    protected:
    virtual void mSendMsg(&SocketObj sobj) override;
    virtual void mWriteMsg(&SocketObj sobj) override;
    private:
    int mSockfd;
    int mListenfd;
    struct sockaddr_in6 mAddress;
  };
  
  class SocketObj{
    friend class BasicSocket;
    friend class TCPSocketServer;
  };
};