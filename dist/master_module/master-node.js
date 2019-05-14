"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
const radio_controller_1 = require("../common/network/radio-controller");
const logger_1 = require("../tools/logger");
/**
 * Communication node for receive and emit command by WiFi or RF
 */
class MasterNode extends radio_controller_1.RadioController {
    constructor(ID) {
        super();
        this.ID = ID;
    }
    onRadioEvent(event) {
        if (event.emitter == this)
            return;
        logger_1.Logger.log(`<Node n°${this.ID}>: receive new event.\n  - Message : ${event.msg}`, this, logger_1.Color.FG_BLUE_LIGHT);
    }
    emitOnRadio(event) {
        this.emit(event);
    }
}
exports.MasterNode = MasterNode;
//# sourceMappingURL=master-node.js.map