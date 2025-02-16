/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       humanfriend22                                             */
/*    Created:      2/15/2025, 9:34:15 PM                                     */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/
#include <sstream>

#include "vex.h"

using namespace vex;

vex::brain Brain;
vex::optical Optical(PORT15);
vex::motor Intake(PORT19, gearSetting::ratio18_1, true);

// Number of data points to collect (2000 * 10ms = 20s)
#define DATA_POINTS 2000

// Used for testing
int randomDataPoint() {
    return (rand() % 100) + 1;
}

int main() {
    if (!Brain.SDcard.isInserted()) {
        Brain.Screen.print("Please insert an SD card and re-run.");
        while (1) {
            this_thread::sleep_for(100);
        }
    }

    /// Setup
    Intake.spin(fwd, 100, pct);
    Optical.setLightPower(100, percent);
    Optical.setLight(ledState::on);

    /// Collect Data
    std::stringstream ss;
    ss << "[";

    // Every 10ms, log detected hue
    for (int i = 0; i < DATA_POINTS; i++) {
        Brain.Screen.clearLine(1);
        Brain.Screen.print("Data Point: %d/%d", i + 1, DATA_POINTS);
        ss << Optical.hue() << ", ";
        this_thread::sleep_for(10);
    };

    // extra zero for the extra comma
    ss << "0]";

    /// Save Data
    std::string data = ss.str();
    const uint8_t* buffer = reinterpret_cast<const uint8_t*>(data.data());
    int32_t length = static_cast<int32_t>(data.size());
    Brain.SDcard.savefile("optical.json", const_cast<uint8_t*>(buffer), length);

    /// Finish
    Intake.stop();
    Optical.setLight(ledState::off);
    Brain.Screen.clearLine(1);
    Brain.Screen.print("Finished!");
};