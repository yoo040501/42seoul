#include "../includes/Client.hpp"

Client::Client(): fd(-1), ch_cnt(0), bot_active(false), pass(false), passcheck(false), auth(false),nick("*"), lownick("*") ,oldnick(""), username(""), hostname(""), 
					servername(""), realname(""), mode(""), addr(), len(0){
}

Client::Client(Client const& copy): fd(copy.fd), ch_cnt(copy.ch_cnt), bot_active(copy.bot_active),pass(copy.pass), passcheck(copy.passcheck), auth(copy.auth), nick(copy.nick),
									lownick(copy.lownick), oldnick(copy.oldnick), username(copy.username), hostname(copy.hostname), servername(copy.servername),
									realname(copy.realname), mode(copy.mode), addr(copy.addr), len(copy.len){
}

Client&	Client::operator=(Client const& oth){
	if (this != &oth){
		this->fd = oth.fd; this->ch_cnt = oth.ch_cnt; this->lownick = oth.lownick;
		this->pass = oth.pass; this->passcheck = oth.passcheck; this->bot_active = oth.bot_active;
		this->auth = oth.auth; this->nick = oth.nick; ; this->oldnick = oth.oldnick;
		this->username = oth.username; this->hostname = oth.hostname;
		this->servername = oth.servername; this->realname = oth.realname;
		this->mode = oth.mode; this->addr = oth.addr; this->len = oth.len;
	}
	return *this;
}

Client::~Client(){}

void	Client::setfd(int f) {fd = f;}
void	Client::setPass(bool flag) {pass = flag;}
void	Client::setBot(bool flag) {bot_active = flag;}
void	Client::setPassCheck(bool flag) {passcheck = flag;}
void	Client::setAuth(bool flag) {auth = flag;}
void	Client::setNick(std::string const &ni){
	oldnick = nick;
	nick = ni;
	lownick = ni;
	std::transform(lownick.begin(), lownick.end(), lownick.begin(), ::tolower);
}

void	Client::setUser(std::string const &us, std::string const &hs, std::string const &sn, std::string const &rn){
	username = us;
	hostname = hs;
	servername = sn;
	realname = rn;
}

void	Client::setaddr(struct sockaddr_in &tmp){
	addr = tmp;
	len = sizeof(tmp);
}

int	Client::getfd() const {return this->fd;}
bool	Client::getPass() const {return this->pass;}
bool	Client::getBot() const {return this->bot_active;}
bool	Client::getPassCheck() const {return this->passcheck;}
bool	Client::getAuth() const {return this->auth;}
std::string& Client::getNick() {return this->nick;}
std::string& Client::getLowNick() {return this->lownick;}
std::string& Client::getOldnick() {return this->oldnick;}
std::string& Client::getUser() {return this->username;}
const std::vector<std::string>& Client::getInvitedChannel() {return this->Invited_channel;}

struct sockaddr_in	Client::getaddr() { return this->addr;}

const std::string &Client::getNickname() const { return this->nick; }

void	Client::addInviteChannel(std::string channel){
	Invited_channel.push_back(channel);
}

void	Client::removeInviteChannel(std::string channel){
	std::vector<std::string>::iterator it = Invited_channel.begin();
	while (it != Invited_channel.end()){
		if (*it == channel)
			it = Invited_channel.erase(it);
		else
			it++;
	}
}
