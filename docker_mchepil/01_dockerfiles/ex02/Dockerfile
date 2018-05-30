FROM ruby
MAINTAINER Chepil <mishamcveres@gmail.com>

RUN apt-get update
RUN apt-get -y autoclean
RUN apt-get -y clean
RUN gem install rails

ONBUILD COPY app/ /opt/app

ONBUILD RUN bundle install
ONBUILD RUN rake db:migrate
ONBUILD RUN rake db:setup
ONBUILD RUN rake db:seed

WORKDIR /opt/app