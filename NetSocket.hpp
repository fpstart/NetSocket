#include <deque>
#include <queue>
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
    public:
    virtual SocketObj(SocketObj&& src);
    virtual &SocketObj operator=(SocketObj&& rhs);
    virtual SocketObj(SocketObj& src)=delete;
    virtual &SocketObj operator=(SocketObj& rhs)=delete;
    virtual sockaddr_in6 getAddr();
    virtual &SocketObj operator<< (const char byte);
    virtual &SocketObj operator<< (const char* data);
    virtual &SocketObj operator>> (char*& target);
    private:
    virtual SocketObj(int clientid,struct sockaddr_in6 address,BasicSocket* super);
    BasicSocket* mSuper;
    int mClientid;
    struct sockaddr_in6 mAddress;
  };
};