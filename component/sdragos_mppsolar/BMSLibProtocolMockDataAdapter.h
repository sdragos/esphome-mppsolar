#pragma once

#include "BMSLibProtocolDataAdapter.h"

namespace sdragos
{
    namespace mppsolar
    {
        /// @brief Provides a simple mock implementation of the BMSLibProtocolDataAdapter class, that is meant to be
        ///        for understanding and testing of BMSLibProtocol implementations
        class BMSLibProtocolMockDataAdapter : public BMSLibProtocolDataAdapter
        {
        public:
            BMSLibProtocolMockDataAdapter() = default;

            uint8_t *getBMSFirmwareVersion() override
            {
                // returns 4 bytes
                auto reply = new uint8_t[4];
                reply[0] = 0;
                reply[1] = 0;
                reply[2] = 0;
                reply[3] = 1;
                return reply;
            }

            uint8_t *getBMSHardwareVersion() override
            {
                // returns 4 bytes
                auto reply = new uint8_t[4];
                reply[0] = 0;
                reply[1] = 0;
                reply[2] = 0;
                reply[3] = 1;
                return reply;
            }

            uint8_t *getNumberOfCells() override
            {
                auto reply = new uint8_t[2];
                reply[0] = 0;
                reply[1] = 8; // 8 cells
                return reply;
            }

            uint8_t *getCellVoltageOrNull(size_t cellNumber) override
            {
                // 3.327V --> 33V --- bad precision
                // value * 0.1V
                auto reply = new uint8_t[2];
                reply[0] = 0;
                reply[1] = 33;
                return reply;
            }

            uint8_t *getNumberOfTemperatureSensors() override
            {
                auto reply = new uint8_t[2];
                reply[0] = 0;
                reply[1] = 3; // 3 sensors
                return reply;
            }

            uint8_t *getTemperatureOfSensorOrNull(size_t temperatureSensorNumber) override
            {
                uint16_t kelvin = 2931; // ((273.15 + 20Celsius)*100)/10
                auto reply = new uint8_t[2];
                reply[0] = (uint8_t)(kelvin >> 8);
                reply[1] = (uint8_t)kelvin;
                return reply;
            }

            uint8_t *getModuleChargeCurrent() override
            {
                uint16_t amps = 572; // 57.2A * 10 (returning divisions of 0.1A)
                auto reply = new uint8_t[2];
                reply[0] = (uint8_t)(amps >> 8);
                reply[1] = (uint8_t)amps;
                return reply;
            }

            uint8_t *getModuleDischargeCurrent() override
            {
                uint16_t amps = 900; // 90A * 10 (returning divisions of 0.1A)
                auto reply = new uint8_t[2];
                reply[0] = (uint8_t)(amps >> 8);
                reply[1] = (uint8_t)amps;
                return reply;
            }

            uint8_t *getModuleVoltage() override
            {
                uint16_t volts = 264; // 26.4V * 10 (returning divisions of 0.1V)
                auto reply = new uint8_t[2];
                reply[0] = (uint8_t)(volts >> 8);
                reply[1] = (uint8_t)volts;
                return reply;
            }

            uint8_t *getStateOfCharge() override
            {
                auto reply = new uint8_t[2];
                reply[0] = 0x00;
                reply[1] = 70; // 70% charged
                return reply;
            }

            uint8_t *getModuleTotalCapacity() override
            {
                uint32_t milliAmpHours = 280000; // 280Ah * 1000 (returning divisions of 1 mAh)
                auto reply = new uint8_t[4];
                reply[0] = (uint8_t)(milliAmpHours >> 24);
                reply[1] = (uint8_t)(milliAmpHours >> 16);
                reply[2] = (uint8_t)(milliAmpHours >> 8);
                reply[3] = (uint8_t)milliAmpHours;
                return reply;
            }

            uint8_t *getChargeVoltageLimit() override
            {
                uint16_t amps = 292; // 29.2V * 10 (returning divisions of 0.1V)
                auto reply = new uint8_t[2];
                reply[0] = (uint8_t)(amps >> 8);
                reply[1] = (uint8_t)amps;
                return reply;
            }

            uint8_t *getDischargeVoltageLimit() override
            {
                uint16_t amps = 200; // 20V * 10 (returning divisions of 0.1V)
                auto reply = new uint8_t[2];
                reply[0] = (uint8_t)(amps >> 8);
                reply[1] = (uint8_t)amps;
                return reply;
            }

