all: main.o playFair.o 

hello: main.o fun1.o fun2.o
	g++ main.o PlayFairDecrypter.o PlayFairEncrypter.o -o bin

main.o: main.cpp
	g++ -c main.cpp

playFair.o: PlayFairDecrypter.cpp PlayFairEncrypter.cpp
	g++ -c PlayFairDecrypter.cpp PlayFairEncrypter.cpp

