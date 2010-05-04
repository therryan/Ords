ords: ords.o file.o plaintext.o settings.o args.o ui.o uifuncs.o init.o definition.o def_term.o dictionary.o question.o collection.o utils.o
	g++ -o ords ords.o file.o plaintext.o settings.o args.o ui.o uifuncs.o init.o definition.o def_term.o dictionary.o question.o collection.o utils.o

ords.o: ords.cpp file/file.h cli/cli.h
	g++ -Wall -pedantic -c ords.cpp
	
file.o: file/file.cpp file/file.h
	g++ -Wall -pedantic -c file/file.cpp
	
plaintext.o: file/plaintext.cpp file/plaintext.h
	g++ -Wall -pedantic -c file/plaintext.cpp
	
settings.o: file/settings.cpp file/settings.h
	g++ -Wall -pedantic -c file/settings.cpp
	
args.o: cli/args.cpp cli/args.h
	g++ -Wall -pedantic -c cli/args.cpp
	
ui.o: cli/ui.cpp cli/ui.h
	g++ -Wall -pedantic -c cli/ui.cpp
	
uifuncs.o: cli/uifuncs.cpp cli/uifuncs.h
	g++ -Wall -pedantic -c cli/uifuncs.cpp
	
init.o: init/init.cpp init/init.h
	g++ -Wall -pedantic -c init/init.cpp
	
definition.o: data/definition.cpp data/definition.h
	g++ -Wall -pedantic -c data/definition.cpp
	
def_term.o: data/def_term.cpp data/def_term.h
	g++ -Wall -pedantic -c data/def_term.cpp
	
dictionary.o: data/dictionary.cpp data/dictionary.h
	g++ -Wall -pedantic -c data/dictionary.cpp

question.o: data/question.cpp data/question.h
	g++ -Wall -pedantic -c data/question.cpp
	
collection.o: data/collection.cpp data/collection.h
	g++ -Wall -pedantic -c data/collection.cpp
	
utils.o: utils/utils.cpp utils/utils.h
	g++ -Wall -pedantic -c utils/utils.cpp
	
clean:
	rm ords ords.o file.o plaintext.o settings.o args.o ui.o uifuncs.o init.o definition.o def_term.o dictionary.o question.o collection.o utils.o