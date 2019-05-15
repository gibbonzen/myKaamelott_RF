"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
const radio_receiver_1 = require("../common/receiver/radio-receiver");
const logger_1 = require("../tools/logger");
const uint8_t_1 = require("../tools/uint8_t");
const event_tools_1 = require("../tools/event-tools");
class DoorNode extends radio_receiver_1.RadioReceiver {
    constructor(ID) {
        super();
        this.ID = new uint8_t_1.uint8_t(ID);
    }
    onRadioEvent(event) {
        logger_1.Logger.log(`<Node n°${this.ID}> receive new event from <${event.emitter.ID}>.`, this, logger_1.Color.FG_CYAN);
        let data = event_tools_1.EventTools.radioDecode(event.data);
        logger_1.Logger.log('  Data: {');
        logger_1.Logger.log(`    "emitter": ${data.emitter},`);
        logger_1.Logger.log(`    "receiver": ${data.receiver},`);
        logger_1.Logger.log('    "command": {');
        logger_1.Logger.log(`      "ID": ${data.command.ID},`);
        logger_1.Logger.log(`      "value": [${data.command.value}]`);
        logger_1.Logger.log('    }');
        logger_1.Logger.log('  }');
    }
}
exports.DoorNode = DoorNode;
//# sourceMappingURL=door-node.js.map