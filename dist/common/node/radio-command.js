"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
var RadioCommands;
(function (RadioCommands) {
    // Common commands
    RadioCommands[RadioCommands["SET_HOUR"] = 0] = "SET_HOUR";
    RadioCommands[RadioCommands["SET_MIN"] = 1] = "SET_MIN";
    RadioCommands[RadioCommands["SET_AUTO"] = 2] = "SET_AUTO";
    // Door command
    RadioCommands[RadioCommands["OPEN"] = 16] = "OPEN";
    RadioCommands[RadioCommands["CLOSE"] = 17] = "CLOSE";
    RadioCommands[RadioCommands["STOP"] = 18] = "STOP";
    // Bird table command
    RadioCommands[RadioCommands["FEED"] = 32] = "FEED";
    RadioCommands[RadioCommands["SET_STANDARD_WEIGHT"] = 34] = "SET_STANDARD_WEIGHT";
})(RadioCommands = exports.RadioCommands || (exports.RadioCommands = {}));
class RadioCommand {
    constructor(ID, value) {
        this.ID = ID;
        this.value = value;
    }
}
exports.RadioCommand = RadioCommand;
//# sourceMappingURL=radio-command.js.map