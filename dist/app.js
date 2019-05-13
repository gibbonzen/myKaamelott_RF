"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
const door_node_1 = require("./door_module/door-node");
const logger_1 = require("./tools/logger");
class Main {
    constructor(parameters) {
        console.log("Start program");
        this.logger = new logger_1.Logger(this);
        this.logger.log("test");
        // Create Door module
        let doorNode = new door_node_1.DoorNode(1);
    }
}
new Main([]);
//# sourceMappingURL=app.js.map