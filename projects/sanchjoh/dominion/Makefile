CFLAGS = -Wall -fpic -coverage -lm -std=c99

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)

testDrawCard: testDrawCard.c dominion.o rngs.o
	gcc -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

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

tests.out: unittest1.c unittest2.c dominion.c rngs.c
	echo "Results for running unit tests:" > tests.out

	echo	"unittest1.c:" >> tests.out
	gcc -o unittest1 unittest1.c dominion.c rngs.c $(CFLAGS)
	./unittest1 >> tests.out
	gcov -b dominion.c >> tests.out

	echo "unittest2.c:" >> tests.out
	gcc -o unittest2 unittest2.c dominion.c rngs.c
	./unittest2 >> tests.out
	gcov -b dominion.c >> tests.out

randtests.out: randomtestadventurer.c randomtestcard1.c dominion.o rngs.o
	echo "Results for running the randomized tests:" > randtests.out

	echo "randomtestadventurer.c:" >> randtests.out
	gcc -o randomtestadventurer -g randomtestadventurer.c dominion.c rngs.c $(CFLAGS)
	./randomtestadventurer >> randtests.out
	echo " " >> randtests.out
	echo "First GCOV result:" >> randtests.out
	gcov -b -f dominion.c >> randtests.out
	echo " " >> randtests.out

	echo "randomtestcard1.c:" >> randtests.out
	gcc -o randomtestcard1 -g randomtestcard1.c dominion.c rngs.c $(CFLAGS)
	./randomtestcard1 >> randtests.out
	echo "Second GCOV result:" >> randtests.out
	gcov -b -f dominion.c >> randtests.out
	echo " " >> randtests.out

	echo "randomtestcard2.c:" >> randtests.out
	gcc -o randomtestcard2 -g randomtestcard2.c dominion.c rngs.c $(CFLAGS)
	./randomtestcard2 >> randtests.out

	echo " " >> randtests.out
	echo "Third GCOV result:" >> randtests.out
	gcov -b -f dominion.c >> randtests.out

all: playdom player testDrawCard testBuyCard badTestDrawCard tests.out

clean:
	rm -f *.o playdom.exe playdom test.exe test player player.exe testInit
	rm -f testInit.exe *.gcov *.gcda *.gcno *.so unittest1 unittest2 tests.out
	rm -f randomtests.out randomtestadventurer randomtestcard1 randomtestcard2
