"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
const event_tools_1 = require("../../tools/event-tools");
class RadioReceiver {
    onEvent(event) {
        if (!event_tools_1.EventTools.isReceiver(event, this))
            return;
        this.onRadioEvent(event);
    }
    setRadioNetwork(network) {
        this.network = network;
        this.network.listen(this);
    }
}
exports.RadioReceiver = RadioReceiver;
//# sourceMappingURL=radio-receiver.js.map