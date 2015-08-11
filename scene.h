#ifndef SCENE_H
#define SCENE_H
#include <functional>
#include <string>
#include <vector>

using namespace std;

class Character;

void noHaceNada(int*, int);
static string OPCIONES[] = { "LOOK", "SUBIR", "BAJAR", "NADA" };

struct Description{
	Description() :id(-1), desc(""){}
	Description(int i, string d) :id(i), desc(d){}
	int id;
	string desc;
};

class Action{
public:
	Action():result(nullptr), id(-1), value(-1), dest(-1){}
	Action(Description *r, int i, int val, int de) :result(r), id(i), value(val), dest(de){}
	Description *result;
	int id;
	int value;
	int dest;
	function<void(int*,int)> func = &noHaceNada;

	void ejecutar(int *i){ func(i,dest); }
};

class Scene{
public:
    Scene() :paisaje(nullptr), acciones(NULL), mobs(NULL){}
    Scene(Description *p, vector<Action*> a):paisaje(p), acciones(a), mobs(NULL){}
    Scene(Description *p, vector<Action*> a, vector<Character*> c):paisaje(p), acciones(a), mobs(c){}

	Description *paisaje;
	vector<Action*> acciones;
    vector<Character*> mobs;
};

int init_scene(vector<Scene>* world);
#endif // SCENE_H

