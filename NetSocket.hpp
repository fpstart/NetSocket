#ifndef __SOCKET_ZEROSRP_H__
#include <string>
namespace ZSRP
{
  class BasicSocketIO
  {
    ///所有Socket类的父类，提供泛型支持
    protected:
      /** @brief 由子类重写，提供多态性
        @prama[in] buf 发送的数据*/
      virtual void sendMsg(string& buf) = 0;
  }；
};
#define __SOCKET_ZEROSRP_H__
#endif