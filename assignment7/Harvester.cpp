
#include "Insect.h"
#include "Harvester.h"

#include <vector>
using namespace std;

void Harvester::turn(vector<vector<Insect*> > & board, int turn, int &food){
	food = food + 1;

}



Harvester::Harvester(){
	name = "Harvester";
	food = 2;
	health = 1;
	damage = 0;
}

