#include "../includes/Server.hpp"

bool Server::isPort(char *pt) // 0 ~ 65535, 0 ~ 1023 Well-known port
{
    std::string tmp(pt);
	std::istringstream iss(tmp);
	iss >> std::noskipws >> port;
    if (!iss.eof() || iss.fail())
        return false;
    if (port < 1024 || port > 65535)
        return false;
    return true;
}

void    Server::setSockaddr(struct  sockaddr_in &_server_addr){
    memset(&_server_addr, 0, sizeof(_server_addr));
    _server_addr.sin_family = AF_INET;
    _server_addr.sin_addr.s_addr = INADDR_ANY;
    _server_addr.sin_port = htons(port);
}

void    Server::createEvent(int fd)
{
    struct kevent event_tmp;
    EV_SET(&event_tmp, fd, EVFILT_READ, EV_ADD, 0, 0, NULL);
    changeList.push_back(event_tmp);
}

bool	Server::generateClient(){
	Client		cl;
	socklen_t   client_len = sizeof(client_addr);
	
	cl.setfd(accept(server_fd,(struct sockaddr*)&client_addr, &client_len));  // 클라이언트 연결 허용 
	if (cl.getfd() < 0)
		return false;
	cl.setaddr(client_addr);
	fcntl(cl.getfd(), F_SETFL, O_NONBLOCK);
	createEvent(cl.getfd());
	client.insert(std::make_pair(cl.getfd(), cl));
	sendMsg(WAITING(), cl.getfd());
	return true;
}

void	Server::generateBot(){
	Bot					*_bot = new Bot();
    struct sockaddr_in	bot_addr;
    socklen_t			bot_len = sizeof(bot_addr);

    // 봇 클라이언트 소켓 생성
    int bot_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (bot_fd < 0) {
        throw SocketFailException();
    }

	setSockaddr(bot_addr);
    if (connect(bot_fd, (struct sockaddr*)&bot_addr, bot_len) < 0) {
        close(bot_fd);
        throw SocketFailException();
    }
    fcntl(bot_fd, F_SETFL, O_NONBLOCK);

    _bot->setfd(bot_fd);
    _bot->setaddr(bot_addr);

    createEvent(_bot->getfd());
    bot = _bot;
}

// 원래 구현되어 있던 Server.cpp 코드
Channel& Server::getChannel(std::string &chName){
    std::map<std::string, Channel>::iterator it;

    for (it = channel.begin(); it != channel.end(); ++it){
        if (it->first == chName)
            break;
    }
    return it->second;
}

bool Server::isServerUser(std::string user){
    std::map<int, Client>::iterator it;

    for (it = client.begin(); it != client.end(); ++it){
        if (it->second.getLowNick() == user)
            return true;
    }
    return false;
}

bool Server::isValidChname(std::string &chName){
    std::map<std::string, Channel>::iterator it;

    for (it = channel.begin(); it != channel.end(); ++it){
        if (it->first == chName)
            return true;
    }
    return false;
}

Client& Server::getClient(std::string &clName){
    std::map<int, Client>::iterator it;

    for (it = client.begin(); it != client.end(); ++it){
        if (it->second.getLowNick() == clName)
            break;
    }
    return it->second;
}

std::map<std::string, int>	Server::getNicks()	{return this->nick;}
std::map<std::string, Channel> Server::getChannels() { return this->channel; }
std::map<int, Client> Server::getClients() { return this->client; }
