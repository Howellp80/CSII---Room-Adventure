all:
	g++ Main.cpp Game.cpp Player.cpp Space.cpp Center.cpp Water.cpp Hot.cpp Cold.cpp Dark.cpp -o gold

clean:
	rm gold
