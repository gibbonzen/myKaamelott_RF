"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
const open_command_1 = require("./open-command");
const close_command_1 = require("./close-command");
const radio_command_1 = require("../common/node/radio-command");
class DoorCommandFactory {
    create(data) {
        switch (data.command.ID.valueOf()) {
            case radio_command_1.RadioCommands.OPEN:
                return new open_command_1.OpenCommand();
            case radio_command_1.RadioCommands.CLOSE:
                return new close_command_1.CloseCommand();
            default:
                return undefined;
        }
    }
}
exports.DoorCommandFactory = DoorCommandFactory;
//# sourceMappingURL=door-commands.js.map