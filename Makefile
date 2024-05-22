# Nom de l'exécutable
EXEC = main

# Liste des fichiers source
SRC = main.c affichage.c entrainement.c statistique.c fathlete.c verification.c menu.c

# Liste des fichiers objets
OBJ = $(SRC:.c=.o)

# Compilateur
CC = clang

# Options de compilation
CFLAGS = -g -Wno-everything -pthread -lm

# Règle pour créer l'exécutable
$(EXEC): $(OBJ)
  $(CC) $(CFLAGS) -o $@ $^

# Règle pour compiler les fichiers .c en fichiers .o
%.o: %.c
  $(CC) $(CFLAGS) -c -o $@ $<

# Règle pour nettoyer les fichiers objets et l'exécutable
clean:
  rm -f $(OBJ) $(EXEC)