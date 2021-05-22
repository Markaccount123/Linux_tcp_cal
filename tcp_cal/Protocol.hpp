#ifndef __PROTOCOL_HPP__
#define __PROTOCOL_HPP__ 

#include<iostream>

typedef struct Request{
  int x;//左操作数
  int y;//右操作数
  char op;//操作符
}Request;

typedef struct Response{
  int code;//表示结果值是否可被信任，为0的时候，说明结果可以信任
  int result;//结果
}Response;


#endif 

