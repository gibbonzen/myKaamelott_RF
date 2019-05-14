"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
class RadioReceiver {
    onEvent(event) {
        this.onRadioEvent(event);
    }
    setRadioNetwork(network) {
        this.network = network;
        this.network.listen(this);
    }
}
exports.RadioReceiver = RadioReceiver;
//# sourceMappingURL=radio-receiver.js.map