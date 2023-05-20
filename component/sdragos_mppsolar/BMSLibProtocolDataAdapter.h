#pragma once

#include "esphome.h"

namespace sdragos
{

    namespace mppsolar
    {
        class BMSLibProtocolDataAdapter
        {
        public:
            // Version information
            virtual uint8_t *getBMSFirmwareVersion();
            virtual uint8_t *getBMSHardwareVersion();

            // BMS general status
            virtual uint8_t *getNumberOfCells();
            virtual uint8_t *getCellVoltageOrNull(size_t cellNumber);
            virtual uint8_t *getNumberOfTemperatureSensors();
            virtual uint8_t *getTemperatureOfSensorOrNull(size_t temperatureSensorNumber);
            virtual uint8_t *getModuleChargeCurrent();
            virtual uint8_t *getModuleDischargeCurrent();
            virtual uint8_t *getModuleVoltage();
            virtual uint8_t *getStateOfCharge();
            virtual uint8_t *getModuleTotalCapacity();

            // BMS warning information inquiry
            // All reply with 2 bytes and only the LSB is set to one of:
            //      0x00 - Normal
            //      0x01 - Below normal
            //      0x02 - Above higher limit
            //      0xF0 - Other error
            virtual uint8_t *getNumberOfCellsForWarningInfo();
            virtual uint8_t *getCellPairVoltageState(size_t oddCellNumber);
            virtual uint8_t *getNumberOfTemperatureSensorsForWarningInfo();
            virtual uint8_t *getTemperatureSensorPairState(size_t oddTemperatureSensorNumber);
            virtual uint8_t *getModuleChargeVoltageState();
            virtual uint8_t *getModuleDischargeVoltageState();
            virtual uint8_t *getCellChargeVoltageState();
            virtual uint8_t *getCellDischargeVoltageState();
            virtual uint8_t *getModuleChargeCurrentState();
            virtual uint8_t *getModuleDischargeCurrentState();
            virtual uint8_t *getModuleChargeTemperatureState();
            virtual uint8_t *getModuleDischargeTemperatureState();
            virtual uint8_t *getCellChargeTemperatureState();
            virtual uint8_t *getCellDischargeTemperatureState();

            // BMS charge and discharge information inquiry
            virtual uint8_t *getChargeVoltageLimit();
            virtual uint8_t *getDischargeVoltageLimit();
            virtual uint8_t *getChargeCurrentLimit();
            virtual uint8_t *getDischargeCurrentLimit();
            virtual uint8_t *getChargeDischargeStatus();
            virtual uint8_t *getRuntimeToEmptySeconds();
        }; // class BMSLibProtocolDataAdapter
    } // namespace mppsolar
} // namespace sdragos
