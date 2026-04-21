#include <iostream>
#include "SmartHomeHub.h"
#include "BrandAFactory.h"
#include "SmartHomeFacade.h"
#include "Commands/TurnOnCommand.h"
#include "Commands/TurnOffCommand.h"
#include "Commands/TurnOnGroupCommand.h"
#include "Adapter.h"
#include "Device.h"
using namespace std;


int main() {

    cout << "===== Smart Home System =====\n\n";

    
    SmartHomeHub& hub = SmartHomeHub::getInstance(); // Singleton instance of SmartHomeHub

    //////////////////////////////////////////////////////////////////////
    BrandAFactory factory;               // Abstract Factory for creating devices of Brand A

    Device* light = factory.createLight("Living Room Light");
    Device* camera = factory.createSecurityCamera("Front Door Camera");
    Device* sensor = factory.createMotionSensor("Hallway Sensor");

    hub.addDevice(light);
    hub.addDevice(camera);
    hub.addDevice(sensor);

    cout << "Devices created using Abstract Factory.\n\n";
    // ============================================
    // 3) Observer Pattern - Motion Sensor triggers Camera
    MotionSensor* motion = dynamic_cast<MotionSensor*>(sensor);
    SecurityCamera* cam = dynamic_cast<SecurityCamera*>(camera);

    if (motion && cam) {
        motion->subscribe(cam);
        cout << "Camera subscribed to Motion Sensor.\n";
        motion->turnOn();  // triggers observer notification to camera
    }

    cout << "\n";

    // ============================================
    // 4) State Pattern - Light state changes
    Light* l = dynamic_cast<Light*>(light);
    if (l) {
        l->turnOn();
        l->turnOff();
    }

    cout << "\n";
    // ============================================
    // 5) Command Pattern - Encapsulate light on/off actions
    TurnOnCommand* cmdOn = new TurnOnCommand(light);
    hub.executeCommand(cmdOn);

    hub.undoLastCommand();

    cout << "\n";

  // ============================================
    // 6) Composite Pattern - Grouping devices

    DeviceGroup* group = new DeviceGroup("Living Room Group");
    group->addDevice(light);
    group->addDevice(camera);

    TurnOnGroupCommand* groupCmd = new TurnOnGroupCommand(group);
    hub.executeCommand(groupCmd);

    cout << "\n";

    // ============================================
    // 7) Adapter Pattern
   
    OldDevice* oldTV = new OldDevice("Old TV");
    Device* adaptedDevice = new DeviceAdapter(oldTV);

    adaptedDevice->turnOn();
    adaptedDevice->turnOff();

    cout << "\n";

    // ============================================
    // 8) Facade Pattern
    SmartHomeFacade facade(&factory);
    facade.MorningMode();
    facade.SecurityMode();

    

    return 0;
}