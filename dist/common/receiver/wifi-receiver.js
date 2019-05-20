"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
class WifiReceiver {
    onEvent(event) {
        throw new Error("Method not implemented.");
    }
    setWifiNetwork(network) {
        this.network = network;
        this.network.subscribe(this);
    }
}
exports.WifiReceiver = WifiReceiver;
//# sourceMappingURL=wifi-receiver.js.map