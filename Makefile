test:
	make kuranes;
	make clean;
	make run;
kuranes: main.o read_data.o time_conv.o media_ini.o audio.o load_maps.o ini_obj.o management_game.o physics.o draw.o events.o levels.o clean_up.o
	c++ -o kuranes main.o read_data.o time_conv.o media_ini.o audio.o load_maps.o ini_obj.o management_game.o physics.o draw.o events.o levels.o clean_up.o -lSDL -lSDL_mixer -lSDL_ttf -lm

main.o: main.c 
	c++ -I "/usr/include/SDL" -I "/usr/local/include/SDL/" -c main.c -lm;

read_data.o: read_data.c 
	c++ -c read_data.c

time_conv.o: time_conv.c 
	c++ -c time_conv.c

media_ini.o: media_ini.c
	c++ -I "/usr/include/SDL" -I "/usr/local/include/SDL/" -c media_ini.c

audio.o: audio.c 
	c++ -I "/usr/include/SDL" -c audio.c

load_maps.o: load_maps.c 
	c++ -g -I "/usr/include/SDL" -I "/usr/local/include/SDL/" -c load_maps.c
	
ini_obj.o: ini_obj.c 
	c++ -I "/usr/include/SDL" -c ini_obj.c 

management_game.o: management_game.c 
	c++  -I "/usr/include/SDL" -I "/usr/local/include/SDL/" -c management_game.c
	
physics.o: physics.c 
	c++ -I "/usr/include/SDL" -c physics.c
	
draw.o: draw.c 
	c++ -I "/usr/include/SDL" -I "/usr/local/include/SDL/" -c draw.c

events.o: events.c 
	c++ -I "/usr/include/SDL" -c events.c

levels.o: levels.c 
	c++ -g -I "/usr/include/SDL" -c levels.c
clean_up.o: clean_up.c 
	c++ -I "/usr/include/SDL" -I "/usr/local/include/SDL/" -c clean_up.c
	
run:
	./kuranes
	
clean:
	-rm *.o 
