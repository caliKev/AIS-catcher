# -------------------
# The build container
# -------------------
FROM debian:bullseye-slim AS build

RUN apt-get update
RUN apt-get upgrade -y

RUN apt-get install git make gcc g++ cmake pkg-config -y
RUN apt-get install librtlsdr-dev libairspy-dev libhackrf-dev libairspyhf-dev libzmq3-dev libsoxr-dev libcurl4-openssl-dev zlib1g-dev libpq-dev -y

COPY . /root/AIS-catcher

RUN cd /root/AIS-catcher; mkdir build; cd build; cmake ..; make; make install

# -------------------------
# The application container
# -------------------------
FROM debian:bullseye-slim

RUN apt-get update
RUN apt-get upgrade -y

RUN apt-get install librtlsdr0 libairspy0 libhackrf0 libairspyhf1 libzmq5 libsoxr0 libcurl4 libpq-dev postgresql postgresql-client -y

COPY --from=build /usr/local/bin/AIS-catcher /usr/local/bin/AIS-catcher

ENTRYPOINT ["/usr/local/bin/AIS-catcher"]

#RUN sudo -u postgres createdb ais
RUN postgres createdb ais
RUN psql ais <DBMS/create.sql

#RUN su postgres; createdb ais; exit; cd /root/AIS-catcher; psql ais <DBMS/create.sql