            uint8_t *getChargeCurrentLimit() override
            {
                uint16_t amps = 1400; // 140A * 10 (returning divisions of 0.1A)
                auto reply = new uint8_t[2];
                reply[0] = (uint8_t)(amps >> 8);
                reply[1] = (uint8_t)amps;
                return reply;
            }

            uint8_t *getDischargeCurrentLimit() override
            {
                uint16_t amps = 3400; // 340A * 10 (returning divisions of 0.1A)
                auto reply = new uint8_t[2];
                reply[0] = (uint8_t)(amps >> 8);
                reply[1] = (uint8_t)amps;
                return reply;
            }

            uint8_t *getChargeDischargeStatus() override
            {                                          // returning 2 bytes, the LSB will be created by mixing flags
                const uint8_t fullChargeRequest = 8;   // 0000 1000 Set when BMS needs battery fully charged
                const uint8_t chargeImmediately2 = 16; // 0001 0000 Set when SoC is low, like 10~14%
                const uint8_t chargeImmediately = 32;  // 0010 0000 Set when SoC is very low, like 5~9%
                const uint8_t dischargeEnable = 64;    // 0100 0000
                const uint8_t chargeEnable = 128;      // 1000 0000

                auto reply = new uint8_t[2];
                reply[0] = 0x00;
                reply[1] = chargeEnable | dischargeEnable;
                return reply;
            }

            uint8_t *getRuntimeToEmptySeconds() override
            {
                uint16_t seconds = 1200; // 20 hours * 60 (returning Seconds)
                auto reply = new uint8_t[2];
                reply[0] = (uint8_t)(seconds >> 8);
                reply[1] = (uint8_t)seconds;
                return reply;
            }

            uint8_t *getNumberOfCellsForWarningInfo() override
            {
                auto reply = new uint8_t[2];
                reply[0] = 0;
                reply[1] = 8; // 8 cells
                return reply;
            }

            uint8_t *getCellPairVoltageState(size_t oddCellNumber) override
            {
                auto reply = new uint8_t[2];
                reply[0] = 0;
                reply[1] = 0x00; // Normal state
                return reply;
            }

            uint8_t *getNumberOfTemperatureSensorsForWarningInfo() override
            {
                auto reply = new uint8_t[2];
                reply[0] = 0;
                reply[1] = 4; // 4 sensors
                return reply;
            }

            uint8_t *getTemperatureSensorPairState(size_t oddTemperatureSensorNumber) override
            {
                auto reply = new uint8_t[2];
                reply[0] = 0;
                reply[1] = 0x01; // below normal
                return reply;
            }

            uint8_t *getModuleChargeVoltageState() override
            {
                auto reply = new uint8_t[2];
                reply[0] = 0;
                reply[1] = 0x00; // Normal
                return reply;
            }

            uint8_t *getModuleDischargeVoltageState() override
            {
                auto reply = new uint8_t[2];
                reply[0] = 0;
                reply[1] = 0x00; // Normal
                return reply;
            }

            uint8_t *getCellChargeVoltageState() override
            {
                auto reply = new uint8_t[2];
                reply[0] = 0;
                reply[1] = 0x00; // Normal
                return reply;
            }

            uint8_t *getCellDischargeVoltageState() override
            {
                auto reply = new uint8_t[2];
                reply[0] = 0;
                reply[1] = 0xF0; // Other error
                return reply;
            }

            uint8_t *getModuleChargeCurrentState() override
            {
                auto reply = new uint8_t[2];
                reply[0] = 0;
                reply[1] = 0x00; // Normal
                return reply;
            }

            uint8_t *getModuleDischargeCurrentState() override
            {
                auto reply = new uint8_t[2];
                reply[0] = 0;
                reply[1] = 0x02; // Above higher limit
                return reply;
            }

            uint8_t *getModuleChargeTemperatureState() override
            {
                auto reply = new uint8_t[2];
                reply[0] = 0;
                reply[1] = 0x00; // Normal
                return reply;
            }

            uint8_t *getModuleDischargeTemperatureState() override
            {
                auto reply = new uint8_t[2];
                reply[0] = 0;
                reply[1] = 0x00; // Normal
                return reply;
            }

            uint8_t *getCellChargeTemperatureState() override
            {
                auto reply = new uint8_t[2];
                reply[0] = 0;
                reply[1] = 0x00; // Normal
                return reply;
            }

            uint8_t *getCellDischargeTemperatureState() override
            {
                auto reply = new uint8_t[2];
                reply[0] = 0;
                reply[1] = 0x02; // Above higher limit
                return reply;
            }
        };
    } // namespace mppsolar
} // namespace sdragos