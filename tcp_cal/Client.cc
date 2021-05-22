#include"Client.hpp"

void Usage(std::string proc)
{
  std::cout << "Usage#"<< "\n\t";
  std::cout << proc << " server_ip  server_port "<< std::endl;
}

int main(int argc,char *argv[])
{
  if(argc != 3){
    Usage(argv[0]);
    exit(1);
  }

  client *cp = new client(argv[1],atoi(argv[2])); 
  cp->initclient();
  cp->start();

  return 0;
}
