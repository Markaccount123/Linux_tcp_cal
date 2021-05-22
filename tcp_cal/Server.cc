#include"Server.hpp"

void Usage(std::string proc)
{
  std::cout << "Usage : "<< "\n\t";
  std::cout << proc << " server_port "<< std::endl;
}

int main(int argc,char *argv[])
{
  if(argc != 2){
    Usage(argv[0]);
    exit(1);
  }

  server *sp = new server(atoi(argv[1])); 
  sp->initServer();
  sp->start();

  delete sp;
}
