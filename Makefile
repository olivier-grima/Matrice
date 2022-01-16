CC = g++ # le compilateur `a utiliser                                           
CFLAGS = -Wall -std=c++17 # les options du compilateur                               
LDFLAGS = -lm  # les options pour l editeur de liens                           
SRC = matriceDouble.cpp matriceCreuse.cpp main.cpp   # les fichiers sources                         
PROG = MATRICE  # nom de l executable                                         
OBJS =  $(SRC:.c=.o) # les .o qui en decoulent                                 
.SUFFIXES: .c .o    # lien entre les suffixes                                   

all: $(PROG)

# etapes de compilation et d edition de liens                                 
$(PROG): $(OBJS)
		$(CC) -o $@ $^ $(LDFLAGS) #$@ la cible $^toutes les d ́ependances        

main.o:matrice.hpp matriCreuse.hpp matriceDouble.hpp
matrice.o:matrice.hpp
matriceDouble.o: matriceDouble.hpp
matriceCreuse.o: matriceCreuse.hpp
# le lien entre .o et .c                                                        
%.o: %.cpp
		$(CC) $(CFLAGS) -c $<  #$< derniere dependance                        

