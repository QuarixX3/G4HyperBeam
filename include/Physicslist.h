#ifndef PhysicsList_h
#define PhysicsList_h 1

#include "G4VModularPhysicsList.hh"

namespace HyperBeam {

class PhysicsList : public G4VModularPhysicsList {
        public:
            PhysicsList();
            ~PhysicsList();
};

}

#endif
