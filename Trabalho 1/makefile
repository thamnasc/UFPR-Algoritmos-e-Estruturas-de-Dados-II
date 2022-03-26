parametrosCompilacao=-Wall #-Wshadow
nomePrograma=trab

all: $(nomePrograma)

$(nomePrograma): main.o ordenacao.o testes.o
	gcc -o $(nomePrograma) main.o ordenacao.o testes.o $(parametrosCompilacao)

main.o: main.c
	gcc -c main.c $(parametrosCompilacao)

ordenacao.o: ordenacao.h ordenacao.c
	gcc -c ordenacao.c $(parametrosCompilacao)

testes.o: testes.h testes.c
	gcc -c testes.c $(parametrosCompilacao)

clean:
	rm -f *.o *.gch $(nomePrograma)
