"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
class RadioController {
    onEvent(event) {
        this.onRadioEvent(event);
    }
    setRadioNetwork(network) {
        this.network = network;
        this.network.listen(this);
    }
    emit(event) {
        this.network.emit(event);
    }
}
exports.RadioController = RadioController;
//# sourceMappingURL=radio-controller.js.map