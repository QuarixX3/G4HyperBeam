#include "ActionInitialization.h"
#include "PhysicsList.h"
#include "DetectorConstruction.h"
#include "PrimaryGeneratorAction.h"
#include "G4VisExecutive.hh"
#include "G4RunManagerFactory.hh"


int main(int argc, char** argv) {

        // make UI here
        //  G4UIExecutive* ui = nullptr;
        //  if (argc == 1) {
        //      ui = new G4UIExecutive(argc, argv);
        //  }

        // construct run manager
        auto runManager = G4RunManagerFactory::CreateRunManager(G4RunManagerType::Serial);

        using namespace HyperBeam;
        
        runManager->SetUserInitialization(new DetectorConstruction("geometry.gdml")); // construct detector
        runManager->SetUserInitialization(new PhysicsList());                         // physics list
        runManager->SetUserInitialization(new ActionInitialization());                // set user action initialization

        // initializing
        runManager->Initialize();

        // create visual
        // G4VisManager* visManager = new G4VisExecutive();
        // visManager->Initialize();

         G4UImanager* UImanager = G4UImanager::GetUIpointer();

         if (argc > 1) {
                 G4String command = "/control/execute ";
                 UImanager->ApplyCommand(command + argv[1]);
         }
         else {
                 UImanager->ApplyCommand("/run/beamOn 1000");
         }

        // finish ui stuff
        //  if (ui) {
        //      UImanager->ApplyCommand("/control/execute vis.mac);
        //      ui->SessionStart();
        //      delete ui;
        //  }
        // else {
        //         G4String command = "/control/execute ";
        //         G4String fileName = argv[1];
        //         UImanager->ApplyCommand(command + fileName);
        // }

        // delete visManager;
        delete runManager;

        return 0;
}
