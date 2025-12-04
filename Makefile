# Compilateur
CXX = g++

# Options de compilation
# -Iinc : indique où trouver les .h
# -Wall -Wextra : active les avertissements
CXXFLAGS = -Wall -Wextra -Iinc

# Liste des fichiers sources
SRC = tests/test_fonctions.cpp src/fonctions.cpp src/vecteur.cpp


# Transformation des .cpp en .o (fichiers objets)
OBJ = $(SRC:.cpp=.o)

# Nom de l'exécutable final
EXEC = fonctions

# Règle par défaut
all: $(EXEC)

# Édition de liens (création de l'exécutable)
$(EXEC): $(OBJ)
	$(CXX) $(OBJ) -o $(EXEC)

# Compilation des fichiers sources en objets
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Nettoyage des fichiers générés
clean:
	rm -f $(OBJ) $(EXEC)