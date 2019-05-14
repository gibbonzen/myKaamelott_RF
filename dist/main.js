"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
const logger_1 = require("./tools/logger");
const master_node_1 = require("./master_module/master-node");
const protocole_radio_1 = require("./common/network/protocole-radio");
const door_node_1 = require("./door_module/door-node");
const radio_event_1 = require("./common/event/radio-event");
class Main {
    constructor(parameters) {
        logger_1.Logger.log("Start program", this, logger_1.Color.FG_RED);
        // Init network
        // Create radio networking
        let radioNet = new protocole_radio_1.ProtocoleRadio();
        // Init nodes
        // Create master module
        let masterNode = new master_node_1.MasterNode(0);
        masterNode.setRadioNetwork(radioNet);
        // Create Door module
        let doorNode = new door_node_1.DoorNode(1);
        doorNode.setRadioNetwork(radioNet);
        // Simulation
        masterNode.emitOnRadio(new radio_event_1.RadioEvent(masterNode, "Test radio message 2"));
    }
}
new Main([]);
//# sourceMappingURL=main.js.map