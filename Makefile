CC = g++ # le compilateur `a utiliser                                           
CFLAGS = --std=c++14 # les options du compilateur                               
LDFLAGS = -lm  # les options pour l’ ́editeur de liens                           
SRC = main.cpp matriceDouble.cpp  # les fichiers sources                         
PROG = MATRICE  # nom de l’ex ́ecutable                                         
OBJS =  $(SRC:.c=.o) # les .o qui en d ́ecoulent                                 
.SUFFIXES: .c .o    # lien entre les suffixes                                   

all: $(PROG)

#  ́etapes de compilation et d’ ́edition de liens                                 
$(PROG): $(OBJS)
		$(CC) -o $@ $^ $(LDFLAGS) #$@ la cible $^toutes les d ́ependances        

main.o:matrice.hpp matriCreuse.hpp matriceDouble.hpp
matriceDouble.o: matriceDouble.hpp
# le lien entre .o et .c                                                        
%.o: %.cpp
		$(CC) $(CFLAGS) -c $<  #$< derniere dependance                        

