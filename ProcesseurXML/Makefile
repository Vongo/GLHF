MODEL = $(wildcard ./model/*.cpp)

all: commun
commun: *.l *.y *.cpp
	flex -P xml xml.l
	bison -p xml --debug --verbose --defines=xml.tab.h xml.y
	g++ -std=c++11 -g -DYYDEBUG -o xmltool main.cpp ${MODEL} xml.tab.c lex.xml.c
	touch commun
clean:
	-rm -rf xml.tab.c lex.xml.c xml.tab.h xml.output xmltool commun
test:
	cd Tests; ./mktest.sh