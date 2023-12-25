#ifndef __SOCKET_ZEROSRP_H__
#define SOCKET_TYPE int
#define SOCKET_ADDR sockaddr_in6
#define SInfo struct SocketInfo
#include <string>
namespace ZSRP
{
  class BasicSocketIO
  {
    ///所有Socket类的父类，提供泛型支持
    protected:
      struct SocketInfo
      {
        ///套接字信息
        SOCKET_TYPE fd;
        SOCKET_ADDR ad;
      };
      /** 
       *@brief 由子类重写，提供多态性
       *@prama[in] buf 发送的数据
       */
      virtual void writeMsg(SInfo obj,string& buf) = 0;
      /** 
       *@brief 由子类重写，提供多态性
       *@prama[out] buf 接受的数据
       */
      virtual void readMsg(SInfo obj,string& buf) = 0;
      /**
       * @brief 父类提供的访问方法
       * @prama[in] buf 发送的数据
       */
       static void SuWrite(BasicSocketIO& cls,SInfo obj,string& buf){cls.writeMsg(obj,buf)};
      /**
       * @brief 父类提供的访问方法
       * @prama[out] buf 接受的数据
       */
       static void SuRead(BasicSocketIO& cls,SInfo obj,string& buf){cls.readMsg(obj,buf)};
  }；
};
#define __SOCKET_ZEROSRP_H__
#endif