gg = g++ -g
excutable = test

$(excutable): driver.o Insect.o Bees.o Harvester.o Thrower.o Fire.o Longthrower.o Shortthrower.o Wall.o Ninja.o Bodyguard.o Gamefiles.o
	$(gg) driver.o Insect.o Bees.o Harvester.o Thrower.o Fire.o Longthrower.o Shortthrower.o Wall.o Ninja.o Bodyguard.o Gamefiles.o -o $(excutable)
driver.o: driver.cpp
	$(gg) -c driver.cpp
Insect.o: Insect.cpp
	$(gg) -c Insect.cpp
Bees.o: Bees.cpp
	$(gg) -c Bees.cpp
Harvester.o: Harvester.cpp
	$(gg) -c Harvester.cpp
Thrower.o: Thrower.cpp
	$(gg) -c Thrower.cpp
Fire.o: Fire.cpp
	$(gg) -c Fire.cpp
Longthrower.o: Longthrower.cpp
	$(gg) -c Longthrower.cpp
Shortthrower.o: Shortthrower.cpp
	$(gg) -c Shortthrower.cpp
Wall.o: Wall.cpp
	$(gg) -c Wall.cpp
Ninja.o: Ninja.cpp
	$(gg) -c Ninja.cpp
Bodyguard.o: Bodyguard.cpp
	$(gg) -c Bodyguard.cpp
Gamefiles.o: Gamefiles.cpp
	$(gg) -c Gamefiles.cpp

clean:
	-rm *.o $(objects) test