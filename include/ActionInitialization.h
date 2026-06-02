#ifndef ACTIONINITIALIZATION_H
#define ACTIONINITIALIZATION_H 1

#include "G4VUserActionInitialization.hh"

namespace HyperBeam {

class ActionInitialization : public G4VUserActionInitialization 
    {
        public:
            ActionInitialization();
            ~ActionInitialization();

            void BuildForMaster() const override;
            void Build() const override;
    };

}
