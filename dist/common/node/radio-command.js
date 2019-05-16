"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
var RadioCommands;
(function (RadioCommands) {
    RadioCommands[RadioCommands["OPEN"] = 0] = "OPEN";
    RadioCommands[RadioCommands["CLOSE"] = 1] = "CLOSE";
    RadioCommands[RadioCommands["FEED"] = 2] = "FEED";
})(RadioCommands = exports.RadioCommands || (exports.RadioCommands = {}));
class RadioCommand {
    constructor(ID, value) {
        this.ID = ID;
        this.value = value;
    }
}
exports.RadioCommand = RadioCommand;
//# sourceMappingURL=radio-command.js.map