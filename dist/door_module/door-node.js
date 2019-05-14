"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
const radio_receiver_1 = require("../common/receiver/radio-receiver");
const logger_1 = require("../tools/logger");
class DoorNode extends radio_receiver_1.RadioReceiver {
    constructor(ID) {
        super();
        this.ID = ID;
    }
    onRadioEvent(event) {
        logger_1.Logger.log(`<Node n°${this.ID}>: receive new event.`, this, logger_1.Color.FG_CYAN);
        logger_1.Logger.log(`  - Message: ${event.msg}`);
    }
}
exports.DoorNode = DoorNode;
//# sourceMappingURL=door-node.js.map