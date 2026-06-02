#include "G4GDMLParser.hh"
#include "DetectorConstruction.h"
#include "G4NistManager.hh"
#include "G4Box.hh"
#include "G4Tubs.hh"
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4SystemOfUnits.hh"

namespace HyperBeam {

DetectorConstruction::DetectorConstruction(const G4String& gdmlFile) : G4VUserDetectorConstruction(), fGDMLFile(gdmlFile) {}
DetectorConstruciton::~DetectorConstruction() {}

G4VPhysicalVolume* DetectorConstruction::Construct() {
        fParser.Read(fGDMLFile);

        return fParser.GetWorldVolume();

}

}
