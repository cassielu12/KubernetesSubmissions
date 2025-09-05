FROM alpine:latest

RUN apk add --no-cache g++

WORKDIR /usr/src/app

COPY PrintTime.cpp ./

RUN g++ -std=c++23 -o PrintTimeApp PrintTime.cpp 

CMD ["./PrintTimeApp"]