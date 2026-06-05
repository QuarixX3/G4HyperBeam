#ifndef DetectorConstruction_h
#define DetectorConstruction_h 1

#include "globals.hh"
#include <vector>
#include "G4VUserDetectorConstruction.hh"
#include "G4VPhysicalVolume.hh"
#include "G4GDMLParser.hh"
#include "G4String.hh"

namespace HyperBeam {

class DetectorConstruction : public G4VUserDetectorConstruction {
        public:
            DetectorConstruction(const G4String& gdmlFile);
            ~DetectorConstruction();

            G4VPhysicalVolume* Construct() override;

        private:
            G4String fGDMLFile;
            G4GDMLParser fParser;

};

}

#endif
