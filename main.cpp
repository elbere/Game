#include <iostream>
#include <string>
#include <vector>
#include "scene.h"

using namespace std;
vector<Scene> World;
int world_index = 0;



int init(){
	init_scene(&World);
	return 0;
}

void print_opciones(){
	for (int i = 0; i < World[world_index].acciones.size(); ++i){
		cout << i << ": " << OPCIONES[World[world_index].acciones[i]->value] << " ";
	}
	cout << endl;
}

int main()
{
	init();
	int play = true;
	int first_time_in = true;
	int curr_action = -1;
	int old_world = world_index;
	while (play){
		if (first_time_in){
			cout << World[world_index].paisaje->desc << endl;
			first_time_in = false;
		}
		else if (curr_action > -1){
			cout << World[world_index].acciones[curr_action]->result->desc << endl;
		}
		else {
			play = false;
		}

		print_opciones();

		cin >> curr_action;
		World[world_index].acciones[curr_action]->ejecutar(&world_index);

		if (old_world != world_index){ old_world = world_index; first_time_in = true; }

		cout << endl;

	}


	return 0;
}

