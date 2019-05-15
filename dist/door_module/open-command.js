"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
const radio_command_1 = require("../common/node/radio-command");
const uint8_t_1 = require("../tools/uint8_t");
class OpenCommand extends radio_command_1.RadioCommand {
    constructor() {
        super(new uint8_t_1.uint8_t(0), []);
    }
}
exports.OpenCommand = OpenCommand;
//# sourceMappingURL=open-command.js.map