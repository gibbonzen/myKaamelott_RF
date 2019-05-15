"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
const radio_receiver_1 = require("../common/receiver/radio-receiver");
const logger_1 = require("../tools/logger");
const uint8_t_1 = require("../tools/uint8_t");
class BirdTableNode extends radio_receiver_1.RadioReceiver {
    constructor(ID) {
        super();
        this.ID = new uint8_t_1.uint8_t(ID);
    }
    onRadioEvent(event) {
        logger_1.Logger.log(`<Node n°${this.ID}>: receive new event from <${event.emitter.ID}>.`, this, logger_1.Color.FG_CYAN);
        logger_1.Logger.log(`  Data: [${event.data}]`);
    }
}
exports.BirdTableNode = BirdTableNode;
//# sourceMappingURL=bird-table-node.js.map