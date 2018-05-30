FROM debian
MAINTAINER Chepil <mishamcveres@gmail.com>

RUN apt-get update -y && apt-get upgrade -y
RUN apt-get install bzip2 wget -y
RUN wget http://dl.4players.de/ts/releases/3.0.13.8/teamspeak3-server_linux_amd64-3.0.13.8.tar.bz2
RUN bunzip2 *.bz2
RUN tar -xvf *.tar

CMD ["sh", "teamspeak3-server_linux_amd64/ts3server_minimal_runscript.sh"]
