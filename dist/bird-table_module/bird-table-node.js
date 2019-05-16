"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
const radio_receiver_1 = require("../common/receiver/radio-receiver");
const logger_1 = require("../tools/logger");
const uint8_t_1 = require("../tools/uint8_t");
const event_tools_1 = require("../tools/event-tools");
const bird_table_command_factory_1 = require("./bird-table-command-factory");
const class_tools_1 = require("../tools/class-tools");
class BirdTableNode extends radio_receiver_1.RadioReceiver {
    constructor(ID) {
        super();
        this.ID = new uint8_t_1.uint8_t(ID);
    }
    onRadioEvent(event) {
        logger_1.Logger.log(`<Node n°${this.ID}>: receive new event from <${event.emitter.ID}>.`, this, logger_1.Color.FG_CYAN);
        let command = event_tools_1.EventTools.extractCommand(event, new bird_table_command_factory_1.BirdTableCommandFactory());
        if (this.isRunnable(command)) {
            logger_1.Logger.log(`Command [${class_tools_1.ClassTools.getObjectClass(command)}] is runnable...`, this);
        }
        else
            logger_1.Logger.log(`Unknown command`, this);
    }
    isRunnable(command) {
        return command !== undefined;
    }
    run(command) {
    }
}
exports.BirdTableNode = BirdTableNode;
//# sourceMappingURL=bird-table-node.js.map