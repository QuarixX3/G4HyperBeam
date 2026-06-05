#ifndef PHYSICSLIST_H
#define PHYSICSLIST_H 1

#include "G4VModularPhysicsList.hh"

namespace HyperBeam {

class PhysicsList : public G4VModularPhysicsList {
        public:
            PhysicsList();
            ~PhysicsList();
};

}

#endif
