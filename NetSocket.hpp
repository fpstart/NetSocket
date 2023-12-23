#ifndef __SOCKET_ZEROSRP_H__
#include <string>
namespace ZSRP
{
  class BasicSocketIO
  {
    ///所有Socket类的父类，提供泛型支持
    protected:
      virtual void sendMsg(string buf) = 0;
  }；
};
#define __SOCKET_ZEROSRP_H__
#endif