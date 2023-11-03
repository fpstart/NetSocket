namespace zeroref{
  class SocketObj;
  class BasicSocket{
    friend class SocketObj;
    protected:
    virtual void mSendMsg(&SocketObj sobj);
    virtual void mWriteMsg(&SocketObj sobj);
  };
  class TCPSocketServer : public BasicSocket{}
}