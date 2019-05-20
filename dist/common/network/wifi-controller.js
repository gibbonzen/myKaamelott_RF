"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
class WifiController {
    onEvent(event) {
        this.onWifiEvent(event);
    }
    setWifiNetwork(network) {
        this.network = network;
        this.network.subscribe(this);
    }
    emit(event) {
        this.network.emit(event);
    }
}
exports.WifiController = WifiController;
//# sourceMappingURL=wifi-controller.js.map