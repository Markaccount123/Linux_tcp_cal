#ifndef __CLIENT_HPP__
#define __CLIENT_HPP__ 

#include<iostream>
#include<unistd.h>
#include<cstdlib>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<sys/wait.h>
#include"Protocol.hpp"
class client{
  private:
    std::string ip;
    int port;
    int sock;
  public:
    client(std::string _ip,int _port)
      :ip(_ip),port(_port),sock(-1)
    {}

    void initclient()
    {
      sock = socket(AF_INET,SOCK_STREAM,0);
      if(sock < 0){
        std::cerr<<"socket error!"<<std::endl;
        exit(2);
      }

    }

    void start()
    {
      struct sockaddr_in server;
      server.sin_family = AF_INET;
      server.sin_port = htons(port);
      server.sin_addr.s_addr = inet_addr(ip.c_str());

      if(connect(sock,(struct sockaddr*)&server,sizeof(server)) < 0){
          std::cerr << "connect error"<<std::endl;
          exit(3);  
        }

      //建立的是短链接，所以只需要C发过去，S返回回来，那么一次通信就算结束了
      Request rq;
      Response rsp;
      std::cout << "date1# ";
      std::cin >> rq.x;
      std::cout << "date2# ";
      std::cin >> rq.y;
      std::cout << "op# ";
      std::cin >> rq.op;

      send(sock,&rq,sizeof(rq),0);
      ssize_t s = recv(sock,&rsp,sizeof(rsp),0);
      if(s > 0){
        std:: cout <<"code : "<<  rsp.code <<std::endl;
        std::cout <<"result : "<<rsp.result << std::endl;
      }
    }


    ~client()
    {
      close(sock);
    }
};























#endif 
