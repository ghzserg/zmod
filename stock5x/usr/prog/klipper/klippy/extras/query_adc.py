# Utility for querying the current state of adc pins
#
# Copyright (C) 2019  Kevin O'Connor <kevin@koconnor.net>
#
# This file may be distributed under the terms of the GNU GPLv3 license.

class QueryADC:
    def __init__(self, config):
        self.printer = config.get_printer()
        self.adc = {}
        gcode = self.printer.lookup_object('gcode')
        gcode.register_command("QUERY_ADC", self.cmd_QUERY_ADC,
                               desc=self.cmd_QUERY_ADC_help)
        gcode.register_command("GET_FILAMENT_VALUE", self.cmd_GET_FILAMENT_VALUE,
                               desc=self.cmd_GET_FILAMENT_VALUE_help)
        gcode.register_command("GET_CUT_VALUE", self.cmd_GET_CUT_VALUE,
                               desc=self.cmd_GET_CUT_VALUE_help)
    def register_adc(self, name, mcu_adc):
        self.adc[name] = mcu_adc
    cmd_QUERY_ADC_help = "Report the last value of an analog pin"
    def cmd_QUERY_ADC(self, gcmd):
        name = gcmd.get('NAME', None)
        if name not in self.adc:
            objs = ['"%s"' % (n,) for n in sorted(self.adc.keys())]
            msg = "Available ADC objects: %s" % (', '.join(objs),)
            gcmd.respond_info(msg)
            return
        value, timestamp = self.adc[name].get_last_value()
        msg = 'ADC object "%s" has value %.6f (timestamp %.3f)' % (
            name, value, timestamp)
        pullup = gcmd.get_float('PULLUP', None, above=0.)
        if pullup is not None:
            v = max(.00001, min(.99999, value))
            r = pullup * v / (1.0 - v)
            msg += "\n resistance %.3f (with %.0f pullup)" % (r, pullup)
        gcmd.respond_info(msg)
    def get_status(self, eventtime):
        value, timestamp = self.adc["temperature_sensor filamentValue"].get_last_value()
        value1, timestamp1 = self.adc["temperature_sensor cutValue"].get_last_value()
        return {'value': value,'cut': value1}
    cmd_GET_FILAMENT_VALUE_help = "get extruder filament sensor value"
    def cmd_GET_FILAMENT_VALUE(self, gcmd):
        value, timestamp = self.adc["temperature_sensor filamentValue"].get_last_value()
        msg = "value:%.5f" % (value)
        gcmd.respond_info(msg)
    cmd_GET_CUT_VALUE_help = "get extruder filament sensor value"
    def cmd_GET_CUT_VALUE(self, gcmd):
        value, timestamp = self.adc["temperature_sensor cutValue"].get_last_value()
        msg = "value:%.5f" % (value)
        gcmd.respond_info(msg)

def load_config(config):
    return QueryADC(config)
