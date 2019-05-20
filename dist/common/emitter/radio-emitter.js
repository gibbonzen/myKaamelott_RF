"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
class RadioEmitter {
    setRadioNetwork(network) {
        this.network = network;
    }
    emit(event) {
        this.network.emit(event);
    }
}
exports.RadioEmitter = RadioEmitter;
//# sourceMappingURL=radio-emitter.js.map