CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -I include

# Cibles par défaut
all: main

# Programme principal
main: bin/main.exe

bin/main.exe: src/main.cpp src/vecteur.cpp include/vecteur.hpp
	$(CXX) $(CXXFLAGS) src/main.cpp src/vecteur.cpp -o bin/main.exe

# Test pour la classe Vecteur
test_vecteur: bin/test_vecteur.exe

bin/test_vecteur.exe: tests/test_vecteur.cpp src/vecteur.cpp include/vecteur.hpp
	$(CXX) $(CXXFLAGS) tests/test_vecteur.cpp src/vecteur.cpp -o bin/test_vecteur.exe

# Nettoyage des exécutables
clean:
	rm -f bin/*.exe
