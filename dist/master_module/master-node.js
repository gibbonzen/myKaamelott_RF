"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
const radio_event_1 = require("../common/event/radio-event");
const logger_1 = require("../tools/logger");
const uint8_t_1 = require("../tools/uint8_t");
const network_adapter_1 = require("../common/network/network-adapter");
const radio_command_1 = require("../common/node/radio-command");
/**
 * Communication node for receive and emit command by WiFi or RF
 */
class MasterNode extends network_adapter_1.NetworkAdapter {
    constructor(ID) {
        super();
        this.ID = new uint8_t_1.uint8_t(ID);
    }
    onRadioEvent(event) {
        if (event.emitter == this)
            return;
        logger_1.Logger.log(`<Node n°${this.ID}> receive new event by radio.\n`);
        logger_1.Logger.log(`  Data : [${event.data}]`, this, logger_1.Color.FG_BLUE_LIGHT);
    }
    emitOnRadio(event) {
        this.emit(event);
    }
    onWifiEvent(event) {
        if (event.emitter == this)
            return;
        logger_1.Logger.log(`<Node n°${this.ID}> receive new event by wifi.\n`);
        let radioEvents = this.translateEvent(event);
        radioEvents.forEach(e => this.emitOnRadio(e));
    }
    emitOnWifi(event) {
        this.emit(event);
    }
    translateEvent(event) {
        return event.data
            .filter(d => d instanceof radio_command_1.RadioCommand)
            .map(c => new radio_event_1.RadioEvent(this, event.receiver, c));
    }
}
exports.MasterNode = MasterNode;
//# sourceMappingURL=master-node.js.map