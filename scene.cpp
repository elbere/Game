#include "scene.h"

void noHaceNada(int*,int){}

void mover(int *i, int d){	*i = d;}

int init_scene(vector<Scene>* world){
	Scene temp;
	temp.paisaje = new Description(0, "Estas en un tronco hueco...");

	Action *action1 = new Action(new Description(1, "Pues no ves na"), 1, 0, 0); // LOOK
	Action *action2 = new Action(new Description(2, "Pues subes"), 2, 1, 1); // SUBIR
	action2->func = &mover;

	Action *action3 = new Action(new Description(3, "Pues bajas mas"), 3, 2, 0); // BAJAR

	temp.acciones.push_back(action1);
	temp.acciones.push_back(action2);
	temp.acciones.push_back(action3);
	world->push_back(temp);

	Scene temp2;
	temp2.paisaje = new Description(0, "Estas fuera...");
	action1 = new Action(new Description(2, "Pues bajas"), 2, 2, 0); // BAJAR
	action1->func = &mover;
	temp2.acciones.push_back(action1);
	world->push_back(temp2);

	return 0;
}
