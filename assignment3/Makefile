CC = g++ -g
exe_file = test

$(exe_file): driver.o traits.o tenants_traits.o tenants_biz.o house.o apartments.o buisness.o player.o
	$(CC) driver.o traits.o tenants_traits.o tenants_biz.o house.o apartments.o buisness.o player.o -o $(exe_file)
traits.o: traits.cpp
	$(CC) -c traits.cpp
house.o: house.cpp
	$(CC) -c house.cpp
apartments.o: apartments.cpp
	$(CC) -c apartments.cpp
buisness.o: buisness.cpp
	$(CC) -c buisness.cpp
tenants_biz.o: tenants_biz.cpp
	$(CC) -c tenants_biz.cpp
tenants_traits.o: tenants_traits.cpp
	$(CC) -c tenants_traits.cpp
driver.o: driver.cpp
	$(CC) -c driver.cpp
player.o: player.cpp
	$(CC) -c player.cpp
