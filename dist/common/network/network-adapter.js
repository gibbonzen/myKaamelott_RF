"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
const wifi_event_1 = require("../event/wifi-event");
const radio_event_1 = require("../event/radio-event");
class NetworkAdapter {
    onEvent(event) {
        if (event instanceof radio_event_1.RadioEvent)
            this.onRadioEvent(event);
        if (event instanceof wifi_event_1.WifiEvent)
            this.onWifiEvent(event);
    }
    setRadioNetwork(network) {
        this.radioNetwork = network;
        this.radioNetwork.subscribe(this);
    }
    setWifiNetwork(network) {
        this.wifiNetwork = network;
        this.wifiNetwork.subscribe(this);
    }
    emit(event) {
        if (event instanceof radio_event_1.RadioEvent)
            this.radioNetwork.emit(event);
        if (event instanceof wifi_event_1.WifiEvent)
            this.wifiNetwork.emit(event);
    }
}
exports.NetworkAdapter = NetworkAdapter;
//# sourceMappingURL=network-adapter.js.map