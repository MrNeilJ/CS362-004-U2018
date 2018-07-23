CFLAGS = -Wall -fpic -coverage -lm -std=c99

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)
#To run playdom you need to entere: ./playdom <any integer number> like ./playdom 10*/
testDrawCard: testDrawCard.c dominion.o rngs.o
	gcc  -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

badTestDrawCard: badTestDrawCard.c dominion.o rngs.o
	gcc -o badTestDrawCard -g  badTestDrawCard.c dominion.o rngs.o $(CFLAGS)

testBuyCard: testDrawCard.c dominion.o rngs.o
	gcc -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

testAll: dominion.o testSuite.c
	gcc -o testSuite testSuite.c -g  dominion.o rngs.o $(CFLAGS)

interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)

runtests: testDrawCard 
	./testDrawCard &> unittestresult.out
	gcov dominion.c >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out


player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)


unitTest1:
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.c unitTest1.c rngs.c -o unitTest1 -lm -g

unitTest2:
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.c unitTest2.c rngs.c -o unitTest2 -lm -g

unitTest3:
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.c unitTest3.c rngs.c -o unitTest3 -lm -g

unitTest4:
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.c unitTest4.c rngs.c -o unitTest4 -lm -g

cardTest1:
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.c cardTest1.c rngs.c -o cardTest1 -lm -g

cardTest2:
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.c cardTest2.c rngs.c -o cardTest2 -lm -g

cardTest3:
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.c cardTest3.c rngs.c -o cardTest3 -lm -g

cardTest4:
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.c cardTest4.c rngs.c -o cardTest4 -lm -g

unitCardTest:
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.c unitTest1.c rngs.c -o unitTest1 -lm -g
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.c unitTest2.c rngs.c -o unitTest2 -lm -g
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.c unitTest3.c rngs.c -o unitTest3 -lm -g
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.c unitTest4.c rngs.c -o unitTest4 -lm -g
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.c cardTest1.c rngs.c -o cardTest1 -lm -g
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.c cardTest2.c rngs.c -o cardTest2 -lm -g
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.c cardTest3.c rngs.c -o cardTest3 -lm -g
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.c cardTest4.c rngs.c -o cardTest4 -lm -g

unitTestOutput:
	./unitTest1 &> unittestresults.out
	./unitTest2 >> unittestresults.out
	./unitTest3 >> unittestresults.out
	./unitTest4 >> unittestresults.out
	./cardTest1 >> unittestresults.out
	./cardTest2 >> unittestresults.out
	./cardTest3 >> unittestresults.out
	./cardTest4 >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	cat dominion.c.gcov >> unittestresults.out

unittestresults:
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.c unitTest1.c rngs.c -o unitTest1 -lm -g
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.c unitTest2.c rngs.c -o unitTest2 -lm -g
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.c unitTest3.c rngs.c -o unitTest3 -lm -g
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.c unitTest4.c rngs.c -o unitTest4 -lm -g
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.c cardTest1.c rngs.c -o cardTest1 -lm -g
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.c cardTest2.c rngs.c -o cardTest2 -lm -g
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.c cardTest3.c rngs.c -o cardTest3 -lm -g
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.c cardTest4.c rngs.c -o cardTest4 -lm -g
	./unitTest1 &> unittestresults.out
	./unitTest2 >> unittestresults.out
	./unitTest3 >> unittestresults.out
	./unitTest4 >> unittestresults.out
	./cardTest1 >> unittestresults.out
	./cardTest2 >> unittestresults.out
	./cardTest3 >> unittestresults.out
	./cardTest4 >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	cat dominion.c.gcov >> unittestresults.out


all: playdom player

clean:
	rm -f *.o playdom.exe playdom player player.exe  *.gcov *.gcda *.gcno *.so *.out testDrawCard testDrawCard.exe unitTest1 unitTest2 unitTest3 unitTest4 cardTest1 cardTest2 cardTest3 cardTest4 unittestresults.out
