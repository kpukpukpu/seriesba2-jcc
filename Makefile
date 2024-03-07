CC = $(CXX)
CXXFLAGS = -std=c++11 -pedantic -Wall

all: factmain

factmain: factmain.o demander_annee.o date_Paques.o affiche_date.o

demander_annee.o: demander_annee.cpp demander_annee.h
date_Paques.o: date_Paques.cpp date_Paques.h
affiche_date.o: affiche_date.cpp affiche_date.h 
factmain.o: factmain.cpp affiche_date.h date_Paques.h demander_annee.h

