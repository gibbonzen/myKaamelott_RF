"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
const logger_1 = require("./tools/logger");
const master_node_1 = require("./master_module/master-node");
const protocole_radio_1 = require("./common/network/protocole-radio");
const door_node_1 = require("./door_module/door-node");
const radio_event_1 = require("./common/event/radio-event");
const uint8_t_1 = require("./tools/uint8_t");
const bird_table_node_1 = require("./bird-table_module/bird-table-node");
const open_command_1 = require("./door_module/open-command");
const close_command_1 = require("./door_module/close-command");
const feed_command_1 = require("./bird-table_module/feed-command");
class Main {
    constructor(parameters) {
        logger_1.Logger.log("Start program", this, logger_1.Color.FG_RED);
        // Init network
        // Create radio networking
        this.radioNet = new protocole_radio_1.ProtocoleRadio();
        // Init nodes
        // Create master module
        this.masterNode = new master_node_1.MasterNode(0b0000);
        this.masterNode.setRadioNetwork(this.radioNet);
        // Create Door module
        this.doorNode = new door_node_1.DoorNode(0b0001);
        this.doorNode.setRadioNetwork(this.radioNet);
        // Create bird table
        this.birdTableNode = new bird_table_node_1.BirdTableNode(0b0010);
        this.birdTableNode.setRadioNetwork(this.radioNet);
        // Simulation
        this.runDoorSimulation();
    }
    runDoorSimulation() {
        let command = new open_command_1.OpenCommand();
        let event = new radio_event_1.RadioEvent(this.masterNode, this.birdTableNode, command);
        this.masterNode.emitOnRadio(event);
        let sendEvent = () => this.masterNode.emitOnRadio(new radio_event_1.RadioEvent(this.masterNode, this.doorNode, new close_command_1.CloseCommand()));
        this.delay(5000, sendEvent);
        sendEvent = () => this.masterNode.emitOnRadio(new radio_event_1.RadioEvent(this.masterNode, this.birdTableNode, new feed_command_1.FeedCommand()));
        this.delay(5000, sendEvent);
    }
    getData() {
        let data = [];
        for (let i = 0; i < 10; i++) {
            data.push(new uint8_t_1.uint8_t(i));
        }
        return data;
    }
    delay(millis, next) {
        setTimeout(() => {
            next();
        }, millis);
    }
}
new Main([]);
//# sourceMappingURL=main.js.map